/**
 */

//Given a set of distinct integers, S, return all possible subsets.
//
//Note:
//Elements in a subset must be in non-descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If S = [1,2,3], a solution is:
//
//[
// [3],
// [1],
// [2],
// [1,2,3],
// [1,3],
// [2,3],
// [1,2],
// []
// ]
#include <vector>

using namespace std;

class Solution {
public:
//Make sure you know how to calc time complexity O(2^N)
//T(n) = T(n-1)+T(n-2)+T(n-3)+...+T(1)
//
//Or think about this problem as a combination sum
//this problem is asking for: Cn0+Cn1+Cn2+...Cnn = 2^n;
//Learn how to prove it
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> result;
        if (!S.empty()) {
            sort(S.begin(), S.end());
            vector<int> candidate;
            generateSubsets(0, S.size()-1, S, result, candidate);
        }
        return result;
    }
    
    void generateSubsets(const int start, const int end, const vector<int>& array, vector<vector<int>>& result, vector<int>& candidate)
    {
        if (start > end) {
            //terminate condition
            result.push_back(candidate);//record solution
            return;
        }
        else
        {//assert start <= end
            result.push_back(candidate);//empty set without any more digits from array
            vector<int> restoreCandidate = candidate;
            for(int i=start; i <=end; ++i){
                candidate.push_back(array[i]);
                generateSubsets(i+1, end, array, result, candidate);
                //backtrack
                candidate = restoreCandidate;
            }
        }
    }
};

//int main()
//{
//    vector<int> array = {3,2,1};
//    Solution test;
//    vector<vector<int>> result = test.subsets(array);
//    for (vector<int>& candidate: result) {
//        for (int i=0; i < candidate.size(); ++i) {
//            printf("%d,", candidate[i]);
//        }
//        printf("\n");
//    }
//    return 0;
//}




