#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
int n,m;
const int INF=987654321;
vector<vector<int>> dist, p;
int main(){
    fastio;
    cin>>n>>m;
    dist.resize(n+1,vector<int>(n+1,INF));
    p.resize(n+1,vector<int>(n+1));
    for(int i(0),v1,v2,cost; i<m; i++){
        cin>>v1>>v2>>cost;
        dist[v1][v2]=dist[v2][v1]=cost;
        p[v1][v2]=v2;
        p[v2][v1]=v1;
    }
    for(int v2(1); v2<=n; v2++){
        for(int v1(1); v1<=n; v1++){
            for(int v3(1); v3<=n; v3++){
                if(dist[v1][v3]>dist[v1][v2]+dist[v2][v3]){
                    dist[v1][v3]=dist[v1][v2]+dist[v2][v3];
                    p[v1][v3]=p[v1][v2];
                }
            }
        }
    }
    for(int v1(1); v1<=n; v1++){
        for(int v2(1); v2<=n; v2++){
            if(v1==v2) cout<<"- ";
            else cout<<p[v1][v2]<<' ';
        }
        cout<<'\n';
    }
}