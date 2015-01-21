/*
 * Solution.cpp
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */
#include <stddef.h>
#include <stdio.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);//WARNING, make dummy node on the stack
        dummy.next = head;

        ListNode* prev = &dummy;
        for (;head != NULL; head=head->next)
        {
            if ( head->next != NULL &&
                 head->next->val != head->val ) {
                prev = head;
                //printf("prev = %d\n", prev->val);
            }
            else
            {
                if ( head->next == NULL)
                {//last node
                    //printf("last node\n");
                    break;
                }
                else
                {//head val == head->next val
                    while(head->next != NULL &&
                            head->val == head->next->val) {
                        head = head->next;
                    }//now head val != head->next val, but head should still be skipped
                    prev->next = head->next;
                }
            }
        }
        prev->next = head;
        return dummy.next;
    }
};


//int main()
//{
//    ListNode a(1);
//    ListNode b(1);
//    a.next = &b;
//
//    Solution test;
//    ListNode* result = test.deleteDuplicates(&a);
//    while (result != NULL){
//        printf("%d,",result->val);
//        result = result->next;
//    }
//}


