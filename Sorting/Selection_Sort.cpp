#include<bits/stdc++.h>

using namespace std;

void selection(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_ind=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[min_ind]>a[j])
            {
                min_ind=j;
            }
        }
        swap(a[min_ind],a[i]);
    }
}

void print(int a[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    selection(a,n);
    print(a,n);

    return 0;
}