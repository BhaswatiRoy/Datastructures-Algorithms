void deleteNode(Node *head, int key)
{
    Node *temp=head;
    Node *prev;
    while(temp->data!=key)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
}

/* Function to reverse the linked list */
void reverse(Node* head)
{
    Node *curr=head;
    Node *prev=NULL;
    Node *nxt=NULL;
    while(curr->next!=head)
    {
        //move next pointer to upcoming node so that we don't lose link to upcoming node
        nxt=curr->next;
        //break the pointer to upcoming node and set it to past node to reverse
        curr->next=prev;
        
        //shift past pointer ahead
        prev=curr;
        //shift current pointer ahead
        curr=nxt;
    }
    //after all iterations curr is pointing to last node so is set to 2nd last node
    curr->next=prev;
    //head is made to point to last node which is curr
    head->next=curr;
}
