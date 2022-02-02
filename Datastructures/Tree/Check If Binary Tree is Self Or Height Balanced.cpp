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

//height fining function with a bit modification
//everytime we are comparing the height of left subtree & right subtree of any node
int heightbalanced(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh=heightbalanced(root->left);
	//if by chance left height gives -1 then return -1 (not balanced so lh==-1)
	if(lh==-1)
	{
		return -1;
	}
	int rh=heightbalanced(root->right);
	//if by chance right height gives -1 then return -1 (not balanced so rh==-1)
	if(rh==-1)
	{
		return -1;
	}
	//at any point if at any node absolute diff between left & right height is >1 then it is not balanced
	//and we don't need to check for others this will return -1 denoting tree is not balanced
	if(abs(lh-rh)>1)
	{
		return -1;
	}
	
	return max(lh,rh)+1;
}

bool isbalanced(node *root)
{
	if(heightbalanced(root)!=-1)
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

