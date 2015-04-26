/*
 * Solution.cpp
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 */

#include <stddef.h>
#include <vector>
#include <stdio.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

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
public://Time O(N), Space O(lgN)
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode* origHead = head;
        while(head != nullptr)
        {
            ++len;
            head = head->next;
        }
        return getBST(origHead, 0, len-1);
    }

    TreeNode* getBST(ListNode*& head, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        else
        {
            int median = (start+end)/2;
            TreeNode* leftChild = getBST(head, start, median-1);
            //now head has moved to median
            TreeNode* root = new TreeNode(head->val);
            root->left = leftChild;
            head = head->next;//now head move to median+1
            TreeNode* rightChild = getBST(head, median+1, end);
            root->right = rightChild;
            return root;
        }
    }
};

int main()
{
    ListNode head(0);
    Solution test;
    TreeNode* result = test.sortedListToBST(&head);
    printf("%d,", result->val);
}
