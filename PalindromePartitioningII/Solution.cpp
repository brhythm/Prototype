/**
 */
//
//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//For example, given s = "aab",
//Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
#include <string>
#include <stdio.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        bool d[n][n];//whether string [i,j] is palindrome
        memset(&d, false, sizeof(bool)*n*n);
      
        for (int j=0; j < n; ++j)
        {
            d[j][j] = true;
            for (int i=j-1; i>=0; --i)
            {
                if (i == j-1)
                {// j == i+ 1
                    d[i][j] = s[i]==s[j];
                }
                else
                {
                    d[i][j] = s[i]==s[j] ? d[i+1][j-1]: false;
                }
            }
        }
        
        int cut[n];//min cut for string[0,i]
        fill_n(cut, n, INT_MAX);
        cut[0] = 0;
        for (int i=1; i < n; ++i)
        {
            if (d[0][i])
            {
                cut[i] = 0;//optimum
            }
            else
            {
                for (int j=0; j <= i-1; ++j)
                {
                    if (d[j+1][i])
                    {
                        cut[i] = min(cut[i], cut[j]+1);
                        //printf("debug cut[%d] = %d\n", i, cut[i]);
                    }//else, d[j+1][i] not palindrome, can not cut here
                }
            }
        }
        return cut[n-1];
        
    }
};

//int main()
//{
//    string testString("1");
//    Solution test;
//    int  result = test.minCut(testString);
//    printf("min cut = %d\n", result);
//    return 0;
//    
//}


