#include<bits/stdc++.h>

using namespace std;
int a[100], n=100, top=-1;

void push(int x)
{
    if(top >= n-1)
    {
        cout << "stack overflow";
    }
    else{    
        top++;
        a[top]=x;
        cout<<x<<"pushed element"<<endl;
    }

}

void pop()
{
    if(top <= -1)
    {
        cout << "stack unerflow";

    }
    else{
        int x = a[top];
        cout << "popped element" << x;
        top--;
    }
}

void peek()
{
    if(top < 0)
    {
        cout << "stack underflow";
    }
    else
    {
        cout << "top element" << a[top];
    }
}

void display()
{
    if(top<0)
    {
            cout << "stack underflow";
    }
    else
    {
        for(int i = top; i >= 0; i--)
        {
            cout<< a[i] <<" ";
        }
    }
}

int main()
{
    int ch;
    int val;
    
    while(1)
    {
      
      cout << "enter choice \n 1-push \n 2-pop \n 3-peek \n 4-display \n";
      cout << "enter your choice";

      cin >> ch;

      switch(ch)
      {
          case 1: cout << "enter the value";
                  cin >> val;
                  push(val);
                  break;

          case 2: pop(); 
                  break;

          case 3: peek();
                   break;

          case 4: display();
                  break;

         default: cout << "Invalid choice";                      
      }


    }

}