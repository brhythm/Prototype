/**
 */
//
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.
//
#include <cstdio>

class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        while ( start <= end ) {
            int median = (start + end) / 2;
            //printf("start = %d, end = %d\n", start, end);
            if (A[median] == target) {
                return median;
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
            else
            {//pivot > median
                if ( target < A[median] && target >= A[start]) {
                    end = median-1;
                }
                else
                {
                    start = median + 1;
                }
            }
        }
        return -1;
    }
};

//int main()
//{
//    int array[] = { 4,5,6,7,0,1,2};
//    Solution test;
//    int result = test.search(array, 7, -1);
//    printf("%d\n", result);
//    return 0;
//    
//}

//WARNING, the trick here is pivot is EITHER left side of median or right side of median
//BUT, when you write condition, the condition MUST also hold for an array WITHOUT pivot.
//because it is likely that the second/third round enter a range where there is no pivot

//if condition does not hold for normal sorted array is the reason why the following logic failed

//if (A[start] > A[median]) {
//    //pivot < median
//    if ( target < A[median] || target >= A[start]) {
//        end = median -1;
//    }
//    else
//    {
//        start = median +1;
//    }
//}
//else
//{//pivot > median
//    if ( target > A[median] || target <= A[end]) {
//        start = median + 1;
//    }
//    else
//    {
//        end = median-1;
//    }
//}



