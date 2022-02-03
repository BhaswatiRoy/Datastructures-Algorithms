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

//function to create new node
node *create(int data)
{
	node *temp=new node();
	temp->data=data;
	//for new node created both left and right links are set as null
	temp->left=temp->right=NULL;
	return temp;
}

//function to insert new node in BST
node *insert(node *root,int data)
{
	//if tree is empty then we will just create new nodes and insert
	if(root==NULL)
	{
		root=create(data);
	}
	//if data value is less than root then recursively insert to left
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else if(data>=root->data)
	{
		root->right=insert(root->right,data);
	}
	return root;
}

vector<double>v;

vector<double> averageoflevels(node *root)
{
	if(root==NULL)
	{
		return {};
	}
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		double sum=0;
		int size=q.size();
		for(int i=0;i<size;i++)
		{
			node *temp=q.front();
			q.pop();
			sum+=temp->data;
			if(temp->left!=NULL)
			{
				q.push(temp->left);
			}
			if(temp->right!=NULL)
			{
				q.push(temp->right);
			}
		}
		v.push_back(sum/size);
	}
	//cout<<v.size()<<endl;
	return v;
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	cout<<"Average of all Levels are:";
	averageoflevels(root);
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
}

