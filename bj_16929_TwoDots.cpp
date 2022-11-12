#include <iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;
int n,m,visited[50][50], dy[]={1,-1,0,0}, dx[]={0,0,1,-1},flag;
char board[50][50];
void dfs(int y,int x,int py,int px,int cnt){
	visited[y][x]=cnt;
	for(int i=0; i<4; i++){
		int nxtY=y+dy[i], nxtX=x+dx[i];
		if(nxtY<0|| nxtY>=n|| nxtX<0|| nxtX>=m|| board[nxtY][nxtX]!=board[y][x]) continue;
		if(!visited[nxtY][nxtX]) dfs(nxtY,nxtX,y,x,cnt+1);
		else if(!(nxtY==py&& nxtX==px)&& cnt>=4){
			flag=true;
			return;
		}
	}
}
int main() {
	fastio;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin>>board[i][j];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j]){
				dfs(i,j,-1,-1,1);
				if(flag) break;
			}
		}
		if(flag) break;
	}
	printf(flag? "Yes":"No");
}
