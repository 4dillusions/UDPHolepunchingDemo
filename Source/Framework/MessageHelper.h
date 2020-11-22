/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <string>

namespace Network
{
	class SocketAddress;
	class UDPSocket;

	class MessageHelper final
	{
	public:
		MessageHelper() = delete;
		MessageHelper(const MessageHelper&) = delete;
		MessageHelper(MessageHelper&&) = delete;
		~MessageHelper() = delete;
		MessageHelper& operator=(const MessageHelper&) = delete;
		MessageHelper& operator=(MessageHelper&&) = delete;

		static void SendToRemoteMachine(UDPSocket* sock, SocketAddress& address, const std::string& message);
		static std::string ReceiveFromRemoteMachine(UDPSocket* sock, SocketAddress& address);
		static std::string ReceiveFromRemoteMachine(UDPSocket* sock);
	};
}
