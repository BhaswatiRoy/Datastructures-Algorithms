#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

//provide a range to every node and if the node value is not in that range then not bst
bool isvalidbst(node *root, long minval,long maxval)
{
	if(root==NULL)
	{
		return true;
	}
	//the value should be in range (minval,maxval) both exclusive
	//if not in range then not bst
	if(root->data >= maxval || root->data<=minval)
	{
		return false;
	}
	//for left subtree maxval=root->data and for right subtree minval=root->data
	//if both the left and right subtrees are bsts then return True in end
	return isvalidbst(root->left,minval,root->data) && isvalidbst(root->right,root->data,maxval);
}

int main()
{
	root=create();
	if(isvalidbst(root,INT_MIN,INT_MAX)==true)
	{
		cout<<"Tree is BST"<<endl;
	}
	else
	{
		cout<<"Tree is not BST"<<endl;
	}
}
