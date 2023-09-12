vector<vector<int>>allpaths;
vector<int>onepath;
void findpaths(TreeNode* root)
{
        if(root==NULL)
        {
            return;
        }
        onepath.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            allpaths.push_back(onepath);
            onepath.pop_back();
            return;
        }
        findpaths(root->left);
        findpaths(root->right);

        onepath.pop_back();
}
