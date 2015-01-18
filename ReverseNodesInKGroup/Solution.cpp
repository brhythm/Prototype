/**
 */

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// 
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// 
// You may not alter the values in the nodes, only nodes itself may be changed.
// 
// Only constant memory is allowed.
// 
// For example,
// Given this linked list: 1->2->3->4->5
// 
// For k = 2, you should return: 2->1->4->3->5
// 
// For k = 3, you should return: 3->2->1->4->5
//

#include "stddef.h"
#include "stdio.h"

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// Note: for list problem, here is a few tips
// 1) use dummy head
// 2) try to use the original list links 
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
    
        if (k > 1)
        {
            ListNode dummy(-1);
            dummy.next = head;
            ListNode* slowPtr = &dummy;
            ListNode* fastPtr = &dummy;
            
            while( fastPtr->next != nullptr)
            {
                for (int i=0; i < k && fastPtr != nullptr; ++i)
                {
                    fastPtr = fastPtr->next;
                }
                if (fastPtr == nullptr)
                {//k group is not found, we have finished the task
                    //do nothing
                    break;
                }
                
                //now start insert firstslowptr right after fastPtr
                ListNode* firstSlowPtr = slowPtr->next;
                //warning, must connect the next k-group with the previous one
                //bug here
                slowPtr->next = fastPtr;
                slowPtr = firstSlowPtr;
                //printf("1)fast node:%d\n", fastPtr->val);
                //printList(dummy.next, 1);
                
                while (slowPtr != fastPtr) {
                    ListNode* nextSlowPtr = slowPtr->next;
                    slowPtr->next = fastPtr->next;
                    fastPtr->next = slowPtr;
                    slowPtr = nextSlowPtr;
                }
                //now all nodes in K group have been reversed
                fastPtr = firstSlowPtr;
                slowPtr = fastPtr;//warning, bug here. sync slowPtr before moving fastPtr
                //printf("2)fast node:%d\n", fastPtr->val);
                //printList(dummy.next, 2);
                
            }
            head= dummy.next;
            
        }
        
        return head;
    }
    
    void printList (ListNode* head, int debugIndex)
    {
        printf("%d) ", debugIndex);
        while(head != nullptr)
        {
            printf("%d," , head->val);
            head = head->next;
        }
        printf("\n");
    }
};

//int main()
//{
//    ListNode firstNode(1);
//    ListNode secondNode(2);
//    ListNode thirdNode(3);
//    ListNode fourthNode(4);
//    firstNode.next = &secondNode;
//    secondNode.next = &thirdNode;
//    thirdNode.next = &fourthNode;
//    
//    Solution test;
//    ListNode* resultHead = test.reverseKGroup(&firstNode, 2);
//    
//    while(resultHead != nullptr)
//    {
//        printf("%d," , resultHead->val);
//        resultHead = resultHead->next;
//    }
//}
//


