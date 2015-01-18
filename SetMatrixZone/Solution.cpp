/*
 * Solution.cpp
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */
#include <vector>

using namespace std;

class Solution {
public:
	//Time complexity O(mn) anyway
    void setZeroes(vector<vector<int> > &matrix) {
    	int numRow = matrix.size();
    	int numColumn = matrix[0].size();
    	vector<bool> isRowZero(numRow, false);
    	vector<bool> isColumnZero(numColumn, false);

    	for (int i=0; i < numRow; ++i) {
    		for (int j=0; j < numColumn; ++j)
    		{
    			if (matrix[i][j] == 0) {
    				isRowZero[i] = isColumnZero[j] = true;
    			}
    		}
    	}
    	for (int i=0; i < numRow; ++i) {
    		if (isRowZero[i]) {
    			//warning, learn 2d array address
    			fill(&matrix[i][0], &matrix[i][0]+numColumn, 0);
    		}
    	}
    	for (int j=0; j < numColumn; ++j) {
    		if (isColumnZero[j]){
    			//column address is not contiguous
    			for (int i=0; i < numRow; ++i) {
    				matrix[i][j] = 0;
    			}
    		}
    	}
    }
};




