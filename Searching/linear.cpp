#include<bits/stdc++.h>

using namespace std;

int linear(int a[], int n, int key)
{
   for(int i=0; i<n; i++)
   {
       if(a[i]==key)
       {
           return i;
       }
       
   }
   return -1;
   
}
int main()
{
    int n,i;
    cin>>n;

    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;

    int p=linear(a,n,key);
    if(p==-1){
        cout<<"element not Present";
    }
    else{
        cout<<"present at index "<<p<<endl;
    }
    return 0;
}