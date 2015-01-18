/*
 * Solution.cpp
 *
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#include <stddef.h>
#include <vector>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

using namespace std;
class Solution {
public:
	//warning, read the question again, understand what is reversed
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

		ListNode* dummyHead = new ListNode(-1);
		ListNode* resultTail = dummyHead;
		int carry = 0;
		while (l1 != NULL || l2 != NULL) {
			int ai = l1 !=NULL ? l1->val:0;
			int bi = l2 != NULL ? l2->val:0;
			int sum = ai + bi + carry;
			int currentDigit = sum % 10;
			carry = sum / 10;
			ListNode* node = new ListNode(currentDigit);
			resultTail->next = node;
			resultTail = node;

			if (l1!=NULL) {
				l1 = l1->next;
			}
			if (l2 != NULL) {
				l2 = l2->next;
			}
		}

		if (carry == 1) {
			ListNode* node = new ListNode(1);
			resultTail->next = node;
			resultTail = node;
		}
		return dummyHead->next;
	}
};

