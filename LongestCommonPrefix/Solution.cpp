/*
 * Solution.cpp
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        //printf("size is %d\n", n);
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return strs[0];
        }

        // (n > 1)
        int commonPrefixIndex = -1;
        bool shouldTerminate = false;
        for (int index = 0; shouldTerminate == false; ++index) {
             commonPrefixIndex = index-1;
             for (int i = 0; i < n; ++i) {
                if (strs[i][index] == '\0'
                        || strs[i][index] != strs[0][index]) {
                    shouldTerminate = true;
                    break;
                } // strs[i][index] != '\0' && == str[0][index]
            }
           //printf("common prefix %d\n", commonPrefixIndex);
        }
        if (commonPrefixIndex >= 0) {
            return strs[0].substr(0, commonPrefixIndex + 1);
        } else {
            return "";
        }
    }
};
//
//int main() {
//    vector<string> testVector = { "aa", "aaaa" };
//    Solution test;
//    string result = test.longestCommonPrefix(testVector);
//    printf("result is %s\n", result.c_str());
//    return 0;
//}

