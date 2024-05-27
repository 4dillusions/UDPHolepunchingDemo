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

using namespace Network;

int main()
{
	Net::Init();

	auto* socket = new UDPSocket;
	SocketAddress anyAddress(PortNumber);
	socket->Bind(anyAddress);
	SocketAddress clientFirstAdress{}, clientSecondAddress{};

	//cout << "STUN server public address: " << SocketAddress::GetLocalIp() << ":" << PortNumber << endl;

	MessageHelper::ReceiveFromRemoteMachine(socket, clientFirstAdress);
	MessageHelper::ReceiveFromRemoteMachine(socket, clientSecondAddress);

	MessageHelper::SendToRemoteMachine(socket, clientFirstAdress, clientSecondAddress.ToString());
	MessageHelper::SendToRemoteMachine(socket, clientSecondAddress, clientFirstAdress.ToString());

	delete socket;
	Net::Cleanup();
	cout << "Hole punching was finished! You may turn off the STUN server.\n";
	PauseProgram();

	return 0;
}
