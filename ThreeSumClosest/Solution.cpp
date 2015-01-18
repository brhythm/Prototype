/*
 * Solution.cpp
 *
 * Given an array S of n integers, find three integers in S such that
 * the sum is closest to a given number, target. Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 */
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//Time O(N^2)
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {

    	int closestSum = num[0] + num[1] + num[2];
    	sort(num.begin(), num.end());

    	for (int i=0; i < num.size()-1; ++i)
    	{
    		int j = i+1;
    		int k = num.size()-1;
    		while(j < k) {
    			int localSum = num[i] + num[j] + num[k];
    			//found best solution,break
    			if (localSum == target) {
    				closestSum = localSum;
    				break;
    			}
    			//update closest sum if necessary
    			if ( abs(double(localSum-target)) < abs(double(closestSum-target))) {
    				closestSum = localSum;
    			}
    			//update index to continue searching
    			if ( localSum < target) {
    				++j;
    			}
    			else {//localSum > target
    				--k;
    			}
    		}
    		if (closestSum == target) {
    			break;
    		}//else continue searching for closestSum
    	}

    	return closestSum;
    }
};




