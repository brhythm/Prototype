/**
 */

//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        size_t numRow = grid.size();
        int sum = 0;
        if (numRow > 0 && grid[0].size() > 0) {
            size_t numCol = grid[0].size();
            int D[numRow][numCol];
            memset(&D[0][0], 0, numRow*numCol*sizeof(int));
            D[0][0] = grid[0][0];
            for (size_t j=1; j < numCol; ++j) {
                D[0][j] = D[0][j-1] + grid[0][j];
            }
            for (size_t i=1; i < numRow; ++i) {
                D[i][0] = D[i-1][0] + grid[i][0];
            }
            for (size_t i=1; i < numRow; ++i) {
                for (size_t j=1; j < numCol; ++j) {
                    D[i][j] = grid[i][j] + min(D[i-1][j], D[i][j-1]);
                   // printf("D[%d,%d]=%d\n", i, j, D[i][j]);
                }
            }
            sum = D[numRow-1][numCol-1];
        }
        return sum;
    }
};

//int main()
//{
//    vector<vector<int>> grid;
//    grid.push_back({1,2});
//    grid.push_back({1,1});
//    Solution test;
//    int sum = test.minPathSum(grid);
//    printf("%d\n", sum);
//    return 0;
//}