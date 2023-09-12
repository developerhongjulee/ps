#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int n,dp[101]; //n번째 전깃줄을 사용할 때 최대 갯수
int main(){
    fastio;
    cin>>n;
    vector<vector<int>> value;
    for(int i=1,idx,v; i<=n; i++){
        cin>>idx>>v;
        value.push_back({idx,v});
    }
    sort(value.begin(),value.end());
    dp[0]=1;
    for(int i=1; i<n; i++){
        int subsol=-1, subsol_idx=-1;
        for(int j=0; j<i; j++){
            if(value[i][1]>value[j][1]&&dp[j]>subsol){
                subsol=dp[j];
                subsol_idx=j;
            }
        }
        dp[i]=dp[subsol_idx]+1;
    }
    cout<<n-*max_element(dp+1, dp+n+1);
}