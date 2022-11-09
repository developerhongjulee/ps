#include<bits/stdc++.h>
using namespace std; 
deque<vector<int>> snake;
int dir=0,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int board[101][101];
tuple<int,char> turn[100];
bool isSnakePart(int y,int x){
	for(auto snakepart:snake){
			if((y==snakepart[0]&&x==snakepart[1])){
				return true;
			}
	}
	return false;
}
int main(){
	int n,k,l,ax,ay,t_input;
	char dir_input;
	scanf("%d",&n);
	scanf("%d",&k);
	while(k--){
		scanf("%d %d",&ay,&ax);
		board[ay][ax]='a';
	}
	scanf("%d",&l);
	for(int i=0; i<l; i++){
		cin>>t_input>>dir_input;
		turn[i]=make_tuple(t_input,dir_input);
	}
	snake.push_back({1,1});//y,x
	int turn_idx=1,turn_time;
	char turn_dir;
	tie(turn_time,turn_dir)=turn[0];
	int t,head_y,head_x;
	for(t=1;;t++){
		head_y=snake.front()[0]+dy[dir];
		head_x=snake.front()[1]+dx[dir];
		if(head_y<1|| head_y>n|| head_x<1|| head_x>n) break;
		if(isSnakePart(head_y,head_x)) break;
		snake.push_front({head_y,head_x});
		if(board[head_y][head_x]=='a') board[head_y][head_x]=0;
		else snake.pop_back();
		if(t==turn_time){
			if(turn_dir=='L')	dir=(dir+3)%4;
			else/*turn_dir=='D'*/dir=(dir+1)%4;
			if(turn_idx<l) tie(turn_time,turn_dir)=turn[turn_idx++];
			else turn_time=10001;
		}
	}
	printf("%d",t);
}
