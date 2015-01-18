/*
 * Given a sorted linked list,
 * delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
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
    };
public:
    ListNode* deleteDuplicates(ListNode *headPtr) {
        //Running time O(N), space complexity O(1)
        ListNode* originalHeadPtr = headPtr;
        while (headPtr != NULL && headPtr->next != NULL) {
            if (headPtr->next->val == headPtr->val) {
                //next node is redundant
                ListNode* dummyNodePtr = headPtr->next;
                headPtr->next = dummyNodePtr->next;
                delete dummyNodePtr;
                //WARNING, do not move head here, e.g. {1,1,1}
            } else {
                headPtr = headPtr->next;
            }
        }

        return originalHeadPtr;
    }
};

