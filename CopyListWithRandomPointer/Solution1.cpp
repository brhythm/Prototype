/**
 */

//
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.
//

#include "stddef.h"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//In-place solution
//Time O(N), space O(1)
class Solution1 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    
        RandomListNode dummy(-1);
        dummy.next = head;
        
        //first iteration,
        //insert copied node right after each node
        //random ptr is unset
        while (head != nullptr) {
            RandomListNode* copiedNode = new RandomListNode(head->label);
            copiedNode->next = head->next;
            head->next = copiedNode;
            //copiedNode->random is unset now
            
            head = head->next->next;
        }
        
        //second iteration
        //set random ptr
        head = dummy.next;
        while (head != nullptr) {
            //be careful, random might ne null, bug here
            if (head->random != nullptr)
            {
                //this is because we use that magic insertion trick
                //we remember where the copied random node address cos
                //we make it next to the original node
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        
        //third iteration
        //split the two list
        head = dummy.next;
        RandomListNode* newHead = head == nullptr? nullptr: head->next;

        while (head != nullptr) {
            RandomListNode* copiedNode = head->next;
            head->next = head->next->next;
            
            copiedNode->next = (head->next == nullptr) ? nullptr: head->next->next;
            
            head = head->next;
        }
    
        return newHead;
    }
};
