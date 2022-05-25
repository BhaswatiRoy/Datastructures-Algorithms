#include<bits/stdc++.h>
using namespace std;

/*
In sorted linked list we can remove duplicates by iteration as duplicates will be always side by side to eachother
But in unsorted linked list we have to set to keep track as duplicates will always not be side by side
*/

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

node* deleteduplicates(node* head) 
{
    node* temp=head;
    //ListNode* nextl=head->next;
    if(temp==NULL)
    {
        return head;
    }
    while(temp!=NULL && temp->link!=NULL)
    {
        if (temp->data==temp->link->data)
        {
            //if same double iteration
            temp->link=temp->link->link;
        }
        else
        {
            //if not same single iteration
            temp=temp->link;
        }
    }
    return head;
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
	insert(1);
	insert(2);
	insert(3);
	insert(3);
	insert(4);
	insert(5);
	node *temp=head;
	cout<<"Before Duplicates Removal ";
	print();
	head=deleteduplicates(head);
	cout<<"After Duplicates Removal ";
	print();
}
