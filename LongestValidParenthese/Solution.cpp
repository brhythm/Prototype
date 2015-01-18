/**
 */

//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    //TODO work another DP verison
    int longestValidParentheses(string s) {
        int maxLength = 0;
        int lastSoloOpenBrace = -1;//warning, init value is important, bug here
        stack<int> openBraces;
        for (int i=0; i < s.length(); ++i) {
            if (s[i] == '(') {
                openBraces.push(i);
            }
            else
            {//s[i] == ')'
                if (!openBraces.empty()) {
                    openBraces.pop();
                    if (!openBraces.empty()) {
                        maxLength = max(maxLength, i - openBraces.top());
                    }
                    else
                    {//after finding the match, stack is empty
                        maxLength = max(maxLength, i - lastSoloOpenBrace);
                    }
                }
                else
                {// stack is empty, find a dangling close brace
                    lastSoloOpenBrace =i;
                }
            }
        }
        return maxLength;
    }
    
};

//use stack to maintain the "(" that might be matched
//push index into stack so that we can eaily calc the length

//int main()
//{
//    //string s = ")(()())";
//    string s="()";
//    Solution test;
//    int result = test.longestValidParentheses(s);
//    printf("result is %d\n", result);
//    return 0;
//}



