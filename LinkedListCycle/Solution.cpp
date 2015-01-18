/*
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stddef.h>

class Solution {
	struct ListNode {
		int val;
		ListNode *next;
	};
	
public:
    bool hasCycle(ListNode *head) {
    	
    	if (head != NULL)
    	{
    		ListNode* fastPtr = head;
    		ListNode* slowPtr = head;
    		bool isCycleDetected = false;
    		fastPtr = fastPtr->next;
    			
    		while(isCycleDetected == false &&
    				fastPtr != NULL ) {
    			//when they meet, at least they are not NULL yet
    			isCycleDetected = (fastPtr == slowPtr);
    			
    			fastPtr = fastPtr->next;
    			if (fastPtr != NULL)
    			{// moves 2 steps
    				fastPtr = fastPtr->next;
    			}//fastPtr reaches null
    			
    			slowPtr = slowPtr->next;
    		}
    		return isCycleDetected;
    	}
    	else
    	{//empty list
    		return false;
    	}
    }
};

