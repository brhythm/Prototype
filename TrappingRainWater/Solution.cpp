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
using namespace std;
class Solution {
public:
	//this approach seems to be too complicated, try the second reference
	//Time ?? think about it carefully, it is O(N)
    int trap(int A[], int n) {
    	int index= 0;
    	int sum = 0;
    	while (index < n) {
    		int nextShallowPoint = -1;
    		int leftWallIndex = -1;
    		if( findNextShallowPoint(index, A, n, nextShallowPoint, leftWallIndex)) {
    			//find rightWallIndex
    			int rightWallIndex = -1;
    			if (findRightWallIndex(nextShallowPoint, A, n, leftWallIndex, rightWallIndex)) {
    				int height = min(A[leftWallIndex], A[rightWallIndex]);
    				for (int j= leftWallIndex+1; j < rightWallIndex; ++j) {
    					if (height - A[j] > 0) {
    						sum += height - A[j];
    					}
    				}
    				//printf("tmp sum = %d\n", sum);
    				index = rightWallIndex;
    			}
    			else //rightwall not found, end of trap
    			{
    				break;
    			}
    		}
    		else
    		{
    			break;
    		}
    	}
    	return sum;
    }

    bool findNextShallowPoint(const int startIndex, const int A[], const int n,
    		                  int& nextShallowPoint, int& leftWallIndex)
    {
    	bool isFound = false;
    	if ( startIndex + 1 < n) {
    		leftWallIndex = startIndex;//init to startIndex
        	//nextShallowPoint = startIndex;//init to startIndex
        	for (int i = startIndex+1; i < n; ++i)
        	{
        		if (A[i] < A[leftWallIndex]) {
            		isFound = true;
        			nextShallowPoint = i++;
        			//warning, bug here , <=
            		while (A[i] <= A[nextShallowPoint] &&
            				i < n) {
            			nextShallowPoint = i++;
            		}
    				//printf("found shallow = %d, leftWall = %d\n", A[nextShallowPoint], A[leftWallIndex]);
            		break;
        		}
        		else
        		{// A[i] >= A[leftWallIndex]
        			leftWallIndex = i;
        		}
        	}
    	}
    	return isFound;
    }
    //WARNING, the tricky thing here is that you must consider leftWallHeight to determine
    // where is the highest right wall
    //find right wall after startIndex
    bool findRightWallIndex(const int startIndex, const int A[], const int n, const int leftWallIndex,
    		                int& rightWallIndex)
    {
		bool isFound = false;
		if (startIndex + 1 < n) {
			rightWallIndex = startIndex;
			for (int i = startIndex+1; i < n; ++i)
				if (A[i] > A[rightWallIndex]) {
					rightWallIndex = i;
					//warning,bug here ,must have the condition
				if (A[rightWallIndex] > A[leftWallIndex])
					break;
			}
			if (rightWallIndex != startIndex)
			{
				isFound = true;
				//printf("found right wall : %d\n", A[rightWallIndex]);
			}
		}
    	return isFound;
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


