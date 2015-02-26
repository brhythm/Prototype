/**
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 
 Empty cells are indicated by the character '.'.
 
 You may assume that there will be only one unique solution.
 */
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    //sudoku is always 9x9
    //validation include row, column and square
    //there is NO zero in sudoku
    void solveSudoku(vector<vector<char> > &board) {
        if (board.size()== 9)
            recursiveSolver(0, 0, board);
        return;
        
    }
    
    bool recursiveSolver(int row, int column, vector<vector<char>>& board) {
        int n = 9;
        if (row == n) {
            //terminate condition
            //found solution
            return true;
        }
        if (column == n) {//complete current row
            //try to resolve next row
            return recursiveSolver(row + 1, 0, board);
        } else {                                      //solve this row
            //try to place digits at missing spot
            if (board[row][column] == '.') {
                //for missing spot
                for (int i=1; i <=9; ++i) {
                    char digit = i + '0';
                    board[row][column] = digit;
                    bool isValid = validateGrid(row, column, board);
                    //printf("debug %c at %d,%d is %d\n", board[row][column], row, column, isValid);
                    if (isValid)
                    {
                        //vector<vector<char>> restoreBoard = board;
                        if (!recursiveSolver(row, column+1, board)) {
                            //fail to find solution
                            //backtrack
                            board[row][column] = '.';
                            //ready to try next available digit
                        }
                        else
                        {//found solution
                            return true;
                        }
                    }
                    else
                    {//else try next digit
                        board[row][column] = '.';
                    }
                }
                //we have tried all possible digit, nothing could be placed at this spot
                return false;
            }
            else
            {//current digit is placed go to next column
                return recursiveSolver(row, column+1, board);
            }
        }
    }
    
    //only need to validate row, column and square
    //this function would be called many times, performance is important
    bool validateGrid(const int row, const int column, vector<vector<char>>& board)
    {
        size_t n = 9;
        //Learn! Don't use array for validation, there is a faster way
        //vector<bool> isTaken(n+1, false);//isTaken[0] is dummy
        //validate row
        for (size_t j=0; j< n; ++j)
        {
            if (j != column && board[row][j] == board[row][column])
                return false;
        }
        //validate column
        for (size_t i=0; i< n; ++i) {
            if (i != row && board[i][column] == board[row][column])
                return false;
        }
        //validate square
        //Remember how to do it
        for (int i = 3*(row/3); i < 3*(row/3+1); ++i)
            for(int j= 3*(column/3); j < 3*(column/3+1);++j)
            {
                if ( i != row && j!=column && board[i][j]==board[row][column])
                    return false;
            }
        return true;
    }
};

int main()
{
    return 0;
}