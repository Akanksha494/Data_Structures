
#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int> &v,vector<int> &sub)
{
    int n=v.size();
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int current=0;
        for(int j=i;j<n;j++)
        {
            current+=v[j];
            if(current>mx)
            {
            mx=current;
            sub.push_back(i);
            sub.push_back(j);
            }
        }
    }
    return mx;
}

int main()
{
  vector<int> v;
  vector<int>sub;
  v={-2,1,-3,4,-1,2,1,-5,4};
  
  int longest=kadane(v,sub);
  cout<<longest<<endl;
  for(int i=sub[0];i<sub[1];i++)
  {
      cout<<v[i]<<" ";
  }
}