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

int maxval=INT_MIN;

int maxpath(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	//if sum of left/right subtree is -ve then we will not consider that instead we will consider 0
	//considering -ve value nodes will never give us max path sum instead ignoring them will give
	//finding left path sum
	int leftsum=max(0,maxpath(root->left));
	//finding right path sum
	int rightsum=max(0,maxpath(root->right));
	
	//this is an extra parameter used over height function to find max sum value of path which gets stored
	//path sum for any given node is left path sum + right path sum + node value and update max path sum if current path sum is greater
	maxval=max(maxval, (leftsum+rightsum+root->data));
	
	int data=root->data;
	return max(leftsum,rightsum) + data;
}

int maxpathsum(node *root)
{
	maxpath(root);
	return maxval;
}

int main()
{
	root=create();
	int ans=maxpathsum(root);
	cout<<"Max Path Sum of Binary Tree is:"<<ans<<endl;
}

