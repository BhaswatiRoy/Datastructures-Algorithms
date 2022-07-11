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

//Reverse Pre Order Traversal - root, right, left 
//for every level we start viewing from right side and start adding nodes
void rightview(node* root,int level,vector<int>&ans1)
{
    if(root==NULL)
    {
        return;
    }
    //if the level is equal to size of ans vector then we will add that node
    //because in that case we are adding new level nodes from right side 
    if(level==ans1.size())
    {
        ans1.push_back(root->data);
    }
    //right recursion
    rightview(root->right,level+1,ans1);
    //left recursion
    rightview(root->left,level+1,ans1);
}

vector<int> rightsideview(node* root) 
{
    vector<int>ans1;
    rightview(root,0,ans1);
    return ans1;
}

//Pre Order Traversal - root, left, right 
//for every level we start viewing from left side and start adding nodes
void leftview(node* root,int level,vector<int>&ans2)
{
    if(root==NULL)
    {
        return;
    }
    //if the level is equal to size of ans vector then we will add that node
    //because in that case we are adding new level nodes from right side 
    if(level==ans2.size())
    {
        ans2.push_back(root->data);
    }
    //left recursion
    rightview(root->left,level+1,ans2);
    //right recursion
    rightview(root->right,level+1,ans2);
}

vector<int> leftsideview(node* root) 
{
    vector<int>ans2;
    leftview(root,0,ans2);
    return ans2;
}

int main()
{
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	root=insert(root,5);
	vector<int>rightside=rightsideview(root);
	cout<<"Right Side View of BST:";
	for(int i=0;i<rightside.size();i++)
	{
		cout<<rightside[i]<<" ";
	}
	cout<<endl;
	
	cout<<"Left Side View of BST:";
	vector<int>leftside=leftsideview(root);
	for(int j=0;j<leftside.size();j++)
	{
		cout<<leftside[j]<<" ";
	}
	cout<<endl;
}
