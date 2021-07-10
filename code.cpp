#include <bits/stdc++.h>
using namespace std;

void dfs1(int s,vector<int>&vis,vector<int>adj[],vector<int>&storedfs)
{
    storedfs.push_back(s);
    vis[s]=1;
    for(auto it:adj[s])
    {
        if(!vis[it])
        dfs1(it,vis,adj,storedfs);
    }
    
}

vector<int>dfs(int V,vector<int>adj[])
{  vector<int>vis(V+1,0);
   vector<int>storedfs;
    for(int i=1;i<=V;i++)
	{
	    if(!vis[i])
	    dfs1(i,vis,adj,storedfs);
	}
	return storedfs;
}
int main() {
    int V,e;
    cin>>V>>e;
    
    vector<int>adj[V+1] ;
    
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	vector<int>ans=dfs(V, adj);
    for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
    }
	return 0;
}