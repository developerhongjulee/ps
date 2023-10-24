#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
typedef vector<vector<pair<int,int>>> adjlist;
typedef long long ll;
int n;
vector<int> sz;
adjlist adj_list;
ll ret;
ll dfs(int v,int p){ //v에서의 노드수: sz[v], v를 루트로 하는 서브트리에서 v에서의 가중치합: dfsvalue
    ll cost_sum=0;
    sz[v]=1;
    for(auto [u,cost]: adj_list[v]){
        if(u==p) continue;
        ll dfsvalue = dfs(u,v);
        sz[v]+=sz[u];
        cost_sum+=dfsvalue+cost*sz[u];
    }
    return cost_sum;
}
void dfs2(int v,int p,ll cost_sum){
    ret=min(ret,cost_sum);
    for(auto [u,cost]: adj_list[v]){
        if(u==p) continue;
        dfs2(u,v,cost_sum+cost*(n-2*sz[u]));
    }
}
int main(){
    fastio;
    while(true){
        cin>>n;
        if(n==0) break;
        sz=vector<int>(n);
        adj_list=adjlist(n);
        ret=LLONG_MAX;
        for(int i(0),a,b,w;i<n-1;i++){
            cin>>a>>b>>w;
            adj_list[a].push_back({b,w});
            adj_list[b].push_back({a,w});
        }
        dfs2(0,-1,dfs(0,-1));
        cout<<ret<<'\n';
    }
}