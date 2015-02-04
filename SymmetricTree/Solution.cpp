/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal
 * if they are structurally identical and the nodes have the same value.
 *
 */

#include <stddef.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    //Time O(N) , space O(H)
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
        {
            return true;
        }
        else
        {
            return isSymmetricTrees(root->left, root->right); 
        }
    }

    bool isSymmetricTrees(const TreeNode* source, const TreeNode* target)
    {
        if (source == nullptr && target == nullptr)
        {
            return true;
        }
        if (source != nullptr && target != nullptr)
        {
            if (source->val == target->val)
            {
                return isSymmetricTrees(source->left, target->right) &&
                       isSymmetricTrees(source->right, target->left);
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};






