/*
1. vector of vector for BT
2. vector for BT
3. reverse level order for BT
4. level order for N-ary T
*/

//storing level order traversal in vector<vector<int>> for Binary Tree
vector<vector<int>> levelOrder(TreeNode* root) 
{
        if(root==NULL)
        {
            return {};
        }
        vector<vector<int>>levelordertraversal;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>onelevel;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                onelevel.push_back(node->val);
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            levelordertraversal.push_back(onelevel);
        }
        return levelordertraversal;
}


//storing level order traversal in vector<int> for Binary Tree
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

//reverse level order traversal for Binary Tree
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

//level order traversal of N-ary Tree
vector<vector<int>> levelOrder(Node* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        //vector to store final level wise nodes
        vector<vector<int>>levels;
        queue<Node*>q;
        q.push(root);
        //iterate till queue is empty
        while(!q.empty())
        {
            vector<int>onelevel;
            //find size of queue to find no of nodes in 1 level
            int size=q.size();
            //iterate and push all nodes in one level
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                onelevel.push_back(temp->val);
                vector<Node*>child=temp->children;
                //also store next level nodes for further iterations
                for(int i=0;i<child.size();i++)
                {
                    if(child[i]!=NULL)
                    {
                        q.push(child[i]);
                    }
                }
            }
            //push vector storing nodes of one level in final vector
            levels.push_back(onelevel);
        }
        return levels;
    }
