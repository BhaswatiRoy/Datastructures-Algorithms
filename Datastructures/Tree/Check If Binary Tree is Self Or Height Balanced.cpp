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

int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh=height(root->left);
	int rh=height(root->right);
	
	//we are taking max of lh and rh and adding 1 for root
	int ht=max(lh,rh)+1;
	
	return ht;
}

bool isbalanced(node *root)
{
	if(root==NULL)
	{
		return true;
	}
	if(isbalanced(root->left)==false)
	{
		return false;
	}
	if(isbalanced(root->right)==false)
	{
		return false;
	}
	//finding height of left subtree
	int lh=height(root->left);
	//finding height of right subtree
	int rh=height(root->right);
	
	//if absolute difference of both heights is less than 1 then it is height balanced tree
	if(abs(lh-rh)<=1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	root=create();
	if(isbalanced(root)==true)
	{
		cout<<"Tree is balanced"<<endl;
	}
	else
	{
		cout<<"Tree is not balanced"<<endl;
	}
}

