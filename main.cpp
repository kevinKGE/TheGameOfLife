/// Author: Kevin Gerber

#include <iostream>
#include <vector>
#include "algorithm"
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#include <unistd.h>
#else
#include <unistd.h>
#endif

using namespace std;

/// Method for cleaning the console.
void clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

/// Grid generator.
/// \param gridSize: int
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

/// Ask the user where he wants to add a cell.
/// \return Location of a cell to place on the map
vector<int> getCoordCell()
{
    int x, y;
    vector<int> coord;

    cout << "Where do you want to add a cell? " << endl;
    cout << "enter two coordinates: " << endl;
    cin >> x >> y;

    coord.push_back(x);
    coord.push_back(y);

    return coord;
}

/// Display the grid in the console.
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

    vector<vector<char*>> gridTemp = grid;

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

            // Dead or live condition:
            if (alive == 3 )
            {
                addCell({i, j}, gridTemp);
            } else if (alive < 2 || alive > 3)
            {
                killCell({i, j}, gridTemp);
            }
        }
    }
    grid = gridTemp;
}

void addCellsRandomly(int nbOfCells, vector<vector<char*>> &grid)
{
    int randomX, randomY;
    for(int i = 0; i < nbOfCells; ++i)
    {
        randomX = 1 + (rand() % (grid.size()-1));
        randomY = 1 + (rand() % (grid.size()-1));

        if(grid[randomX][randomY] == ". ")
        {
            addCell({randomX, randomY}, grid);
        }
        else
        {
            --i;
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

    int cells = 0;
    int cellsNumber;
    int loopsNumber;
    int gridSize;

    cout << "Hello ! Welcome to The Game Of Life." << endl;
    cout << "Please enter the size of the grid that you want to display:" << endl;
    cin >> gridSize;
    cout << "Please enter the number of loops that you want to execute:" << endl;
    cin >> loopsNumber;
    cout << "Finally, enter the number of cells that you want to put in the grid:" << endl;
    cin >> cellsNumber;

    vector<vector<char*>> grid = createGrid(gridSize);

    addCellsRandomly((gridSize*gridSize/3), grid);

    while(cells < cellsNumber) {
        addCell(getCoordCell(), grid);
        cells++;
    }
    printGrid(grid);

    int loops = 0;

    while(loops < loopsNumber) {
        cout << "Life cycle: " << loops << endl;
        lifeCycle(grid);
        printGrid(grid);
        sleep(1.2);
        loops++;
        clear();
    }
}