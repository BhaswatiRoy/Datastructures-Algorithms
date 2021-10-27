#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *head=NULL;

node *insert(int data)
{
	node *temp;
	temp=new node();
	temp->data=data;
	temp->link=head;
	head=temp;
}

//since head is declared as global variable so we do not need to pass it as parameter
//if we would have declared head as local variable then we would have passes it as parameter
void reverse()
{
	node *current=head;
	//previous is set to null as front of the linked list will point to NULL after reversing
	node *prev=NULL;
	node *next;
	//using loop to iterate through the linked list and reverse link at each node
	while(current!=NULL)
	{
		//storing link of current node to next variable otherwise we can not traverse the linked list
		next=current->link;
		//changing link of current node to previous node address
		current->link=prev;
		//setting value of previous node address as current node address 
		//moving previous to current or iterating ahead
		prev=current;
		//setting value of current node address as next node address so that we can iterate through the linked list 
		//moving current to next or iterating ahead 
		current=next;
	}
	//prev is iterated to last node and head will point to start from end
	head=prev;
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
		cout<<"Enter value at "<<n-i<<" index:";
		cin>>data; 
		insert(data);
	}
	print();
	cout<<endl;
	cout<<"After Reversing ";
	reverse();
	print();
	cout<<endl;
}
