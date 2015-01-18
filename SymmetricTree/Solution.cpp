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
    //Time O(N) for sure
    //Space O(lgN), the space complexity for these recursive functions is actually:
    //the deepest level of recursion ? in this case ->tree height
    //In other words, the recursive function would start to return once reach the deepest level
    //
    bool areTreesIdentical(TreeNode *rootA, TreeNode *rootB) {
        if ( rootA != NULL && rootB != NULL && rootA->val == rootB->val) {
            //current node is identical
            if (areTreesIdentical(rootA->left, rootB->left)) {
                //left subtree is identical
                return areTreesIdentical(rootA->right, rootB->right);
            }
            else {
                // left subtree is NOT identical
                return false;
            }
        }
        else if (rootA == NULL && rootB == NULL) {
            // reach the end of tree, identical!
            return true;
        }
        else {// rootA or rootB is null,
              // rootA->val != rootB-> val
              //Not identical
            return false;
        }
    }

};






