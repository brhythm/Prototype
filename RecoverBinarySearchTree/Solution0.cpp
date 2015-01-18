/**
 */
//In order walk with O(1) space complexity
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


#include <stddef.h>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> solution;
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
                    solution.push_back(current->val);
                    current = current->right;
                }
            }
            else
            {//no left child
                solution.push_back(current->val);
                current = current->right;
            }
        }
        return solution;
    }
};

//int main()
//{
//    vector<shared_ptr<TreeNode>> tree;
//    for (int i=0; i < 9; ++i) {
//        shared_ptr<TreeNode> node = make_shared<TreeNode>(i);
//        tree.push_back(node);
//    }
//    tree[5]->left = tree[1].get();
//    tree[5]->right = tree[6].get();
//    tree[1]->left = tree[0].get();
//    tree[1]->right = tree[3].get();
//    tree[3]->left = tree[2].get();
//    tree[3]->right = tree[4].get();
//    tree[6]->right = tree[8].get();
//    tree[8]->left = tree[7].get();
//    
//    Solution1 test;
//    vector<int> solution = test.inorderTraversal(tree[5].get());
//    for (int val : solution ) {
//        printf("%d,", val);
//    }
//    return 0;
//}
//





