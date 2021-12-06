#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node *link;
};

int main()
{
	//pointer to node storing NULL value
	node *p=NULL;
	
	//pointer to newly created node
	node *temp=new node();
	
	//assigning value 4 to data stored in linked list
	temp->data=4;
	
	//linking to null value as this is the first and last node
	temp->link=NULL;
	
	p=temp;
	cout<<p->data<<endl;
}
