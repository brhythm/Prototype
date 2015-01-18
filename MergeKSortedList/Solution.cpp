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

//use size k heap to get the smallest among the k list
//each round, it takes lgK to heapify
//Time O(lgk *N), space O(k)
class CompareListNode {
public:
    bool operator() (ListNode* n1, ListNode* n2)//returns true if t1 is eailer than t2
    {
        if (n1->val >= n2->val) {
            return true;
        }
        else
        {
            return false;
        }
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(-1);
        ListNode* head = &dummy;
        //Learn how to use custom comparator 
        priority_queue<ListNode*, vector<ListNode*>, CompareListNode> maxHeap;
        for (ListNode* oneNode : lists) {
            if (oneNode != nullptr) {
                //WARNING, must do null check, otherwise runtime error during heapify
                maxHeap.push(oneNode);
            }
        }
        while (!maxHeap.empty()) {
            ListNode* current = maxHeap.top();
            maxHeap.pop();
            if (current->next != nullptr) {
                maxHeap.push(current->next);
            }
            head->next = current;
            head = current;
        }
        return dummy.next;
    }
};

//Yes, we could use merge sort, time complexity O(lgK*N)
//but space complexity is O(N)

//int main()
//{
//    vector<ListNode* > lists;
//    Solution test;
//    ListNode* result = test.mergeKLists(lists);
//    return 0;
//}
