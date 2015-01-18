/*
 * Solution.cpp
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with
 * the character '.'.
 *
 * A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 */
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
    	if (board.size() != 9 ||
    	    board[0].size() != 9 )
    	{
    		return false;
    	}
    	else
    	{
    		//check all rows
    		//warning, be careful where you reset bool array
    		bool isUsed[9];
    		for (int i=0; i < 9; ++i) {
        		fill(isUsed, isUsed+9, false);
    			for (int j=0; j < 9; ++j) {
    				if ( !validate(board[i][j], isUsed))
    				{
    					return false;
    				}
    			}
    		}
    		//check all columns
    		for (int i=0; i < 9; ++i) {
        		fill(isUsed, isUsed+9, false);
    			for (int j=0; j < 9; ++j) {
    				if ( !validate(board[j][i], isUsed))
    				{
    					return false;
    				}
    			}
    		}
    		//check sub-board
    		for (int row = 0; row < 9; row += 3) {
    			for (int column = 0; column < 9; column +=3) {
    				//for each sub-board
    	    		fill(isUsed, isUsed+9, false);
    				for (int i=row; i < row+3; ++i) {
    					for (int j=column; j < column+3; ++j){
    						if ( !validate(board[i][j], isUsed)) {
    							return false;
    						}
    					}
    				}
    			}
    		}
    		return true;
    	}
    }

    bool validate(char currentChar, bool isUsed[]) {
    	if (currentChar == '.') {
    		return true;
    	}
    	else {
    		//warning, it is more natural to use '1' instead of 49
    		if ( isUsed[currentChar - '1'] ) {
    			return false;
    		}
    		else
    		{
    			isUsed[currentChar - '1'] = true;
    			return true;
    		}
    	}
    }
};

//int main()
//{
//	vector<vector<char> > board;
//	char* array[] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
//	for (int i=0; i < 9; ++i) {
//		vector<char> oneRow(9, '.');
//		for(int j=0; j < 9; ++j) {
//			oneRow[j] = array[i][j];
//		}
//		board.push_back(oneRow);
//
//	}
//	Solution test;
//	bool isOK = test.isValidSudoku(board);
//	printf("is valid? %d\n", isOK);
//}



