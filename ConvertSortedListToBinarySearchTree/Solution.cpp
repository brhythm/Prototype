/*
 * Solution.cpp
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 *
 */

#include <stddef.h>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head != NULL) {
            vector<int> values;
            while (head != NULL) {
                values.push_back(head->val);
                head = head->next;
            }
            return bstHelper(0, values.size(), values);
        } else {
            return NULL;
        }

    }

    /*
     * Construct a bst based on the number from startIndex to endIndx
     * rootIndex is your parent node index
     */
    static TreeNode* bstHelper(int startIndex, int endIndex, vector<int>& num) {
        if (startIndex < endIndex) {
            int median = (startIndex + endIndex) / 2;
            TreeNode *rootPtr = new TreeNode(num[median]);
            //WARNING, learn the trick to handle corner case

            //leftIndex = startIndex + median / 2; accurate or lean on left
            //because '/' always round down
            rootPtr->left = bstHelper(startIndex, median, num);
            //rightIndex = median+1 + endIndex / 2; lean on right or accurate
            //we use + 1 to make it round up
            rootPtr->right = bstHelper(median+1, endIndex, num);
            return rootPtr;
        }
        else
        {
            return NULL;
        }
    }
};

