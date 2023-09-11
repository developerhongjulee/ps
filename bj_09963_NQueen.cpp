#include<bits/stdc++.h>
using namespace std;
int n, ret, visited_x[15], visited_dg_r[31], visited_dg_l[31];
void bt(int k){ //한 줄에 하나씩 놓지 않으면 답안됨
    if(k==n) {ret++;return;}
    for(int v=0; v<n; v++){
        if(visited_x[v]||visited_dg_r[k-v+n]||visited_dg_l[k+v]) continue;
        visited_x[v]=visited_dg_r[k-v+n]=visited_dg_l[k+v]=true;
        bt(k+1);
        visited_x[v]=visited_dg_r[k-v+n]=visited_dg_l[k+v]=false;
    }
}
int main(){
    cin>>n;
    bt(0);
    printf("%d", ret);
}