/**
 */

//Given a sorted array of integers, find the starting and ending position of a given target value.
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
        int start = -1;
        int end = -1;
        if (n > 0) {
            start = n;//default to invalid index n
            end = -1;//default to invalid index -1;
            binarySearch(A, 0, n-1, target, start, end);
            if (start == n) {
                start = -1;//target not found
            }
        }
        vector<int> result = {start, end};
        return result;
    }
    
    void binarySearch(int A[], int searchStart , int searchEnd, int target, int& start, int& end)
    {
        if (searchStart > searchEnd) {
            return;
        }
        else if (searchStart == searchEnd )
        {
            if (A[searchStart] == target) {
                start = min(start, searchStart);
                end = max(end, searchEnd);
            }//else target not found, return, do nothing
        }
        else
        {//searchStart < searchEnd
            int searchMedian = (searchStart + searchEnd)/2;
            if (A[searchMedian] == target) {
                start = min(start, searchMedian);
                end = max(end, searchMedian);
                //continue search in the possible range
                binarySearch(A, searchStart, searchMedian-1, target, start, end);
                binarySearch(A, searchMedian+1, searchEnd, target, start, end);
            }
            else if (A[searchMedian] > target)
            {
                binarySearch(A, searchStart, searchMedian-1, target, start, end);
            }
            else
            {//A[searchMedian] < target
                binarySearch(A, searchMedian+1, searchEnd, target, start, end);
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












