/*
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids.
 * How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 */
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        //construct D[m+1][n+1];have one extra row/column for convenience; bound condition
        // D[0][], D[][0] are extra
        int numRows = obstacleGrid.size();
        int numCols = obstacleGrid[0].size();

        //init all grids to be 0
        vector<int> oneRow (numCols+1, 0);
        vector<vector<int> > D(numRows+1, oneRow);

        //WARNING!! Don't overwrite D[1][1] is the for loop
        //D[1][1] might not be 1;

        for (int row=0; row < numRows; ++row) {
            for (int column=0; column < numCols; ++column) {
                if (obstacleGrid[row][column] == 1) {
                    //obstacle
                    D[row+1][column+1] = 0;
                }
                else
                {//calculate unique path for this grid
                    if (row == 0 && column== 0) {
                        //NOTE, don't overwrite D[1][1],it is not calculated
                        D[row+1][column+1] = 1;
                    }
                    else
                    {
                        D[row+1][column+1] = D[row][column+1] + D[row+1][column];
                    }
                }
            }
        }
        return D[numRows][numCols];
    }
};




