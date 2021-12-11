#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *head=NULL;

//function to insert node at nth position
void insert(int data,int n)
{
	node *temp1=new node();
	temp1->data=data;
	temp1->link=NULL;
	if(n==1)
	{
		temp1->link=head;
		head=temp1;
		//end the function if we need to insert at beginning only
		return;
	}
	else
	{
		node *temp2=head;
		//starting from 0 index the n-1 is required index to insert
		//thus we will traverse upto n-2 index
		for(int i=0;i<n-2;i++)
		{
			temp1->link=temp2->link;
		}
		//setting link of temp1 (the node to insert) as link to (n-1) index node
		temp1->link=temp2->link;
		//setting link of temp2 (the previous node to the position to insert) to temp1
		temp2->link=temp1;
	}
}

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
	int n,data,pos;
	cout<<"Enter the number of node:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter value:";
		cin>>data;
		cout<<"Enter the position to insert:";
		cin>>pos;
		insert(data,pos);
	}
	print();
}
