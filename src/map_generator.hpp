#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class map_generator
{
    public:
        const int width=30;
        const int height=100;
        int **map; //0-tunnel, 1-rock
        int **map2;
        map_generator(unsigned int seed);


    private:
        const int filler_probability = 55;
        const int smoothings = 7;
        unsigned int seed;
        int count_walls(int cordX, int cordY);
        void smooth_map();

};
