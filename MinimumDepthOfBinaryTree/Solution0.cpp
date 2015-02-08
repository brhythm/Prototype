/*
 * Solution.cpp
 *
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 */

#include <stddef.h>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//Warning, the definition of leaf node is it has no child
//Time O(N), space O(lgN)
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        else
        {
            int depth = 0;
            int min_depth = INT_MAX;
            dfs(root, depth, min_depth);
            return min_depth;
        }
    }
    
    void dfs(TreeNode* root, int& depth, int& min_depth)
    {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            //reach a leaf node, terminate condition
            ++depth;
            min_depth = min(min_depth, depth);
        }
        else
        {//left or right child is not null, not leaf not yet
            int currentDepth = depth+1;
            dfs(root->left, currentDepth, min_depth);
            currentDepth = depth+1;
            dfs(root->right, currentDepth, min_depth);
        }
    }
};

