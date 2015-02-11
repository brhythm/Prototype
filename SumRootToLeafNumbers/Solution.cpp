/**
 */

//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//For example,
//
//  1
// / \
//2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

#include <stdio.h>
#include <vector>

using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum=0;
        vector<int> numbers;
        dfs(root, numbers, sum);
        return sum;
    }
    
    void dfs(TreeNode* root, vector<int>& numbers, int& sum)
    {
        if (root == nullptr) {
            return;
        }
        numbers.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            //this is leaf node, add to sum
            int numberOnPath = convertToNumber(numbers);
            sum += numberOnPath;
            return;
        }
        else
        {//not a leaf node
            vector<int> restoreNumbers = numbers;
            if (root->left != nullptr) {
                dfs(root->left, numbers, sum);
            }
            //backtrack
            numbers = restoreNumbers;
            if (root->right != nullptr)
            {
                dfs(root->right, numbers, sum);
            }
        }
    }
    
    int convertToNumber(const vector<int>& numbers)
    {
        int result = 0;
        for (int digit : numbers) {
            result = result*10 + digit;
        }
        return result;
    }
};

