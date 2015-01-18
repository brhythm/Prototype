#include "Solution.h"

int Solution::singleNumber(int A[], int n) {
	int x=0;
	for ( int index = 0; index < n; ++index )
	{
		x = x^A[index];
	}
	return x;
	        
}

