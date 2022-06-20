#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
void push(Node** head,int newdata)
{
    Node* newnode=new Node();
    newnode->data=newdata;
    newnode->next=*head;
    *head=newnode;
}

void append(Node** head,int newdata)
{
    Node* newnode=new Node();
    newnode->data=newdata;
    newnode->next=NULL;
    Node* temp=*head;
    if(*head==NULL)
    {
        *head=newnode;
    }
    while(temp!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;

}

void insert_at_pos(Node** head,int newdata,int pos)
{
    Node* newnode=new Node();
    newnode->data=newdata;
    newnode->next=NULL;
    Node* temp=*head;
    Node* prev;
    int i=0;
    while(temp!=NULL && i<pos)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }     
    if(pos==0)
    {
        newnode->next=NULL;
        
        *head=newnode;
    }
    else{
        prev->next=newnode;
        newnode->next=temp;
    }
}
void printlist(Node* node)
{
   while(node!=NULL)
   {
    cout<<node->data;
    node=node->next;
   }
}

int main()
{
   Node* head=NULL;
   append(&head,6);
   push(&head,4);
   push(&head,8);
   insert_at_pos(&head,7,3);
   append(&head,5);
   cout<<"The LinkedList is=";
   printlist(head);
   return 0;
}