/**
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along 
 * the longest path from the root node down to the farthest leaf node.
 * 
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


class Solution {
	struct TreeNode {
	     int val;
	     TreeNode *left;
	     TreeNode *right;
	     //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	 
public:
    int maxDepth(TreeNode *root) {
    	int maxDepth = 0;    
    	if ( root != NULL)
    	{
    		//maxDepth++;
    		dfs(root, &maxDepth);
    	}
    	
    	return maxDepth;
    }
    
    void dfs(TreeNode *root, int* depth)
    {
    	if (root != NULL)
    	{
    		(*depth)++;
    		int leftDepth; 
    		int rightDepth = leftDepth = *depth;
    		dfs(root->left, &leftDepth);
    		dfs(root->right, &rightDepth);
    		//finish dfs, update max depth
    		if ( leftDepth > rightDepth)
    		{
    			*depth = leftDepth;
    		}
    		else
    		{
    			*depth = rightDepth;
    		}
    	}
    }
    
};
