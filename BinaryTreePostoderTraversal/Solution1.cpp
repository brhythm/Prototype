/*
 * Solution.cpp
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 *
 */
#include <vector>
#include <stack>
#include <stddef.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //Time complexity O(N)
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
        TreeNode* head = reverse(source, target);
        while( head != nullptr && head != origSource)
        {
            result.push_back(head->val);
            head = head->right;
        }
        if (head != nullptr)
        {//head == origSource
            result.push_back(head->val);
        }
        reverse(source, target);
    }

    TreeNode* reverse(TreeNode* source, TreeNode* target)
    {// reverse list, output new list head, new list terminate with null 
        if (source == target)
        {
            return source;
        }
        TreeNode dummy(-1);
        assert(source != nullptr && target != nullptr);
        TreeNode* head = source;
        while ( head != target->right)
        {
            TreeNode* nextHead = head->right;
            TreeNode* nextNode = dummy->right;
            dummy->right = head;
            head->right = nextNode;
            head = nextHead; 
        }
        return dummy.right;
    }
};






