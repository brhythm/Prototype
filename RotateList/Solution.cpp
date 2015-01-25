/*
 * Solution.cpp
 *
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 *
 */
//WARNING, must form a cycle, because k might be > n
// fast and slow ptr does not work unless 
#include <stddef.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {

        if (head != NULL) {
            ListNode* originalHead = head;
            int length = 1;
            while (head->next != NULL) {
                head = head->next;
                ++length;
            }
            head->next = originalHead; //now it is a circle

            head = originalHead;
            ListNode* newHead = originalHead;
            int rotate = length - k % length;
            if (rotate != length )
            {
                for (int i = 0; i < rotate - 1; ++i) {
                    head = head->next;
                }
                newHead = head->next;
                head->next = NULL;
            }
            else
            {
                //warning, length -1
                for (int i=0; i < length-1; ++i) {
                    head = head->next;
                }
                head->next = NULL;
            }
            return newHead;
        } else {
            return NULL;
        }

    }
};


