/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space.
 * You may not modify the values in the list, only nodes itself can be changed.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stddef.h>

class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
 public:
    ListNode *swapPairs(ListNode *current) {
        ListNode dummyHead(0);

        ListNode* dummyHeadPtr = &dummyHead;
        dummyHeadPtr->next = current;

        //WARNING, the trap here is
        // 2->1->4->3
        // you might forget to make 1->4
        ListNode* head2 = dummyHeadPtr;
        while (current != NULL && current->next != NULL)
        {
            head2->next = current->next;
            current->next = head2->next->next;
            head2->next->next = current;

            head2 = current;
            current = current->next;
        }

        return dummyHeadPtr->next;
    }
};



