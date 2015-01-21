/*
 * Solution.cpp
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 */

#include <stddef.h>
#include <climits>
#include <vector>

using namespace std;
//Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        bool isValid = true;
        vector<int> nodes;
        if (root!= NULL)
        {
            isValid = inorderWalk(root, nodes);
        }
        return isValid;
    }

    bool inorderWalk(TreeNode* root, vector<int>& nodes)
    {
        bool isValidBST = true;
        if (root->left != NULL)
        {
            isValidBST = inorderWalk(root->left, nodes);
            if (!isValidBST)
            {
                return false;
            }
        }//left subtree is valid
        if ( nodes.empty() )
        {
            nodes.push_back(root->val);
        }
        else if ( root->val > nodes.back())
        {//prevNode exists and current node > prevNode
            //only keep one node in the vector
            nodes[0] = root->val;
        }
        else
        {//prevNode exists and current node <= prevNode
            return false;
        }//root node is valid
        if ( root->right != NULL)
        {
            isValidBST = inorderWalk(root->right, nodes);
            if (!isValidBST)
            {
                return false;
            }
        }//right subtree is valid
        return true;
    }

};

//warning, the obstacle in this problem is
//validation must make sure all nodes in the left/right substree is smaller/greater than root node
//that's why simply verfiying each node is NOT correct




