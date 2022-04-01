#include<bits/stdc++.h>

using namespace std;

void mergesort(int a[], int l, int h)
{
   if( l <= h)
   {
       int mid = ( l + h ) / 2;
       mergesort(a, l, mid);
       mergesort(a, mid+1, h);
       merge(a, l, mid, h);
   }
}

void merge(int a[], int l, int mid, int h)
{
    int i=l, j=mid+1, k =l;
    int temp[10];

    while(i <= mid && j <= h)
    {
        if(a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    if(i > mid)
    {
        while(j <= h)
        {
           temp[k] = a[j];
           k++;
           j++;

        }
    }
    else
    {
        while(i <= mid)
        {
            temp[k] = a[i];
            k++;
            i++;
        }
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

    mergesort(a,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
