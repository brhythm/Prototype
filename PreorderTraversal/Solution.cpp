/*
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 * 
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
#include <vector>
#include <stack>

using namespace std;

class Solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
    };

public:
    vector<int> preorderTraversal(TreeNode *root) {
        //Running time O(N), space complexity O(N)
        vector<int> resultVector;

        stack<TreeNode*> nodeStack;

        if (root != NULL) {
            nodeStack.push(root);
            while (!nodeStack.empty()) {
                //Node, stack.pop() does not return value
                TreeNode* nodePtr = nodeStack.top();
                nodeStack.pop();
                resultVector.push_back(nodePtr->val);

                if (nodePtr->right != NULL) {
                    nodeStack.push(nodePtr->right);
                }
                if (nodePtr->left != NULL) {
                    nodeStack.push(nodePtr->left);
                }
            }
        }
        return resultVector; //return empty vector

    }
};
