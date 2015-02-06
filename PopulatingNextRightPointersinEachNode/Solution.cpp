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
#include <deque>
using namespace std;

class Solution {

    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
    };

public:

    //The first thought is level order traversal
    //then set each node in current queue to point to its neighbor
    //However, queue does not support random access. We will use deque here
    
    //Time O(N), Space O(N)
    void connect(TreeLinkNode *root) {
        if ( root==nullptr) {
            return;
        }
        deque<TreeLinkNode*> current;
        deque<TreeLinkNode*> next;
        current.push_back(root);//everything in queue is NOT null
        
        while (!current.empty()) {
            size_t size = current.size();
            int i=0;
            for (; i <  size -1; ++i) {
                current[i]->next = current[i+1];
                if (current[i]->left != nullptr) {
                    next.push_back(current[i]->left);
                }
                if (current[i]->right != nullptr) {
                    next.push_back(current[i]->right);
                }
            }
            //now i =size-1;
            current[i]->next = nullptr;
            if (current[i]->left != nullptr) {
                next.push_back(current[i]->left);
            }
            if (current[i]->right != nullptr) {
                next.push_back(current[i]->right);
            }
            current.clear();
            swap(current, next);
        }
    }

};

