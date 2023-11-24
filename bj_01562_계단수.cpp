#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
const int MOD=1000000000, q=(1<<10)-1;
int n,dp[101][10][1<<10],ret; //dp[i][j][k]: i: idx, j:num,k:bit
int main(){
    fastio;
    cin>>n;
    for(int k=1; k<=9; k++)
        dp[1][k][1<<k]=1;
    for(int i(2); i<=n; i++){
        for(int j(0); j<=9; j++){
            for(int k(0); k<=q; k++){
                if(j==0)
                    dp[i][0][k|(1<<0)]=(dp[i][0][k|(1<<0)]+dp[i-1][1][k])%MOD;
                else if(j==9)
                    dp[i][9][k|(1<<9)]=(dp[i][9][k|(1<<9)]+dp[i-1][8][k])%MOD;
                else{
                    dp[i][j][k|(1<<j)]=(dp[i][j][k|(1<<j)]+dp[i-1][j-1][k])%MOD;
                    dp[i][j][k|(1<<j)]=(dp[i][j][k|(1<<j)]+dp[i-1][j+1][k])%MOD;
                }
            }
        }
    }
    for(int j(0); j<=9; j++) ret= (ret+dp[n][j][q])%MOD;
    cout<<ret;
}


//https://js1jj2sk3.tistory.com/41