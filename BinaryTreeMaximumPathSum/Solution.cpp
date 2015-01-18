/*
 * Solution.cpp
 *
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 */

#include <stddef.h>
#include <climits>
using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
//WARNING!the path may start and end at any node in the tree
//what makes a valid path, you can draw it with one line
//for most nodes, you can only select either lefMaxSum or rightMaxSum,
//if you decide to select both, that would be the globalMaxSum,
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int globalMaxSum = INT_MIN;
        maxSum(root, globalMaxSum);
        return globalMaxSum;
    }

    // return value is the maxSum starting from root, which means
    // root node must be included
    // while keep track of globalMaxSum all the time during dfs
    int maxSum(TreeNode* root, int& globalMaxSum) {
        if (root == NULL) {    //leaf node
            return 0;
        } else {
            int sum = root->val;
            int leftMaxSum = maxSum(root->left, globalMaxSum);
            int rightMaxSum = maxSum(root->right, globalMaxSum);

            if (leftMaxSum > 0 && rightMaxSum > 0) { // try to select both and see whether it is larger than globalMaxSum
                int localMax = sum + leftMaxSum + rightMaxSum;
                globalMaxSum = max(localMax, globalMaxSum);
            }
            // not sure about the previous selection result,maybe we didn't select both eventually
            //must check anyway
            int localmax = max(leftMaxSum, rightMaxSum);
            if (localmax > 0) {
                sum += localmax;
            }
            globalMaxSum = max(sum, globalMaxSum);

            return sum;
        }
    }
};

