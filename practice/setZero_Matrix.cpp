#include<bits/stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();
    vector<int> d1(n,-1),d2(m,-1);
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
          if(mat[i][j]==0)
          {
              d1[i]=0;
              d2[j]=0;
          }
      }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(d1[i]==0 || d2[j]==0)
            {
                mat[i][j]=0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> v;
    v={{1,2,3},{1,0,1},{0,1,1}};
    setZeroes(v);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"/n";
    }
    
}