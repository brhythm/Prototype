#include <stddef.h>
#include <queue>
using namespace std;

class Solution0 {

    struct TreeLinkNode {
        int val;
        TreeLinkNode *left, *right, *next;
    };

public:
	//Recursive solution Time O(N), Space O(lgN)
    void connect(TreeLinkNode *root) {
		if (root == nullptr)
		{
			return;
		}
		//root->next should be processed already
		if (root->left != nullptr)
		{
			root->left->next = root->right;
		}
		if (root->right != nullptr)
		{
			root->right->next = root->next? root->next->left: nullptr;
		}
		connect(root->left);
		connect(root->right);
    }
};

