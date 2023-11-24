#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
const int MAX=30000;
int n,m,K,c[MAX+1],p[MAX+1],weight[MAX+1],value[MAX+1];
vector<int> v,w;
int find(int v){
    if(v==p[v]) return v;
    else return p[v]=find(p[v]);
}
bool unite(int v1,int v2){
    v1=find(v1); v2=find(v2);
    if(v1==v2) return false;
    else{
        p[v2]=v1;
        weight[v1]+=weight[v2];
        value[v1]+=value[v2];
        return true;
    }
}
int main(){
    fastio;
    cin>>n>>m>>K;
    for(int i(1); i<=n; i++){
        p[i]=i;
        cin>>value[i];
    }
    fill_n(weight,MAX+1,1);
    for(int i(0),a,b; i<m; i++){
        cin>>a>>b;
        unite(a,b);
    }
    for(int i(1); i<=n; i++){
        if(i==find(i)){
            v.push_back(value[i]);
            w.push_back(weight[i]);
        }
    }
    //배낭 k로 이룰 수 있는 최대 가치
    vector<vector<int> > dp=vector<vector<int> >(K+1,vector<int>(v.size(),0));
    for(int k(1); k<K; k++){
        for(int j(0); j<v.size(); j++){
            if(w[j]<=k) dp[k][j]=max(dp[k-w[j]][j-1]+v[j],dp[k][j-1]);
            else dp[k][j]=dp[k][j-1];
        }
    }
    for(int k(1); k<K; k++){
        for(int j(0); j<v.size(); j++) {
            cout<<dp[k][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<dp[K-1][v.size()-1];
}