#include<bits/stdc++.h>

using namespace std;

int a[100],n=100,rear=-1,front=-1;

void Enqueue(int x)
{
    if(rear>=n-1)
    {
        cout<<"Queue is full";
    }
    
    else if(front=rear=-1)
        {
            rear=0;
            front=0;
            a[rear]=x;
        }
    else
        {
            rear++;
            a[rear]=x;
        }
    
}

void Dequeue()
{
    if(front==-1||front>rear)
    {
        cout<<"Queue is empty";
    }
    else
    {
      cout<<"element is deleted"<<a[front];
      front++;
    }
}

void peek()
{
    if(front==-1)
    {
        cout<<"Queue is empty";
    }
    else
    {
        cout<<a[front];
    }
}

void display()
{
    if(front==-1)
    {
        cout<<"Queue is empty";
    }
    else
    {
        for(int i=front; i<=rear; i++)
        {
            cout<<a[i];
        }
    }
}

int main()
{
    int ch,n;
    int val;

    while(1)
    {
        cout<<" 1-Enqueue \n 2-Dequeue \n 3-peek \n 4-Display \n";

        cout<<"enter your choice\n";
        cin>>ch;

        switch(ch)
        {
            case 1 : cout<<"enter the value";
                     cin>>val;
                     Enqueue(val);
                     break;

           case 2 : Dequeue();
                    break;
                       
           case 3 : peek();
                    break;
            
          case 4 : display();
                   break;

          default: cout<<"Invalid choice";
        }
    }
}