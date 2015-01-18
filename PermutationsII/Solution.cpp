/*
 * Solution.cpp
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * For example,
 *
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<int> candidate;
    	vector<vector<int> > solution;

  //  	sort(num.begin(), num.end());
    	printOneDigit(0, num, candidate, solution);

    	return solution;
    }

    void printOneDigit(int index, vector<int>& num,
    		           vector<int>& candidate, vector<vector<int> >& solution )
    {
    	if ( candidate.size() == num.size()) {
    		//we have printed n digits
    		solution.push_back(candidate);

    		return;
    	}
    	else
    	{
    		vector<int> restoredCandidate = candidate;
    		set<int> digitSet;//use set to remove duplicate, use space O(N)
    		for (int i=index; i < num.size(); ++i) {
    			if (digitSet.find(num[i]) == digitSet.end()) {
    				//if digit has not appeared
    				swap(num[i], num[index]);
    				candidate.push_back(num[index]);//Warning!! You keep making mistake here, at least twice
    				printOneDigit(index+1, num, candidate, solution);

    				//backtrack
    				candidate = restoredCandidate;
    				swap(num[i], num[index]);
    				digitSet.insert(num[i]);
    			}
    		}
    	}

    }
};
/**
 * Warning, sort num cannot guarantee that duplicate numbers would always be continuous, because the algorithm you choose would do SWAP,
 * thus duplicate numbers might NOT be next to each other
 */



