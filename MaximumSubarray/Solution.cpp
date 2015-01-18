/*
 * Find the contiguous subarray within an array
 * (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 *
 */
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        /* use DP, running time O(N), space complexity O(1)
         *
         * D[i] is max contiguous sum including A[i],
         * which means maxSum for a segment
         * (either a subarray ends at A[i] or subarray starts from A[i])
         *
         * through keeping track of maxSum in all those small segments, we can find
         * the maxSubarray
         *
         * D[i] = max(D[i-1] + A[i], A[i])
         * D[0] = A[0]
         */
        int D = A[0];
        int maxSum = D;
        for (int i=1; i < n; ++i)
        {
            D = max(D+A[i], A[i]);
            maxSum = max(maxSum, D);
        }
        return maxSum;
    }
};
