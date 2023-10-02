#include<bits/stdc++.h>
using namespace std;
#define MIN -10001
#define fastio ios::sync_with_stdio(false),cin.tie(0)
vector<int> adj_list[200001];
int n,score[200001], dp[200001][2];
int dfs(int v,bool flag){
    if(dp[v][flag]!=MIN) return dp[v][flag];
    if(flag) dp[v][flag]=score[v];
    else dp[v][flag]=0;
    for(int u: adj_list[v]){
        if(flag) dp[v][true]+=dfs(u,false);
        else dp[v][false]+=max(dfs(u,true), dfs(u,false));
    }
    return dp[v][flag];
}
void trace(int v,bool flag, vector<int>& ret){
    if(flag) ret.push_back(v);
    for(int u: adj_list[v]){
        if(flag) trace(u,false,ret);
        else dp[u][true]>dp[u][false]?trace(u,true,ret):trace(u,false,ret);
    }
}
int main(){
    fastio;
    cin>>n;
    for(int v(1); v<=n; cin>>score[v++]);
    fill_n(&dp[0][0], 2*(n+1), MIN);
    for(int v(2),p; v<=n; v++) cin>>p,adj_list[p].push_back(v);

    cout<<dfs(1,true)<<' '<<dfs(1,false)<<'\n';
    vector<int> trace1,trace2;
    trace(1,true, trace1);
    trace(1,false,trace2);

    sort(trace1.begin(),trace1.end());
    sort(trace2.begin(),trace2.end());
    for(int v: trace1) cout<<v<<' '; cout<<"-1\n";
    for(int v: trace2) cout<<v<<' '; cout<<"-1";
}