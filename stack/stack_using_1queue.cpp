#include<bits\stdc++.h>

using namespace std;

class Stack
{
    queue<int> q1;

    public:
    void push(int x)
    {
       q1.push(x);
       int size = q1.size()-1;

       while(size)
       {
           q1.push(q1.front());
           q1.pop();
       }

       
    }


    int pop()
    {
        int res;

        if(q1.empty())
        {
            res = -1;

        }
        else
        {
            res = q1.front();
            q1.pop();
        }

        return res;

    }
};

int main()
{
    Stack s;

   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);

   cout << s.pop() << " ";
   cout << s.pop() << " ";
   cout << s.pop() << " ";
   cout << s.pop() << " ";

   return 0;

}
