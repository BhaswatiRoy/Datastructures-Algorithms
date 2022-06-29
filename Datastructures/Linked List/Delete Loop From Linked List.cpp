void removeLoop(Node* head)
{
        Node* fast=head;
        Node* slow=head;
        while(slow!=NULL && fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        //if low & high are pointing to head then if they keep iterating 1 step it will be e never ending process
        // 1 -> 2 -> 3 -> 4 -> 1 (loop is at head node)
        if(slow==head)
        {
            //in that case iterate fast to node before slow and set that to NULL
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
            fast->next=NULL;
        }
        //if both are not pointing to head then we solve normally
        // 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop is at middle node)
        else if(slow==fast)
        {
            slow=head;
            //now iterate both low & high by 1 steps each until their next node is same
            //the point at which their next node is same is the loop point
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
            //so next node of the node before loop point node is set to NULL
            fast->next=NULL;
        }
}
