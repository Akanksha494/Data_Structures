#include <bits/stdc++.h>

using namespace std;

int duplicate(vector<int> &v)
{
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second>1)
        return it->first;
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