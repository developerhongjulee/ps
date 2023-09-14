#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
int n, num[10001], dp[10001][2];
vector<int> adj_list[10001];
int dfs(int v, int p, int flag){
    if(dp[v][flag]>=0) return dp[v][flag];
    int sum=0;
    if(flag) sum+=num[v];
    for(int u: adj_list[v]){
        if(u==p) continue;
        if(flag) sum+=dfs(u,v,!flag);
        else sum+=max(dfs(u,v,flag), dfs(u,v,!flag));
    }
    return dp[v][flag]=sum;
}
int main(){
    fastio;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>num[i];
    for(int i=0,v1,v2; i<n-1; i++){
        cin>>v1>>v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    fill_n(&dp[0][0], 10001*2,-1);
    cout<<max(dfs(1,0,true),dfs(1,0,false));
}
