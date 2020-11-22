/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

// ReSharper disable CppUnusedIncludeDirective
#ifdef _WIN64
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX

	//Error	C4996 'inet_ntoa': Use inet_ntop() or InetNtop() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
	//Error	C4996 'gethostbyname': Use getaddrinfo() or GetAddrInfoW() instead or define _WINSOCK_DEPRECATED_NO_WARNINGS to disable deprecated API warnings
	#define _WINSOCK_DEPRECATED_NO_WARNINGS

	#include "Windows.h"
	#include "WinSock2.h"
	#include "WS2tcpip.h"
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <sys/types.h>
	#include <netdb.h>
	#include <cerrno>
	#include <fcntl.h>
	#include <unistd.h>
	#include <arpa/inet.h>
	#include <linux/in.h>

	typedef int SOCKET;
	const int NO_ERROR = 0;
	const int INVALID_SOCKET = -1;
	const int WSAECONNRESET = ECONNRESET;
	const int WSAEWOULDBLOCK = EAGAIN;
	const int SOCKET_ERROR = -1;
#endif

#include <iostream>
#include <vector>
#include <string>
// ReSharper restore CppUnusedIncludeDirective

using namespace std;

inline std::vector<std::string> SplitString(const std::string& text, char seperator)
{
    vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = text.find(seperator, pos)) != std::string::npos)
    {
        std::string substring(text.substr(prev_pos, pos - prev_pos));

        output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(text.substr(prev_pos, pos - prev_pos));

    return output;
}

inline string GetLine(const string question)
{
	string result;
	cout << question;
	cin >> result;

	return result;
}

inline void PauseProgram()
{
	#ifdef _WIN64
		system("pause");
	#else
		getchar();
	#endif

}

const unsigned short PortNumber = 64000;
const int MessageBufferSize = 4096;
