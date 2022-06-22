#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

int intersection(Node* head1,Node* head2)
{
   int l1=0,l2=0; 
   while(head2!=NULL || head1!=NULL)
   {
       if(head1!=NULL)
       {
           l1++;
           head1=head1->next;
       }
       if(head2!=NULL)
       {
           l2++;
           head2=head2->next;
       }
       
   }
   return abs(l2-l1);
}


void push(Node** head,int val)
{
   Node* newnode=new Node();
   newnode->data=val;
   newnode->next=*head;
   *head=newnode;
}

void printlist(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    Node* head=NULL;
    push(&head,4);
    push(&head,2);
    push(&head,1);
    push(&head,3);
    push(&head,1);
    Node* head1=head;
    head=head->next->next->next;
    Node* headsec;
    push(&headsec,3);
    headsec->next=head;
    Node* head2=headsec;
    //printlist(head2);
    int a=intersection(head1,head2);
    cout<<a;
    //printlist(head);
    
return 0;

}