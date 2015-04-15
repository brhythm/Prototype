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
		//How to get the starting index
		//The start station we found, the accumulated sum starting from this position 
		//MUST BE ALWAYS POSITIVE until S[n], if sum at any following station becomes negative,
	    //it means starting from here would FAIL to finish the trip.
		//Then what ? If the final solution is index i
	    //Observe that sum of Delta[0]...Delta[i-1] must be negative
	    // and sum of Delta[i]...Delta[n] must be positive
	    // 
		// When we found a FAIL, we simply found a sequence which sums up to a negative number, the final answer will NOT fall into it
        // so we can safely try starting from next index (reset sum = 0), and see whether we could reach Delta[n] with sum being always positive
    		sum = 0;
			int startIndex = 0;
			for (int i = 0; i < numStation; ++i) {
				sum += diff[i];
				if (sum < 0) {
					//FAILED, remaining gas cannot cover the diff at this station
					//old startIndex is a bad starting point, but right answer will could be exluded from that old range
					startIndex = i + 1;//try next possible startIndex
					sum = 0;		   //reset sum
				}
			}
			return startIndex;
    	}
    }
};



