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

//function to find height
int findheight(node *root)
{
	node *temp=root;
	int a,b;
	if(root==NULL)
	{
		return -1;
	}
	else
	{
		//height of left subtree
		a=findheight(root->left);
		//height of right subtree
		b=findheight(root->right);
		if(a>b)
		{
			//+1 is for counting root
			return a+1;
		}
		else
		{
			//+1 is for counting root
			return b+1;
		}
	}
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	int h=findheight(root);
	cout<<"Height Of Binary Search Tree is:"<<h<<endl;
}

