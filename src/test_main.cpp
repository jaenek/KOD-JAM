#include <iostream>
#include "map_generator.hpp"
#include <ctime>
using namespace std;


int main() {
    map_generator mapa(time(NULL));

    for(int x=0; x< mapa.width; x++)
    {
        for(int y=0; y<mapa.height; y++)
        {
            cout <<  mapa.map[x][y];
        }
        cout<<endl;
    }


    return 0;
}