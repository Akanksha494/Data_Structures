#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head,int val)
{
   Node* newnode=new Node();
   newnode->data=val;
   newnode->next=*head;
   *head=newnode;
}

void intersection(Node* head1,Node* head2,Node* result)
{
   unordered_set<Node*> s;
   while(head1!=NULL)
   {
       s.insert(head1);
       head1=head1->next;
   }
   
   while(head2!=NULL)
   {
       if(s.find(head2)!=s.end())
       {
           push(&result,head2->data);
           head2=head2->next;
       }
   }

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
    Node* result=NULL;
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
    intersection(head1,head2,result);
    
    printlist(result);
    
return 0;

}