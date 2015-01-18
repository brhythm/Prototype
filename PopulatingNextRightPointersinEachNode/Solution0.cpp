#include <stddef.h>
#include <queue>
using namespace std;

class Solution0 {

    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
    };

public:
    /**
     * use preorder walk, it is easy to connect all siblings
     * the difficult thing is connecting 4->5, because they are not siblings
     *      0
     *    1   2
     *   3 4 5 6
     *
     *  Ask each node to look at their uncle node, connect to uncle's children
     *  Note that sometimes a node does not have uncle (e.g. node 10),
     *  make my sibling's left child my right child's uncle,
     *   i.e. make 5 to be 10's uncle
     *
     *   Thus only nodes on the right border does not have uncle,
     *   that's why they point to NULL
     *
     *           0
     *    1              2
     *  3   4        5     6
     * 7 8 9 10    11 12 13 14
     *
     */
    void connect(TreeLinkNode *rootPtr) {
        connectHelper(rootPtr, NULL);
    }

    void connectHelper(TreeLinkNode *rootPtr, TreeLinkNode *siblingPtr)
    {
        if (rootPtr!= NULL)
        {
           if(rootPtr->left != NULL) {
                rootPtr->left->next = rootPtr->right;
                connectHelper(rootPtr->left, rootPtr->right);
            }//else left child is null
            if (rootPtr->right != NULL) {
                if (siblingPtr!= NULL) {
                    rootPtr->right->next = siblingPtr->left;
                    //WARNING!!, though my right child does not have sibling,
                    // my sibling's children is also 'sibling' to my right child, and
                    // they shall be connected
                    connectHelper(rootPtr->right, siblingPtr->left);
                }
                else
                {
                    connectHelper(rootPtr->right, NULL);
                }
            }//else right child is null
        }

    }
};

