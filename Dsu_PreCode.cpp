const int N = 2e3+10;
int par[N];

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
