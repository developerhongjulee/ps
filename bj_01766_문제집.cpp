#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int n,m;
int main(){
    fastio;
    cin>>n>>m;
    vector<vector<int>> adj_list=vector<vector<int>>(n+1,vector<int>());
    vector<int> indegree=vector<int>(n+1,0);
    for(int i(0),a,b; i<m; i++){
        cin>>a>>b;
        adj_list[a].push_back(b);
        indegree[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int v(1); v<=n; v++){
        if(indegree[v]==0) pq.push(v);
    }
    while(!pq.empty()){
        int v=pq.top(); pq.pop();
        cout<<v<<' ';
        for(int u: adj_list[v]){
            if(--indegree[u]==0) pq.push(u);
        }
    }
}