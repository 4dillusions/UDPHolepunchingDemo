/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "Framework/NetworkSystem.h"
#include "Framework/Net.h"
#include "Framework/UDPSocket.h"
#include "Framework/SocketAddress.h"
#include "Framework/MessageHelper.h"
#include "Framework/IpV4Address.h"

#include <thread>

using namespace Network;

void StunClient()
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
}

void UDPReceiver()
{
	Net::Init();

	const int port = 24000;
	const int MessageByteBufferSize = 1024;
	char messageByteBuffer[MessageByteBufferSize];

	const auto receiverSocket = new UDPSocket;
	receiverSocket->SetNonBlocking();
	receiverSocket->BindAny(port);

	while (true)
	{
		memset(messageByteBuffer, 0, MessageByteBufferSize);
		SocketAddress senderAddress{};
		const int receiverRes = receiverSocket->ReceiveFrom(messageByteBuffer, MessageByteBufferSize, senderAddress);
		if (receiverRes > 10)
		{
			cout << "local IP: " << SocketAddress::GetLocalIp() << endl;
			cout << "sender IP: " << senderAddress.GetIp() << endl;
			cout << "sender message: " << string(messageByteBuffer) << endl;
		}

		std::this_thread::sleep_for(1s);
	}

	delete receiverSocket;
	Net::Cleanup();
}

int main()
{
	StunClient();
	//UDPReceiver();
	
	PauseProgram();

	return 0;
}
