#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
string s1,s2;
vector<vector<int>> dp;
int n,m;
int main(){
	fastio;
	cin>>s1>>s2;
	n=s1.size();
	m=s2.size();
	s1 = '0'+s1;
	s2 = '0'+s2;
	dp.resize(n+1,vector<int>(m+1,0));
	for(int i(1); i<=n; i++){
		for(int j(1); j<=m; j++){
			dp[i][j]=s1[i]==s2[j]?
				dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<'\n';
	
	string ret="";
	int i=n,j=m;
	while(dp[i][j]>0){
		if(dp[i][j]==dp[i][j-1]) j--;
		else if(dp[i][j]==dp[i-1][j]) i--;
		else if(dp[i][j]==dp[i-1][j-1]+1){
			ret=s1[i]+ret;
			i--;j--;
		}
	}
	cout<<ret;
}
