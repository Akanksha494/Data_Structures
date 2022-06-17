#include<bits/stdc++.h>

using namespace std;


int kadane(vector<int> &v,vector<int> &sub)
{
    int n=v.size();
    int current=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
          current+=v[i];
            if(current>mx)
            {
            mx=current;
            }
            if(current<0)
            {
                current=0;
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
  
}