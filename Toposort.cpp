#include<bits/stdc++.h>

using namespace std;

int main()
{
    int node = 10;
    vector <int> adj[node];
    int edge, indegree[node];
    for(int i=0;i<node;i++)
    {
        indegree[i] = 0;
    }
    cin>>edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    for(int k=0;k<node;k++)
    {
        for(int i=0;i<node;i++)
        {
            if(indegree[i] == 0)
            {
                cout<<i<<" ";
                for(int j=0;j<adj[i].size();j++)
                {
                    int child = adj[i][j];
                    indegree[child]--;
                }
                indegree[i] = -1;
            }
        }
    }

}
