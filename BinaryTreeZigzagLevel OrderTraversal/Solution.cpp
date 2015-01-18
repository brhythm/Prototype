/**
 */
//
// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
// For example:
// Given binary tree {3,9,20,#,#,15,7},
// 3
// / \
// 9  20
// /  \
// 15   7
// return its zigzag level order traversal as:
// [
//  [3],
//  [20,9],
//  [15,7]
//  ]
//

#include <vector>
#include <stddef.h>
#include <queue>

using namespace std;

 // Definition for binary tree
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> solution;
        if (root != nullptr)
        {
            queue<TreeNode*> current;
            queue<TreeNode*> next;
            current.push(root);
            bool rightToLeft = false;
          
            while (!current.empty()) {
                vector<int> oneLevel;
                while (!current.empty()) {
                    TreeNode* node = current.front();
                    current.pop();
                    oneLevel.push_back(node->val);
                    if (node->left != nullptr) {
                        next.push(node->left);
                    }
                    if (node->right != nullptr) {
                        next.push(node->right);
                    }
                }
                //current queue is empty
                if (rightToLeft) {
                    reverse(oneLevel.begin(), oneLevel.end());
                }
                //flip the flag
                rightToLeft = !rightToLeft;
                solution.push_back(oneLevel);
                swap(current, next);
            }
            
        }
        return solution;
       
    }
};



