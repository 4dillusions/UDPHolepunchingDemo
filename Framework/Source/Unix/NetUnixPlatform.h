/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "../Net.h"
#include "../NetworkSystem.h"

namespace Network
{
	bool Net::Init()
	{
        cout << "OK - initialize network\n";
		return true;
	}

	void Net::Cleanup()
	{ 
        cout << "Close network\n";
    }
}
