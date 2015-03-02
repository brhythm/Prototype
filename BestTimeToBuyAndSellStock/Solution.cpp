/**
 *Say you have an array for which the ith element is the price of a given stock on day i.
 *If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
#include <vector>
#include <climits>
using namespace std;

class Solution {
public://Time O(N), Space O(1)
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0;
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i=0; i < prices.size(); ++i)
        {
            if (prices[i] < low)
            {
                low = prices[i];
                high = prices[i];
                maxProfit = max(maxProfit, high-low);
            }
            if (prices[i] > high)
            {
                high = prices[i];
                maxProfit = max(maxProfit, high-low);
            }
        }
        return maxProfit;
    }
};


