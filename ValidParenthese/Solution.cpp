/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not
 *
 */
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string str) {
        int index=0;
        stack<char> closeBracketStack;
        while (index < str.length()) {
           if (str[index] == '(' ) {
                closeBracketStack.push(')');
            }
           else if (str[index] == '{') {
               closeBracketStack.push('}');
           }
           else if (str[index] == '[') {
               closeBracketStack.push(']');
           }
           else {//expect close brackets
               if (!closeBracketStack.empty() &&
                   closeBracketStack.top() == str[index]) {
                   closeBracketStack.pop();
               }
               else
               {//stack is empty or close brackets does not match
                   return false;
               }
           }
           index++;
        }
        if (!closeBracketStack.empty()) {//WARNING, bug here, check whether stack is empty
            return false;
        }
        else
        {
            return true;
        }
    }
};




