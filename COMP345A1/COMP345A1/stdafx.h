// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <iostream>     // std::cout
#include <string>
#include <vector>       // std::vector
#include <algorithm>    // std::sort
#include <time.h>		// for rand()


using namespace std;


// constants
# define CoalMaxNumInResourceMarket 24
# define OilMaxNumInResourceMarket 24
# define GarbageMaxNumInResourceMarket 24
# define UraniumMaxNumInResourceMarket 12

# define HouseMaxNumPerPlayer 22

# define NumTypeOfResource 4
enum TypeOfResource{ Coal, Oil, Garbage, Uranium };


