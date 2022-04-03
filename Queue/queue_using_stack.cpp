#include<bits\stdc++.h>

using namespace std;

class Queue
{
    stack<int> s1,s2;
    public:
    void Enqueue(int x)
    {
        s1.push(x);

    }

    int Dequeue()
    {
        if(s1.empty() && s2.empty())
        {
            cout<<"Queue empty";
        }


        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x=s2.top();
        s2.pop();
        return x;
    }
};

int main()
{
   Queue q;

   q.Enqueue(1);
   q.Enqueue(2);
   q.Enqueue(3);

   cout<<q.Dequeue()<<" ";
   cout<<q.Dequeue()<<" ";
   cout<<q.Dequeue()<<" ";

   return 0; 
}