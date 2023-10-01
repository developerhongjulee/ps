#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
typedef pair<int,int> pii;
#define V first
#define COST second
int T,n,m;
int dfs(int v,int p,vector<vector<pii>>& adj_list){
    int sum=0;
    for(pii& adj: adj_list[v]){
        int u=adj.V;
        if(u==p) continue;
        if(adj_list[u].size()==1 && adj_list[u][0].V==v) sum+=adj.COST;
        else sum+=min(dfs(u,v,adj_list), adj.COST);
    }
    return sum;
}
int main(){
    fastio;
    cin>>T;
    while(T--){
        cin>>n>>m;
        vector<vector<pii>> adj_list=vector<vector<pii>>(n+1,vector<pii>());
        for(int i=0,v1,v2,d; i<m; i++){
            cin>>v1>>v2>>d;
            adj_list[v1].push_back({v2,d});
            adj_list[v2].push_back({v1,d});
        }
        cout<<dfs(1,0,adj_list)<<'\n';
    }
}