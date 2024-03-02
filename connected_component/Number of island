#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
vector <int> adj[N];
int vis[N];

void dfs(int node)
{
	vis[node]=1;
	for(auto child : adj[node]){
		if(!vis[child])dfs(child);
	}
}
int main()
{
	int n,e;
	cin >> n >> e;
	while(e--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int count = 0;
	for(int i=1; i <= n ; i++)
	{
		if(!vis[i])
		{
			count++;
			dfs(i);
		}
	}
	cout<< count << endl;
}
