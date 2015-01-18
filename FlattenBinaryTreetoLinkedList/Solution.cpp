/*
 * Solution.cpp
 * Flatten Binary Tree to Linked List
 *
 *        1
 *       / \
 *      2   5
 *     / \   \
 *    3   4   6
 *
 *  1
 *   \
 *    2
 *     \
 *      3
 *       \
 *        4
 *         \
 *          5
 *           \
 *            6
 */

#include <stddef.h>
#include <stack>

using namespace std;
struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void flatten(TreeNode *root) {
        if ( root != NULL) {
            stack<TreeNode*> nodeStack;

            nodeStack.push(root);
            while(!nodeStack.empty()) {
                TreeNode* currentNode = nodeStack.top();
                nodeStack.pop();

                if (currentNode->right!= NULL) {
                    nodeStack.push(currentNode->right);
                }
                if (currentNode->left != NULL) {
                    nodeStack.push(currentNode->left);
                }
                if (!nodeStack.empty()) {
                    currentNode->right = nodeStack.top();
                }
                else {
                    currentNode->right = NULL;
                }
               currentNode->left = NULL;
            }
        }
    }
};






