#include <bits/stdc++.h>

using namespace std;

vector<int> duplicate_and_missing(vector<int> &v)
{
    vector<int> ar;
    int n=v.size();
    int cnt[n+1]={0};
    for(int i=0;i<v.size();i++)
    {
      cnt[v[i]]++;
      
    }
    for(int i=1;i<=v.size();i++)
    {
      if(cnt[i]==0 || cnt[i]>1)
      {
        ar.push_back(i);
        
      }
    }
    return ar;
}
int main()
{
    vector<int> v;
    v={1,2,5,4,2};
    vector<int> d=duplicate_and_missing(v);
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}