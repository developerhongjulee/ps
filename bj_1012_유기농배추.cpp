#include<bits/stdc++.h>
int n,m,k,board[50][50], cnt;
const int dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
void dfs(int y,int x){
	board[y][x]=2;
	for(int i=0; i<4; i++){
		int nxtY=y+dy[i], nxtX=x+dx[i];
		if(nxtY<0|| nxtY>=n|| nxtX<0|| nxtX>=m|| board[nxtY][nxtX]!=1) continue;
		dfs(nxtY,nxtX);
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		memset(board,0x00, sizeof(board));
		cnt=0;
		scanf("%d %d %d", &m,&n,&k);
		for(int i=0; i<k; i++){
			int x,y;
			scanf("%d %d", &x,&y);
			board[y][x]=1;
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(board[i][j]==1){
					dfs(i,j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
}
