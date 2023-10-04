#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int T,n,k,w;
int main(){
    fastio;
    cin>>T;
    while(T--){
        cin>>n>>k;
        vector<int> indegree=vector<int>(n+1,0);
        vector<int> d=vector<int>(n+1,0);
        vector<vector<int>> adj_list=vector<vector<int>>(n+1,vector<int>());
        vector<vector<int>> adj_list_reverse=vector<vector<int>>(n+1,vector<int>());
        for(int v(1); v<=n; cin>>d[v++]);
        for(int i(0),x,y; i<k; i++){
            cin>>x>>y;
            indegree[y]++;
            adj_list[x].push_back(y);
            adj_list_reverse[y].push_back(x);
        }
        cin>>w;
        queue<int> q;
        for(int v(1); v<=n; v++){
            if(indegree[v]==0) q.push(v);
        }
        vector<int> time=vector<int>(n+1);
        while(!q.empty()){
            int v=q.front();q.pop();
            int tmax=0;
            for(int p: adj_list_reverse[v]) tmax=max(tmax,time[p]);
            time[v]=tmax+d[v];
            if(v==w) break;
            for(int u: adj_list[v]){
                indegree[u]--;
                if(indegree[u]==0) q.push(u);
            }
        }
        cout<<time[w]<<'\n';
    }
}