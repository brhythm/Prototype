
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
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> solution;
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->left != nullptr) {
                //try to find predecessor (righest node in my left subtree)
                TreeNode* predecessor = current->left;
                while (predecessor ->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = current;// create thread s.t. we can come back later
                    current = current->left;
                }
                else
                {//predecessor->right == current
                    //we have visited that predecessor before, remove thread to restore tree
                    predecessor->right = nullptr;
                    solution.push_back(current->val);
                    current = current->right;
                }
            }
            else
            {//no left child
                solution.push_back(current->val);
                current = current->right;
            }
        }
        return solution;
    }
};
//The idea is inorder traversal must visit left, visit me, visit right
//However, when we go left(my left child), there is no way to come back to me again
//Thus morris inorder walk let you create link to successor before going left, that's how we go back
//Note that morris walk would remove the created link and thus does not change the tree structure

