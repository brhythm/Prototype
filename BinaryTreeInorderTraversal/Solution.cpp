
/**
 * Definition for binary tree
 */
#include <vector>
#include <stack>
#include <stddef.h>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
public: //Using stack
	//Running time O(N), space complexity O(N)
    vector<int> inorderTraversal(TreeNode *root) {
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
//Note: The idea is keep going left until we reach leaf node,
//same parent node in the stack on the way
//when we reach nullPtr (leaf node), it means all the left child has been printed
//then we can check top of the stack to print the latest parent node
//once parent node is done, try to put right kid into stack, that's
// print left kid, print me, print right kid
