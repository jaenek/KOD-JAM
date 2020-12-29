#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "map_object.hpp"

class map_generator
{
    public:
        std::vector<std::vector<map_object>>map;
        std::vector<std::vector<map_object>>map2;
        map_generator(unsigned int seed);
        static int ROWS;
        static int COLS;

    private:
        const static int gold_chance = 2;
        const int filler_probability = 55;
        const int smoothings = 7;
        unsigned int seed;
        int count_walls(int cordX, int cordY);
        void smooth_map();
        void add_gold();
        void add_exit();

};
