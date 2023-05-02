/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0).
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool IsLiveMember(int nr, int nc, int r, int c, vector<vector<int>> &board)
  {
    if (nr >= 0 && nr < r)
    {
      if (nc >= 0 && nc < c)
      {
        return board[nr][nc];
      }
    }
    return 0;
  }
  void gameOfLife(vector<vector<int>> &board)
  {
    vector<vector<int>> newboard(board.size(),vector<int>(board[0].size(),0));
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; ++i)
    {
      for (int j = 0; j < col; ++j)
      {
        int numberofLiveMembers = 0;
        numberofLiveMembers += IsLiveMember(i, j - 1, row, col, board);
        numberofLiveMembers += IsLiveMember(i, j + 1, row, col, board);
        numberofLiveMembers += IsLiveMember(i - 1, j - 1, row, col, board);
        numberofLiveMembers += IsLiveMember(i - 1, j + 1, row, col, board);
        numberofLiveMembers += IsLiveMember(i + 1, j - 1, row, col, board);
        numberofLiveMembers += IsLiveMember(i + 1, j + 1, row, col, board);
        numberofLiveMembers += IsLiveMember(i - 1, j, row, col, board);
        numberofLiveMembers += IsLiveMember(i + 1, j, row, col, board);
        if (!board[i][j])
          if (numberofLiveMembers == 3)
          {
            newboard[i][j] = 1;
          }
          else
          {
            newboard[i][j] = 0;
          }

      if (board[i][j])
      {

        if (numberofLiveMembers < 2)
        {
          newboard[i][j] = 0;
        }
        else if (numberofLiveMembers <= 3)
        {
          newboard[i][j] = 1;
        } else {
        newboard[i][j] = 0;
        }
      }
    }
    }
    board=newboard;
  }
};

int main(int argc, char const *argv[])
{
  Solution s;
  vector<vector<int>> board{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
  s.gameOfLife(board);
  return 0;
}
