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
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode dummy(-1);
        dummy.next = head;
        while (head->next != nullptr)
        {//head is the tail of sorted list
            ListNode* currentNodeToInsert = head->next;
            ListNode* nextNodeToInsert = head->next->next;
            head->next = nullptr;//disconnect head->next from the sorted list
            //prepare to insert head->next
            ListNode* current = &dummy;
            while(current->next != nullptr &&
                  currentNodeToInsert->val >= current->next->val)
            {
                current = current->next;
            }
            //now currentNodeToInsert  should be inserted after current
            if ( current->next != nullptr )
            {//insertion does not happen at tail
                currentNodeToInsert->next = current->next;
                current->next = currentNodeToInsert;
            }
            else
            {//current->next == nullptr
            //restore currentNodeTOInsert to be head->next
                head->next = currentNodeToInsert;
                head = currentNodeToInsert;//update tail
            }
            head->next = nextNodeToInsert;
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


