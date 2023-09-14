#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
int n,m,w[100001];
vector<int> adj_list[100001];
void dfs(int v, int value){
    w[v]+=value;
    for(int u: adj_list[v]) dfs(u, w[v]);
}
int main(){
    fastio;
    cin>>n>>m;
    int p;
    cin>>p;
    for(int v=2; v<=n; v++){
        cin>>p;
        adj_list[p].push_back(v);
    }
    for(int i=0,v,value; i<m; i++){
        cin>>v>>value;
        w[v]+=value;
    }
    dfs(1,0);
    for(int v=1; v<=n; v++) cout<<w[v]<<' ';
}