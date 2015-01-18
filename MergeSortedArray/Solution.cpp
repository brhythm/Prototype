/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n)
 * to hold additional elements from B.
 *
 * The number of elements initialized in A and B are m and n respectively.
 *
 */
// right shift all elements in A >> n
// do the merge
// but mergesort could start from the biggest element too !
// solution: merge from the biggest, print from the right end of the array
//
// Time: O(n+m), Space: O(m+n), no extra space
// Warning!!there is no sentinel , mergesort might fail!!
#include <climits>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int leftIndex = m-1;
        int rightIndex = n-1;
        int currentIndex = m+n-1;


        while( rightIndex >=0 ) {
            //there are still some elements to be merged
            int maxInA = INT_MIN;//A[-1] = INT_MIN;
            if (leftIndex >= 0) {
                maxInA = A[leftIndex];
            }

            if (maxInA >= B[rightIndex]) {
                // A is bigger, put A
                A[currentIndex] = maxInA;
                leftIndex--;
            }
            else {
                //B is bigger, put B
                A[currentIndex] = B[rightIndex];
                rightIndex--;
            }
            currentIndex--;
        }
    }
};


