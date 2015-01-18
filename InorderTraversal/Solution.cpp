/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
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
    vector<int> inorderTraversal(TreeNode *root) {
        //Running time O(N), space complexity O(N)
        vector<int> resultVector;
        stack<TreeNode*> nodeStack;
        TreeNode* nodePtr = root;

        while ((nodePtr != NULL) || !nodeStack.empty()) {
            //current node might be left node or right node
            if (nodePtr != NULL) {    //keep going left
                                      //save parent
                nodeStack.push(nodePtr);
                nodePtr = nodePtr->left;
            } else {
                //get the last parent node and print
                TreeNode* parentNodePtr = nodeStack.top();
                nodeStack.pop();
                resultVector.push_back(parentNodePtr->val);
                nodePtr = parentNodePtr->right;
            }
        }

        return resultVector; //return empty vector

    }
};
