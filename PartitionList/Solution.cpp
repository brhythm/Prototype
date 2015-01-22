class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* smallerTail = dummy;//last node that is smaller than x
        ListNode* biggerTail = dummy;//last node that is >= x
        for(; head != NULL; head = head->next)
        {
            if (head->val < x ) {
                if (head == smallerTail->next)
                {//no need to move node 'head'
                    smallerTail = head;
                }
                else
                {//insert head after smaller tail
                    biggerTail->next = head->next;
                    
                    head->next = smallerTail->next;
                    smallerTail->next = head;
                    smallerTail = head;
                }
            }
            else
            {//'head' belongs to bigger number section, do nothing
                biggerTail = head;
            }
        }
        
        return dummy->next;
    }
};