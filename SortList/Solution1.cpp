#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    //Time O(N), Space O(lgN)
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        int length =0;
        ListNode* origHead = head;
        while (head != nullptr) {
            ++length;
            head = head->next;
        }
        return sort(&origHead, length);
    }
    
    ListNode* sort(ListNode** head, int length)
    {
        if (length == 1)
        {//terminate
            ListNode* origHead = *head;
            *head = (*head)->next;//move to new node, get through 'no random access' property in list
            origHead->next = nullptr;//prepare for merge
            return origHead;
        }
        else
        {
            ListNode* leftHead = sort(head, length/2);
            ListNode* rightHead= sort(head, length-length/2);
            return merge(leftHead, rightHead);
        }
    }
    
    // assume each list is terminated by null
    // return merged list terminated by null
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummy(-1);
        ListNode* head = &dummy;
        while (left != nullptr || right != nullptr) {
            int leftValue = left == nullptr ? INT_MAX: left->val;
            int rightValue = right == nullptr ? INT_MAX: right->val;
            if (leftValue < rightValue) {
                head->next = left;
                left = left->next;
            }
            else
            {
                head->next = right;
                right = right->next;
            }
            head = head->next;
        }
        return dummy.next;
    }
};


