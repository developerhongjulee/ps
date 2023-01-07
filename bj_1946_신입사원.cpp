#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define A first
#define B second
pii score[100000];
int localhigh[100000];
int T,n, ret;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        ret=n;
        for(int i=0; i<n; i++){
            scanf("%d %d", &(score[i].A),&(score[i].B));
        }
        sort(score, score+n, greater<>());
        localhigh[n-1]=score[n-1].B; //localmax[k]: k~n-1범위에서의 최댓값
        for(int i=n-1; i>0; i--){
            localhigh[i-1]=min(localhigh[i], score[i-1].B);
        }
        for(int i=0; i<n-1; i++){
            if(score[i].B>localhigh[i+1]) ret--;
        }
        printf("%d\n", ret);
    }
}