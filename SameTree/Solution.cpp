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
    
	bool isSameTree(TreeNode *source, TreeNode *target)
    {
        if (source == nullptr && target == nullptr)	
        {
            return true;
        }
        if ( source != nullptr && target != nullptr )
        {
            return isSameTree(source->left, target->left) &&
                   isSameTree(source->right, target->right);
        }
        return false; 
    }

};
