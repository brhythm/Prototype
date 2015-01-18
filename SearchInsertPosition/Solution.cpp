/*
 * Given a sorted array and a target value,
 * return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 */
class Solution {
public://Running time O(lgN)
    int searchInsert(int A[], int n, int target) {
        if (n > 0){
            return searchInsertHelper(A, target, 0, n-1);
        }
        else
            return 0;
   }

    int searchInsertHelper(int A[], int target, int startIndex, int endIndex) {
        if (startIndex <= endIndex) {
            int medianIndex = (startIndex + endIndex) / 2;
            if (A[medianIndex] == target) {
                return medianIndex;
            } else if (A[medianIndex] < target) {
                return searchInsertHelper(A, target, medianIndex + 1, endIndex);

            } else { // medianIndex > target
                return searchInsertHelper(A, target, startIndex, medianIndex-1);
            }
        }
        else {// startIndex>endIndex
            return startIndex;
        }
    }

};

