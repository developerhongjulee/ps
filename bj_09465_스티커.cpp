#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
const int MAX = 100001;
int T,n;
int main(){
    fastio;
    cin>>T;
    while(T--){
        cin>>n;
        int v[2][MAX], dp[MAX][3]={0};
        for(int i(0); i<2; i++){
            for(int j(1); j<=n; cin>>v[i][j++]);
        }
        for(int i(1); i<=n; i++){
            dp[i][0]=max(dp[i-1][2],dp[i-1][1])+v[0][i];
            dp[i][1]=max(dp[i-1][2],dp[i-1][0])+v[1][i];
            dp[i][2]=max(dp[i-1][0], max(dp[i-1][1],dp[i-1][2]));
        }
        cout<<*max_element(dp[n],dp[n]+3)<<'\n';
    }
}