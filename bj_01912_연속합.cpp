#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int n,dp,ret,maxvalue=-1000;
int main(){
    fastio;
    cin>>n;
    for(int i=0,cur; i<n; i++){
        cin>>cur;
        maxvalue=max(cur,maxvalue);
        dp=max(dp+cur,0);
        ret=max(dp,ret);
    }
    cout<<(ret>0?ret:maxvalue);
}