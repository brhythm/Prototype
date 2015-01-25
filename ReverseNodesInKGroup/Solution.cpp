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
    
            if (head == nullptr || k <= 1)
            {
                return head;
            }
            ListNode dummy(-1);
            dummy.next = head;
            ListNode* slow = head;
            ListNode* fast= head;
            ListNode* prev = &dummy;
            
            while( fast != nullptr)
            {
                int index = 0;//warning, bug here when judging whehter k steps are moved
                for (; index < k && fast != nullptr; ++index)
                {
                    fast = fast->next;
                }
                if (index < k)
                {//k group is not found, we have finished the task
                    //do nothing
                    break;
                }
                else
                {
                    //now start insert k nodes after prev
                    ListNode* prevGroupTail = slow;
                    while (slow!= fast) {
                        ListNode* nextNode = slow->next;
                        slow->next = prev->next;
                        prev->next = slow;
                        slow = nextNode;
                    }
                    //now all nodes in K group have been reversed
                    prev = prevGroupTail;
                    prev->next = fast;//WARNING connect two groups, bug here
                    slow = fast;
                }
                
            }
            return dummy.next;
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


