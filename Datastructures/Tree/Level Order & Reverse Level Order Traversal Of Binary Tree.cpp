//storing level order traversal in vector<vector<int>>
vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>v;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }


//storing level order traversal in vector<int>
vector<int> levelorder(node *root)
{
	if(root==NULL)
	{
		return {};
	}
	//create queue that will store the pointer to node to reach back to the nodes while traversing
	queue<node*>q;
	//to store final ans
	vector<int>level;
	//when we have root node address then we will push that into the queue
	q.push(root);
	while(!q.empty())
	{
		//while there is atleast one node address then we can use the loop
		node *temp=q.front();
		level.push_back(temp->data);
		if(temp->left!=NULL)
		{
			//push left link node in queue
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			//push right link node in queue
			q.push(temp->right);
		}
		//removing used link from front of queue 
		q.pop();
	}
	return level;
}

//reverse level order traversal
vector<int> reverselevelorder(node *root)
{
	if(root==NULL)
	{
		return {};
	}
	//create queue that will store the pointer to node to reach back to the nodes while traversing
	queue<node*>q;
	//to store final ans
	vector<int>revlevel;
	//when we have root node address then we will push that into the queue
	q.push(root);
	while(!q.empty())
	{
		//while there is atleast one node address then we can use the loop
		node *temp=q.front();
		revlevel.push_back(temp->data);
		if(temp->right!=NULL)
		{
			//push right link node in queue
			q.push(temp->right);
		}
		if(temp->left!=NULL)
		{
			//push left link node in queue
			q.push(temp->left);
		}
		//removing used link from front of queue 
		q.pop();
	}
	//reversing in end to get final ans
	reverse(revlevel.begin(),revlevel.end());
	return revlevel;
}

