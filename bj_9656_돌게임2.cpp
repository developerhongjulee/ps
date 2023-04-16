#include<iostream>
using namespace std;
int n, dp[1001]; 
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
	dp[1]=dp[3]=true;
	for(int i=4; i<=n; i++) dp[i]=!(dp[i-1] || dp[i-3]);
	cout<<(dp[n]?"CY":"SK");
}
