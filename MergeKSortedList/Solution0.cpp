/**
 */

//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    //Bottom up merge, Time O(NlgK), Space O(1)
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return nullptr;
        }
        vector<ListNode*> next;
        while (lists.size() > 1) {
            int i=0;
            for (i=0; i < lists.size()-1; i += 2) {
                ListNode* newList = merge(lists[i], lists[i+1]);
                next.push_back(newList);
            }
            if (i == lists.size()-1) {
                //solo list that remains
                next.push_back(lists.back());
            }
            lists.clear();
            swap(lists, next);
        }
        return lists[0];
    }
    
    //In-place merge of two lists, time O(n)
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail->next->next = nullptr;
            tail = tail->next;
        }
        if (left != nullptr) {
            //more elements to be merged in left
            tail->next = left;
        }
        if (right != nullptr) {
            //more elements to be merged in right
            tail->next = right;
        }
        return dummy.next;
    }
};


