/*
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * x=100, return 1
 */

class Solution {
public:
    int reverse(int x) {
    	//assume 32 bit machine
    	//int has 32 bit
    	int sign = 1;
    	if (x < 0)
    	{
    		sign = -1;
    		x = -x;
    	}
    	int reversedChar[32];
    	int index = 0;
    	while ( x != 0)
    	{
    		reversedChar[index++] = x % 10;
    		x = x / 10;
    	}
    	
    	int i=0;

    	int sum = 0;
    	//,0,0, ,3,2,1
    	while ( i < index )
    	{
    		sum = sum*10 + reversedChar[i++];
    	}
    	
    	return sum*sign;
    }
};
