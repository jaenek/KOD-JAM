#include <iostream>
#include "map_generator.hpp"
#include <ctime>
using namespace std;


int main() {
    map_generator mapa(time(NULL));

    for(int x=0; x< mapa.rows; x++)
    {
        for(int y=0; y<mapa.columns; y++)
        {
            cout << (mapa.map[x][y]) ? 1 : 0;
        }
        cout<<endl;
    }


    return 0;
}