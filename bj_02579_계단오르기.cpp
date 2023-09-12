#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int n, a[301],dp[301][2]; //i인덱스의 계단, 전계단을 밟음
int main(){
    fastio;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    dp[1][false]=a[1];
    dp[2][false]=a[2];
    dp[2][true]=a[1]+a[2];
    for(int v=3; v<=n; v++){
        dp[v][false]=max(dp[v-2][false], dp[v-2][true])+a[v];
        dp[v][true]=dp[v-1][false]+a[v];
    }
    cout<<*max_element(dp[n], dp[n]+2);
}