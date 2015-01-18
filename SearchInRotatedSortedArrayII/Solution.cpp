/**
 */

//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//
//Write a function to determine if a given target is in the array.
#include <stdio.h>

class Solution {
public:
    bool search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while ( start <= end ) {
            int median = (start + end) / 2;
            //printf("start = %d, end = %d\n", start, end);
            if (A[median] == target) {
                return true;
            }
            if (A[start] > A[median]) {
                //pivot < median
                if ( target > A[median] && target <= A[end]) {
                    start = median +1;
                }
                else
                {
                    end = median -1;
                }
            }
            else if (A[start] < A[median])
            {//pivot > median
                if ( target < A[median] && target >= A[start]) {
                    end = median-1;
                }
                else
                {
                    start = median + 1;
                }
            }
            else
            {//start == median, here we don't know where is pivot, it is slow
                int change = start+1;
                for (; change <= end; ++change) {
                    if (A[change] != A[median]) {
                        break;
                    }
                }
                start = change;
                end = change > median ? end : median-1;
                
            }
        }
        return false;
       
    }
};

//int main()
//{
//    int array[] = {1,3,1,1,1};//in this case, start == median == end, not easy to know whether pivot is on the left side or right side
//    Solution test;
//    bool result = test.search(array, 5, 3);
//    printf("result is %d\n", result);
//    return 0;
//}





