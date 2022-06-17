#include<bits/stdc++.h>

using namespace std;

void solve(int ar[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(ar[i]%2==0)
        {
          ar[i]=1;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    solve(ar,n);
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}