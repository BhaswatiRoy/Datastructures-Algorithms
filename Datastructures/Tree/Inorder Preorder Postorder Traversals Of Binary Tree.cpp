#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *head;

node *create()
{
	int x;
	node *temp;
	temp=new node();
	cout<<"Enter the data (Enter -1 for no node):";
	cin>>x;
	if(x==-1)
	{
		//exit the function
		return 0;
	}
	temp->data=x;
	cout<<"Enter left child of "<<x<<":"<<endl;
	//recursively call the function to store left child
	//function returns a pointer to left child  to store in parent node left child link
	temp->left=create();
	cout<<"Enter right child of "<<x<<":"<<endl;
	//recursivley call the function to store right child
	//function returns a pointer to right child to store in parent node right child link
	temp->right=create();
	
	return temp;
}

//inorder traversal
void inorder(node *head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		//left root right
		inorder(head->left);
		cout<<head->data<<" ";
		inorder(head->right);
	}
}

//preorder traversal
void preorder(node *head)
{
	if(head==NULL)
	{
		return;
	}
	//root left right
	else
	{
		cout<<head->data<<" ";
		preorder(head->left);
		preorder(head->right);
	}
}

void postorder(node *head)
{
	if(head==NULL)
	{
		return;
	}
	//left right root
	else
	{
		postorder(head->left);
		postorder(head->right);
		cout<<head->data<<" ";
	}
}

int main()
{
	head=create();
	cout<<"Inorder Traversal:";
	inorder(head);
	cout<<endl;
	cout<<"Preorder Traversal:";
	preorder(head);
	cout<<endl;
	cout<<"Postorder Traversal:";
	postorder(head);
	cout<<endl;
}

