/*
 * Solution.cpp
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */
#include <stddef.h>
#include <vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.empty())
        {
            return NULL;
        }
        else
        {
            return generateSubTree(preorder, inorder,
                                   0, inorder.size()-1,
                                   0, inorder.size()-1);
        }
    }

    TreeNode* generateSubTree(vector<int>& preorder, vector<int>& inorder,
                              int pStart, int pEnd,
                              int iStart, int iEnd)
    {
        if (pStart > pEnd)
        {//TODO terminate condition
            return NULL;
        }
        else
        {
            //pStart node is the root of subtree
            int rootValue = preorder[pStart];
            TreeNode* root = new TreeNode(rootValue);
            //find indexOfRoot
            int indexOfRoot = iStart;
            for(int i= iStart; i <=iEnd ; ++i)
            {
                if (inorder[i] == rootValue)
                {//this logic will fail if there is duplicate
                    indexOfRoot = i;
                    break;
                }
            }
            root->left = generateSubTree(preorder, inorder,
                                        pStart+1, pStart + indexOfRoot -iStart,
                                        iStart, indexOfRoot-1);
            //leftEnd = pStart+1 + indexOfRoot-iStart-1 = pStart + indexOfRoot -iStart
            root->right = generateSubTree(preorder, inorder,
                                          pStart+indexOfRoot-iStart+1, pEnd,
                                          indexOfRoot+1, iEnd);
            return root;
        }
    }
};



