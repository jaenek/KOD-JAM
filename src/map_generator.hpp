#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <array>

class map_generator
{
    public:
        static const int rows=30;
        static const int columns=100;
        std::array<std::array<int, columns>, rows> map{}; // 0-tunnel 1-rock
        std::array<std::array<int, columns>, rows> map2{};
        map_generator(unsigned int seed);

    private:
        const int filler_probability = 55;
        const int smoothings = 7;
        unsigned int seed;
        int count_walls(int cordX, int cordY);
        void smooth_map();

};
