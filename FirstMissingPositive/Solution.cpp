/**
*/

//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0) {
            return 1;
        }
        int missingElement = 1;//default is 1
        int i = 0;
        while ( i < n) {
            if (A[i] > 0 && A[i] != i+1 && A[i] <=n && A[A[i]-1] != A[i]) {
                swap(A[i], A[A[i]-1]);
            }
            else
            {//no need to swap
                ++i;
            }
        }
        
        //from begin to end
        for (i=0; i < n; ++i) {
            if (A[i] != i+1) {
                missingElement = i+1;
                break;
            }
        }
        if (i == n) {
            //fail to find missing element
            missingElement = i+1;
        }
        
        return missingElement;
    }
};

// According to the problem, any integer i should be placed at A[i-1]
// The missing element position would have another number at it
//
// Any integer would be placed at the right position within 2 swaps
// After that, iterate through the array and find the out of order element
//
//WARNING, the missing element might be replaced by any number , there might be more than 1 missing element


//int main()
//{
//    int array[] = {-1,4,2,1,9,10};
//    Solution test;
//    int result = test.firstMissingPositive(array, 6);
//    printf("result = %d\n", result);
//    return 0;
//}

