/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> *resultVectorPtr = new vector<int>();
        
        stack<TreeNode*> nodeStack;
        
        if (root != NULL) {
            nodeStack.push(root);
            while (!nodeStack.empty()) {
                //Node, stack.pop() does not return value
                TreeNode* nodePtr = nodeStack.top();
                nodeStack.pop();
                resultVectorPtr->push_back(nodePtr->val);
                
                if (nodePtr->right != NULL) {
                    nodeStack.push(nodePtr->right);
                }
                if (nodePtr->left != NULL) {
                    nodeStack.push(nodePtr->left);
                }
            }
        }
        return *resultVectorPtr; //return empty vector
        
    }
};