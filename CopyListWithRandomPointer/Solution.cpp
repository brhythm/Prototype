/**
 */

//
//A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.
//

#include "stddef.h"
#include <unordered_map>
#include <cassert>

using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//Time O(N), space O(N)
//Can u do it better ? with no extra space??
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode dummy(-1);
        dummy.next = head;
        
        // map old node its copied node
        unordered_map<RandomListNode*, RandomListNode*> copiedNodeMap;
        RandomListNode* prevCopiedNode = &dummy;
        
        // assume list does not contain cycle
        
        //first iteration
        //create all nodes, add to hash
        //random ptr is NOT deep copied yet
        while (head != nullptr) {
            //fetch or create the copied node of head
            RandomListNode* currentCopiedNode = new RandomListNode(head->label);
            //random ptr just use shallow copy now
            currentCopiedNode->random = head->random;
            copiedNodeMap[head] = currentCopiedNode;
            
            //connect prev->current
            prevCopiedNode->next = currentCopiedNode;
            prevCopiedNode = currentCopiedNode;
    
            head = head->next;
        }
        
        //second iteration, iterate through copied list
        //deep copy random ptr, search in hash
        head = dummy.next;
        while (head != nullptr) {
            if (head->random != nullptr)
            {
                auto nodeIter = copiedNodeMap.find(head->random);
                assert(nodeIter != copiedNodeMap.end());
                head->random = nodeIter->second;
            }
            head = head->next;
        }
        
        return dummy.next;
    }
};

