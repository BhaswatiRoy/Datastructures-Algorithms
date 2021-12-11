#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *head=NULL;

//function to insert node at beginning 
void insertbeginning(int data)
{
	node *temp=new node();
	temp->data=data;
	//node inserted at beginning points to next node
	temp->link=head;
	//node inserted at beginning will act as head node now
	head=temp;
}

//function to print the finally created linked list
void print()
{
	node *temp=head;
	cout<<"Linked List is:";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}

int main()
{
	int n,data;
	cout<<"Enter the number of node:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter value at "<<(n-i)<<" node:";
		cin>>data;
		insertbeginning(data);
	}
	print();
}
