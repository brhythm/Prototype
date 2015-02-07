/*
 * Solution.cpp
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

#include <vector>
#include <stddef.h>
#include <algorithm>
 // Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

using namespace std;
 class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty())
        {
            return NULL;
        }
        else
        {
            reverse(postorder.begin(), postorder.end());
            return generateSubTree(postorder, inorder,
                                   0, inorder.size()-1,
                                   0, inorder.size()-1);
        }
    }

    TreeNode* generateSubTree(vector<int>& mirrorPreorder, vector<int>& inorder,
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
            int rootValue = mirrorPreorder[pStart];
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
            root->right = generateSubTree(mirrorPreorder, inorder,
                                        pStart+1, pStart + iEnd-indexOfRoot,
                                        indexOfRoot+1, iEnd);
            //rightend  = pStart+1 + iEnd-indexOfRoot-1 = pStart + iEnd-indexOfroot
            root->left = generateSubTree(mirrorPreorder, inorder,
                                          pStart + iEnd-indexOfRoot+1, pEnd,
                                          iStart, indexOfRoot-1);
            return root;
        }
    }
};




