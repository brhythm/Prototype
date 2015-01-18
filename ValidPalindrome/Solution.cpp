/**
 */
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.
//

#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

//warning!! alphanumeric ?? alpha + numeric
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
        {//empty string is valid
            return true;
        }
        else
        {//non empty string
            //warning, must use ::touppper instead of toupper
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            bool isValidPalindrome = true;
            int i = 0;
            int j = s.length()-1;
            while ( i < j ) {
                bool isLeftValid = isalnum(s[i]);
                bool isRightValid = isalnum(s[j]);
                if ( isLeftValid && isRightValid )
                {//both left ,right are valid
                    if (s[i] == s[j])
                    {
                        ++i;
                        --j;
                    }
                    else
                    {
                        isValidPalindrome = false;
                        break;
                    }
            
                }
                else if (!isLeftValid)
                {//left invalid
                    ++i;
                }
                else
                {//right invalid
                    --j;
                }
            }
            return isValidPalindrome;
            
        }
    }
    
};

//int main()
//{
//    string s("1a2");
//    Solution test;
//    //printf("Hello??\n");
//    printf("is palindrome? %d\n", test.isPalindrome(s) == true);
//    return 0;
//}


