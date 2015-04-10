/**
 Implement regular expression matching with support for '.' and '*'.
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 */

#include <stdio.h>


class Solution {
public://Recursive solution
    bool isMatch(const char *s, const char *p) {
        if ( *p == '\0') {
            //terminate condition
            return *s == '\0';
        }
        //p[0] has something to be matched
        //s[0] might be empty already
        if (*(p+1) != '*') {
            //p must match a letter in s
            if (*p == *s || (*p == '.' && *s != '\0')) {
                return isMatch(s+1, p+1);
            }
            else
            {
                return false;
            }
        }
        else
        {// next char is *
            while (*p == *s || (*p == '.' && *s != '\0')) {
                //try every x* with every possible s and see whether it reaches solution or not
                if (isMatch(s, p+2)) {//WARNING, bug here. if use isMatch(s+1, p+2), we assume x* must match at least one x
                    return true;
                }
                ++s;
            }
            //we have matched zero or more letters in s
            return isMatch(s, p+2);
        }
    }
};

int main()
{//corner case
//ab, .*c => false
//aaa, a*a
    Solution test;
    printf("is match ? : %d\n", test.isMatch("aaa", "a*a"));
}




