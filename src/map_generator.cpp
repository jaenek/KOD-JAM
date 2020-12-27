#include "map_generator.hpp"


map_generator::map_generator(unsigned int seed)
{
    srand(seed);

    //Wypelnij kamieniem / niczym / podloga
    for (int x=0; x < rows; x++)
    {
        for( int y = 0; y < columns; y++)
        {
            if ( x == 0 || x == rows - 1 || y == 0 || y == columns - 1) {
                //Border
                map[x][y] = 1;
            }
            else {
                //Rock
                if (rand()%100 <= filler_probability) map[x][y] = 1;
                //Tunnel
                else map[x][y] = 0;
            }
    
        }
    }

    // Wygladz
    for(int i =0; i < smoothings; i++) {
       map_generator::smooth_map();
    }

    for (int x=0; x < rows; x++)
    {
        for (int y=0; y < columns; y++)
        {
            map[x][y] = map2[x][y];
        }
    }
}

void map_generator::smooth_map()
{
    for (int x=0; x < rows; x++)
    {
        for (int y=0; y < columns; y++)
        {
            int surround_walls = count_walls(x, y);

            if (surround_walls > 4) map2[x][y] = 1;
            else if (surround_walls < 4) map2[x][y] = 0;
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
            if (x >= 0 && x < rows && y >= 0 && y < columns)
            {
                //Jesli rozwazany "piksel" nie jest tym, ktory jest w cordX i cordT
                if (x != cordX || y != cordY)
                {
                    count += map[x][y];
                }
            }
            else {
                count += 1;
            }

        }

    }

    return count;
}