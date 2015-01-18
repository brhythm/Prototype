/**
 */

//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
//confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//

#include <stddef.h>
#include <algorithm>

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
    void recoverTree(TreeNode *root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (current->left != nullptr) {
                //try to find predecessor (righest node in my left subtree)
                TreeNode* predecessor = current->left;
                while (predecessor ->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = current;// create thread s.t. we can come back later
                    current = current->left;
                }
                else
                {//predecessor->right == current
                    //we have visited that predecessor before, remove thread to restore tree
                    predecessor->right = nullptr;
                    if (prev != nullptr && current->val < prev->val) {
                        if (first == nullptr) {
                            //printf("debug1: %d, %d\n", prev->val, current->val);
                            first = prev;
                        }
                        second = current;
                    }
                    prev = current;
                    current = current->right;
                }
            }
            else
            {//no left child
                if (prev != nullptr && current->val < prev->val) {
                    if (first == nullptr) {
                        //printf("debug2: %d, %d\n", prev->val, current->val);
                        first = prev;
                        
                    }
                    second = current;
                }
                prev = current;
                current = current->right;
            }
        }
        
        if (second != nullptr) {
            //printf("debug swap %d, %d\n", first->val, second->val);
            swap(first->val, second->val);
        }
        
    }
};

//convert tree to threaded binary tree
// create thread to come back to ancestor nodes ( During inorder walk, the biggest concern is how to come back when we dig into subtree)
// THREAD POINTS TO SUCCESSOR, thus to create thread, you must find your predecessor and make yourself its right child
//
// we should restore the tree when the algorithm is done, all threads would be removed when we finish using them
//
//for each node
//if it has left child
//      find the rightest node in its left subtree (predecessor)
//      if ( meet myself when searching for predecessor)
//          predecessor->right = NULL  // we have visited that predecessor before, remove thread to restore tree
//          print current node
//          current = current->right
//      else
//          predecessor->right = current // create thread s.t. we can come back later
//          current = current->left
//else
//      print current node
//      current = current->right
//
//
//int main()
//{
//    TreeNode five(-5);
//    TreeNode two(2);
//    TreeNode zero(0);
//    zero.left = &two;
//    zero.right = &five;
//    Solution test;
//    test.recoverTree(&zero);
//    printf("%d, %d\n", zero.val, zero.left->val);
//    return 0;
//}




