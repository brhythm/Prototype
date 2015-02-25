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
public://Time roughly O(n!), because you have to try all comboniation for these n numbers
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        generateCombo(0, candidates, target, path, result);
        return result;
    }
    
    //generate combo from index
    void generateCombo(const int start, const vector<int>& candidates, int target,
                       vector<int>& path, vector<vector<int>>& result)
    {
        if ( target == 0)
        {//terminate condition
            //record solution
            result.push_back(path);
            return;
        }
        else if ( target < 0)
        {//terminate condition
            //fail to find solution
            return;
        }
        else
        {//target > 0
            for (size_t i=start; i < candidates.size() && candidates[i] <= target; ++i)
            {
                path.push_back(candidates[i]);
                //here, startIndex is still i, because this problem allows duplicate elements
                generateCombo(i, candidates, target-candidates[i], path, result);
                //any solution would be recorded automatically
                //backtrack
                path.pop_back();
            }
            //we have tried all possible digits in candidates, return
        }
    }
    
};

int main()
{
    return 0;
}