/*
Suppose that two players are playing a tic-tac-toe game on an n×n board.
They’re following specific rules to play and win the game.

* A move is guranteed to be valid if a mark is placed on empty block.
* No more moves are allowed once a winning condition is reached.
* A player who succeeds in placing n of thier marks in a horizontal, vertical, or diagonal row wins the game.

Your task is to implement a TicTacToe class, which will be used by two players to play the game and win the fairly.

Keep in mind the following functionalities that need to be implemented:
 
 * The TicTacToe class, which declares an object to create the board.
 * Init (n), which initializes the object of TicTacToe to create the board of size n.
 * Move (row, col, player) indicates that the player with ID player plays at the board’s cell (row, col). move is guaranteed to be a valid move.
   At each move, this function returns the player ID if any player wins and returns 0 if no one wins. 

Constraints:
   * 3 <=n <=9
   * The player should be either 1 or 2
   * 0<=row,col<=n
   * Every call to move() will be a unique row, col combination
   * The move function will be called at most n^2 combinations

*/

#include<vector>
using namespace std;

class TicTacToe{

    public:
        // TicTacToe class contains rows, cols, diagonal,
        // and antiDiagonal to create a board.
        vector<vector<int>> board;
        // vector<int> cols;
        // int diagonal;
        // int antiDiagonal;

        // Constructor is used to create n * n tic - tac - toe board.
        TicTacToe(int n){
            board.assign(n,vector<int>(n,0));

            // rows.assign(n, 0);
            // cols.assign(n, 0);
            // diagonal = 0;
            // antiDiagonal = 0;
        }

        // Move function will allow the players to play the game
        // for given row and col.
        int Move(int row, int col, int player){
            if (row<0 || row >= board.size()) return -1;
            if (col<0 || col >= board.size()) return -1;

             if(board[row][col]!=0){
                return -1;
             } else {
                board[row][col]= player;
                // lets check if  there is a winner
                bool iscolwinner=true;
                bool isrowinner=true;
                for (int x=0; x<board.size();++x ){
                    if(board[x][col]!=player) iscolwinner=false;
                    if(board[row][x]!=player) isrowinner=false;
                }
                if (isrowinner||iscolwinner){
                    return player;
                }
                if (row ==col)  {
                  // check for diagonal
                  bool isdiagwinner=true;
                  for (int x=0; x<board.size();++x ){
                    if (board[x][x]!=player) isdiagwinner=false;
                  }
                  if(isdiagwinner) return player;
                }
                if (row+col==board.size()-1){
                    bool isdiagwinner=true;
                  for (int x=0; x<board.size();++x ){
                    if (board[x][board.size()-1-x]!=player) isdiagwinner=false;
                  }
                  if(isdiagwinner) return player;
                }

                   return 0;   
             }
                        return -1;
        }
};