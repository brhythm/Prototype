/*
 * Solution.cpp
 *
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Follow up:
 * Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {


        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while (fastPtr != nullptr)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
            if (fastPtr != nullptr)
            {
                fastPtr = fastPtr->next;
            }
            if (slowPtr == fastPtr)
            {
                break;
            }
        }
        //printf("fastPtr is NULL? %d\n", fastPtr == nullptr);
        if (fastPtr == nullptr)
        {
            return nullptr;
        }
        //detect cycle
        //let fastPtr walk another x steps, it must stop at the beginning of cycle
        //let slowPtr walk another x steps from head, it must stop at the beginning of cycle
        //when they meet, we know that we have walked x steps
        slowPtr= head;
        while(slowPtr != fastPtr)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        return slowPtr;
    }
};

//
//int main()
//{
//    ListNode firstNode(1);
//   // firstNode.next = &firstNode;
//
//    Solution test;
//    ListNode* result = test.detectCycle(&firstNode);
//
//    if (result != nullptr)
//    {
//        printf("cycle detected\n");
//    }
//    else
//    {
//        printf("no cycle\n");
//    }
//}


