#include<bits/stdc++.h>

using namespace std;

int binary(int a[], int n, int key)
{
    int l = 0, mid;
    int h = n-1;
    while(h >= l)
    {
        mid=l + ( h-l ) / 2;

        if(a[mid] == key)
        {
            return mid;
        } 
            
        else if(a[mid] < key)
        {
            l = mid + 1;
        }

        else
        {
            h = mid - 1;
        }
     
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    int key;
    cin >> key;

    int p=binary(a, n, key);
    if(p==-1){
        cout<<"element not present";

    }
    else{
        cout<<"element present at "<<p<<endl;
    }
    return 0;
}