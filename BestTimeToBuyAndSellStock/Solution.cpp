/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * If you were only permitted to complete at most one transaction
 *  (ie, buy one and sell one share of the stock), 
 * design an algorithm to find the maximum profit.
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	//Running time O(N), space O(1)
    	if ( prices.size() > 0 )
    	{
    		int minIndex = 0;
    		int maxIndex = 0;
    	
    		int maxProfit = prices[maxIndex] - prices[minIndex];
    		for ( int index = 1; index < prices.size(); ++index )
    		{
    			if (prices[index] < prices[minIndex] )
    			{// update minIndex, must refresh maxIndex too
    			minIndex = index;
					maxIndex = index;
				}
				else if ( prices[index]> prices[maxIndex] )
				{
					maxIndex = index;
				}

				int localMaxProfit = prices[maxIndex] - prices[minIndex];
				if ( localMaxProfit> maxProfit )
				{
					maxProfit = localMaxProfit;
				}
			}
			return maxProfit;    
    	}
    	else
    	{
    		return 0;
    	}
    }
};

