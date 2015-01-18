/*
 * Given a sorted array, remove the duplicates in place such that
 * each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 *
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n >= 1) {
            int count = 1;
            for (int i = 0; i < n - 1; ++i) {
                if (A[i + 1] != A[count - 1]) {
                    A[count] = A[i + 1];
                    count++;
                }
            }
            return count;
        } else {
            return 0;
        }
    }
};

