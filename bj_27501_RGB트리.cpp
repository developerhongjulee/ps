#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
#define R 0
#define G 1
#define B 2
vector<int> adj_list[500001];
int n,score[500001][3],dp[500001][3];
char trace[500001], convert[3]={'R','G','B'};
int dfs(int v,int p,int flag){
    if(dp[v][flag]) return dp[v][flag];
    dp[v][flag]=score[v][flag];
    for(int u: adj_list[v]){
        if(u==p) continue;
        dp[v][flag]+=max(dfs(u,v,(flag+1)%3),dfs(u,v,(flag+2)%3));
    }
    return dp[v][flag];
}
void set_trace(int v,int p,int flag){
    trace[v]=convert[flag];
    for(int u: adj_list[v]){
        if(u==p) continue;
        int f1=(flag+1)%3;
        int f2=(flag+2)%3;
        set_trace(u,v,dp[u][f1]>dp[u][f2]?f1:f2);
    }
}
int main(){
    fastio;
    cin>>n;
    for(int i(0),v1,v2; i<n-1; i++){
        cin>>v1>>v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    for(int v(1); v<=n; cin>>score[v][R]>>score[v][G]>>score[v++][B]);
    int ret[3]={dfs(1,0,R),dfs(1,0,G),dfs(1,0,B)};
    auto m =max_element(ret,ret+3);
    cout<<*m<<'\n';
    set_trace(1,0,m-ret);
    for(int v(1); v<=n; cout<<trace[v++]);
}