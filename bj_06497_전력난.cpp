#include<bits/stdc++.h>
using namespace std;
int n,m, p[200000];
int find(int v){
    if(v==p[v]) return v;
    else return p[v]=find(p[v]);
}
bool unite(int a, int b){
    a=find(a), b=find(b);
    if(a==b) return false;
    else{
        p[b]=a; return true;
    }
}
int main(){
    while(true) {
        cin>>m>>n;
        if(m==0&&n==0) break;
        for (int v=0; v<m; v++) p[v]=v;
        vector<vector<int>> edgelist;
        int dist_sum=0;
        for (int i=0; i<n; i++) {
            int v1,v2,dist;
            cin>>v1>>v2>>dist;
            edgelist.push_back({v1,v2,dist});
            dist_sum+=dist;
        }
        sort(edgelist.begin(),edgelist.end(),
             [](vector<int>& v1,vector<int>& v2)->bool {return v1[2]<v2[2];});
        int cnt=0, mst_dist=0;
        for(auto& edge: edgelist) {
            if(unite(edge[0], edge[1])) {
                cnt++;
                mst_dist+=edge[2];
            }
            if(cnt==m-1) break;
        }
        cout<<dist_sum-mst_dist<<'\n';
    }
}