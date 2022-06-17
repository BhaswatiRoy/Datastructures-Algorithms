/*
Segregate Even Odd Linked Lists - group according to value of node
modify the list such that all the even numbers appear before all the odd numbers in the modified list. 
The order of appearance of numbers within each segregation should be same as that in the original list.
*/
class Solution{
public:
    // even -> odd
    Node* divide(int N, Node *head)
    {
       //even & odd are linked lists
       Node *even=NULL;
       Node *odd=NULL;
       //eventemp & oddtemp are node iterators
       Node *eventemp=NULL;
       Node *oddtemp=NULL;
       while(head!=NULL)
       {
           if(head->data%2==0)
           {
               //no node was initially attached to even part so set them to current position of head
               if(even==NULL)
               {
                   even=head;
                   eventemp=head;
               }
               else
               {
                   eventemp->next=head;
                   eventemp=eventemp->next;
               }
           }
           else 
           {
               //no node was initially attached to odd part so set them to current position of head
               if(odd==NULL)
               {
                   odd=head;
                   oddtemp=head;
               }
               else
               {
                   oddtemp->next=head;
                   oddtemp=oddtemp->next;
               }
           }
           head=head->next;
        }
        //if even has elements then we will connect end of even with start of odd
        if(eventemp!=NULL)
        {
            eventemp->next=odd;
        }
        //if odd has elements then we will make it point to NULL marking end of list
        if(oddtemp!=NULL)
        {
            oddtemp->next=NULL;
        }
        //if even part is not null then we will return that
        if(even!=NULL)
        {
            return even;
        }
        //otherwise if no even numbers are present we will return odd
        return odd;
    }
};

/*
Odd Even Linked List - gorup according to index of node
Group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        else if(head->next==NULL)
        {
            return head;
        }
        ListNode* odd=head;
        ListNode* even=head->next;
        //points at node 2
        ListNode* evenstart=head->next;
        while(even!=NULL && even->next!=NULL)
        {
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        //odd last element will now link to even start element so that both odd and even parts get connected
        odd->next=evenstart;
        return head;
    }
};
