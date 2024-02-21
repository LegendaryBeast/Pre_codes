#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define tri pair<int,pair<int,int>>

const int N=1e3+10;
vector<pair<int,int>>wt[N];
int vis[N];
vector<pair<int,int>>edge;

int prims(int s){
    int sum=0;
    for(int i=0; i<N; i++)vis[i]=0;
    
    priority_queue < tri,vector<tri>,greater<tri>> pq;
    pq.push({0,{s,-1}});
    
    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if(vis[temp.S.F]==1)continue;
        vis[temp.S.F]=1;
        sum += temp.F;
        edge.push_back({temp.S.S,temp.S.F});
        for(auto x : wt[temp.S.F]){
            int c_v = x.F;
            int c_w = x.S;
            if(!vis[c_v])pq.push({c_w,{c_v,temp.S.F}});
        }
    }
    return sum;
}


int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        wt[u].push_back({v,w});
        wt[v].push_back({u,w});
    }
    int i=1;
    int ans=prims(0);
        for(auto x : edge){
            if(x.S!=-1 && x.F!=-1)cout<<"Edge "<<i++<<" = "<<min(x.F,x.S)<<" -> "<<max(x.F,x.S)<<endl;
        }
        cout<<"Weight of MST="<<ans<<endl;
}
