#include <bits/stdc++.h>
using namespace std;

int main() {
	int V,e;
	cin>>V>>e;
	
	vector<int>adj[V+1];
	for(int i=0;i<e;i++)
	{
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    
	}
	queue<int>q;
	vector<int> indeg(V,0);
	vector<int> ans;
	for(int i=0;i<V;i++)
	{
	    for(auto it:adj[i])
	    indeg[it]++;
	}
	for(int i=0;i<V;i++)
	{
	    if(indeg[i]==0)
	    q.push(i);
	    
	}
	while(!q.empty())
	{
	    int node=q.front();
	    q.pop();
	    ans.push_back(node);
	    for(auto it:adj[node])
	    {indeg[it]--;
	    if(indeg[it]==0)
	    q.push(it);
	        
	    }
	}
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
	return 0;
}