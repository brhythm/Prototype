/*
 * Solution.cpp
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 *
 * For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
#include <algorithm>
#include <cmath>
#include <map>
#include <cmath>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 0)
        {
            return 0;
        }
        int leftWall[n];
        fill(leftWall, leftWall+n, 0);
        int rightWall[n];
        fill(rightWall, rightWall+n, 0);
        int max = A[0];
        //scan from left to right
        for (int i=0; i<n; ++i) {
            leftWall[i] = max;
            if (A[i] > max) {
                max = A[i];
            }
        }
        //scan from right to left
        max = A[n-1];
        for (int i=n-1; i>=0; --i) {
            rightWall[i] = max;
            if (A[i] > max) {
                max = A[i];
            }
        }
        int sum = 0;
        for (int i=0; i < n; ++i) {
            int water = min(leftWall[i], rightWall[i])-A[i];
            if (water > 0) {
                sum += water;
            }
        }
        return sum;
    }
};


int main()
{
//	int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};
//	int n=12;
//    int array[] = {5,4,1,2};
//    int n = 4;
    //corner case
	int array[] = {5,2,1,2,1,5};
	int n = 6;
//    int array[] = {5,5,1,7,1,1,5,2,7,6};
//    int n = 10;
//	int array[]={2,4,5,6,8,5,5,0,0,0,3,3};
//	int n = 12;
	Solution test;
	int sum = test.trap(array, n);
	printf("sum = %d\n", sum);
}


