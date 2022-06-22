#include<bits/stdc++.h>

using namespace std;

class Node{
  public:    
  int data;
  Node* next;
};

void push(Node** head,int val)
{
    Node*newnode=new Node();
    newnode->data=val;
    newnode->next=*head;
    *head=newnode;
}

void createCycle(Node** head,int a,int b)
{
    int cnta=0,cntb=0;
    Node* p1=*head;
    Node* p2=*head;
    while(cnta != a || cntb != b)
    {
        if(cnta!=a)
        {
            p1=p1->next;
            cnta++;
        }
        
        if(cntb!=b)
        {
        p2=p2->next;
        cntb++;
        }
    }
    p2->next=p1;
}

bool detect_cycle(Node* head)
{
    Node* fast=head;
    Node* slow=head;
    
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        return true;
    }
    return false;
}

 int main()
 {
     Node* head=NULL;
     push(&head,4);
     push(&head,3);
     push(&head,2);
     push(&head,1);
     createCycle(&head,1,3);
     if(detect_cycle(head)==true)
     {
     cout<<"the cycle is detected";
     }
     else
     {
         cout<<"No";
     }
     return 0;
 }