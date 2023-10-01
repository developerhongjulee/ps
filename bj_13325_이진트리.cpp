#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
typedef pair<int,int> pii;
#define V first
#define COST second
vector<pii> adj_list[2097152];
int k,ret;
int dfs(int v){
    vector<int> dist_list;
    int max_dist=0;
    for(pii& e: adj_list[v]){
        int dist=dfs(e.V)+e.COST;
        max_dist=max(dist,max_dist);
        dist_list.push_back(dist);
    }
    for(int i=0; i<dist_list.size(); i++){
        if(dist_list[i]<max_dist){
            ret+=max_dist-dist_list[i];
        }
    }
    return max_dist;
}
int main(){
    fastio;
    cin>>k;
    int p=pow(2,k)-1;
    for(int v=0,c1,c2; v<p; v++){
        cin>>c1>>c2;
        ret+=c1+c2;
        adj_list[v].push_back({2*v+1,c1});
        adj_list[v].push_back({2*v+2, c2});
    }
    dfs(0);
    cout<<ret;
}