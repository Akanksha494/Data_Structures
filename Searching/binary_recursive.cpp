#include<bits/stdc++.h>

using namespace std;

int binary(int a[], int l, int h, int key)
{  
    int mid;
    while(h >= l)
    {
        mid=l + ( h-l ) / 2;

        if(a[mid] == key)
        {
            return mid;
        } 
            
        else if(a[mid] < key)
        {
          return binary(a, mid+1, h, key); 
        }

        else
        {
            return binary(a, l, mid-1, key);
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

    int p = binary(a, 0, n-1, key);
    if(p == -1){
        cout << "element not present";

    }

    else{
        cout << "element present at " << p << endl;
    }

    return 0;
}