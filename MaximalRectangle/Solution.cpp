/*
 * Solution.cpp
 *
 * Given a 2D binary matrix filled with 0's and 1's,
 * find the largest rectangle containing all ones and return its area.
 */
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
class Solution {
public:
    //Time O(N^2)
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rowMax = matrix.size();
        if (rowMax == 0)
        {//stop calculating
            return 0;
        }
        int columnMax = matrix[0].size();

        int maxArea = 0;
        vector<int> oneColumn(rowMax, 0);
        vector<vector<int>> h(columnMax, oneColumn);//h[i] is column[i]
        //WARNING, in order to calculate histogram, our h array is different from matrix
        // h[i] is column[i], however, matrix[i] is row[i]
        //printf("row = %d, column = %d\n", rowMax, columnMax);
        for (int j=0; j < rowMax; ++j)
        {
            h[columnMax-1][j] = matrix[j][columnMax-1] == '1' ? 1 : 0;
            for (int i = columnMax-2; i>=0; --i)
            {
                h[i][j] = matrix[j][i]=='1' ? h[i+1][j]+1:0;
                //printf("h[%d][%d]= %d\n", i , j, h[i][j]);
            }
        }

        for (int i=0; i < columnMax; ++i)
        {
            //h[i] is bar height starting from column[i]
            maxArea = max(maxArea, maxRectangle(h[i]));
        }
        return maxArea;
   }

    //calculate maxRectangle in histogram
    //Time O(N), N= height.size()
    int maxRectangle(vector<int>& height)
    {
        height.push_back(0);//add dummy 0
        stack<int> barsToExtend;//store index of bar
        int maxArea = 0;
        int n = height.size();
        for (int i=0; i < n; ++i)
        {
            int stackTopHeight = barsToExtend.empty() ? -1 : height[barsToExtend.top()];
            if (height[i] < stackTopHeight)
            {
                while(!barsToExtend.empty() &&
                       height[barsToExtend.top()] > height[i])
                {
                    int candidateHeight = height[barsToExtend.top()];
                    barsToExtend.pop();
                    int candidateWidth = barsToExtend.empty() ? i : i-1-barsToExtend.top();
                    maxArea = max(maxArea, candidateHeight*candidateWidth);
                }//now the remaining stackTopHeight <= height[i], it is not cut, leave in the stack
            }//else height[i] >= stackTopHeight, just push into stack
            barsToExtend.push(i);
        }
        return maxArea;
    }
};
//define h[i,j] to be the height of bar starting from [i,j]
//h[i,j] = matrix[i][j], i = columnMax-1
//         matrix[i][j] ? matrix[i+1][j] + 1: 0
//It took O(MN) to fill this height array

//int main()
//{
//    vector<vector<char>> matrix;
//    vector<char> oneRow = {'0', '0'};
//    matrix.push_back(oneRow);
//    Solution test;
//    int result = test.maximalRectangle(matrix);
//    printf("result is %d\n", result);
//    return 0;
//}
