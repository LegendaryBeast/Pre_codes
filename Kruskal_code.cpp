#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define tri pair<int,pair<int,int>>

const int N = 2e3+10;
int par[N];
vector <pair<int,int>> ans_list;

void make(int v){
    par[v]=v;
}

int find(int v){
    if(par[v]==v)return v;
    else return par[v] = find(par[v]);
}

void Union(int u, int v){
    u=find(u);
    v=find(v);
    if(u != v){
        par[v] = u;
    }
}

int kruskal(vector<pair<int,pair<int,int>>>list){
    int mst_weight=0;
    ans_list.clear();
    sort(list.begin(),list.end());
    
    for(int i=0; i<N; i++){
        make(i);
    }
    for(int i=0; i<list.size(); i++){
        int u = list[i].S.F;
        int v = list[i].S.S;
        int w = list[i].F;
        if(find(u) == find(v))continue;
        Union(u,v);
        mst_weight += w;
        ans_list.push_back({min(u,v),max(u,v)});
    }
    
    return mst_weight;
}


int main()
{
    int n,e;
    cin>>n>>e;
    vector <pair<int,pair<int,int>>> list;
    for(int i=1; i<=e ; i++){
        int u, v, w;
        cin >> u >> v >> w;
        list.push_back({w,{u,v}});
    }
    
    cout << "MST Weight = " << kruskal(list) << endl;
    for(auto x : ans_list)
    {
        cout << "Edge from = " << x.F << " to " << x.S << endl;
    }
}

