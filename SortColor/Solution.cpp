/*
 * Given an array with n objects colored red, white or blue,
 * sort them so that objects of the same color are adjacent,
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 *
 * Follow up:
 * Could you come up with an one-pass algorithm using only constant space?
 */

/*
 * Since there are only three colors, the expected sorting result is 000 11 2222
 * it is very similar to three way partition. But you need to find the position of pivot,
 * i.e. the position of 1 , which might waste one pass.
 *
 * Can we do better ??
 *
 * 1) modify three way partition, make two index move in such direction  -> <-
 *
 */
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(int A[], int n) {

        //[a,b,c,d,e,f,g]
        // i           j
        // A[index] == 0 if index < i
        //          == 1 if index >=i && <=j
        //          == 2 if index > j
        //why do we choose to init i, j in this way ?
        //i, j would not be out of bound if there is no 1, or no 0, or no 2
        int i=0;
        int j=n-1;

        //WARNING,init value of  A[i], A[j] is not guaranteed
        for (int index=0; index <=j; ) {
            if (A[index] == 0) {
                swap(A[index], A[i]);
                ++i;
                ++index;//if A[i]==0 index = i = 0, keep increasing both index, ok
            }
            else if ( A[index] == 1) {
                ++index;//do nothing
            }
            else {//A[index] == 2
                swap(A[index], A[j]);
                --j;
            }
        }
    }
};


