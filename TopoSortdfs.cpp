#include <bits/stdc++.h>
using namespace std;

void findtoposort(int s,stack<int> &st,vector<int> &vis,vector<int>adj[])
{
    vis[s]=1;
    for(auto it:adj[s])
    {
        if(!vis[it])
        {
            findtoposort(it,st,vis,adj);
        }
    }
    st.push(s);
}

vector<int> toposort(int V,vector<int>adj[])
{
    stack<int> st;
    vector<int>ans;
    vector<int> vis(V+1,0);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        findtoposort(i,st,vis,adj);
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


int main() {
    int V,e;
    cin>>V>>e;
    vector<int>adj[V+1];
    vector<int>final;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
       
    }
    final=toposort(V,adj);
    for(int i=0;i<final.size();i++){
        	cout<<final[i]<<" ";
}
}
