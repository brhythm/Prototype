/*
 *
 * Given an array where elements are sorted in ascending order,
 * Given convert it to a height balanced BST.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stddef.h>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        TreeNode(int x) :
                val(x), left(NULL), right(NULL) {
        }
    };
public:
    //Running time O(N), space complex O(N)
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() > 0) {
            return bstHelper(0, num.size(), num);
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

