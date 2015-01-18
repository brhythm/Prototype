/**
 */

//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//For example,
//X X X X
//X O O X
//X X O X
//X O X X
//After running your function, the board should be:
//
//X X X X
//X X X X
//X X X X
//X O X X

#include <vector>
#include <queue>
#include <assert.h>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int numOfRow = board.size();
        if (numOfRow >0 )
        {
            int numOfColumn = board[0].size();
            queue<pair<int, int>> gridQueue;
            //check first row and last row
            for (int column=0; column < numOfColumn; ++column) {
                if (board[0][column] == 'O') {
                    gridQueue.push(make_pair(0, column));
                }//else, continue check next column
                if (board[numOfRow-1][column] == 'O') {
                    gridQueue.push(make_pair(numOfRow-1, column));
                }
            }
            //check first column and last column
            for (int row=0; row < numOfRow; ++row) {
                if (board[row][0] == 'O') {
                    gridQueue.push(make_pair(row, 0));
                }
                if (board[row][numOfColumn-1] == 'O') {
                    gridQueue.push(make_pair(row, numOfColumn-1));
                }
            }
            bfs(gridQueue, board);
            //flip all remaining 0, revert Z->0
            for (int row=0; row < numOfRow; ++row) {
                for (int column = 0; column < numOfColumn; ++column) {
                    if (board[row][column] == 'O') {
                        board[row][column] = 'X';
                    }
                    else if (board[row][column] == 'Z')
                    {
                        board[row][column] = 'O';
                    }
                }
            }
            
        }
    }
    
    void bfs(queue<pair<int, int>>& gridQueue, vector<vector<char>> &board)
    {
        int numOfRow = board.size();
        int numOfColumn = board[0].size();
        
        while (!gridQueue.empty()) {
            auto grid = gridQueue.front();
            gridQueue.pop();
            int i = grid.first;
            int j= grid.second;
            
            board[i][j] = 'Z';//tag as 'NOT flip'
            if ( i-1 >= 0 && board[i-1][j] == 'O') {
                gridQueue.push(make_pair(i-1, j));
            }
            if ( i+1 < numOfRow && board[i+1][j] == 'O') {
                gridQueue.push(make_pair(i+1, j));
            }
            if ( j-1 >= 0 && board[i][j-1] == 'O' ) {
                gridQueue.push(make_pair(i, j-1));
            }
            if ( j+1 < numOfColumn && board[i][j+1] == 'O' ) {
                gridQueue.push(make_pair(i, j+1));
            }
        }
    }
    
};

//warning, the trick is this problem is how to get rid of the isVisitedMap, which takes O(N) space
//if you start bfs from the four boarder, every 'O' that could NOT be connected should be flipped
//Note corner case: if there is no 0 on the four boarder

//why BFS ?? imagine it in your head
//for each node, the four surrounding nodes are just like the children of it , push it into the bfs queue
//don't forget to mark node that has been visited

int main()
{
    vector<vector<char>> board;
    board.push_back({'X', 'X', 'X', 'X'});
    board.push_back({'X', 'O', 'O', 'X'});
    board.push_back({'X', 'X', 'O', 'X'});
    board.push_back({'X', 'O', 'X', 'X'});
    
//    board.push_back({'X', 'X', 'X'});
//    board.push_back({'X', 'O', 'X'});
//    board.push_back({'X', 'X', 'X'});
    Solution test;
    test.solve(board);
    
    for(auto& oneLine : board )
    {
        printf("[");
        for(char c : oneLine )
        {
            printf("%c,", c);
        }
        printf("]\n");
    }
    
    return 0;
}






