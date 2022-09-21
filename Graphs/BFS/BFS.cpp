#include<bits/stdc++.h>

using namespace std;

vector<int> BFS(int V,vector<int> adj[])
{
    vector<int> v;
    vector<int> vis(V+1,0);
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
             int a=q.front();
             q.pop();
             v.push_back(a);
             
             for(auto it:adj[a])
             {
                 if(!vis[it])
                 {
                     q.push(it);
                     vis[it]=1;
                 }
             }
            }
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
    vector<int> adj[5];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 4);
    
    vector<int> d=BFS(5,adj);
    
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    return 0;
}