/*
 * Populate each next pointer to point to its next right node.
 *
 * If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 *
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <stddef.h>
#include <queue>
using namespace std;

class Solution {

    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
    };

public:

    /* If your first thougth is level order travel, it is intuitive that you
     * can keep a prevNodePtr, and alwasy connect prevNodePtr and currentNodePtr
     * if prevNodePtr->next is NULL
     * The only problem here is nodes on right border shall point to NULL,
     * go through these nodes again and set the next to NULL
     *
     * Running time(O(N)), space compliextyO(O(N))
    */
    void connect(TreeLinkNode *rootPtr) {
        queue<TreeLinkNode*> nodeQueue;
        if (rootPtr != NULL) {
            TreeLinkNode* prevNodePtr = NULL;
            nodeQueue.push(rootPtr);
            while (!nodeQueue.empty()) {
                TreeLinkNode* nodePtr = nodeQueue.front();
                nodeQueue.pop();
                if (prevNodePtr != NULL &&
                        prevNodePtr->next == NULL ) {
                    prevNodePtr->next = nodePtr;
                }
                if (nodePtr->left != NULL) {
                    nodeQueue.push(nodePtr->left);
                    nodePtr->left->next = nodePtr->right;
                }
                if (nodePtr->right != NULL) {
                    nodeQueue.push(nodePtr->right);
                }
                prevNodePtr = nodePtr;
            }
            while (rootPtr != NULL) {
                rootPtr->next = NULL;
                rootPtr = rootPtr->right;
            }
        }

    }

};

