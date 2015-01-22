/**
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
 */

//Recursive approach, easier to implement
#include <stddef.h>
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public://Time O(N) , Space O(M) (M is the number of unique nodes)
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr ||
            head->next == nullptr) {
            //terminate condition
            return head;
        }
        else
        {
            if (head->val == head->next->val) {
                //found duplicate
                while (head->next != nullptr &&
                       head->val == head->next->val) {
                    //remove duplicate
                    ListNode* toRemove = head->next;
                    head->next = toRemove->next;
                    delete toRemove;
                }
                ListNode* newHead = head->next;
                delete head;
                return deleteDuplicates(newHead);
            }
            else
            {//we should keep head
                head->next = deleteDuplicates(head->next);
                return head;
            }
        }
    }
};

