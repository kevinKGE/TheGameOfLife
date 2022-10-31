#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include "algorithm"
#include "iterator"

using namespace std;

vector<vector<char*>> createGrid(int gridSize)
{
    vector<vector<char*>> grid;

    for (int i = 0; i < gridSize; i++)
    {
        grid.push_back({});
        for (int j = 0; j < gridSize; j++)
        {
            grid[i].push_back(". ");
        }
    }
    return grid;
}

vector<int> getCoordCell()
{
    int x, y;
    vector<int> coord;

    cout << "Where do you want to add a cell? " << endl;
    cout << "enter two coordinates : " << endl;
    cin >> x >> y;

    coord.push_back(x);
    coord.push_back(y);

    return coord;
}

void printGrid(vector<vector<char*>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void addCell(vector<int> coord, vector<vector<char*>> &grid)
{
    grid[coord[0]][coord[1]] = "0 ";
}

void killCell(vector<int> coord, vector<vector<char*>> &grid)
{
    grid[coord[0]][coord[1]] = ". ";
}

/*
void lifeCycle(vector<vector<char*>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid.size(); j++) {
            int count;

                if (grid[i - 1][j - 1] == "0 " && grid[i - 1][j + 1] == "0 " && grid[i + 1][j + 1] == "0 " &&
                    grid[i + 1][j - 1] == "0 "
                    && grid[i][j - 1] == "0 " && grid[i][j + 1] == "0 " && grid[i - 1][j] == "0 " &&
                    grid[i + 1][j] == "0 ") {

                }
        }
        }
    }

}
*/
int main()
{
/*
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
*/
    vector<vector<char*>> grid = createGrid(5);
    printGrid(grid);
    addCell(getCoordCell(), grid);
    printGrid(grid);
/*
    while(1)
    {
        lifeCycle(grid);
    }
    */
}