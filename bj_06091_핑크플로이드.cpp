#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
typedef vector<int> vi;
int n,p[1025];
int find(int v){
    if(v==p[v]) return v;
    else return p[v]=find(p[v]);
}
bool unite(int v1,int v2){
    v1=find(v1),v2=find(v2);
    if(v1==v2) return false;
    else{
        p[v2]=v1; return true;
    }
}
priority_queue<vi,vector<vi>,function<bool(vi&,vi&)>> pq([](vi& v1,vi& v2)->bool {return v1[2]>v2[2];});
vi adj_list[1025];
int main(){
    fastio;
    cin>>n;
    for(int i(1); i<=n; p[i]=i,i++);
    for(int i(1),dist; i<=n-1; i++){
        for(int j(i+1); j<=n; j++){
            cin>>dist;
            pq.push({i,j,dist});
        }
    }
    while(!pq.empty()){
        auto e=pq.top();pq.pop();
        int v1=e[0],v2=e[1];
        if(unite(v1,v2)){
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
    }
    for(int v(1); v<=n; v++){
        cout<<adj_list[v].size()<<' ';
        sort(adj_list[v].begin(),adj_list[v].end());
        for(int u: adj_list[v]) cout<<u<<' ';
        cout<<'\n';
    }
}