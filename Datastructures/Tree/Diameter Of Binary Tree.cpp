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

int maxpath=0;

//this function is same as finding height of a binary tree 
//in finding height function we have heights of both left & right subtree 
int findheight(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh=findheight(root->left);
	int rh=findheight(root->right);
	//maximum path length is maximum of path length and lh+rh value
	//this is an extra parameter used over height function to find max value of path which gets stored
	maxpath=max(maxpath,lh+rh);
	
	//in end we are again returning same value as height function did for the root node considered at any point
	return 1+max(lh,rh);
}

//diameter is the longest path between any 2 nodes (may or may not pass via root)
//using the height function to find the diameter
int finddiameter(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	findheight(root);
	return maxpath;
}

int main()
{
	root=create();
	int dia=finddiameter(root);
	cout<<"Diameter of Binary Tree is:"<<dia<<endl;
}

