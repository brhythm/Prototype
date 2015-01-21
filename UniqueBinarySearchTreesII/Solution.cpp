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

 // Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
     //what is time complexity ???

    vector<TreeNode *> generateTrees(int n) {
        return generateSubTree(1, n);
    }

    vector<TreeNode*> generateSubTree(int start, int end)
    {
        vector<TreeNode*> subTreeRoots;
        if (start < end )
        {
            for(int i = start; i <= end ; ++i)
            {
                vector<TreeNode*> leftSubTrees = generateSubTree(start, i-1);
                vector<TreeNode*> rightSubTrees = generateSubTree(i+1, end);
                //note left or right subtree vector would never be empty
                //because NULL pointer would be returned it the subtree is empty
                for(TreeNode* leftChild: leftSubTrees)
                {
                    for(TreeNode* rightChild: rightSubTrees)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = leftChild;
                        root->right = rightChild;
                        subTreeRoots.push_back(root);
                    }
                }
            }
        }
        else if (start == end)
        {
            TreeNode* leafNode = new TreeNode(start);
            subTreeRoots.push_back(leafNode);
        }
        else
        {//start > end , terminate algorithm
            subTreeRoots.push_back(NULL);
        }
        return subTreeRoots;
    }
};
//The trick in this problem is devide the problem into left subtree and right subtree

int main()
{
    Solution test;

//    vector<TreeNode*> result =  test.generateTrees(1);
//    for(auto node: result)
//    {
//
//    }
    return 0;
}


