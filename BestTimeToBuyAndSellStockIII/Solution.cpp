/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time 
 * 
 * (ie, you must sell the stock before you buy again).
 * 
 * 
 *
 */

#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

class Solution {
public:
	static int maxProfit(vector<int> &prices) {
		//Running time O(N), space O(N)
		if (prices.size() > 0) {
			//leftVector[i] = maxProfit between 0 ~ i;
			vector<int> leftVector(prices.size(), 0);
			//rightVector[i] = maxProfit between i~n-1
			vector<int> rightVector(prices.size(), 0);
			
			int localMin = prices[0];
			//leftVector[0]=0;
			for (int i=1; i< prices.size(); ++i)
			{
				localMin = min(prices[i], localMin);
				leftVector[i] = max(leftVector[i-1], prices[i]-localMin); 
			}
			
			int localMax = prices[prices.size()-1];
			//rightVector[n-1]=0
			for (int i=prices.size()-2; i>=0; --i)
			{
				localMax = max(prices[i], localMax);
				rightVector[i] = max(rightVector[i+1], localMax-prices[i]);
			}
			
			int maxProfit = 0;
			for(int i=0; i < prices.size(); ++i)
			{
				maxProfit = max(maxProfit, leftVector[i]+rightVector[i]);
			}
			
			return maxProfit;
		}
		else
		{
			return 0;
		}
	}
};
/*
int main()
{
	//int test[] = {2,1,4,5,2,9,7};
	int test[] ={1,2,4,2,5,7,2,4,9,0};
	int num = sizeof(test)/sizeof(int);
	vector<int> testVector(test, test+ num);
	
	cout << Solution::maxProfit(testVector) << endl;
	
}
*/

/*
	for (int i=1; i < prices.size(); ++i) {
		// for each D[i]
		
		maxProfitVector[i] = maxProfitVector[i-1];
		//currentMax = D[i-1] 
		numTransactions[i] = numTransactions[i-1];
		//default numTransaciton is numTransaction[i-1], if no transaction occurred
		
		//if ( prices[i] > prices[i-1])
		//{
		int localMin = prices[i-1];// localMin price among [x, i-1]
		
		int lastPossibleDay = i-1;
		while (numTransactions[lastPossibleDay] ==2)
			lastPossibleDay--;
		
		//lastPossibleDay might have 1 or 0 transactions
		for (int x=lastPossibleDay; x >=0; --x )
		{// Note that we try all possible D[x] in descending order
			if (prices[x] < localMin)
			{
				localMin = prices[x];
			}

			int diff = prices[i] - localMin;
			if ( (maxProfitVector[x] + diff) >=  maxProfitVector[i] ) 
			//WARNING MUST USE >=, we want to minimize the numTransactions
			{
				maxProfitVector[i] = maxProfitVector[x] + diff;
				numTransactions[i] = numTransactions[x] + 1;
			}
				
		}
		
		//}
	}		

	
	for (int i=0; i< prices.size(); ++i)
	{
		cout << maxProfitVector[i] << "," << numTransactions[i] << endl;
	}
	return maxProfitVector[prices.size()-1];
	
} else {
	return 0;
}
*/
