#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *root=NULL;

node *create()
{
	int x;
	node *temp=new node();
	cout<<"Enter the data (Enter -1 for no node):";
	cin>>x;
	if(x==-1)
	{
		return NULL;
	}
	temp->data=x;
	cout<<"Enter left child of "<<x<<":"<<endl;
	temp->left=create();
	
	cout<<"Enter right child of "<<x<<":"<<endl;
	temp->right=create();
	
	return temp;
}

vector<int>v;

bool getpath(node *root,int x)
{
	if(root==NULL)
	{
		return false;
	}
	v.push_back(root->data);
	//if we found the value then we will return T
	if(root->data==x)
	{
		return true;
	}
	//if any of right or left subtree returns T then we will return T
	if(getpath(root->left,x) || getpath(root->right,x))
	{
		return true;
	}
	//if the node is not found and we have to go back to parent subtree then we will return F
	//also remove the current node from vector as that node don't contribute to path
	v.pop_back();
	return false;
}

int main()
{
	root=create();
	int x=7;
	getpath(root,x);
	cout<<"Path from root to node "<<x<<" is:";
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

