/**
 */

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//"((()))", "(()())", "(())()", "()(())", "()()()"

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        string candidate;
        recursiveGeneration(n, 0, 0, candidate, solution);
        return solution;
    }
    
    void recursiveGeneration(const int n, const int leftNum, const int rightNum, string& candidate, vector<string>& solution)
    {
        if (leftNum == n && rightNum == n) {
            //terminate condition
            //complete one solution
            solution.push_back(candidate);
        }
        else
        {
            string restoreCandidate = candidate;
            if (leftNum < n) {//we can put more left parenthese
                candidate += "(";
                recursiveGeneration(n, leftNum+1, rightNum, candidate, solution);
                //solution would be recorded automatically
                //backtrack
                candidate = restoreCandidate;
            }
            if (rightNum < leftNum) {
                candidate += ")";
                recursiveGeneration(n, leftNum, rightNum+1, candidate, solution);
            }
        }
    }
};

//int main()
//{
//    Solution test;
//    vector<string> solution = test.generateParenthesis(3);
//    for (string path : solution) {
//        printf("%s\n", path.c_str());
//    }
//}