/*
 * Merge two sorted linked lists and
 * return it as a new list.
 *
 * The new list should be made by splicing together the nodes of the first two lists.
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
        ListNode(int x)
        :val(x),
         next(NULL)
        {

        }
    };
 public:
    ListNode *mergeTwoLists(ListNode *leftListPtr, ListNode *rightListPtr) {
        ListNode dummyHead(0);
        ListNode* headPtr = &dummyHead;
        while(leftListPtr != NULL && rightListPtr != NULL) {
            if (leftListPtr->val > rightListPtr->val) {
            //right node is smaller, put right,
                headPtr->next = rightListPtr;
                rightListPtr = rightListPtr->next;
            }
            else
            {//left <= right
                headPtr->next = leftListPtr;
                leftListPtr = leftListPtr->next;
            }
            headPtr = headPtr->next;
        }
        if (leftListPtr != NULL)
        {
            headPtr->next = leftListPtr;
        }
        else //(rightListPtr != NULL)
        {
            headPtr->next = rightListPtr;
        }
        return dummyHead.next;

    }
};




