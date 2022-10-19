//
// Created by Yonasz on 22.01.2022.
//

#include <iostream>
#include <time.h>
#include "Game.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Game g1;

    if(argc==2)
    {
        int x=atoi(argv[1]);
        g1.load(x);
        g1.run();
    }
    else
    {
        g1.load();
        g1.run();
    }

    return 0;
}