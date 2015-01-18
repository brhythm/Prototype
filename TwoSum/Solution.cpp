/*
 * Solution.cpp
 * Given an array of integers, find two numbers such that they add up to
 * a specific target number.
 *
 * The function twoSum should return indices of the two numbers
 * such that they add up to the target, where index1 must be less than index2.
 *
 * Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 *
 */
#include <vector>
#include <map>
using namespace std;
//Warning, read the problem carefully, index starts from 1

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> solution;
    	map<int,int> indexMap;
    	for (int i=0; i < numbers.size();++i) {
    		indexMap[numbers[i]] = i+1;
    	}
    	//start from smaller index
    	for (int i=0; i < numbers.size(); ++i) {
    		int partner = target-numbers[i];
    		map<int,int>::iterator iter= indexMap.find(partner);
    		if ( iter != indexMap.end() &&
    			 i+1 != iter->second)
    		{//warning cannot return two same index
    			solution.push_back(i+1);
    			solution.push_back(iter->second);
    			break;
    		}
    	}
    	return solution;
    }
};


