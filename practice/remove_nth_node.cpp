#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* remove_nth_node(Node* head,int n)
{
    Node* temp=head;
    int c=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    temp=head;
    for(int i=1;i<c-n;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
    
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
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    printlist(head);
    remove_nth_node(head,4);
    cout<<endl;
    printlist(head);
    
return 0;

}