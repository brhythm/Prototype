/*
 * Given an array and a value, remove all instances of that value in place
 * and return the new length.
 *
 * The order of elements can be changed.
 * It doesn't matter what you leave beyond the new length.
 *
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int newIndex = 0;
        for (int index=0; index < n; ++index) {
            if (A[index] != elem )
                A[newIndex++] = A[index];
        }
        return newIndex;
    }
};


