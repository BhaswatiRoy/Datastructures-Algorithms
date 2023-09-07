// use binary search logic to add mid of every array to the tree
TreeNode* convert(vector<int>&nums, int left, int right)
{
        // if left index crosses right then binary search is over
        if(left>right)
        {
            return NULL;
        }
        // calculate the mid pointer 
        int mid=left+(right-left)/2;
        // add a new node for the mid pointer value
        TreeNode* currnode=new TreeNode(nums[mid]);
        // for left and right subtrees, take left and right portions of array
        // by changing the left and right pointers
        currnode->left=convert(nums, left, mid-1);
        currnode->right=convert(nums, mid+1, right);

        return currnode;
}

TreeNode* sortedArrayToBST(vector<int>& nums) 
{
        int n=nums.size();
        if(n==0)
        {
            return NULL;
        }
        TreeNode* root=convert(nums, 0, n-1);
        return root;
}
