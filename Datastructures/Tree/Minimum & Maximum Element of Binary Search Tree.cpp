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

//function to fnd minimum element i.e left most and last element of left subtree
int findmin(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	node *temp=root;
	//iterate to leftmost element of left subtree
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}

//function to find maximum element i.e right most and last element of right subtree
int findmax(node *root)
{
	if(root==NULL)
	{
		return -1;
	}
	node *temp=root;
	//iterate to rightmost element of right subtree
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp->data;
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	int min=findmin(root);
	int max=findmax(root);
	cout<<"Minimum element is:"<<min<<endl;
	cout<<"Maximum element is:"<<max<<endl;
	
}

