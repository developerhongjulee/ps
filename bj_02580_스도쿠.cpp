#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int n,board[9][9], visited[3][9][10]; //visited[STR][i][v]: REC/ROW/COL,(i번째 것의),v를 사용했는지
#define REC 0
#define ROW 1
#define COL 2
vector<vector<int>> coord;
bool bt(int k){
    if(k==coord.size()) return true;
    int y=coord[k][0], x=coord[k][1];
    int rec_idx=3*(y/3)+x/3;
    for(int v=1; v<=9; v++){
        if(visited[REC][rec_idx][v] || visited[ROW][y][v] || visited[COL][x][v]) continue;
        visited[REC][rec_idx][v]=visited[ROW][y][v]=visited[COL][x][v]=true;
        board[y][x]=v;
        if(bt(k+1)) return true;
        visited[REC][rec_idx][v]=visited[ROW][y][v]=visited[COL][x][v]=false;
    }
    return false;
}
int main(){
    fastio;
    for(int i=0,v; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>v;
            if(v==0) coord.push_back({i,j});
            else{
                board[i][j]=v;
                int rec_idx=3*(i/3)+j/3;
                visited[REC][rec_idx][v]=visited[ROW][i][v]=visited[COL][j][v]=true;
            }
        }
    }
    bt(0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++) cout<<board[i][j]<<' ';
        cout<<'\n';
    }
}