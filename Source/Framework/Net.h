/*
UDP Holepunching demo
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace Network
{
	class Net final
	{
	public:
		Net() = delete;
		Net(const Net&) = delete;
		Net(Net&&) = delete;
		~Net() = delete;
		Net& operator=(const Net&) = delete;
		Net& operator=(Net&&) = delete;

		static bool Init();
		static void Cleanup();
	};
}
