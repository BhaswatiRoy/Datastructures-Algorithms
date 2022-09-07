//brute force - if we need to return node value only

//TC=O(n), SC=O(n)
bool getpath(TreeNode* root, vector<int>&path, int x)
    {
        if(root==NULL)
        {
            return false;
        }
        path.push_back(root->val);
        if(root->val==x)
        {
            return true;
        }
        if(getpath(root->left,path,x)==true || getpath(root->right,path,x)==true)
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    int lcabrute(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //finding both paths of root to p & root to q and then comparing if there is a match
        vector<int>path1;
        bool ans1=getpath(root,path1,p->val);
        vector<int>path2;
        bool ans2=getpath(root,path2,q->val);
        int n=path1.size(),m=path2.size();
        int i=0,j=0,match=-1;
        while(i<n && j<m)
        {
            if(path1[i]==path2[j])
            {
                match=path1[i];
            }
            i++;
            j++;
        }
        return match;
    }


TreeNode* lcaoptimized(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        //if we found any of the nodes we will return tht node
        if(root==NULL || root==p || root==q)
        {
            return root;
        }
        //left and right traversals
        TreeNode* left=lcaoptimized(root->left,p,q);
        TreeNode* right=lcaoptimized(root->right,p,q);
        //if left is null then return right
        if(left==NULL && right!=NULL)
        {
            return right;
        }
        //if right is null then return left
        else if(left!=NULL && right==NULL)
        {
            return left;
        }
        //if both are not null so we found the node below which p & q is present
        //this is why from one side p will be returned and from the other side q will be returned
        else if(left!=NULL && right!=NULL)
        {
            return root;
        }
        return NULL;
    }
