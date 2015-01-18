/**
 */

//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
// ["ABCE"],
// ["SFCS"],
// ["ADEE"]
// ]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.

#include <vector>
#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        bool isFound = false;
        size_t numRow = board.size();
        if(numRow > 0 && word.length() > 0)
        {
            size_t numCol = board[0].size();
            for (int i=0; i < numRow && !isFound; ++i) {
                for (int j=0; j < numCol && !isFound; ++j) {
                    if (board[i][j] == word[0]) {
                        isFound = recursiveSearch(i, j, 0, word, board);
                    }
                }
            }

        }
        return isFound;
    }
    
    //board might be updated during the search
    bool recursiveSearch(const int row, const int column, const int wordIndex, const string& word, vector<vector<char>>& board)
    {
        size_t numRow = board.size();
        size_t numCol = board[0].size();
        if (board[row][column] == word[wordIndex])
        {//current char matches
            if (wordIndex == word.length()-1)
            {//the complete word is already found
                return true;
            }
            else
            {
                //try to start searching from current position
                char restoreChar = board[row][column];
                board[row][column] = '.';
                //try going right
                if (column+1 < numCol &&
                    board[row][column+1] != '.')
                {
                    if (recursiveSearch(row, column+1, wordIndex+1, word, board)) {
                        return true;
                    }//else going right does not lead to solution
                }
                //try going left
                if (column-1 >=0 &&
                    board[row][column-1] != '.') {
                    if (recursiveSearch(row, column-1, wordIndex+1, word, board)) {
                        return true;
                    }//else going left does not lead to solution
                }
                //try going up
                if (row-1 >=0 &&
                    board[row-1][column] != '.') {
                    if (recursiveSearch(row-1, column, wordIndex+1, word, board)) {
                        return true;
                    }//else going up does not lead to solution
                }
                //try going down
                if (row+1 < numRow &&
                    board[row+1][column] != '.') {
                    if (recursiveSearch(row+1, column, wordIndex+1, word, board)) {
                        return true;
                    }//else going down does not lead to solution
                }
                //backtrack
                //cancel current step
                board[row][column] = restoreChar;
                return false;
            }
        }
        else
        {//does not match
            return false;
        }
    }
};





