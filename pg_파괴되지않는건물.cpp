#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>> psum(n+1,vector<int>(m+1));
    
    for(int i=0; i<skill.size(); i++){
        int degree=skill[i][5]*(skill[i][0]==1?-1:1);
        int r1=skill[i][1], c1=skill[i][2],r2=skill[i][3],c2=skill[i][4];
        psum[r1][c1]+=degree;
        psum[r2+1][c1]-=degree;
        psum[r1][c2+1]-=degree;
        psum[r2+1][c2+1]+=degree;
    }
    int memo=0;
    for(int y=0; y<n; y++){
        memo=0;
        for(int x=0; x<m; x++){
            psum[y][x]+=memo;
            memo=psum[y][x];
        }
    }
    for(int x=0; x<m; x++){
        memo=0;
        for(int y=0; y<n; y++){
            psum[y][x]+=memo;
            memo=psum[y][x];
        }
    }
    int ret=0;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(board[y][x]+psum[y][x]>0) ret++;
        }
    }

    return ret;
}
