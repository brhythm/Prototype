/*
 * Solution.cpp
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 */
#include <vector>
#include <stack>
#include <stddef.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //Time complexity O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {

    	vector<int> solution;
    	stack<TreeNode*> nodeStack;
    	if (root != NULL) {
    		nodeStack.push(root);

    		while(!nodeStack.empty()) {
    			TreeNode* currentNode = nodeStack.top();
    			if ( currentNode->left != NULL ||
    			     currentNode->right != NULL) {
    				//has one or two children
    				if (currentNode->right != NULL) {
    					nodeStack.push(currentNode->right);
    				}
    				if (currentNode->left != NULL) {
    					nodeStack.push(currentNode->left);
    				}
    			}
    			else
    			{//no child, this is leave node already
    				solution.push_back(currentNode->val);
    				nodeStack.pop();

    				//WARNING, here we must trace back to print all parent nodes
    				//instead of only one parent node
    				while (!nodeStack.empty())
    				{//peek prevNode
						TreeNode* prevNode = nodeStack.top();
						if (prevNode->left == currentNode ||
						    prevNode->right == currentNode)
						{ //prevNode is currentNode's parent
							solution.push_back(prevNode->val);
							nodeStack.pop();

							currentNode = prevNode;
						}
						else
						{//prevNode is my sibling, do nothing
							break;
						}
					}
    			}
    		}
    	}
    	return solution;
    }
};






