// Compile: g++ -O2 -lSDL2 -std=c++20 game.cpp

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include "algorithm"
#include "iterator"

/*
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
*/

using namespace std;

void createGrid(int gridSize)
{
    // vector<vector<char*>> grid2 = {{"a","b"},{"c", "d"}};
    vector<vector<char*>> grid;

    for (int i = 0; i < gridSize; i++)
    {
        grid.push_back({". "});
        for (int j = 0; j < gridSize; j++)
        {
            grid[i].push_back(". ");
            cout << grid[i][j];
        }
        cout << endl;
    }

}

int main()
{
    createGrid(50);
    return 0;
}