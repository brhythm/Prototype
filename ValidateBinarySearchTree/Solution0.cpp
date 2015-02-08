/*
 * Solution.cpp
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 */

#include <stddef.h>
#include <climits>
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
public://Time O(N), Space O(lgN)
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode* root, int lower, int upper)
    {
        if (root == nullptr) {
            return true;
        }
        if (root->val > lower &&
            root->val < upper) {
            return isValidBST(root->left, lower, root->val) &&
            isValidBST(root->right, root->val, upper);
        }
        else
        {
            return false;
        }
    }

};






