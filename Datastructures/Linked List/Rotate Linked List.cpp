class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL || k==0)
        {
            return head;
        }
        ListNode* temp=head;
        int sz=1;
        while(temp->next!=NULL)
        {
            sz++;
            temp=temp->next;
        }
        //making a circular linked list
        //1->2->3 will become 1->2->3
        //                    |_____|
        temp->next=head;
        //for all multiples of k the list is same like 1->2 rotated twice becomes 1->2 again
        //if k is 12 and sz is 5 then finding rotated list for k=12 is same for k=2
        k=k%sz;
        //rotating last k nodes we are left with sz-k nodes
        //suppose in prev list k=2 so we need list as 3->2->1
        //so rotating 2,3 we are left with sz-k=3-2=1 node 
        int x=sz-k;
        while(x--)
        {
            //temp was pointing to head now move it to x position from head
            temp=temp->next;
        }
        //that point needs to be set to NULL and head to the next node of temp
        head=temp->next;
        temp->next=NULL;
        
        return head;
    }
};
