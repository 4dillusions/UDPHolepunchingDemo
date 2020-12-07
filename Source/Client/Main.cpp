/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "NetworkSystem.h"
#include "Net.h"
#include "UDPSocket.h"
#include "SocketAddress.h"
#include "MessageHelper.h"
#include "IpV4Address.h"
#include <thread>

using namespace Network;

int main()
{
	Net::Init();

	auto* socket = new UDPSocket;
	SocketAddress stunServerAddress(PortNumber, GetLine("STUN server ip: ").c_str());
	SocketAddress anyAddress(0);
	socket->Bind(anyAddress);

	//cout << "Client local IP: " << SocketAddress::GetLocalIp() << endl;

	MessageHelper::SendToRemoteMachine(socket, stunServerAddress, "Hello server!");

	const string serverMessage = MessageHelper::ReceiveFromRemoteMachine(socket);
	auto remoteMachineIpAndPort = SplitString(serverMessage, ':');
	SocketAddress remoteMachineAddress(std::atoi(remoteMachineIpAndPort[1].c_str()), IpV4Address{ remoteMachineIpAndPort[0] });

	for (int i = 0; i < 10; i++)
	{
		MessageHelper::SendToRemoteMachine(socket, remoteMachineAddress, "Hello friend client! " + std::to_string(i));
		MessageHelper::ReceiveFromRemoteMachine(socket);
		std::this_thread::sleep_for(1s);
	}

	delete socket;
	Net::Cleanup();

	PauseProgram();

	return 0;
}
