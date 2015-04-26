/**
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
 */
#include <vector>
#include <stddef.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	public://Time complexity: Catalan number. What the hell is that?
     vector<TreeNode *> generateTrees(int n) {
         return getSubTree(1, n);
     }
     vector<TreeNode*> getSubTree(int start, int end)
     {
         vector<TreeNode*> result;
         if (start <= end)
         {
             for (int i=start; i <= end; ++i)
             {

                 vector<TreeNode*> leftTrees = getSubTree(start,i-1);
                 vector<TreeNode*> rightTrees = getSubTree(i+1, end);
                 for(TreeNode* left : leftTrees)
                 {
                     for (TreeNode* right: rightTrees)
                     {
                         TreeNode* root = new TreeNode(i);
                         root->left = left;
                         root->right = right;
                         result.push_back(root);
                     }
                 }
             }
         }
         else
         {//start > end,
             //WARNING, bug here , must put a null
             result.push_back(nullptr);
         }
         return result;
     }
};

int main()
{
    TreeNode head(1);
    //TreeNode two(2);
    //head.right = &two;
    Solution test;
   return 0;
}





