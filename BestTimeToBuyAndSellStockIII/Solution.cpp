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
	int maxProfit(vector<int> &prices) {
		//Running time O(N), space O(N)
	    if (prices.size() == 0)
	    {
	        return 0;
	    }
	    int n=prices.size();
	    vector<int> left(n, 0);//max profit in [0, i-1] with at most one transaction
	    vector<int> right(n, 0);//max profit in [i, n-1], with at most one transaction
	    //To calc left or right, we already know that it took O(N) to calc local max in length-N array
	    //So without any optimization, we could filled up left in O(N^2)
	    //However, we could use DP to memorize the subproblems we have solved easily, and
	    //filling up left array could be optimized to O(N)
	    int localMin = prices[0];
	    for (int i=1; i < n; ++i)
	    {
	        localMin = min(localMin, prices[i]);
	        left[i] = max(left[i-1], prices[i]-localMin);
	    }
	    localMin = prices[n-1];
	    int localMax = prices[n-1];
	    //right[n-1] = 0
	    for (int i=n-2; i >=0; --i)
	    {
	        localMax = max(localMax, prices[i]);
	        right[i] = max(right[i+1], localMax-prices[i]);
	    }
	    int maxProfit =0;
	    for (int i=0; i < n; ++i)
	    {
	        maxProfit = max(maxProfit, left[i]+right[i]);
	    }
	    return maxProfit;
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
