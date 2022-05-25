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

node *removeduplicates(node *head) 
{
    int sz=0;
    node *temp=head;
    set<int>st;
    st.insert(temp->data);
    while(temp!=NULL && temp->link!=NULL)
    {
        //check if next element is present or not
        if(st.find(temp->link->data)!=st.end())
        {
            //if present then change the link
            temp->link=temp->link->link;
        }
        else
        {
            st.insert(temp->link->data);
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
	insert(5);
	insert(4);
	insert(3);
	insert(2);
	insert(1);
	insert(3);
	node *temp=head;
	cout<<"Before Duplicates Removal ";
	print();
	head=removeduplicates(head);
	cout<<"After Duplicates Removal ";
	print();
}
