/*
 * Solution.cpp
 *
 * Given an array S of n integers, are there elements a, b, c,
 * and d in S such that a + b + c + d = target? Find all unique quadruplets in the array
 * which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 * A solution set is:
 *  (-1,  0, 0, 1)
 *  (-2, -1, 1, 2)
 *  (-2,  0, 0, 2)
 */
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
//WARNING, Do it again
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {

        vector<vector<int> > solution;
        multimap<int, pair<int, int> > cache;
        int totalNum = num.size();
        for (int i=0; i < totalNum; ++i)
        {
            for (int j=i+1; j < totalNum; ++j) {
                //during construction, i always smaller than j
                cache.insert(make_pair(num[i]+num[j], make_pair(i,j)));
            }
        }
        for (multimap<int, pair<int, int> >::iterator sumIter = cache.begin(); sumIter != cache.end(); ++sumIter)
        {
            int firstSum = sumIter->first;
            pair<multimap<int, pair<int, int> >::iterator, multimap<int, pair<int, int> >::iterator > range
                        = cache.equal_range(target-firstSum);
            for(multimap<int, pair<int, int> >::iterator pairIter = range.first; pairIter != range.second; ++pairIter) {
                int a = sumIter->second.first;
                int b = sumIter->second.second;
                int c = pairIter->second.first;
                int d = pairIter->second.second;

                if ( a != c && a!= d && b!= c && b!=d)
                {
                    int array[] = { num[a], num[b], num[c], num[d]};
                    vector<int> oneSolution(array, array+ sizeof(array)/sizeof(array[0]));
                    sort(oneSolution.begin(), oneSolution.end());
                    solution.push_back(oneSolution);
                }
            }
        }
        sort(solution.begin(), solution.end());
        solution.erase(unique(solution.begin(), solution.end()), solution.end());
        return solution;
    }
};






