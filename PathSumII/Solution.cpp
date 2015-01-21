/*
 * Solution.cpp
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
 * equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \    / \
 *       7    2  5   1
 * return
 * [
 *   [5,4,11,2],
 *   [5,8,4,5]
 * ]
 */

#include <stddef.h>
#include <vector>

using namespace std;
 // Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> solution;
        vector<int> candidate;
        dfs(root, sum, candidate, solution);
        return solution;
    }

    void dfs(TreeNode* root, int sum, vector<int>& candidate, vector<vector<int>>& solution)
    {
        if (root == NULL)
        {//terminate algorithm, fail to find solution
            return ;
        }
        candidate.push_back(root->val);
        if (root->left == NULL &&
            root->right == NULL)
        {//this is leaf node
            if (sum == root->val)
            {//record soltuion
                solution.push_back(candidate);
            }//else return
        }
        else
        {
            vector<int> restoreCandidate = candidate;
            dfs(root->left, sum-root->val, candidate, solution);
            //if there is any solution, it must have been recorded
            //backtrack
            candidate = restoreCandidate;
            dfs(root->right, sum-root->val, candidate, solution);
        }
    }
};






