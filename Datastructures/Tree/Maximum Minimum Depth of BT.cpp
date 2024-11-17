/*
Maximum Depth: Both left and right subtree heights are computed then the maximum of both is taken nd +1 done for considering the root 
*/

int depth(TreeNode *root)
{
        if(root==NULL)
        {
            return 0;
        }
        int left=depth(root->left);
        int right=depth(root->right);
        return 1+max(left,right);
}

int maxDepth(TreeNode* root) 
{
        int maxht=depth(root);
        return maxht;
}

/*
Minimum Depth: Both left and right subtree heights are computed. 
Then check if any of the left or right height is 0 then return the other side height +1.
If this is not done then for skewed tree code will give 1 other than the actual height.
Then if none of these conditions match then just measure the minimum of both left & right heights
*/

int depth(TreeNode *root)
{
        if(root==NULL)
        {
            return 0;
        }
        int left=depth(root->left);
        int right=depth(root->right);
        //if the left subtree does not exist then return right+1
        if(left==0)
        {
            return right+1;
        }
        //if the right subtree does not exist then return left+1
        if(right==0)
        {
            return left+1;
        }
        //if the last 2 if conditions are not given then for the skewed tree it will give 1
        //and if none of the last 2 conditions match then just return min of both heights
        return 1+min(left,right);
}

int minDepth(TreeNode* root) 
{
        int minht=depth(root);
        return minht;
}
