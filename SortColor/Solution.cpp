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
    //Note: three way partition, you know the pivot already
    void sortColors(int A[], int n) {

        int i=-1;
        int j=-1;
        int pivot = 1;

        for (int index=0; index <n; ++index) {
            if (A[index] < pivot) {
                if (i == j) {
                    //WARNING: bug here
                    //there is no == zone
                    swap(A[index], A[++i]);
                    ++j;
                }
                else
                {   //there is == zone
                    swap(A[index], A[++i]);
                    swap(A[index], A[++j]);
                }
            }
            else if (A[index] == pivot)
            {
                swap(A[index], A[++j]);
            }
            //else A[index] > pivot, do nothing
        }
    }
};

int main()
{
    return 0;
}


