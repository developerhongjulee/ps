#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define DIST second
using namespace std;
int n,k,dp[100001],d[]={2,-1,1};
void bfs(){
	queue<int> q;
	dp[n]=0;
	q.push(n);
	while(!q.empty()){
		auto cur=q.front();q.pop();
		if(cur==k) return;
		for(int i=0; i<3; i++){
			int nxt, nxttime;
			if(i==0){
				nxt=cur*2;
				nxttime=dp[cur];
			}else{
				nxt=cur+d[i];
				nxttime=dp[cur]+1;
			}
			if(nxt>=0&& nxt<=100000&& dp[nxt]>nxttime){
				dp[nxt]=nxttime;
				q.push(nxt);
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&k);
	fill_n(dp,100001,1e9);
	bfs();
	printf("%d", dp[k]);
}
