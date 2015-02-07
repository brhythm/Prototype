/**
 * Definition for binary tree
 */
#include <vector>
#include <queue>
#include <stddef.h>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
using namespace std;
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        } else {
            queue<TreeNode*> current;
            current.push(root);
            queue<TreeNode*> next;

            while (!current.empty()) {
                vector<int> level;
                while (!current.empty()) {
                    TreeNode* node = current.front();
                    //everything in the queue is NOT NULL
                    current.pop();
                    level.push_back(node->val);
                    if (node->left != nullptr) {
                        next.push(node->left);
                    }
                    if (node->right != nullptr) {
                        next.push(node->right);
                    }
                } //now all nodes on current level is processed
                result.push_back(level);
                swap(next, current);
            }
            return result;
        }
    }
};

