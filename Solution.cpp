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
            
            //check first row and last row
            for (int column=0; column < numOfColumn; ++column) {
                if (board[0][column] == '0') {
                    bfs(0, column, board);
                }//else, continue check next column
                if (board[numOfRow-1][column] == '0') {
                    bfs(numOfRow-1, column, board);
                }
            }
            //check first column and last column
            for (int row=0; row < numOfRow; ++row) {
                if (board[row][0] == '0') {
                    bfs(row, 0, board);
                }
                if (board[row][numOfColumn-1] == '0') {
                    bfs(row, numOfColumn-1, board);
                }
            }
            //flip all remaining 0, revert Z->0
            for (int row=0; row < numOfRow; ++row) {
                for (int column = 0; column < numOfColumn; ++column) {
                    if (board[row][column] == '0') {
                        board[row][column] = 'X';
                    }
                    else if (board[row][column] == 'Z')
                    {
                        board[row][column] = '0';
                    }
                }
            }
            
        }
    }
    
    void bfs(const int row, const int column, vector<vector<char>> &board)
    {
        int numOfRow = board.size();
        int numOfColumn = board[0].size();
        assert(board[row][column] == '0');//assert that we start from '0' node
        queue<pair<int, int>> gridQueue;
        gridQueue.push(make_pair(row, column));
        
        while (!gridQueue.empty()) {
            auto grid = gridQueue.front();
            gridQueue.pop();
            int i = grid.first;
            int j= grid.second;
            
            board[i][j] = 'Z';//tag as 'NOT flip'
            if ( i-1 >= 0 && board[i-1][j] == '0') {
                gridQueue.push(make_pair(i-1, j));
            }
            if ( i+1 < numOfRow && board[i+1][j] == '0') {
                gridQueue.push(make_pair(i+1, j));
            }
            if ( j-1 >= 0 && board[i][j-1] == '0' ) {
                gridQueue.push(make_pair(i, j-1));
            }
            if ( j+1 < numOfColumn && board[i][j+1] == '0' ) {
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
//    board.push_back({'X', 'X', 'X', 'X'});
//    board.push_back({'X', '0', '0', 'X'});
//    board.push_back({'X', 'X', '0', 'X'});
//    board.push_back({'X', '0', 'X', 'X'});
    
    board.push_back({'X', 'X', 'X'});
    board.push_back({'X', '0', 'X'});
    board.push_back({'X', 'X', 'X'});
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






