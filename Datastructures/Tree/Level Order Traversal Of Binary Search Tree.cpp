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

//level order traversal
void levelorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	//create queue that will store the pointer to node to reach back to the nodes while traversing
	queue<node*>q;
	//when we have root node address then we will push that into the queue
	q.push(root);
	while(!q.empty())
	{
		//while there is atleast one node address then we can use the loop
		node *temp=q.front();
		cout<<temp->data<<" ";
		if(temp->left!=NULL)
		{
			//push left link node in queue
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			//push right link node in queue
			q.push(temp->right);
		}
		//removing used link from front of queue 
		q.pop();
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
	cout<<"Level Order Traversal:";
	levelorder(root);
}

