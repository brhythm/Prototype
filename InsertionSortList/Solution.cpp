/*
 * Solution.cpp
 *
 * Sort a linked list using insertion sort.
 */
#include <stddef.h>
#include <stdio.h>
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        ListNode* current = &dummy;
        while (head != nullptr) {
            current = &dummy;
            while (current->next != nullptr &&
                   head->val > current->next->val) {
                current = current->next;
            }
            //now current < head < current->next
            //OR if current->next = NULL, it means current < head
            //insert head after current
            ListNode* next = head->next;
            head->next = current->next;
            current->next = head;
            head = next;
        }
        return dummy.next;
    }
};

//int main()
//{
//    ListNode two(2);
//    ListNode one(1);
//    ListNode anotherOne(1);
//    //one.next = &anotherOne;
//    two.next = &one;
//    Solution test;
//    ListNode* result = test.insertionSortList(&two);
//    while (result != nullptr)
//    {
//        printf("%d,", result->val);
//        result = result->next;
//    }
//}


