/*
 * Solution.cpp
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

#include <stddef.h>
#include <algorithm>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {

        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        ListNode* prevPtr = nullptr;
        while(fastPtr != nullptr)
        {
            prevPtr = slowPtr;
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
            if (fastPtr != nullptr)
            {
                fastPtr = fastPtr->next;
            }
        }
        //now slowPtr points to beginning of second half list
        //second half <= first half (if it is odd number)
        prevPtr->next = nullptr;

        //reverse second half
        ListNode* current = slowPtr->next;
        prevPtr = slowPtr;
        prevPtr->next = nullptr;
        while (current != nullptr)
        {//insert current before prev
            ListNode* next = current->next;
            current->next = prevPtr;

            prevPtr = current;
            current = next;
        }
        //now prev is the head of reversed second half

        ListNode* first = head;
        ListNode* second = prevPtr;
        //couple two list
        while(second != nullptr)
        {
            ListNode* nextSecond = second->next;
            ListNode* nextFirst = first->next;
            second->next = first->next;
            first->next = second;

            first = nextFirst;
            second = nextSecond;
        }

    }
};

//Tips: Reverse a linked list is in-place
//Learn the trick to use two ptrs to find the middle of linkedlist


