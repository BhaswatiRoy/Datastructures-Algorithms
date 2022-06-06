//couldn't create codes for making intersections of linked lists
//all codes tested in leetcode platform IDE

/*
brute force - traversing all nodes of 2nd list for all nodes of 1st list 
TC is O(n^2) SC is O(1)
*/
ListNode *getintersectionnodebrute(ListNode *headA, ListNode *headB) 
{
    ListNode* temp1=headA;
    ListNode* temp2=headB;
    //if we put condition temp1->next!=NULL then it will not be executed for linked lists with 1 node
    while(temp1!=NULL)
    {
        //for every node in headA(temp1) we have to check all nodes from starting in headB(temp2)
        temp2=headB;
        while(temp2!=NULL)
        {
            if(temp1==temp2)
            {
                return temp1;
                break;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return NULL;
}

/*
better - traversing and storing all the nodes of 1st list in an unordered map and then travserisng and checking for nods of 2nd list
TC is O(n) SC is O(n)
*/
ListNode *getintersectionnodebetter(ListNode *headA, ListNode *headB) 
{
    ListNode* temp1=headA;
    ListNode* temp2=headB;
    unordered_map<ListNode*,int>mp;
    while(temp1!=NULL)
    {
        mp[temp1]++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(mp.find(temp2)!=mp.end())
        {
            return temp2;
        }
        temp2=temp2->next;
    }
    return NULL;
}

/*
optimal - traversing both linked lists simultaneously and if 1 pointer reaches to end of one list then return to beginning of another list
TC is O(n) SC is O(1)
*/
ListNode *getintersectionnodeoptimal(ListNode *headA, ListNode *headB) 
{
    ListNode* temp1=headA;
    ListNode* temp2=headB;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1==temp2)
        {
            return temp1;
        }
        //if 1st pointer is not null then travrse 
        if(temp1!=NULL)
        {
            temp1=temp1->next;
        }
        //otherwise set it to head and traverse from beginning of 2nd list
        else
        {
            temp1=headB;
        }
        //if 2nd pointer is not null then travrse 
        if(temp2!=NULL)
        {
            temp2=temp2->next;
        }
        //otherwise set it to head and traverse from beginning of 1st list
        else
        {
            temp2=headA;
        }
    }
    return NULL;
}
