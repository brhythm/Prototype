/*
 * Solution.cpp
 *
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
 * You begin the journey with an empty tank at one of the gas stations.
 *
 *  Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 *  Note:The solution is guaranteed to be unique.
 */
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
	//Time: O(N)
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    	int numStation = gas.size();
    	int numCost = cost.size();
    	assert(numStation == numCost);

    	vector<int> diff;
    	int sum=0;
    	diff.reserve(numStation);
    	for (int i=0; i < numStation; ++i)
    	{
    		diff.push_back(gas[i]-cost[i]);
    		sum+= diff[i];
    	}

    	if ( sum < 0)
    	{
    		return -1;
    	}
    	else
    	{
    		sum = 0;
			int startIndex = 0;
			for (int i = 0; i < numStation; ++i) {
				sum += diff[i];
				if (sum < 0) {
					startIndex = i + 1;
					sum = 0;
				}
			}
			return startIndex;
    	}
    }
};



