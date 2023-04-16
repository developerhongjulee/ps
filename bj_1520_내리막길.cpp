#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define Y first
#define X second
int m,n,board[501][501], visited[501][501], dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
int dfs(int y,int x){
	if(visited[y][x]>-1) return visited[y][x];
	visited[y][x]=0;
	for(int i=0; i<4; i++){
		int prevY=y+dy[i], prevX=x+dx[i];
		if(prevY<1|| prevY>m|| prevX<1|| prevX>n||
			!(board[prevY][prevX]>board[y][x])) continue;
		visited[y][x]+=dfs(prevY,prevX);
	}
	return visited[y][x];
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin>>m>>n;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++) cin>>board[i][j];
	}
	fill(&visited[1][1], &visited[m][n+1], -1);
	visited[1][1]=1; 
	cout<<dfs(m,n);
}
