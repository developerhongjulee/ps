#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
string s1,s2;
int n,m,dp[1001][1001];
int min(int a,int b,int c){
    return min(a,min(b,c));
}
int main(){
    fastio;
    cin>>s1>>s2;
    n=s1.size(); m=s2.size();
    s1=' '+s1; s2=' '+s2;
    for(int i(0); i<=n; i++) dp[i][0]=i;
    for(int j(0); j<=m; j++) dp[0][j]=j;
    for(int i(1); i<=n; i++){
        for(int j(1); j<=m; j++){
            if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                );
        }
    }
    cout<<dp[n][m];
}