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
        bool isValid = true;
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
           else {//regular or close bracket
               char expectedBracket = '*' ;//expect NO close bracket
               if (!closeBracketStack.empty()) {
                   expectedBracket = closeBracketStack.top();
               }
               if (isCloseBracket(str[index])) {
                   //it is close bracket
                   if (str[index] != expectedBracket) {
                       return false;//TODO
                   }
                   else {// close bracket match expectation
                       closeBracketStack.pop();
                   }
               }
               //else regular don't care
           }
           index++;
        }
        if (!closeBracketStack.empty()) {
            isValid = false;
        }
        return isValid;
    }

    bool isCloseBracket(const char character) {
        if ( character == '}' ||
             character == ']' ||
             character == ')')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};




