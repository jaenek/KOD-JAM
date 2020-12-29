#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

#include "map_object.hpp"

const int ROWS = 100;
const int COLS = 100;


class map_generator
{
    public:
        std::array<std::array<map_object, COLS>, ROWS> map{}; // 0-tunnel 1-rock, 2-border, 3-gold
        std::array<std::array<map_object, COLS>, ROWS> map2{};
        map_generator(unsigned int seed);

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
