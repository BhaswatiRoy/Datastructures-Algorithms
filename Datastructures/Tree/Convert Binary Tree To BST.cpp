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
node *newroot=NULL;

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

void inorder(node *root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void inorderchange(node *root,vector<int>&v,int &i)
{
    if(root==NULL)
    {
        return;
    }
    inorderchange(root->left,v,i);
    root->data=v[i];
    i++;
    inorderchange(root->right,v,i);
}

node *binarytreetobst(node *root)
{
    int i=0;
    vector<int>v;
    inorder(root,v);
    sort(v.begin(),v.end());
    inorderchange(root,v,i);
    return root;
}

int main()
{
	root=create();
	newroot=binarytreetobst(root);
}


