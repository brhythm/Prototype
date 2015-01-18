/*
 * Solution.cpp
 *
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 */

#include <stddef.h>
#include <queue>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//Warning, the definition of leaf node is it has no child
//Time O(N), space O(N)
class Solution {
public:
    int minDepth(TreeNode *root) {

    	int depth = 0;
    	if ( root != NULL) {
    	   	queue<TreeNode*> currentQueue, nextQueue;
    		//warning : root node is different, it is not considered as a leaf node
    		depth = 1;//root node has depth 1, not zero
    		currentQueue.push(root);
    	   	while( !currentQueue.empty())
    	   	{
    	   		bool isLeafNodeFound = false;
    	   		while(!currentQueue.empty()) {
    	   			//check if currentNode is a leaf node
    	   			TreeNode* currentNode = currentQueue.front();
    	   			currentQueue.pop();
    	   			if (currentNode->left == NULL &&
    	   			    currentNode->right == NULL) {
    	   				isLeafNodeFound = true;
    	   				break;
    	   			}
    	   			else {
    	   				if (currentNode->left != NULL) {
    	   					nextQueue.push(currentNode->left);
    	   				}
    	   				if (currentNode->right != NULL) {
    	   					nextQueue.push(currentNode->right);
    	   				}
    	   			}
    	   		}
    	   		if (!isLeafNodeFound) {
    	   			++depth;
    	   			//currentQueue must be empty
    	   			//make nextQueue currentQueue
    	   			swap(currentQueue, nextQueue);
    	   		}
    	   		else //find min depth
    	   		{
    	   			break;
    	   		}
    	   	}
    	}
    	return depth;
    }
};

