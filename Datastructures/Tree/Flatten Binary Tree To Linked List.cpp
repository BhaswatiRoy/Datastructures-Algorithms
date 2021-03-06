#include <bits/stdc++.h>
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

//prev stores the last completed node - as soon as left & right traversals of any node is completed it is stored in prev
node* prevnode=NULL;
void flatten(node* root) 
{
    if(root==NULL)
    {
        return;
    }
    //goes to absolute right
    flatten(root->right);
    //then goes to absolute left
    flatten(root->left);
    //set right link of current node to prev completed node
    root->right=prevnode;
    //set left link of current node to NULL as this will be a right skewed tree
    root->left=NULL;
    //update prev as the current completed node
    prevnode=root;
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	flatten(root);
}
