#include<bits/stdc++.h>

using namespace std;


  void dfs(int val,vector<int> &vis,vector<int> adj[],vector<int>&v)
  {
      v.push_back(val);
      vis[val]=1;
      for(int it:adj[val])
      {
          if(!vis[it])
          {
              dfs(it,vis,adj,v);
          }
      }
  }

  vector<int>dfs_implement(int V,vector<int>adj[])
  {
      vector<int> v;
      vector<int>vis(V+1,0);
      for(int i=1;i<=V;i++)
      {
          if(!vis[i])
          {
              dfs(i,vis,adj,v);
          }
      }
      return v;
  }

void addEdge(vector<int> adj[],int u,int v)
{
   adj[u].push_back(v);
   adj[v].push_back(u);
}

int main()
{
    vector<int> adj[6];
    
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);
    
    vector<int>d = dfs_implement(5,adj);
    
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}
