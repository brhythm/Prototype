/*
 * Solution.cpp
 *
 *Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * For example:
 * Given binary tree {3,9,20,#,#,15,7}, return its level order traversal as:
 *
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */

#include <vector>
#include <queue>
#include <stddef.h>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    //time complexity O(N + H) = O(N+lgN)
    //TODO:try to do it without extra H time complexity
    vector<vector<int> > levelOrder(TreeNode *root) {

        vector<vector<int> > solution;
        if (root != NULL) {

            queue<TreeNode*> nodeQueue;
            nodeQueue.push(NULL);
            nodeQueue.push(root);
            // Here, we use null as a level tag
            vector<int> oneLevel;

            bool isLevelTagPushed = false;
            while (!nodeQueue.empty()) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                if (currentNode == NULL) {
                    //get level tag, there must be a node following level tag according to our alg
                    if (!oneLevel.empty()) {
                        solution.push_back(oneLevel); //record previous level values;
                        oneLevel.clear();
                    }

                    //current node is the first node at this level
                    currentNode = nodeQueue.front();
                    nodeQueue.pop();
                    isLevelTagPushed = false;
                 }
                oneLevel.push_back(currentNode->val);

                if (isLevelTagPushed == false) {
                    if (currentNode->left != NULL || currentNode->right != NULL) {
                        isLevelTagPushed = true;
                        nodeQueue.push(NULL);
                    }
                }
                if (currentNode->left != NULL) {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right != NULL) {
                    nodeQueue.push(currentNode->right);
                }
            }
            if (!oneLevel.empty()) {
                solution.push_back(oneLevel);
            }
        }

        return solution;
    }
};

