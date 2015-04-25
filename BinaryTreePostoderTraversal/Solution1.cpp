/*
 * Solution.cpp
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 */
#include <vector>
#include <stddef.h>
#include <assert.h>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //Time complexity O(N), Space O(1)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int>  result;
        TreeNode dummy(-1);//This is the trick!!
        dummy.left = root;
        root = &dummy;
        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                //find righest child in my left subtree
                TreeNode* predecessor = root->left;
                while(predecessor->right != nullptr &&
                      predecessor->right != root)
                {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr)
                {
                    //establish the way home
                    predecessor->right = root;
                    root = root->left;
                }
                else
                {
                    predecessor->right = nullptr;
                    printReversePath(root->left, predecessor, result);
                    root = root->right;
                }
            }
            else
            {
                root = root->right;
            }
        }
        return result;
    }

    void printReversePath(TreeNode* source, TreeNode* target, vector<int>& result)
    {//print [ target, ... , source ]
        size_t origSize = result.size();
        for (TreeNode* head=source; head != target->right; head = head->right)
        {
            result.push_back(head->val);
        }
        reverse(result.begin()+origSize, result.end());
   }
};

int main()
{
    TreeNode head(1);
    //TreeNode two(2);
    //head.right = &two;
    Solution test;
    vector<int> result = test.postorderTraversal(&head);
    for(int value: result)
    {
        printf("%d,", value);
    }
    return 0;
}





