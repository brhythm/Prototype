/**
 */

//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    //Even though this is DP O(N^2), looks like 2 loops will fail the big data test
    string longestPalindrome(string s) {
        int n = s.length();
        bool d[n][n];
        //Note that array has contiguous memory
        fill_n(&d[0][0], n*n, false );
        
        int maxLength = 1;
        int start = 0;
        int end = 0;
        for (int i=0; i < n-1; ++i)
        {
            d[i][i] = true;
            bool isPalindrome = s[i] == s[i+1];
            d[i][i+1] = isPalindrome;
            if (isPalindrome)
            {
                maxLength = 2;
                start = i;
                end = i+1;
            }
        }
        d[n-1][n-1] = true;
        // printf("maxlength %d\n", maxLength);
        
        for (int i=0; i < n; ++i)
        {
            for (int j = i+2; j < n; ++j)
            {
                //  printf("debug: isEqual? %d\n", s[i]==s[j]);
                //  printf("i= %d, j = %d\n", i, j);
                bool isPalindrome = s[i] == s[j] ? d[i+1][j-1] :false ;
                
                d[i][j] = isPalindrome;
                if (isPalindrome && (j-i+1)>maxLength)
                {
                    maxLength = j-i+1;
                    start = i;
                    end = j;
                    //printf("i= %d, j = %d\n", i, j);
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};

//int main()
//{
//    string testString("abcff");
//    
//    Solution test;
//    string result = test.longestPalindrome(testString);
//    printf("result = %s\n", result.c_str());
//    
//    return 0;
//    
//}
//Define d[i,j] to be bool value, which means is string between i,j a palindrome string
//
// d[i,j] =   j == i , true
//            j = i+1,  S[i]==S[j]
//            j > i+1,  S[i]==S[j] ? d[i+1, j-1]: false
//
// note that we don't care about j < i, which means we could leave half of the table empty
// figure out how to fill another half elegantly
// Keep track of maxPalindromeStringLength and its index
// O(N^2)