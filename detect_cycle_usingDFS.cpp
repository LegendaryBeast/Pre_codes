bool dfs(int node,int par,vector<int> adj[],bool vis[])
    {
        vis[node]=true;
        bool loop = false;
        for(auto child : adj[node]){
            if(vis[child]&&child==par)continue;
            if(vis[child])return true;
            loop |= dfs(child,node,adj,vis);
        }
        return loop;
    }
