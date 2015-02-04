/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal
 * if they are structurally identical and the nodes have the same value.
 *
 */

#include <stddef.h>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    //Iterative solution 
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
        {
            return true;
        }
        deque<TreeNode*> current;//FIFO
        deque<TreeNode*> next;
        current.push_back(root);
        bool isTreeSymmetric = true;

        while(!current.empty())
        {
            while(!current.empty())
            {
                TreeNode* node = current.front();//everything from queue is not null
                current.pop_front();
                if (node->left != nullptr)
                {
                    next.push_back(node->left);
                }
                if (node->right != nullptr)
                {
                    next.push_back(node->right);
                }
            }
            //finish generating queue for next level
            if (!isLevelSymmetric(next))
            {
                isTreeSymmetric= false;
                break;
            }
            swap(next, current);
        }
        return isTreeSymmetric;
   }

    bool isLevelSymmetric(const deque<TreeNode*>& next)
    {
        int size = next.size();
        if (size == 0)
        {
            return true;
        }
        if (size%2 != 0)
        {
            return false;
        }
        int i = 0;
        int j = size-1;//must be odd number
        while ( i < j)
        {
            if (next[i]->val != next[j]->val)
            {
                return false;
            }
            ++i;
            --j; 
        }
        return true;
    }
};
//Idea: One straightforward way is to level order traverse the tree, and 
//for each level, check whether the nodes in the queues are symmetric or not
//However, queues don't have iterator. We chose to use deque here. Even thought
//we don't need to insert/delete at the end, deque has random access iterator
//(similar interface to vector) and allow us to check symmetric easily
// deque is usually implemented as dynamic array





