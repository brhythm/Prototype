/*
 * Solution.cpp
 *
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */
#include <stddef.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};


//warning, this problem is disgusting
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {

		ListNode* dummyHead = new ListNode(-1);
		dummyHead->next = head;
		ListNode* prev = dummyHead;
		ListNode* prevPrev = NULL;
		for (int i = 1; i < m; head = head->next, ++i) {
			prev = head;
		}

		ListNode* prevToStart = prev;
		prevPrev = prev;
		prev = head;
		head = head->next;
		int i = m + 1;
		while (i <= n) {
			if (prev != NULL) {
				prev->next = prevPrev;
				prevPrev = prev;
				prev = head;
			}
			head = head->next;
			++i;
		}
		prev->next = prevPrev;
		prevToStart->next->next = head;
		prevToStart->next = prev;

		return dummyHead->next;
	}
};

