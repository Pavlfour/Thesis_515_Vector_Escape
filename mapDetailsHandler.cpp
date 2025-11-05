#include "headers/mapManager.hpp"
#include "headers/Globals.hpp"
#include <vector>

namespace maps
{

    /////////////// Intro Maps ///////////////////
    std::vector<std::vector<unsigned char>> map1 =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,4},
        {1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1}
    };

    std::vector<std::vector<unsigned char>> map2 =
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0,0,0,0,0,0,3,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    //////////////////////////////////////////////


    std::vector<std::vector<unsigned char>> map3 =
    {
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,1,1,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0},
        {1,1,0,1,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0},
        {1,1,1,1,1,1,1,1,0,0,0,2,0,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,4},
        {1,1,2,2,2,2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,0,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };


    std::vector<std::vector<unsigned char>> map4 =
    {
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,0,0,0,0,0,2,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0},
        {1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,4},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,2,1,1}
    };


    std::vector<std::vector<unsigned char>> map5 =
    {
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
        {0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
    };

    std::vector<std::vector<unsigned char>> map6 =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {3,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,1,0,1,0,0,3,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,1,0,1,1,1,1,1,0,0,1,0,4,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,1,0,3,1,3,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,0,0,0,0,0,0,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},

    };

    std::vector<std::vector<unsigned char>> map7 =
    {
        {0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,2,2,0,0,0,0,0,4},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
        {2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,3},
        {0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    };

    std::vector<std::vector<unsigned char>> map8 =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,2,1,2,2,1,1,3,0,0,0,0,0,3,1},
        {1,2,2,1,2,2,1,1,1,1,0,1,0,1,1,1},
        {1,1,1,1,1,1,1,1,3,0,0,0,0,0,3,1},
        {1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    // height:26 width:72
    std::vector<std::vector<unsigned char>> map9 =
    {
        {1,2,2,2,2,1,1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,1,1,1,2,1,1,1,1,2,1,2,2,1,1,2,0,0,0,0,0,0},
        {3,1,2,2,2,2,1,1,2,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,1,2,1,2,2,2,1,2,1,1,2,0,0,0,0,0,0},
        {2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,1,1,2,1,2,2,1,2,1,1,1,2,2,2,0,0,0,0,0,0},
        {2,1,2,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,2,2,1,2,2,1,2,3,2,1,2,1,1,1,0,0,0,0,0,0},
        {2,2,2,0,0,0,0,0,0,0,0,0,0,2,2,1,1,2,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,2,2,1,2,2,2,1,2,2,2,2,2,2},
        {2,2,1,1,1,1,1,1,1,1,1,1,0,2,2,2,2,2,3,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,2,1,2,2,1,1,2,2,2,2,2,2},
        {2,2,0,0,0,0,0,0,0,0,0,0,0,2,2,1,2,2,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,2,1,1,3,1,1,1,2,2,2,2,2,2},
        {2,1,0,0,0,0,0,0,0,0,0,0,0,2,2,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,2,2,2,2,2,1,1,2,2,2,2,2,2},
        {2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,2,2,2,2,2,2},
        {1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,3,0,0,0,0,0,0,0,1,2,2,2,1,2,1,0,1,1,2,1,2,2,2,1,2,2,2,2,2,2},
        {2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,2,1,2,2,1,1,0,1,3,2,1,3,1,1,1,2,2,2,2,2,2},
        {2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,2,1,1,2,2,1,1,1,1,0,1,2,2,2,2,1,2,2,2,2,2,2,2,2},
        {3,2,0,0,0,0,0,0,0,2,2,2,1,1,2,1,1,1,1,2,2,2,2,2,2,2,2,1,2,2,2,1,0,1,2,2,1,1,2,2,2,2,2,2,2,2,2},
        {2,2,0,0,0,0,0,0,0,0,2,2,2,1,2,2,2,2,2,1,2,1,2,1,2,1,2,1,1,2,2,1,0,1,2,2,2,2,4,2,2,2,2,2,2,2,2},
        {2,2,0,0,0,0,0,0,0,0,0,2,1,2,2,1,1,3,2,2,1,1,1,3,2,2,1,1,2,2,2,1,0,2,2,2,2,2,0,0,2,2,2,2,2,2,2},
        {2,1,0,0,0,0,0,0,0,0,0,1,2,1,2,2,2,1,2,1,2,2,1,2,2,2,2,2,1,1,3,1,0,2,2,2,1,2,1,0,0,2,0,2,2,2,2},
        {1,2,0,0,0,0,0,0,0,0,0,1,2,1,1,1,1,2,1,1,2,1,2,1,1,1,2,3,2,2,1,1,0,2,1,2,2,2,1,1,0,0,0,0,0,2,1},
        {1,2,0,0,0,0,0,0,0,0,0,2,1,2,2,2,1,2,2,0,0,0,0,2,2,1,1,2,1,1,1,1,0,2,1,2,2,2,2,2,0,1,1,1,0,0,2},
        {2,0,0,0,0,0,0,0,0,0,2,2,1,1,2,2,2,1,1,0,0,0,0,1,1,1,2,1,1,2,1,2,0,2,2,2,2,1,2,2,2,2,1,1,1,0,2},
        {2,0,0,0,0,0,0,0,0,0,2,2,2,2,1,1,2,1,1,0,0,0,0,2,2,3,1,1,2,1,1,2,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,2,2,2,1,2,1,2,1,2,2,0,0,0,0,1,2,1,2,1,2,2,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0,2,2,1,2,2,1,1,1,1,2,1,0,0,0,0,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {0,0,0,0,0,0,0,0,2,2,3,2,1,1,2,1,2,1,2,0,0,0,0,1,1,1,2,2,1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
        {0,0,0,0,0,0,0,2,2,1,2,2,1,2,2,1,2,1,1,0,0,0,0,2,1,2,2,2,2,2,2,2,1,2,2,1,1,1,1,2,1,1,1,2,2,1,2},
        {0,0,0,0,0,0,2,2,2,2,1,2,1,1,1,1,2,1,2,0,0,0,0,1,1,1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,3,2,2},
        {1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };


    // credits map
    std::vector<std::vector<unsigned char>> map10 =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

}


void addMapComponents(mapManager* currentMap)
{

    switch(currentMap->getCurrentMapIndex())
    {
        case 1:

            // Voltwings
            currentMap->addVoltwing({{2*cellSize+16.f,6*cellSize+16.f},{4*cellSize + 16.f,6*cellSize+16.f}},0.5f);
            // Coins
            currentMap->addCoin(2*cellSize + 23.f, 4*cellSize + 23.f);
            currentMap->addCoin(3*cellSize + 23.f, 4*cellSize + 23.f);
            currentMap->addCoin(4*cellSize + 23.f, 4*cellSize + 23.f);
            // Beamloks
            currentMap->addBeamlok({6*cellSize,6*cellSize+32.f},
                                   {12*cellSize+32.f,6*cellSize+32.f},
                                    0.8f);
            break;

        case 2:

            // Coins
            currentMap->addCoin(5*cellSize - 41, 2*cellSize - 41);
            currentMap->addCoin(8*cellSize - 41, 2*cellSize - 41);
            currentMap->addCoin(9*cellSize - 41, 2*cellSize - 41);
            currentMap->addCoin(13*cellSize - 59, 2*cellSize - 41);
            currentMap->addCoin(13*cellSize - 41, 2*cellSize - 41);
            currentMap->addCoin(13*cellSize - 23, 2*cellSize - 41);
            currentMap->addCoin(14*cellSize - 68, 2*cellSize - 41);
            currentMap->addCoin(14*cellSize - 50, 2*cellSize - 41);
            currentMap->addCoin(14*cellSize - 32, 2*cellSize - 41);
            currentMap->addCoin(15*cellSize - 77, 2*cellSize - 41);
            currentMap->addCoin(15*cellSize - 59, 2*cellSize - 41);
            currentMap->addCoin(15*cellSize - 41, 2*cellSize - 41);
            currentMap->addCoin(15*cellSize - 23, 2*cellSize - 41);
            currentMap->addCoin(23*cellSize - 41, 5*cellSize - 41);
            currentMap->addCoin(23*cellSize - 41, 6*cellSize - 41);
            currentMap->addCoin(33*cellSize - 41, 1*cellSize - 41);
            currentMap->addCoin(33*cellSize - 41, 2*cellSize - 41);
            // Beamloks
            currentMap->addBeamlok({17*cellSize,5*cellSize+32.f},
                                   {20*cellSize+32.f,5*cellSize+32.f},
                                    1.5f);
            break;

        case 3:
            // Coins
            currentMap->addCoin(4*cellSize - 41, 2*cellSize - 41);
            currentMap->addCoin(14*cellSize + 23, 23);
            currentMap->addCoin(11*cellSize + 23, 3*cellSize);
            currentMap->addCoin(11*cellSize + 23, 3*cellSize + 18);
            currentMap->addCoin(11*cellSize + 23, 3*cellSize + 36);
            currentMap->addCoin(11*cellSize + 23, 4*cellSize - 9);
            currentMap->addCoin(11*cellSize + 23, 4*cellSize + 10);
            currentMap->addCoin(11*cellSize + 23, 4*cellSize + 28);
            currentMap->addCoin(11*cellSize + 23, 5*cellSize - 18);
            currentMap->addCoin(44*cellSize + 23, 1*cellSize + 23);
            currentMap->addCoin(45*cellSize + 23, 1*cellSize + 23);
            currentMap->addCoin(46*cellSize + 23, 1*cellSize + 23);
            currentMap->addCoin(21*cellSize     , 5*cellSize);
            currentMap->addCoin(21*cellSize + 18, 5*cellSize);
            currentMap->addCoin(21*cellSize + 36, 5*cellSize);
            currentMap->addCoin(21*cellSize + 54, 5*cellSize);
            currentMap->addCoin(21*cellSize     , 5*cellSize + 18);
            currentMap->addCoin(21*cellSize + 18, 5*cellSize + 18);
            currentMap->addCoin(21*cellSize + 36, 5*cellSize + 18);
            currentMap->addCoin(21*cellSize + 54, 5*cellSize + 18);
            currentMap->addCoin(21*cellSize     , 5*cellSize + 36);
            currentMap->addCoin(21*cellSize + 18, 5*cellSize + 36);
            currentMap->addCoin(21*cellSize + 36, 5*cellSize + 36);
            currentMap->addCoin(21*cellSize + 54, 5*cellSize + 36);
            currentMap->addCoin(22*cellSize +  9, 5*cellSize);
            currentMap->addCoin(22*cellSize + 27, 5*cellSize);
            currentMap->addCoin(22*cellSize + 45, 5*cellSize);
            currentMap->addCoin(22*cellSize + 63, 5*cellSize);
            currentMap->addCoin(22*cellSize +  9, 5*cellSize + 18);
            currentMap->addCoin(22*cellSize + 27, 5*cellSize + 18);
            currentMap->addCoin(22*cellSize + 45, 5*cellSize + 18);
            currentMap->addCoin(22*cellSize + 63, 5*cellSize + 18);
            currentMap->addCoin(22*cellSize +  9, 5*cellSize + 36);
            currentMap->addCoin(22*cellSize + 27, 5*cellSize + 36);
            currentMap->addCoin(22*cellSize + 45, 5*cellSize + 36);
            currentMap->addCoin(22*cellSize + 63, 5*cellSize + 36);
            currentMap->addCoin(23*cellSize + 18, 5*cellSize);
            currentMap->addCoin(23*cellSize + 36, 5*cellSize);
            currentMap->addCoin(23*cellSize + 54, 5*cellSize);
            currentMap->addCoin(23*cellSize + 72, 5*cellSize);
            currentMap->addCoin(23*cellSize + 18, 5*cellSize + 18);
            currentMap->addCoin(23*cellSize + 36, 5*cellSize + 18);
            currentMap->addCoin(23*cellSize + 54, 5*cellSize + 18);
            currentMap->addCoin(23*cellSize + 72, 5*cellSize + 18);
            currentMap->addCoin(23*cellSize + 18, 5*cellSize + 36);
            currentMap->addCoin(23*cellSize + 36, 5*cellSize + 36);
            currentMap->addCoin(23*cellSize + 54, 5*cellSize + 36);
            currentMap->addCoin(23*cellSize + 72, 5*cellSize + 36);
            currentMap->addCoin(21*cellSize     , 4*cellSize + 27);
            currentMap->addCoin(21*cellSize + 18, 4*cellSize + 27);
            currentMap->addCoin(21*cellSize + 36, 4*cellSize + 27);
            currentMap->addCoin(21*cellSize + 54, 4*cellSize + 27);
            currentMap->addCoin(21*cellSize     , 4*cellSize + 45);
            currentMap->addCoin(21*cellSize + 18, 4*cellSize + 45);
            currentMap->addCoin(21*cellSize + 36, 4*cellSize + 45);
            currentMap->addCoin(21*cellSize + 54, 4*cellSize + 45);
            currentMap->addCoin(22*cellSize +  9, 4*cellSize + 27);
            currentMap->addCoin(22*cellSize + 27, 4*cellSize + 27);
            currentMap->addCoin(22*cellSize + 45, 4*cellSize + 27);
            currentMap->addCoin(22*cellSize + 63, 4*cellSize + 27);
            currentMap->addCoin(22*cellSize +  9, 4*cellSize + 45);
            currentMap->addCoin(22*cellSize + 27, 4*cellSize + 45);
            currentMap->addCoin(22*cellSize + 45, 4*cellSize + 45);
            currentMap->addCoin(22*cellSize + 63, 4*cellSize + 45);
            currentMap->addCoin(23*cellSize + 18, 4*cellSize + 27);
            currentMap->addCoin(23*cellSize + 36, 4*cellSize + 27);
            currentMap->addCoin(23*cellSize + 54, 4*cellSize + 27);
            currentMap->addCoin(23*cellSize + 72, 4*cellSize + 27);
            currentMap->addCoin(23*cellSize + 18, 4*cellSize + 45);
            currentMap->addCoin(23*cellSize + 36, 4*cellSize + 45);
            currentMap->addCoin(23*cellSize + 54, 4*cellSize + 45);
            currentMap->addCoin(23*cellSize + 72, 4*cellSize + 45);
            currentMap->addCoin(50*cellSize + 23, 4*cellSize + 23);
            currentMap->addCoin(51*cellSize + 23, 2*cellSize + 23);
            currentMap->addCoin(52*cellSize + 23, 2*cellSize + 23);
            currentMap->addCoin(52*cellSize + 23, 3*cellSize + 23);
            currentMap->addCoin(53*cellSize + 23, 3*cellSize + 23);
            currentMap->addCoin(53*cellSize + 23, 4*cellSize + 23);
            // Linear Platforms
            currentMap->addLinearPlatform({36*cellSize,6*cellSize},{41*cellSize,6*cellSize},0.9f);
            currentMap->addLinearPlatform({47*cellSize,4*cellSize},{42*cellSize,4*cellSize},0.9f);
            // Voltwings
            currentMap->addVoltwing({{9*cellSize+16.f,16.f},{9*cellSize + 16.f,6*cellSize + 16.f}}
                                    ,1.5f);
            currentMap->addVoltwing({{49*cellSize+16.f,16.f},{49*cellSize + 16.f,2*cellSize + 16.f},
                                    {52*cellSize + 16.f,2*cellSize + 16.f}, {52*cellSize + 16.f,3*cellSize + 16.f}, 
                                    {54*cellSize + 16.f,3*cellSize + 16.f},{54*cellSize + 16.f,16.f}}
                                    ,3.5f);
            currentMap->addVoltwing({{20*cellSize + 25.f, 4*cellSize + 16.f},{20*cellSize + 25.f, 6*cellSize},
                                    {24*cellSize + 32.f,6*cellSize},{24*cellSize + 32.f,4*cellSize + 16.f}}
                                    ,2.f);
            currentMap->addVoltwing({{49*cellSize+16.f,4*cellSize + 16.f},{49.*cellSize + 16.f,6*cellSize+16.f},
                                    {51*cellSize+16.f,6*cellSize+16.f},{51*cellSize+16.f,4*cellSize + 16.f},
                                    {49*cellSize+16.f,4*cellSize + 16.f}}
                                    ,2.5f);
            break;

        case 4:
            // Coins
            currentMap->addCoin(5*cellSize + 18.f, 9.f);
            currentMap->addCoin(5*cellSize + 18.f, 27.f);
            currentMap->addCoin(5*cellSize + 18.f, 45.f);
            currentMap->addCoin(5*cellSize + 18.f, 63.f);
            currentMap->addCoin(5*cellSize + 18.f, 81.f);
            currentMap->addCoin(5*cellSize + 18.f, 99.f);

            currentMap->addCoin(30*cellSize + 18.f,2*cellSize - 18.f);
            currentMap->addCoin(30*cellSize + 18.f,2*cellSize       );
            currentMap->addCoin(30*cellSize + 18.f,2*cellSize + 18.f);
            currentMap->addCoin(30*cellSize + 18.f,2*cellSize + 36.f);

            //New coins
            currentMap->addCoin(27*cellSize + 23.f,5*cellSize + 23.f);
            currentMap->addCoin(28*cellSize + 23.f,5*cellSize + 23.f);
            currentMap->addCoin(29*cellSize + 23.f,5*cellSize + 23.f);
            currentMap->addCoin(30*cellSize + 23.f,5*cellSize + 23.f);
            currentMap->addCoin(31*cellSize + 23.f,5*cellSize + 23.f);
            currentMap->addCoin(32*cellSize + 23.f,5*cellSize + 23.f);
            currentMap->addCoin(33*cellSize + 23.f,5*cellSize + 23.f);

            // Linear Platforms
            currentMap->addLinearPlatform({10*cellSize,3*cellSize},{14*cellSize,5*cellSize},1.f);
            currentMap->addLinearPlatform({19*cellSize,3*cellSize},{15*cellSize,5*cellSize},1.f);
            currentMap->addLinearPlatform({20*cellSize,3*cellSize},{24*cellSize,5*cellSize},1.f);
            // Voltwings
            currentMap->addVoltwing({{27*cellSize+16.f,5*cellSize + 16.f},{33*cellSize + 16.f,5*cellSize + 16.f}}
                                    ,1.5f);
            break;
        
        case 5:
            // Coins
            currentMap->addCoin(10*cellSize + 23, 16*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 16*cellSize +23);
            currentMap->addCoin(8*cellSize + 23, 16*cellSize +23);
            currentMap->addCoin(7*cellSize + 23, 16*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 6*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 7*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 8*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 9*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 10*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 11*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 12*cellSize +23);
            currentMap->addCoin(11*cellSize + 23, 14*cellSize +23);
            currentMap->addCoin(5*cellSize + 23, 1*cellSize +23);
            currentMap->addCoin(7*cellSize + 23, 1*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 1*cellSize +23);
            currentMap->addCoin(11*cellSize + 23, 1*cellSize +23);
            currentMap->addCoin(13*cellSize + 23, 1*cellSize +23);
            currentMap->addCoin(15*cellSize + 23, 1*cellSize +23);
            currentMap->addCoin(17*cellSize + 23, 1*cellSize +23);
            currentMap->addCoin(11*cellSize + 18, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 36, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 54, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 72, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 90, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 108, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 126, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 144, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 162, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 180, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 198, 10*cellSize +23);
            currentMap->addCoin(11*cellSize + 216, 10*cellSize +23);

            // Voltwings
            currentMap->addVoltwing({{13*cellSize+16.f,12*cellSize + 16.f},{14*cellSize + 16.f,12*cellSize + 16.f},
                                    {14*cellSize+16.f,13*cellSize + 16.f},{13*cellSize + 16.f,13*cellSize + 16.f},
                                    {13*cellSize+16.f,12*cellSize + 16.f}
                                    }
                                    ,1.0f);

            // Linear Platforms
            currentMap->addLinearPlatform({3*cellSize,15*cellSize},{3*cellSize,13*cellSize},0.5f);
            // Beamloks
            currentMap->addBeamlok({16*cellSize,1*cellSize+32.f},
                                   {27*cellSize+32.f,1*cellSize+32.f},
                                    2.0f);
            break;

        case 6:
            // Coins
            currentMap->addCoin(2*cellSize + 23, 13*cellSize +23);
            currentMap->addCoin(4*cellSize + 23, 12*cellSize +23);
            currentMap->addCoin(5*cellSize + 23, 15*cellSize +23);
            currentMap->addCoin(9*cellSize + 23, 7*cellSize +23);
            currentMap->addCoin(13*cellSize + 23, 23);
            currentMap->addCoin(11*cellSize + 23, 4*cellSize +23);
            currentMap->addCoin(15*cellSize + 23, 4*cellSize +23);
            currentMap->addCoin(13*cellSize + 23, 6*cellSize +23);
            currentMap->addCoin(14*cellSize + 23, 15*cellSize +23);
            currentMap->addCoin(2*cellSize + 23, 10*cellSize +23);
            currentMap->addCoin(1*cellSize + 23, 9*cellSize +23);
            currentMap->addCoin(23, 11*cellSize +23);

            // Circular Platforms
            currentMap->addCircularPlatform({10*cellSize,13*cellSize},3*cellSize,0.01f,true,0.0f);
            currentMap->addCircularPlatform({18*cellSize,13*cellSize},3*cellSize,0.01f,false,M_PI);
            currentMap->addCircularPlatform({13*cellSize,4*cellSize},3*cellSize,0.01f,true,0.0f);
            currentMap->addCircularPlatform({20*cellSize,3*cellSize},2*cellSize,0.01f,false,1.95f*M_PI/2.0f);
            break;
        
        case 8:
            currentMap->addCircularPlatform({3*cellSize,22*cellSize},2*cellSize,0.01f,false,0.0f);
            currentMap->addCircularPlatform({6*cellSize,16*cellSize},3*cellSize,0.01f,false,1.95f*M_PI/2.0f);
            // Linear Platforms
            currentMap->addLinearPlatform({2*cellSize,15*cellSize},{2*cellSize,7*cellSize},0.8f);
            currentMap->addLinearPlatform({12*cellSize,7*cellSize},{4*cellSize,7*cellSize},0.8f);
            currentMap->addLinearPlatform({4*cellSize,10*cellSize},{15*cellSize,10*cellSize},1.9f);

            // Voltwings
            currentMap->addVoltwing({{3*cellSize+16.f,22*cellSize+16.f},{3*cellSize + 16.f,22*cellSize + 16.f}}
                                    ,0.2f);
            currentMap->addVoltwing({{6*cellSize+16.f,16*cellSize+16.f},{6*cellSize + 16.f,16*cellSize + 16.f}}
                                    ,0.2f);


            currentMap->addVoltwing({{42*cellSize+16.f,15*cellSize+16.f},{42*cellSize + 16.f,16*cellSize + 16.f}}
                                    ,1.5f);
            currentMap->addVoltwing({{40*cellSize+16.f,17*cellSize+16.f},{40*cellSize + 16.f,15*cellSize + 16.f}}
                                    ,0.75f);
            break;
    }
            
}

void updateMapComponets(mapManager* currentMap,short x,short y)
{
    switch(currentMap->getCurrentMapIndex())
    {
        case 1:
            if(currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] == Cell::TriggerTile)
            {
                currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] = Cell::Empty;
                if(x == 13 && y == 5)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][15] = Cell::ExitTile;
                }
            }
            break;

        case 4:
            if(currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] == Cell::TriggerTile)
            {
                currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] = Cell::Empty;
                if(x == 8 && y == 5)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][8] = Cell::Empty;
                }
                else if(x == 30 && y == 3)
                {
                    currentMap->addLinearPlatform({33*cellSize,3*cellSize},{40*cellSize,6*cellSize},1.0f);
                }

            }
            break;

        case 5:
            if(currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] == Cell::TriggerTile)
            {
                currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] = Cell::Empty;
                if(x == 8 && y == 14)
                {
                    currentMap->addLinearPlatform({1*cellSize,13*cellSize},{1*cellSize,8*cellSize},1.0f);
                    currentMap->addLinearPlatform({3*cellSize,3*cellSize},{3*cellSize,8*cellSize},1.0f);
                }
                else if(x == 11 && y == 16)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][12][15] = Cell::Empty;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][16][4] = Cell::Empty;
                }
                else if(x == 0 && y == 4)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][5] = Cell::Empty;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][6] = Cell::Empty;
                }
                else if(x == 10 && y == 14)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][14][13] = Cell::BlueTile;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][15][11] = Cell::Empty;
                }
                
            }
            break;

        case 6:
            if(currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] == Cell::TriggerTile)
            {
                currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] = Cell::Empty;
                if(x == 23 && y == 9)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][8][10] = Cell::Empty;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][9][10] = Cell::Empty;
                }
            }
        case 7:
            static unsigned char progress = 0;
            if(currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] == Cell::TriggerTile)
            {
                currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] = Cell::Empty;
                // αριστερά πάνω
                if(x == 8 && y == 1)
                {

                    if(progress == 3)
                    {


                        // κρύψε
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][8] = Cell::Empty;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][8] = Cell::Empty;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][14] = Cell::Empty;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][14] = Cell::Empty;

                        // unlock path
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::Empty;

                        // Coins
                        currentMap->addCoin(11*cellSize + 4, 4*cellSize + 4);
                        currentMap->addCoin(11*cellSize + 23, 4*cellSize  + 4);
                        currentMap->addCoin(11*cellSize + 41, 4*cellSize + 4);

                        currentMap->addCoin(11*cellSize +4, 4*cellSize +22);
                        currentMap->addCoin(11*cellSize + 23, 4*cellSize +22);
                        currentMap->addCoin(11*cellSize + 41, 4*cellSize +22);
                        
                        currentMap->addCoin(11*cellSize +4, 4*cellSize +40);
                        currentMap->addCoin(11*cellSize + 23, 4*cellSize +40);
                        currentMap->addCoin(11*cellSize + 41, 4*cellSize +40);

                        
                        currentMap->addCoin(11*cellSize + 4, 5*cellSize + 4);
                        currentMap->addCoin(11*cellSize + 23, 5*cellSize  + 4);
                        currentMap->addCoin(11*cellSize + 41, 5*cellSize + 4);

                        currentMap->addCoin(11*cellSize +4, 5*cellSize +22);
                        currentMap->addCoin(11*cellSize + 23, 5*cellSize +22);
                        currentMap->addCoin(11*cellSize + 41, 5*cellSize +22);
                        
                        currentMap->addCoin(11*cellSize +4, 5*cellSize +40);
                        currentMap->addCoin(11*cellSize + 23, 5*cellSize +40);
                        currentMap->addCoin(11*cellSize + 41, 5*cellSize +40);


                        for(short i = 11;i>=2;i--)
                        {
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][i] = Cell::Empty;
                            currentMap->addCoin(i*cellSize +4, 6*cellSize +4);
                            currentMap->addCoin(i*cellSize + 23, 6*cellSize +4);
                            currentMap->addCoin(i*cellSize + 41, 6*cellSize +4);
                            currentMap->addCoin(i*cellSize +4, 6*cellSize +22);
                            currentMap->addCoin(i*cellSize + 23, 6*cellSize +22);
                            currentMap->addCoin(i*cellSize + 41, 6*cellSize +22);
                            currentMap->addCoin(i*cellSize +4, 6*cellSize +40);
                            currentMap->addCoin(i*cellSize + 23, 6*cellSize +40);
                            currentMap->addCoin(i*cellSize + 41, 6*cellSize +40);
                        }
                        return;

                    }
                    else
                    {

                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][14] = Cell::TriggerTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][14] = Cell::TriggerTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][8] = Cell::TriggerTile;

                        if(progress == 0)
                        {
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::Empty;
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::BlueTile;
                        }
                        else if(progress == 1)
                        {
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::BlueTile;
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::Empty;
                            progress = 0;
                        }
                        else if(progress == 2)
                        {
                            progress = 0;
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::BlueTile;
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::Empty;
                            currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::BlueTile;
                        }
                    }


                }
                // δεξιά πάνω
                else if(x == 14 && y == 1)
                {

                    // εμφάνισε
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][8] = Cell::TriggerTile;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][8] = Cell::TriggerTile;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][14] = Cell::TriggerTile;

                    if(progress == 0)
                    {

                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::BlueTile;
                    }
                    else
                    {
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::Empty;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::BlueTile;
                    }

                    progress = 1;

                }
                // δεξιά κάτω
                else if(x == 14 && y == 3)
                {

                    // εμφάνισε
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][8] = Cell::TriggerTile;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][8] = Cell::TriggerTile;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][14] = Cell::TriggerTile;

                    if(progress == 0)
                    {

                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::Empty;
                    }
                    else if(progress == 1)
                    {
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::Empty;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::BlueTile;
                        progress = 0;
                    }
                    else if(progress == 2)
                    {
                        progress = 3;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::Empty;
                    }






                }
                // αριστερά κάτω
                else if(x == 8 && y == 3)
                {

                    // εμφάνισε
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][8] = Cell::TriggerTile;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][1][14] = Cell::TriggerTile;
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][14] = Cell::TriggerTile;

                    if(progress == 0)
                    {
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::Empty;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::Empty;
                    }
                    else if(progress == 1)
                    {
                        progress = 2;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::Empty;
                    }
                    else
                    {
                        progress = 1;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][4][11] = Cell::Empty;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][11] = Cell::BlueTile;
                        currentMap->getMapPool()[currentMap->getCurrentMapIndex()][6][11] = Cell::Empty;
                    }


                }
            }
            break;
        case 8:
            if(currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] == Cell::TriggerTile)
            {
                currentMap->getMapPool()[currentMap->getCurrentMapIndex()][y][x] = Cell::Empty;
                if(x == 15 && y == 9)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][3][22] = Cell::Empty;
                }
                else if(x == 17 && y == 9)
                {
                    currentMap->getMapPool()[currentMap->getCurrentMapIndex()][5][23] = Cell::Empty;
                    // Beamloks
                    currentMap->addBeamlok({18*cellSize,7*cellSize+32.f},
                                        {21*cellSize+32.f,7*cellSize+32.f},
                                            1.0f);
                    currentMap->addBeamlok({25*cellSize,7*cellSize+32.f},
                                        {30*cellSize+32.f,7*cellSize+32.f},
                                            1.5f);
                }
                else if(x == 32 && y == 19)
                {
                    currentMap->addLinearPlatform({32*cellSize,20*cellSize},{45*cellSize,20*cellSize},0.7f);
                }
            break;
            }
    }
}