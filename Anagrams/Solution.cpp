/**
 * Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.
 */
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        if (!strs.empty())
        {
            map<string, int> indexMap;//sorted string-> original index
            for (int i=0; i < strs.size(); ++i)
            {
                string oneString = strs[i];
                sort(oneString.begin(), oneString.end());
                if (indexMap.find(oneString) == indexMap.end())
                {//never see this string before
                    indexMap[oneString] = i;
                }
                else
                {// found anagram
                    int firstSeenIndex = indexMap[oneString];
                    if (firstSeenIndex >=0 )
                    {
                        result.push_back(strs[firstSeenIndex]);
                        indexMap[oneString] = -1;
                     }//else first appearence has been recorded
                    result.push_back(strs[i]);
               }
            }
        }
        return result;
    }
};



