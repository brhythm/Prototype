/*
 * A robot is located at the top-left corner of a m x n grid
 * (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid
 * (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 */

#include <vector>
using namespace std;
class Solution {
public:
    //Time O(mn) space O(mn)
    int uniquePaths(int m, int n) {

        // construct D[m][n] , init to 0
        vector<int> oneRow(n,0);
        vector<vector<int> > D(m, oneRow);

        // D[0][i] = 1; for i=0~n-1
        for (int column=0; column < n; ++column) {
            D[0][column] = 1;
        }
        // D[i][0] = 1; for i=0~m-1
        for (int row = 0; row < m; ++row) {
            D[row][0] = 1;
        }

        for (int row=1; row < m; ++row) {
            for (int column = 1; column < n; ++column) {
                D[row][column] = D[row][column-1] + D[row-1][column];
            }
        }

        return D[m-1][n-1];
    }
};

/**
 * m is number of rows, n is number of columns
 *
 * Define D(m,n) to be the number of unique path to grid (m,n)
 *
 * D(m,n) = D(m, n-1) + D(n, m-1);
 *
 * D(m,1) = 1; for all m
 * D(1,n) = 1; for all n
 *
 *
 */


