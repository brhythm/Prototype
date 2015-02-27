/**
 */
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.

#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

class Solution {
public:
    //Why this could be solved by greedy instead of DP ?
    //because there is no overlapping subproblems
    //how far we could go from i has nothing to do with [0:i-1] 
    //Warning, time complexity must be O(N)
    bool canJump(int A[], int n) {
        if (n <= 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        int rightMost = 0;
        for (int i=0; i < n-1 && rightMost >= i; ++i) {
            //if rightMost < i, we can't even reach index i, cannot reach the end
            rightMost = fmax(i+A[i], rightMost);
            if ( rightMost >= n-1) {
                return true;
            }
        }
        return false;
    }
};

//int main()
//{
//    //int array[] = {2,3,1,1,4};
//    //int array[]={3,2,1,0,4};
//    //int array[]={0};
//    int array[]={0,2,3};
//    Solution test;
//    bool result = test.canJump(array, 3);
//    printf("%d\n", result);
//    return 0;
//}
