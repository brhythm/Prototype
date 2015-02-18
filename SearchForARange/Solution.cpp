/**
 */

//Given a sorted array of integers, find the lowering and uppering position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = -1;
        int upper = -1;
        if (n > 0) {
            lower = n;//default to invalid index n
            upper = -1;//default to invalid index -1;
            binarySearch(A, 0, n-1, target, lower, upper);
            if (lower == n) {
                lower = -1;//target not found
            }
        }
        vector<int> result = {lower, upper};
        return result;
    }
    
    void binarySearch(int A[], int start , int end, int target, int& lower, int& upper)
    {
        if (start > end) {
            return;
        }
        else
        {//start < end
            int median = (start + end)/2;
            if (A[median] == target) {
                lower = min(lower, median);
                upper = max(upper, median);
                //continue search in the possible range
                binarySearch(A, start, median-1, target, lower, upper);
                binarySearch(A, median+1, end, target, lower, upper);
            }
            else if (A[median] > target)
            {
                binarySearch(A, start, median-1, target, lower, upper);
            }
            else
            {//A[median] < target
                binarySearch(A, median+1, end, target, lower, upper);
            }
        }
    }
};

//int main()
//{
//    int A[] = {5, 7, 7, 8, 8, 10};
//    Solution test;
//    vector<int> result = test.searchRange(A, 6, 8);
//    printf("start = %d, end = %d\n", result[0], result[1]);
//    return 0;
//}












