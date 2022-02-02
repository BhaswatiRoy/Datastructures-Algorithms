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

//function to search an element in BST
bool search(node *root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	else if(root->data==data)
	{
		return true;
	}
	//if element to be searched is smaller than current node value then go to left subtree
	else if(data<=root->data)
	{
		search(root->left,data);
	}
	//if element to be searched is greater than current node value then go to right subtree
	else if(data>root->data)
	{
		search(root->right,data);
	}
	return false;
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	int n;
	cout<<"Enter the number to be searched:";
	cin>>n;
	if(search(root,n)==true)
	{
		cout<<"Number Present"<<endl;
	}
	else
	{
		cout<<"Number Absent"<<endl;
	}
}

