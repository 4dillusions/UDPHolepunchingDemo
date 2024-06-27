/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "NetworkSystemPlatform.h"

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

const unsigned short PortNumber = 64000;
const int MessageBufferSize = 4096;
