
/**
 * Definition for binary tree
 */
#include <vector>
#include <stack>
#include <stddef.h>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
public://Morris preorder walk
       //Time O(N), Space O(1)
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        while (root != nullptr)
        {
            if (root->left != nullptr)
            {//find predecessor (rightest child in left subtree)
                TreeNode* predecessor = root->left;
                while(predecessor->right != nullptr &&
                        predecessor->right != root)
                {//WARNIING, bug here
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr)
                {//create thread to come back to me later
                    predecessor->right = root;
                    result.push_back(root->val);//print me
                    root = root->left;
                }
                else
                {//we have visited this node before, which means
                 //me is printed, left child is printed
                    predecessor->right = nullptr;//remove created thread
                    root = root->right;
                }
            }
            else
            {//no left child
                 result.push_back(root->val);//print me
                 root = root->right;
            }
        }
        return result;
    }
};
//The idea is the same as Morris inorder walk.
//Pre-order walk requires us to visit me, visit left, visit right
//However, when we go left, there is no way to come back to right child again
//Thus morris preorder walk let you create link to successor before going left, that's how we go back to 'Me'
//One question here is that why not create link to go back to right child directly,
//because if we do that, there is no way to visit the same node during processing,
//the created link cannot be removed later, tree structure would be broken




