/*
 * Solution.cpp
 *
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values.
 * (ie, from left to right, level by level from leaf to root).
 *
 * For example: Given binary tree {3,9,20,#,#,15,7},
 * return its bottom-up level order traversal as:
 *[
 *  [15,7],
 *  [9,20],
 *  [3]
 *]
 */

#include <stddef.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//Time O(N), space O(N)
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > solution;
        if (root != NULL) {
            stack<vector<int> > nodeStack;

            queue<TreeNode*> currentQueue;
            currentQueue.push(root);

            queue<TreeNode*> nextQueue;

            vector<int> oneLevel;
            while (!currentQueue.empty()) {
                while (!currentQueue.empty()) {
                    TreeNode* currentNode = currentQueue.front();
                    currentQueue.pop();
                    oneLevel.push_back(currentNode->val);
                    if (currentNode->left != NULL) {
                        nextQueue.push(currentNode->left);
                    }
                    if (currentNode->right != NULL) {
                        nextQueue.push(currentNode->right);
                    }
                } // currentQueue is empty, all node at this level has been recorded

                nodeStack.push(oneLevel);
                oneLevel.clear();

                swap(currentQueue, nextQueue); //currentQ = nextQ, nextQ is empty
            }

            solution.reserve(nodeStack.size());
            while(!nodeStack.empty()) {
                solution.push_back(nodeStack.top());
                nodeStack.pop();
            }

        }

        return solution;
    }
};

