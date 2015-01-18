/*
 * Solution.cpp
 *
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
#include <vector>
using namespace std;

class Solution {
public:
	//Learn, this approach is really straightforward and easy to understand
    int candy(vector<int> &ratings) {

    	int numChildren = ratings.size();
    	vector<int> candy(numChildren, 1);
    	for (int i=1; i < numChildren; ++i)
    	{
    		if (ratings[i] > ratings[i-1]){
    			candy[i]=candy[i-1]+1;
    		}//else, by default, candy i = 1;
    	}

    	for (int i=numChildren-2; i>=0; --i)
    	{
    		if (ratings[i] > ratings[i+1] &&
    		    candy[i] <= candy[i+1])
    		{
    			candy[i] = candy[i+1] + 1;
    		}
    	}

    	int sum = 0;
    	for (int i=0; i < numChildren; ++i){
    		sum += candy[i];
    	}
    	return sum;
    }
};


