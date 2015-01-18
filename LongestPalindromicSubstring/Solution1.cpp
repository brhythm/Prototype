/**
 */

//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    //If you are using DP, fill the table ELEGANTLY!! use ONE loop
    string longestPalindrome(string s) {
        int n = s.length();
        bool d[n][n];
        //Note that array has contiguous memory
        //WARNING, memset is much faster than fill
        memset(d, n*n, true);
        //fill_n(&d[0][0], n*n, true );//init dummy nodes to be true, so d[i][i+1] could be s[i]==s[i+1]
        
        int maxLength = 1;
        int start = 0;
        int end = 0;
        
        for (int j  = 0; j < n; ++j)
        {
            d[j][j] = true;
            for (int i = j-1; i>=0; --i)
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
//    string testString("aaaa");
//    
//    Solution test;
//    string result = test.longestPalindrome(testString);
//    cout << result << endl;
//    
//    return 0;
//    
//}


