/// Author: Kevin Gerber

#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

/// Create grid map of life.
/// \param gridSize
/// \return 2D vector of char*
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

///
/// \return Location of a cell to place on the map
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

/// Print grid in the console.
/// \param grid
void printGrid(vector<vector<char*>> grid)
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

/// Add a cell on the map.
/// \param coord: {int, int}
/// \param grid:  vector<vector<char*>>
void addCell(vector<int> coord, vector<vector<char*>> &grid)
{
    grid[coord[0]][coord[1]] = "0 ";
}

/// Remove a cell from the map.
/// \param coord
/// \param grid
void killCell(vector<int> coord, vector<vector<char*>> &grid)
{
    grid[coord[0]][coord[1]] = ". ";
}


/// Read the map and kill or create cells.
/// \param grid: vector<vector<char*>>
void lifeCycle(vector<vector<char*>> &grid) {

    for (int i = 1; i < grid.size() -1; ++i) {
        for (int j = 1; j < grid.size() -1; ++j) {

            int alive = 0;
            vector<vector<int>> neighbors = {{-1, -1}, {0, -1}, {-1, 1},
                                             {-1, 0}, {1, 0}, {1, -1},
                                             {0, 1}, {1, 1}};

            for(int k = 0; k < neighbors.size(); ++k)
            {
                vector<int> cellToCheck = {i, j};
                cellToCheck[0] += neighbors[k][0];
                cellToCheck[1] += neighbors[k][1];

                if(grid[cellToCheck[0]][cellToCheck[1]] == "0 ")
                {
                   alive++;
                }
            }

            // Dead of live condition:
            if (alive == 3 )
            {
                grid[i][j] = "0 ";
            } else if (alive < 2 || alive > 3)
            {
                grid[i][j] = ". ";
            }
        }
    }
}

/// Loop of the game of life.
/// \return
int main()
{

/*
    // Files for debugging
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
*/

    vector<vector<char*>> grid = createGrid(10);

    int cells = 0;
    int cellsNumber = 8;

    while(cells < cellsNumber) {
        addCell(getCoordCell(), grid);
        cells++;
    }
    printGrid(grid);

    int loops = 0;

    while(loops < 10) {
        cout << "Life cycle: " << loops << endl;
        lifeCycle(grid);
        printGrid(grid);
        loops++;
    }


}