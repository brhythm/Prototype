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
#include <unordered_map>
using namespace std;
class Solution {
public:
    int trap(int A[], int n) {
        if (n > 0) 
        {
            unordered_map<int, pair<int,int>> valleys;//bottomIndex, <leftWallIndex, rightWallIndex>
        }
        //scan from left to right, find all decreasing trend
        int leftWallIndex = -1; 
        for (int i =0; i < n-1; ++i)
        {
            if(A[i] >= A[i+1])
            {
                if (leftWallIndex == -1)
                {
                    leftWallIndex = i;
                }
            }
            else
            {//we are at bottom of valley or its not valley at all 
                if (A[leftWallIndex] > 0 )
                {
                    valleys[i] = make_pair<int,int>(leftWallIndex, -1);
                    leftWallIndex = -1;
                }
            }
        }
        //scan from right to left, find all decreasing trend
        int rightWallIndex = -1;
        for (int i = n-1; i>=1; --i) 
        {
            if (A[i] >= A[i-1])
            {
                if (rightWallIndex == -1)
                {
                    rightWallIndex = i;
                }
            }
            else
            {
                if (A[rightWallIndex] > 0 && valleys.find(i) != valleys.end())
                {
                    valleys[i]->second.second = rightWallIndex;
                    rightWallIndex = -1;
                }
            }
        }
        int sum = 0;
        for (auto iter=valleys.begin(); iter != valleys.end(); ++iter)
        {
            pair<int, int> bounds = iter->second;
            if (bounds.first >=0 && bounds.second >=0)
            {//both wall detected
                int left = bounds.first;
                int right = bounds.second; 
                int amount = ( right-left+1 )*max(A[left], A[right]);
                for (int i=left; i <= right; ++i)
                {
                    amount-= A[i];
                }
                sum += amount;
            }
        }
    }
};


int main()
{
	int array[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int n=12;
//	int array[] = {5,2,1,2,1,5};
//	int n = 6;

//	int array[]={2,4,5,6,8,5,5,0,0,0,3,3};
//	int n = 12;
	Solution test;
	int sum = test.trap(array, n);
	printf("sum = %d\n", sum);
}


