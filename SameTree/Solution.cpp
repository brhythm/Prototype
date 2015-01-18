/*
 * Given two binary trees, 
 * write a function to check if they are equal or not.
 * 
 * Two binary trees are considered equal if they are structurally identical 
 * and the nodes have the same value.
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
class Solution {
	struct TreeNode {
	     int val;
	     TreeNode *left;
	     TreeNode *right;
	};
	
public:
    
	bool isSameTree(TreeNode *sourceNodePtr, TreeNode *targetNodePtr)
	    {
	    	bool isSame = isSameNode(sourceNodePtr, targetNodePtr);
	    	if ( isSame )
	    	{// same node or both null
	    		if ( sourceNodePtr != NULL)
	    		{// same node, continue judge
	    			// both left , right subtree same
	    			isSame = isSameTree(sourceNodePtr->left, targetNodePtr->left) &&
									isSameTree(sourceNodePtr->right, targetNodePtr->right);
	    		}// both null, ok
	    	}// not same tree
	    	return isSame;
	    }
	    
	    bool isSameNode(TreeNode *sourceNodePtr, TreeNode *targetNodePtr)
	    {//TODO can be optimized
	    	bool isSameNode = false;
	    	if (sourceNodePtr != NULL && targetNodePtr != NULL )
	    	{
	    		isSameNode = ( sourceNodePtr->val == targetNodePtr->val );
	    	}
	    	else if ( sourceNodePtr == NULL && targetNodePtr == NULL )
	    	{
	    		isSameNode = true;
	    	}
	    	
	    	return isSameNode;   	
	    }
    
};
