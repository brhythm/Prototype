/*
 * Given a string containing just the characters '(' and ')',
 * find the length of the longest valid (well-formed) parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 */
//DP
//1) define D[i] = longest valid parenthese that end with str[i]
//   target is D[n-1];
//   D[i] = if str[i] = '(', => 0
//          if str[i] = ')', then
//                                if str[i-1] == '(', => D[i-2]+2
//                                else
//                                      k = D[i-1];
//                                      if str[i-k-1] == '(' , => D[i-1]+2+D[i-k-2] ;//WARNING, bug here, D[i-k-2] must be considered
//                                      else 0;//does not match
//
// if we think twice about this conversion function
// when str[i-1] == '(', D[i-1] = k = 0,  D[i] = D[i-1] + 2 + D[i-2] = D[i-2]+2;
// thus optimize the conversion function
// D[i] = if str[i] = '(', => 0
//        else str[i] = ')', then
//                               if str[i-k-1] == '(' , => D[i-1]+2+D[i-k-2] ;//WARNING, bug here, D[i-k-2] must be considered
//                               else 0;//does not match
//
// Actually we can also define D[i] to be the longest valid parenthese that start with str[i], the idea is the same.
#include <string>
#include <string.h>
using namespace std;

class Solution {
public://Time O(N), Space O(N)
    int longestValidParentheses(string s) {
        size_t n = s.length();
        if (n <= 0) {
            return 0;
        }
        int maxLength = 0;
        int D[n+1];
        memset(&D, 0, sizeof(int)*(n+1));//D[0] is dummy, D[i+1] correspond to index i;, our target is D[n]
        //D[0] = 0, dummy, set to zero for convenience ,set by memset
        //D[1] = 0, no matter what str[0] is , D[1] = 0;
        for (int i=1; i < n; ++i) {
            if (s[i] == ')') {
                int k = D[i];
                int indexToMatch = i-k-1;
                if (indexToMatch >= 0 && s[indexToMatch] == '(') {
                    D[i+1] = D[i]+2+D[i-k-1];
                    maxLength = max(maxLength, D[i+1]);
                }//else, indexToMatch is not '(', D[i+1] = 0;
            }//else s[i] == '(', D[i+1] = 0
        }
        return maxLength;
    }
};




