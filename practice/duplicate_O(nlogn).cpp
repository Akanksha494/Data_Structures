#include<bits/stdc++.h>

using namespace std;

int duplicate(vector<int> &v)
{
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==v[i+1])
        {
            return v[i];
        }
    }
}
int main()
{
    vector<int> v;
    v={1,2,3,5,4,2};
    int a=duplicate(v);
    cout<<"the duplicate is="<<a; 
    return 0;
}