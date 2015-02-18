/**
 Given a collection of integers that might contain duplicates, S, return all possible subsets.
 
 Note:
 
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 
 For example,
 If S = [1,2,2], a solution is:
 
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 */


#include <vector>
using namespace std;

class Solution {
public:
    //Time O(2^N)
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> result;
        if (!S.empty()) {
            sort(S.begin(), S.end());
            vector<int> candidate;
            generateSubsets(0, S.size() - 1, S, result, candidate);
        }
        return result;
    }
    
    void generateSubsets(const int start, const int end,
                         const vector<int>& array, vector<vector<int>>& result,
                         vector<int>& candidate) {
        if (start > end) {
            //terminate condition
            result.push_back(candidate); //record solution
            return;
        } else { //assert start <= end
            result.push_back(candidate); //empty set without any more digits from array
            vector<int> restoreCandidate = candidate;
            for (int i = start; i <= end; ++i) {
                if( i>=start+1 && array[i] == array[i-1])//warning, bug here
                {//i >= start+1, not i >=1, because we don't skip first digit at each level
                    continue;
                }
                candidate.push_back(array[i]);
                generateSubsets(i + 1, end, array, result, candidate);
                //backtrack
                candidate = restoreCandidate;
            }
        }
    }
    
};

//int main()
//{
//    int A[] = {5, 7, 7, 8, 8, 10};
//    Solution test;
//    vector<int> result = test.searchRange(A, 6, 8);
//    printf("start = %d, end = %d\n", result[0], result[1]);
//    return 0;
//}












