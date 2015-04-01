/*
 * Solution.cpp
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode dummy(-1);
        dummy.next = head;
        int num = 0;//number of nodes in list
        while (head != nullptr) {
            head = head->next;
            ++num;
        }
        ListNode* prev = &dummy;
        for (int len = 1; len <= num; len*=2) {
            head = dummy.next;
            prev = &dummy;
            while (head != nullptr) {
                ListNode* leftHead = head;
                int count = len;
                while (count > 0 && head != nullptr) {
                    --count;
                    head = head->next;
                }
                if (head != nullptr)
                {
                    //now head should be rightHead
                    ListNode* rightHead = head;
                    prev->next = merge(leftHead, rightHead, len);
                    count = len*2;
                    while (count >0 && prev != nullptr) {
                        --count;
                        prev = prev->next;
                    }
                    //now prev is the tail of mergd list
                    head = prev == nullptr? nullptr: prev->next;
                }//else head is null, this is unpaired leftList, skip it
            }//we have finish merge in current round
        }
        return dummy.next;
    }

    //TODO simplify the following function !!    
    //merge two sorted list  , given their maxLength
    //warning, either list might have NOT end with NULL, i.e. NO sentinel
    //warning, must NOT change tail->next after merge
    //TODO: try to insert sentinel, see whether it could simplify the problem
    ListNode* merge(ListNode* left, ListNode* right, int maxLength)
    {//leftLength = maxLength, rightLength <= leftLength
        ListNode dummy(-1);
        ListNode* head = &dummy;
        int leftCount = maxLength;
        int rightCount = maxLength;
        ListNode* tailNext = right;
        for (; tailNext != nullptr && rightCount > 0; --rightCount) {
            tailNext = tailNext->next;
        }
        //now tailNext points to rightTail->next;
        rightCount = maxLength;
        while (right != nullptr  /*guard for shorter right list */
               && leftCount >0   /*more left node to merge */
               && rightCount > 0 /*more right node to merge*/) {
            if (right->val < left->val) {
                head->next = right;
                right = right->next;
                --rightCount;
            }
            else
            {
                head->next = left;
                left = left->next;
                --leftCount;
            }
            head = head->next;
        }
        if (leftCount > 0) {
            //more left node to merge
            while (leftCount > 0) {
                head->next = left;
                left = left->next;
                head = head->next;
                --leftCount;
            }
        }
        else
        {   //more right node to merge
            while (right != nullptr &&
                   rightCount > 0) {
                    head->next = right;
                    right = right->next;
                    head = head->next;
                    --rightCount;
            }//else no more right node to merge
        }
        head->next = tailNext;
        return dummy.next;
    }
};
//Note: Bottom-up mergeSort
//You are too concern about unpaired elements, actually they would be paired at some point of time
//maybe in the second roung, maybe in the 4th round, maybe in the last round, don't even worry about it
//
//The real obstacle is how to recognize the tail of left and right list during merge
//The initial though was insert null after tail before merge, but we would have to re-connect every mergedList later
//which requires merge function to not only return the head of mergedList, but also the tail of it. It sounds too much effort
//
//One observation is that the variable length list would always be the right one, and it would end with null, thus it is not a problem
//for each merge, we can assume left length = length, right length <= length
//

int main()
{
    ListNode two(2);
    ListNode three(3);
    ListNode four(4);
    three.next = &two;
    two.next = &four;
    Solution test;
    ListNode* head = test.sortList(&three);
    while (head != nullptr) {
        printf("%d->", head->val);
        head = head->next;
    }
    
}

