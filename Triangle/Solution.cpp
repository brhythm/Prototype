/*
 * Solution.cpp
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 * For example, given the following triangle
 * [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
    ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * Bonus point if you are able to do this using only O(n) extra space,
 * where n is the total number of rows in the triangle.
 */
#include <vector>
#include <climits>
#include <stdio.h>
#include <iostream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        int globalMinSum = INT_MAX;
        //scan from bottom to top is much much much easier!!
        vector<int> prevMinSum(n+1, 0);//init vector with n zeros,
        for (int row = n-1; row >=0; --row)
        {
            globalMinSum = INT_MAX;//reset globalMin to get min of current row
            for (int column = 0; column <= row; ++column)
            {
                int localMin = min(prevMinSum[column], prevMinSum[column+1]) + triangle[row][column];
                //prevMinSum[column] is useless now, overwrite safe
                prevMinSum[column] = localMin;
                globalMinSum = localMin < globalMinSum ? localMin: globalMinSum;
            }
        }
        return globalMinSum;
    }
};


//int main()
//{
//    vector<vector<int>> triangle;
//    vector<int> row = {2};
//    triangle.push_back(row);
//    row = {3,5};
//    triangle.push_back(row);
//    row = {6,7,1};
//    triangle.push_back(row);
//    row = {4,2,3,1};
//    triangle.push_back(row);
//    for (int i=0; i < triangle.size(); ++i)
//    {
//        for (int j=0; j < triangle[i].size(); ++j)
//            printf("%d,", triangle[i][j]);
//        printf("\n");
//    }
//    Solution test;
//    int result = test.minimumTotal(triangle);
//    printf("result is %d\n", result);
//    return 0;
//}

