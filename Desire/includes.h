#pragma once
#define ArraySize(arr) (sizeof(arr) / sizeof(arr[0]))
#define AssertIn(x, y) assert(static_cast<unsigned int>(x) < static_cast<unsigned int>(y))

enum TitleIDs
{
	BOOT_UP = 0x00000000,
	DASHBOARD = 0xFFFE07D1,
	MW2 = 0x41560817,
	COD4 = 0x415607E6,
	BO2 = 0x415608C3
};

#include <xtl.h>
#include <xboxmath.h>
#include <xbox.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cctype>
#include <ctime>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <map>
#include <dos.h>

#include <time.h>
#include <xbdm.h>
#include <cstdint>
#include <stdexcept>
#include <iterator>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
#include <xkelib.h>
#include <xtl.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "xorstr.h"
#include "utilities.h"
#include "vector.h"

#ifndef GAME_H
#define GAME_H
namespace game
{
	bool moduleunloading();
	extern int current_title;
}
#endif
#define CURGAME game::current_title