/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal
 * if they are structurally identical and the nodes have the same value.
 *
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
    //Iterative solution using stack
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
        {
            return true;
        }

        stack<TreeNode*> nodeStack;
        nodeStack.push(root->left);
        nodeStack.push(root->right);
        while (!nodeStack.empty()) {
            TreeNode* right = nodeStack.top();
            nodeStack.pop();
            TreeNode* left = nodeStack.top();
            nodeStack.pop();
            if (left == nullptr &&
                right == nullptr){
                //both children are null, OK
                ;
            }
            else if (left == nullptr || right == nullptr) {
                return false;
            }
            else if (left->val != right->val) {
                //both pointer not null
                return false;
            }
            else
            {//left ,right values are equal
                nodeStack.push(right->right);
                nodeStack.push(left->left);
                
                nodeStack.push(right->left);
                nodeStack.push(left->right);
            }
        }
        return true;
    }
    
};
//Idea: One straightforward way is to level order traverse the tree, and 
//for each level, check whether the nodes in the queues are symmetric or not
//However, this algorithm is NOT always correct. e.g. return wrong value for {1,2,2,#,3,#,3}
//
//Use a stack to replace the recursive alg.





