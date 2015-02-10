/*
 * Solution.cpp
 *
 * What if the given tree could be any binary tree?
 * Would your previous solution still work?
 *
 */
#include "stddef.h"
#include <queue>
using namespace std;

 struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

class Solution {
public://Yes, this solution still works
       //Time O(N) , space O(lgN)
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
        {//terminate condition
            return;
        }
        if (root->left != nullptr)
        {
            root->left->next = root->right;
        }
        if (root->right != nullptr)
        {
            root->right->next = root->next == nullptr? nullptr: root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
