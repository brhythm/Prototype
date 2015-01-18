/**
 */

//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix:
//
//[
// [1,   3,  5,  7],
// [10, 11, 16, 20],
// [23, 30, 34, 50]
// ]
//Given target = 3, return true.

#include <vector>

using namespace std;

class Solution {
public:
    //You can observe that the whole matrix is sorted
    //The trick here is to do binary search on the whole 2d matrix
    //Time O(lg(m*n)) = O(lgm) + O(lgn)
    //Space O(1)
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int numberOfRows = matrix.size();
        if (numberOfRows > 0) {
            int numberOfCols = matrix[0].size();
            int start = 0;
            int end = numberOfRows*numberOfCols-1;
            while (start <= end) {
                int median = (start+end)/2;
                int value = matrix[median/numberOfCols][median%numberOfCols];//Learn the convertion here
                if (value == target) {
                    return true;
                }
                else if (value < target)
                {
                    start = median+1;
                }
                else
                {//value > target
                    end = median-1;
                }
            }
            //not found
        }
        return false;
    }
};
//Note , this implementation is much smarter than binary search the row first, then binary search the column
//Plus use less space complexity O(1)



