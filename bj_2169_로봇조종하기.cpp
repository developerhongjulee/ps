#include<iostream>
using namespace std;
int n,m, board[1000][1000], dp[1000][1000]; 
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin>>n>>m;
	for(int y=0; y<n; y++){
		for(int x=0; x<m; x++) cin>>board[y][x];
	}
	dp[0][0]=board[0][0];
	for(int x=1; x<m; x++) dp[0][x]=board[0][x]+dp[0][x-1];
	
	for(int y=1; y<n; y++){
		int l[1000], r[1000];
		l[0]=dp[y-1][0]+board[y][0], r[m-1]=dp[y-1][m-1]+board[y][m-1]; 
		for(int x=1; x<m; x++){
			l[x]=max(dp[y-1][x], l[x-1])+board[y][x];
		}
		for(int x=m-2; x>=0; x--){
			r[x]=max(dp[y-1][x], r[x+1])+board[y][x];
		}
		for(int x=0; x<m; x++) dp[y][x]=max(l[x], r[x]);
	}
	cout<<dp[n-1][m-1];
}

/*
밑으로 가기: 조건 필요 없다.
왼쪽으로 가기: 왼쪽으로만 가다가 밑으로 내려가야 한다.
오른쪽으로 가기: 오른쪽으로만 가다가 밑으로 내려가야 한다. 
*/

