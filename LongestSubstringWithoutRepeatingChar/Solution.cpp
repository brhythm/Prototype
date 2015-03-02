/**
 */

//Given a string, find the length of the longest substring without repeating characters.
//For example, the longest substring without repeating letters for "abcabcbb" is "abc",
//which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
#include <string>
#include <string>
#include <cstdio>
#include <climits>
using namespace std;
class Solution {
public://Time O(N^2), Space O(n)
    int lengthOfLongestSubstring(string s) {
        int longestSubs = 0;
        if (s.length() > 0) {
            //int lastSeen[256];//char -> index
            //use memset on interger is wrong, it set by byte
            vector<int>  lastSeen(256, -1);
            int start = 0;//start index of longest ss
            for (int i=0; i < s.length(); ++i) {
                int charIndex = s[i]-'\0';//REMEMBER, ascii table starts from null char
                if (lastSeen[charIndex] < start) {
                    //never see this char in current substring
                    lastSeen[charIndex] = i;
                }
                else
                {//found duplicate char
                    //update longestSubs with previous currentMax
                    int localMax = i-1 - start+1;
                    //printf("local max %d : %s, start = %d\n", i-start,  s.substr(start, i-start).c_str(), start);
                    longestSubs = max(longestSubs, localMax);
                    //update start
                    start = lastSeen[charIndex]+1;
                    //must update lastSeen again
                    lastSeen[charIndex]=i;//WARNING, this is the trick
                    //continue, try to extend localMax as much as possible
                }
            }
            int localMax = s.length()-start;
            longestSubs = max(longestSubs, localMax);
        }
        return longestSubs;
    }
};
//Note:why not use unordered_map here ? Yes, initially I tried that. But once we detect a duplicate char, and set start = index+1,
//we are supposed to remove all elements <= index from map, which is slow since unordered_map did not remember insertion order
//A faster data structure here is int [], use ASCII character index as the index, keep track of the last seen index of each char
//since we know the startIndex of current substring, if that index falls in between, it means it is duplicate
//this is the most importantant trick in this problem
int main()
{
    //string input = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    //string input = "qopubjguxhxdipfzwswybgfylqvjzhar";
    string input = "vfauaosnlnvacsvpiumoiawcqxswkqwgxyazntnaikameybnuqb";
    //string input = "bbbb";
    Solution test;
    int result = test.lengthOfLongestSubstring(input);
    printf("longest ss = %d\n", result);
    return 0;
}
