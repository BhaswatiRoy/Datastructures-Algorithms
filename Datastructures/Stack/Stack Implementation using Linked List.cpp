#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

//initializing a head variable tp and setting it to NULL signifies an empty linked list i.e empty stack
node *tp=NULL;

void push(int x)
{
	node *temp;
	temp=new node();
	temp->data=x;
	//everytime when new data is added top points to that data
	temp->link=tp;
	tp=temp;
}

void pop()
{
	node *temp;
	//if stack is empty
	if(tp==NULL)
	{
		return;
	}
	temp=tp;
	tp=tp->link;
	//deallocate that node
	delete temp;
}

void print()
{
	//temp will start from top pointer tp always
	node *temp=tp;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->link;
	}
	cout<<endl;
}

int main()
{
	push(2);
	push(3);
	push(4);
	push(5);
	cout<<"Stack is:";
	print();
	cout<<"After Popping:";
	pop();
	print();
	push(6);
	cout<<"After Pushing:";
	print();
}
