/**
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
 */
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    //Implement with non-recursive alg 
    //Time roughly O(n!), because you have to try all comboniation for these n numbers
    vector<vector<int> > combinationSum(vector<int> &input, int target) {
        sort(input.begin(), input.end());
        vector<vector<int>> result;
        vector<int> path;
        vector<int> index;//index of digits that we select
        int currentSum =0;
        int i =0;// current index 
        while (i <= input.size())
        {
            if (currentSum == target)
            {
                result.push_back(path);
                // backtrack
                path.pop_back();
                int prevIndex = index.back();
                index.pop_back();
                currentSum -= input[prevIndex];
                i = prevIndex+1;
            }
            else if ( i == input.size() || currentSum + input[i] > target)
            {
                if (path.empty())
                {
                    break;//terminate condition
                }
                else
                {// backtrack
                    path.pop_back();
                    int prevIndex = index.back();
                    index.pop_back();
                    currentSum -= input[prevIndex];
                    i = prevIndex+1;
                }
            }
            else
            {// currentSum + input[i] <= target
                path.push_back(input[i]);
                index.push_back(i);
                currentSum += input[i];
                //next digit to try is stil input[i]
            }
        }
        return result;
    }
};

int main()
{
    Solution test;
    vector<int> input = {2,3,6,7};
    vector<vector<int>> result = test.combinationSum(input, 7);
    for (vector<int>& solution : result) {
        printf("[");
        for (int digit : solution) {
            printf("%d,", digit);
        }
        printf("]\n");
    }
    return 0;
}






