#include<bits/stdc++.h>
using namespace std;
int n, ret, visited_x[15], visited_dg_r[29], visited_dg_l[29];
void bt(int k){
    if(k==n) {ret++;return;}
    for(int v=0; v<n; v++){
        if(visited_x[v]||visited_dg_r[k-v+n-1]||visited_dg_l[k+v]) continue;
        visited_x[v]=visited_dg_r[k-v+n-1]=visited_dg_l[k+v]=true;
        bt(k+1);
        visited_x[v]=visited_dg_r[k-v+n-1]=visited_dg_l[k+v]=false;
    }
}
int main(){
    cin>>n;
    bt(0);
    printf("%d", ret);
}