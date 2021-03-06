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
    //Time O(N), Space O(N)
    bool isValidBST(TreeNode *root) {
        vector<int> nodes;
        return inorderWalk(root, nodes);

    }

    bool inorderWalk(TreeNode* root, vector<int>& nodes)
    {
        if (root == nullptr) {
            return true;
        }
        //validate left subtree
        if (!inorderWalk(root->left, nodes)) {
            return false;
        }
        //validate root
        if (!nodes.empty() && root->val <= nodes.back()) {
            return false;
        }
        else
        {//root value is valid
            nodes.push_back(root->val);
        }
        //validate right subtree
        return inorderWalk(root->right, nodes);
    }

};

//warning, the obstacle in this problem is
//validation must make sure all nodes in the left/right substree is smaller/greater than root node
//that's why simply verfiying each node is NOT correct




