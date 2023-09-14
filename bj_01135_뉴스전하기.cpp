#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
int n;
vector<int> adj_list[50];
int dfs(int v){ //dfs(v): v의 자식들에게 모두 전파하는 데 걸리는 시간
    if(adj_list[v].empty()) return 0;
    vector<int> dfs_list;
    for(int u: adj_list[v]) dfs_list.push_back(dfs(u));
    sort(dfs_list.begin(),dfs_list.end(), greater<int>());
    for(int i=0; i<dfs_list.size(); i++) dfs_list[i]+=i+1;
    return *max_element(dfs_list.begin(), dfs_list.end());
}
int main(){
    cin>>n;
    int p;
    cin>>p;
    for(int v=1; v<n; v++){
        cin>>p;
        adj_list[p].push_back(v);
    }
    cout<<dfs(0);
}