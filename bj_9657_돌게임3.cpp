#include<iostream>
using namespace std;
int n,dp[1000];
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin>>n;
	dp[2]=true;
	for(int i=5; i<=n; i++) dp[i]=!(dp[i-1] || dp[i-3] || dp[i-4]);
	cout<<(dp[n]?"CY":"SK");
}
