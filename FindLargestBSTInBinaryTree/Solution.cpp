TreeNode* largestBST(TreeNode* root, int& size, int& max, int& min )
{
    if (root==nullptr)
    {
        size = 0;
        return nullptr;
    }
    else
    {
        int leftSize=0;
        int leftMax = INT_MIN;
        int leftMin = INT_MAX;
        TreeNode* leftBSTRoot = largestBST(root->left, leftsize, leftMax, leftMin);
        int rightSize=0;
        int rightMax = INT_MIN;
        int rightMin = INT_MAX;
        TreeNode* rightBSTRoot = largestBST(root->right, rightsize, rightMax, rightMin);
        if ( leftBSTRoot == root->left && 
            rightBSTRoot == root->right && 
            root->val > leftMax &&
            root->val < rightMin)
        {//root is a valid bst
            size = leftSize+rightSize+1;
            max = max(rightMax, root->value);
            min = min(leftMin, root->value);
            return root;
        }
        //root is not a valid bst
        //do not update max/min                
        size = max(leftSize, rightSize)
        if (leftSize > rightSize)
        {
            return leftBSTRoot;
        }
        else
        {
            return rightBSTRoot;
        }
    }

}

