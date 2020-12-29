#include "map_generator.hpp"

map_generator::map_generator(unsigned int seed)
{
    srand(seed);

    //Wypelnij kamieniem / niczym / podloga
    for (int x=0; x < ROWS; x++)
    {
        for( int y = 0; y < COLS; y++)
        {
            if ( x == 0 || x == ROWS - 1 || y == 0 || y == COLS - 1)
            {
                //Border
                map[x][y] = map_object::BORDER;
            }
            else
            {
                //Rock
                if (rand()%100 <= filler_probability) map[x][y] = map_object::ROCK;
                //Tunnel
                else map[x][y] = map_object::TUNNEL;
            }
    
        }
    }

    // Wygladz
    for(int i = 0; i < smoothings; i++)
    {
       smooth_map();
    }

    for (int x=1; x < ROWS-1; x++)
    {
        for (int y=1; y < COLS-1; y++)
        {
            map[x][y] = map2[x][y];
        }
    }

    add_gold();
}

void map_generator::smooth_map()
{
    for (int x=1; x < ROWS-1; x++)
    {
        for (int y=1; y < COLS-1; y++)
        {
            int surround_walls = count_walls(x, y);

            if (surround_walls > 4) map2[x][y] = map_object::ROCK;
            else if (surround_walls < 4) map2[x][y] = map_object::TUNNEL;
        }
    }
}

// 101
// 0X0 return 5 
// 111
int map_generator::count_walls(int cordX, int cordY)
{
    int count=0;

    for (int x=cordX-1; x <= cordX+1; x++)
    {
        for (int y=cordY-1; y <= cordY+1; y++)
        {
            //Jesli rozwazany "piksel" jest w dozwolonej lokalizacji
            if (x > 0 && x < ROWS-1 && y > 0 && y < COLS-1)
            {
                //Jesli rozwazany "piksel" nie jest tym, ktory jest w cordX i cordT
                if (x != cordX || y != cordY)
                {
                    if (map[x][y] == map_object::ROCK || map[x][y] == map_object::BORDER)
                        count++;
                }
            }
            else {
                count++;
            }

        }

    }

    return count;
}

void map_generator::add_gold()
{
    for (int x=1; x < ROWS-1; x++)
    {
        for (int y = 1; y < COLS-1; y++)
        {
            if (rand() % 100 <= gold_chance)
            {
                map[x][y] = map_object::GOLD_ORE;
            }
        }
    }
}
