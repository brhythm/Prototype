/*
 * Solution.cpp
 *
 * Implement next permutation, which rearranges numbers into the lexicographically
 * next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order
 * (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs
 * are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (!num.empty())
        {
            int partitionIndex = -1;
            int prevDigit = num.back();
            for (int i=num.size()-1; i >= 0; --i )
            {
                if (num[i] < prevDigit) {
                    partitionIndex = i;
                    break;
                }
                prevDigit = num[i];
            }
            if (partitionIndex == -1) {
                //this is last permutation already
                //reverse it , done
                reverse(num.begin(), num.end());
            }
            else
            {   //
                int substituteIndex = -1;
                for(int i=num.size()-1; i > partitionIndex; --i)
                {
                    if (num[i] > num[partitionIndex]) {
                        substituteIndex = i;
                        break;
                    }
                }
                int tmp = num[substituteIndex];
                num[substituteIndex] = num[partitionIndex];
                num[partitionIndex] = tmp;
                reverse(num.begin()+partitionIndex+1, num.end());
            }

        }
   }
};

//WARNING, remember this approach
// 687432
// 1) from right to left, find the first digit that violate the increasing order, partition number
// 2) among numbers on the right side of partition number,
//    from right to left, find the first digit that is larger than the partition number, substitute number
//    if there is no digit on the right side, pick up the first digit on the left side
// 3) swap partition number with substitute number
// 4) reverse all digits on the right side of partition number
