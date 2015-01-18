/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as
 * a binary tree in which the depth of the two subtrees of every node
 * never differ by more than 1.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stddef.h>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
 public:
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return dfs(root, depth);
    }
   //dfs would return isBalanced
    bool dfs(TreeNode* rootPtr, int& depth) {
        if (rootPtr == NULL) {
            return true;
        }
        else {
            bool isBalanced = false;
            depth += 1;
            int leftDepth = depth;
            int rightDepth = depth;
            TreeNode* leftChildPtr = rootPtr->left;
            TreeNode* rightChildPtr = rootPtr->right;
            if (dfs(leftChildPtr, leftDepth) &&
                dfs(rightChildPtr, rightDepth)) {
                //both left and right subtree are balanced
                if (abs(leftDepth - rightDepth) <= 1) {
                //diff <= 1, not balanced
                isBalanced = true;
                //WARNING! if you don't take max here, alg will fail
                depth = max(leftDepth, rightDepth);
                }
            }
            return isBalanced;
        }
    }
};

int main()
{
    printf("Nothing\n");
    
    return 1;
}



