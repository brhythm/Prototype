/*
   You are given an n x n 2D matrix representing an image.
   Rotate the image by 90 degrees (clockwise).
   Follow up:
   Could you do this in-place?
 */

#include <vector>
using namespace std;

void RotateImage(vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return;
    }
    int n = matrix.size();
    assert(n == matrix[0].size());
    //flip by diagonal
    for ( int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n-row; ++col)
        {
            swap(matrix[row][col], matrix[n-1-col][n-1-row]);
        }
    }
    //flip by middle horizontal line
    for (int row=0; row < n/2; ++row)
    {
        for (int col=0; col < n; ++col)
        {
            swap(matrix[row][col], matrix[n-1-row][col]);
        }
    }
}



