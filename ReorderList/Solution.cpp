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
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;//prev of slow
        while(fast != nullptr)
        {
            prev= slow;
            fast = fast->next;
            slow = slow->next;
            if (fast != nullptr)
            {
                fast = fast->next;
            }
        }
        //now slow points to beginning of second half list
        //second half <= first half (if it is odd number)
        prev->next = nullptr;

        //reverse second half
        ListNode midHead(-1);//midHead.next = nullptr
        while (slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = midHead.next;
            midHead.next = slow;
            slow = next;
        }
        //merge two lists
        ListNode dummyResult(-1);
        prev = &dummyResult;
        ListNode* first = head;
        ListNode* second = midHead.next;
        while(second != nullptr)
        {
            ListNode *nextFirst = first->next;
            prev->next = first;
            first->next = second;
            prev = second;
            second = second->next;
            first = nextFirst;
        }
        if (first != nullptr) {
            prev->next = first;
        }
        head = dummyResult.next;

    }
};

//Tips: Reverse a linked list is in-place
//Learn the trick to use two ptrs to find the middle of linkedlist


