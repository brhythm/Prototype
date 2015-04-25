/**
 * Definition for binary tree with next pointer.
 */
#include <stddef.h>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) :
            val(x), left(NULL), right(NULL), next(NULL) {
    }
};

class Solution {
public://Time:O(N), Space O(lgN)
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        } else {
            if (root->left != nullptr) {
                if (root->right != nullptr) {
                    root->left->next = root->right;
                } else {
                    TreeLinkNode* uncle = getNextSiblingWithChild(root);
                    if (uncle != nullptr) { //find an uncle who has child
                        root->left->next =
                                uncle->left == nullptr ? uncle->right:uncle->left;
                    } //else, no uncle, left->next is null
                }
            }
            if (root->right != nullptr) {
                TreeLinkNode* uncle = getNextSiblingWithChild(root);
                if (uncle!= nullptr) {
                    root->right->next =
                            uncle->left == nullptr ? uncle->right : uncle->left;
                }
            }
            connect(root->right);//Warning, bug here!! Think about the recursive order
            connect(root->left);
        }
    }

    TreeLinkNode* getNextSiblingWithChild(TreeLinkNode* root)
    {
        TreeLinkNode* head = root->next;
        while(head !=nullptr && head->left == nullptr && head->right == nullptr)
        {
            head = head->next;
        }
        return head;
    }
};
//Note: In this problem, we MUST process right subtree before left subtree
//Otherwise, left subtree would not be able to find correct uncle. BUG HERE
//


