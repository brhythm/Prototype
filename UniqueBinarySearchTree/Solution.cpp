/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 */
#include <stdio.h>

class Solution {
public:
	int numTrees(int n) {
    	int* numTreesArrayPtr = new int[n+1];
    	numTreesArrayPtr[0] = 1;
    	numTreesArrayPtr[1] = 1;
    	//1*2+1*1+2*1 = 5;
    	for (int i=2; i <=n; ++i)
    	{
    		numTreesArrayPtr[i] = 0;
    		for (int j=0; j <= i-1; ++j)
    		{
    			numTreesArrayPtr[i] += numTreesArrayPtr[j] * numTreesArrayPtr[i-1-j];
    		}
    	}
    	int result = numTreesArrayPtr[n];
    	delete[] numTreesArrayPtr;
    	
    	return result;	
    	
    }

    	
};


