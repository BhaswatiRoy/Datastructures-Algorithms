#include<bits/stdc++.h>
using namespace std;

/*
Floyd's Algorithm/Hare & Tortoise Algorithm= states that we will have 2 pointers(hare/fast & tortoise/slow)
Hare/fast pointer iterates by 2steps and Tortoise/slow pointer iterates by 1 step and if there is a cycle present
then both pointers will definitely meet at some point
*/

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

bool detectcycle()
{
	node *slow=head;
	node *fast=head;
	//fast will always be ahead of slow so we can check condition for fast only
	//if at any point we get NULL then cycle is not present
	while(fast!=NULL && fast->link!=NULL)
	{
		//slow iterates by 1 position
		slow=slow->link;
		//fast iterates by 2 positions
		fast=fast->link->link;
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	insertbeginning(5);
	insertbeginning(4);
	insertbeginning(3);
	insertbeginning(2);
	insertbeginning(1);
	//print();
	if(detectcycle()==true)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}
