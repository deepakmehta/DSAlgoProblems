/*
You’re given an (m×n) matrix where each cell of the matrix can have one of three values: 0 represents an empty cell,
1 represents a fresh orange, 2represents a rotten orange

Every minute, an orange becomes rotten if it’s adjacent to a rotten orange in any direction.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1.

Constraints:
  m==grid.length
  n==grid{i}.length
  1 <=m,n <=10
  grid{i}{j} == 0,1,2

*/

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int MinMinutesToRot(vector<vector<int>> grid)
{
    // lets do a bfs over all rotten apples as multiple sources
    // keep repeating till all infections have happened and count the iterations of bfs as minutes
    // If after infections still there are non rotten images return -1 else return number of iterations of bfs;

    queue<pair<int, int>> ros_;
    int iterations = 0;
    // collect all the rotten oranges index
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (grid[i][j] == 2)
                ros_.push(pair<int, int>(i, j));
        }
    }

    // Lets start bfs
    int currentSize = ros_.size();
    while (currentSize > 0)
    {
        pair<int, int> ro = ros_.front();
        ros_.pop();

        if ( grid[ ro.first][ro.second] == 2)
        {
            // lets convert this into empty space
            grid[ro.first][ro.second] = 0;
            // lets check in every direction

            if (ro.first > 1)
            {
                if (grid[ro.first - 1][ro.second] == 1)
                {
                    grid[ro.first - 1][ro.second]=2;
                    ros_.push( pair<int, int>(ro.first - 1, ro.second));
                }
            }
            if (ro.second > 1)
            {
                if (grid[ro.first][ro.second - 1] == 1)
                {
                    grid[ro.first][ro.second - 1]=2;
                    ros_.push(pair<int, int>(ro.first, ro.second - 1));
                }
            }

            if (ro.first < m - 1)
            {
                if (grid[ro.first + 1][ro.second] == 1)
                {
                    grid[ro.first + 1][ro.second]=2;
                    ros_.push(pair<int, int>(ro.first + 1, ro.second));
                }
            }
            if (ro.second < n - 1)
            {
                if (grid[ro.first][ro.second + 1] == 1)
                {
                    grid[ro.first][ro.second + 1]=2;
                    ros_.push(pair<int, int>(ro.first, ro.second + 1));
                }
            }
        }
        currentSize--;
        if (currentSize == 0) {
            currentSize = ros_.size();
            iterations++;
        }
    }

    // check if perfect apple is left
    int perfectapplefound=false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]==1) {
                 perfectapplefound=true;
                 break;
            }
        }
        if(perfectapplefound)break;
    }
    

    return perfectapplefound?-1:iterations-1;
}

int main()
{
    cout << MinMinutesToRot({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}) << endl;
    cout << MinMinutesToRot({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}) << endl;
    cout << MinMinutesToRot({{0, 2}}) << endl;
    cout << MinMinutesToRot({{0, 1, 2}, {1, 0, 2}, {0, 2, 1}}) << endl;
    return 0;
}