#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

const int ROWS = 30;
const int COLS = 100;

class map_generator
{
    public:
        std::array<std::array<int, COLS>, ROWS> map{}; // 0-tunnel 1-rock
        std::array<std::array<int, COLS>, ROWS> map2{};
        map_generator(unsigned int seed);

    private:
        const int filler_probability = 55;
        const int smoothings = 7;
        unsigned int seed;
        int count_walls(int cordX, int cordY);
        void smooth_map();

};
