 #include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *head=NULL;

void insertbeginning(int val)
{
	node *temp=new node();
	temp->data=val;
	temp->link=NULL;
	
	if(head==NULL)
	{
		temp->link=temp;
		head=temp;
		return;
	}
	node *temp1=head;
	while(temp1->link!=head)
	{
		temp1=temp1->link;
	}
	temp1->link=temp;
	temp->link=head;
	head=temp;
}

void print()
{
	node *temp=head;
	//when we need to trvaerse and print we will do until we reach to end element 
	//we should not start again from beginning
	cout<<temp->data<<" ";
	temp=temp->link;
	//since the pointer was initially pointing to head so using the while loop condition nothing gets printed
	//thus we are separately printing 1st value and strating iteration 
	while(temp->link!=head)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	//the last node value gets missed on iteration condition so we printed separately
	cout<<temp->data;
	cout<<endl;
}

int main()
{
	insertbeginning(5);
	insertbeginning(4);
	insertbeginning(3);
	insertbeginning(2);
	print();
}
