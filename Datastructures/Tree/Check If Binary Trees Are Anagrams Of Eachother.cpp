#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/*
If two trees have each levels anagram of each other then the reverse of inorder traversal of one will be equal to inorder traversal of other
*/

struct node
{
	int data;
	node *left;
	node *right;
};

node *root1=NULL;
node *root2=NULL;

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

bool areanagrams(node *root1, node *root2)
{
    vector<int>v1,v2;
    inorder(root1,v1);
    inorder(root2,v2);
    reverse(v1.begin(),v1.end());
    if(v1==v2)
    {
        return true;
    }
    return false;
}

int main()
{
	root1=insert(root1,1);
	root1=insert(root1,3);
	root1=insert(root1,2);
	root1=insert(root1,5);
	root1=insert(root1,4);
	
	root2=insert(root2,1);
	root2=insert(root2,2);
	root2=insert(root2,3);
	root2=insert(root2,4);
	root2=insert(root2,5);
		
	bool ans=areanagrams(root1,root2);
	if(ans==true)
	{
		cout<<"Yes Levels Of Trees Are Anagrams"<<endl;
	}
	else
	{
		cout<<"No Levels Of Trees Are Not Anagrams"<<endl;
	}
}
