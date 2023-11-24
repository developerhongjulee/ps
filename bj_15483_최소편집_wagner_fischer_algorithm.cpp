#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
string s1,s2;
int dp[1001][1001];
int min(int a,int b,int c){
    return min(a,min(b,c));
}
int diff(int i,int j){
    return s1[i]==s2[j]?0:1;
}
int main(){
    fastio;
    cin>>s1>>s2;
    int n=s1.size(), m=s2.size();
    s1=' '+s1;
    s2=' '+s2;
    cout<<s1<<'\n'<<s2<<'\n';
    for(int i=1; i<=n; i++) dp[i][0]=i;
    for(int j=1; j<=m; j++) dp[0][j]=j;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=min(
                    dp[i-1][j]+1,
                    dp[i][j-1]+1,
                    dp[i-1][j-1]+diff(i,j)
            );
        }
    }
    cout<<dp[n][m];
}
