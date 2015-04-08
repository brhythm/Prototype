/**
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 
 Note:
 If there is no such window in S that covers all characters in T, return the emtpy string "".
 
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
#include <stdio.h>
#include <string>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>
using namespace std;
//Warning, T might contain duplicate letters
class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || T.empty()) {
            return "";
        }
        if (S.size() < T.size()) {
            return "";
        }
        string result = "";
        int expectCount[256];
        int actualCount[256];
        int foundLetters =0;
        int minWindowSize = INT_MAX;
        memset(&expectCount[0], 0, sizeof(int)*256);
        memset(&actualCount[0], 0, sizeof(int)*256);
        for (int i=0; i < T.size(); ++i) {
            expectCount[T[i]]++;
        }
        int i=0;
        for (int j=0; j < S.size(); ++j)
        {
            char letter = S[j];
            if (expectCount[letter] > 0) {
                //update counters
                actualCount[letter]++;
                if (actualCount[letter] <= expectCount[letter]) {
                    foundLetters++;
                }
                if (foundLetters == T.size()) {
                    //all letters found
                    while (expectCount[S[i]] == 0 || actualCount[S[i]] > expectCount[S[i]]) {
                        actualCount[S[i]]--;
                        ++i;
                    }
                    //now we got the smallest window that cover all letters
                    int length = j-i+1;
                    if (length < minWindowSize) {
                        minWindowSize = length;
                        result = S.substr(i, length);
                    }
                }
            }
        }
        return result;
    }
};

//Note I used a map to store all indexes of found letter, which might fail the big data set
//map<char, deque<int>> foundLetterMap;//e.g. B => 3, 9
//so try to remove this map, and rescan the indexQueue everytime we refresh i
int main()
{
    Solution test;
    string s = "bdab";
    string t = "ab";
    string result = test.minWindow(s, t);
    printf("result=%s\n", result.c_str());
    return 0;
}











