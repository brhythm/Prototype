/**
 */

//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//[
// ["aa","b"],
// ["a","a","b"]
// ]

#include <vector>
#include <string>

using namespace std;

class Solution {
public://Time O(N^2), Space O(N)
    vector<vector<string>> partition(string s) {
        int n = s.length();
       // bool d[n][n];
       // memset(d, false, sizeof(bool)*n*n );
        // shit 2d array cannot be passed to functions
        vector<bool> oneRow(n, false);
        vector<vector<bool>> d( n, oneRow);
    
        for (int j=0; j < n; ++j)
        {
            d[j][j] = true;
            for (int i=j-1; i >=0; --i)
            {
                if (i == j-1)
                {
                    d[i][j] = s[i]==s[j];
                }
                else
                {// i < j-1
                    d[i][j] = s[i]==s[j] && d[i+1][j-1];
                }
            }
        }
        
        vector<vector<string>> solution;
        vector<string> path;
        getPartition(0, s, d, path, solution);
        return solution;
    }
    
    void getPartition(int start, const string& s,  const vector<vector<bool>>& isPalindrome,
             vector<string>& path, vector<vector<string>>& solution)
    {
        int n =  s.size() ;
        if (start >=n )
        {//terminate , add candidateSolution to solution
            solution.push_back(path);
            return;
        }
       else
        {
           vector<string> restorePath = path;
           for (int end=start; end < n; ++end)
           {
               if (isPalindrome[start][end])
               {
                   path.push_back(s.substr(start, end-start+1));
                   getPartition(end+1, s, isPalindrome, path, solution);
                   //backtrack
                   path = restorePath;
               }//else, try next end
           }
        }
    }
};

//int main()
//{
//    string testString("aabbbc");
//    Solution test;
//    vector<vector<string>> result = test.partition(testString);
//    for (auto oneResult: result)
//    {
//        printf("[ ");
//        for(auto onePartition: oneResult)
//        {
//            printf("%s,", onePartition.c_str());
//        }
//        printf("]\n");
//    }
//}


