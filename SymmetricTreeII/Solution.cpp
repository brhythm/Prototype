/* Given a binary tree,
 * check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * Bonus points if you could solve it both recursively and iteratively.
 */

/*
 * 1) An intuitive approach is to traverse the tree by depth, print all nodes with the same
 * depth into an array, check whether the array is symmetric or not
 *
 * Time:O(N), Space: O(N/2)
 *
 * But the given tree definition does not have depth, you have to define your own struct
 *
 * 2) Another simple way is to in-order walk the tree, print all nodes, check whether the
 * array is symmetric or not
 *
 * Time:O(N), Space: O(N)
 *
 * So is there a better way ?
 * Recall that isIdentical on two binary trees only take O(lgN) space,
 * thus isMirror on two binary trees might take O(lgN) space, too (actually it is)
 *
 * Modify the isIdentical alg to be isMirror, and call it on left subtree and right rubtree
 * Time:O(N), Space: O(lgN);
 *
 */
#include <stddef.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root != NULL) {
            return isMirror(root->left, root->right);
        }
        else {
            return true;
        }

    }

    bool isMirror(TreeNode *rootA, TreeNode *rootB) {
        if ( rootA != NULL && rootB != NULL && rootA->val == rootB->val ) {
            if ( isMirror(rootA->left, rootB->right)) {
                return isMirror(rootA->right, rootB->left);
            }
            else {
                //A->left subtree is not a mirror of B->right subtree
                return false;
            }
        }
        else if ( rootA == NULL && rootB == NULL) {
            // reach the end of tree, mirror!
            return true;
        }
        else {
            // rootA or rootB is null
            // rootA->val != rootB->val
            // not mirror
            return false;
        }
    }
};



