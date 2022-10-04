/*
Using the vertical line concept - middle col is 0 and col to left is -1 and col to right is +1 and so on
so we need the 1st element from each vertical line for top view
*/

vector<int> topView(Node *root)
{
        vector<int>ans;
        if(root==NULL)
        {
            return {};
        }
        //storing line and node val in map 
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            Node *node=it.first;
            int line=it.second;
            //checking if the node val is 1st one in the line
            if(mp.find(line)==mp.end())
            {
                mp[line]=node->data;
            }
            //for left side we will do line-1
            if(node->left!=NULL)
            {
                q.push({node->left,line-1});
            }
            //for right side we will do line+1
            if(node->right!=NULL)
            {
                q.push({node->right,line+1});
            }
        }
        //now adding the 1st line node vale form map
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }
        return ans;
}
