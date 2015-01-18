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
public:
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
                    d[i][j] = s[i]==s[j] ? d[i+1][j-1]: false;
                }
            }
        }
        
        vector<vector<string>> solution;
        vector<string> candidateSolution;
        
        dfs(0, 0, s, d, candidateSolution, solution);
        return solution;
    }
    
    void dfs(int start, int end, string& s,  vector<vector<bool>>& isPalindrome, vector<string>& candidateSolution, vector<vector<string>>& solution)
    {
        int n =  s.size() ;
        if (start >=n )
        {//terminate , add candidateSolution to solution
            if (!candidateSolution.empty())
            {
                solution.push_back(candidateSolution);
            }
            return;
        }
        else if ( end >=n)
        {//invalid attempt, return
            return;
        }
        else
        {
            if (isPalindrome[start][end])
            {
                //write down this palindrome
                candidateSolution.push_back(s.substr(start, end-start+1));
                dfs(end+1, end+1, s, isPalindrome, candidateSolution, solution);
                //once that dfs returned, that solution has been recorded
                
                //backtrack
                candidateSolution.pop_back();

            }
            //else not palindrome
            dfs(start, end+1, s, isPalindrome, candidateSolution, solution);
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


