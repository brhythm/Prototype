/*
 * Solution.cpp
 *
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */

#include <stddef.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Learn this approach, looks like it is not in your mind yet.

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode * result  = head;
        if (head != nullptr)
        {
            // warning!dummy head is really handy!!
            ListNode dummy(-1);
            dummy.next = head;
            ListNode* slowPtr = &dummy;
            ListNode* fastPtr = &dummy;
            //assume n is always valid
            for (int i=0; i <n; ++i )
            {
                fastPtr = fastPtr->next;
            }
            
            while (fastPtr != nullptr && fastPtr->next != nullptr)
            {
                fastPtr = fastPtr->next;
                slowPtr = slowPtr->next;
            }
            //now slowPtr->next is the node need to be deleted
            slowPtr->next = slowPtr->next->next;
            result = dummy.next;

        }
        return result;
    }
};


