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

int commonancestor(node *root, int p, int q)
{
	if(root==NULL)
	{
		return NULL;
	}
	//if both p & q lies on right
	if(root->data<p && root->data<q)
	{
		//traverse to right
		return commonancestor(root->right,p,q);
	}
	//if both p & q lies on left
	if(root->data>p && root->data>q)
	{
		//traverse to left
		return commonancestor(root->left,p,q);
	}
	//else one lies on left and one lies on right so the root must be the last point of intersection from top and first point of intersection from bottom
	return root->data;
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	int p=10,q=20;
	int temp=commonancestor(root,p,q);
	cout<<"Lowest Common Ancestor:"<<temp<<endl;
}
