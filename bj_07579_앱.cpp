#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
int N,M,v[101],w[101],max_cost_sum;
int f(){
    vector<vector<int> > knapsack=vector<vector<int> >(max_cost_sum+1,vector<int>(N+1,0));
    for(int k(0); k<=max_cost_sum; k++){ //k: 비용의 합, knapsack[k][j]: 1..j까지로 이룰 수 있는 최대 메모리
        for(int j(1); j<=N; j++){
            if(w[j]<=k) knapsack[k][j]=max(knapsack[k-w[j]][j-1]+v[j], knapsack[k][j-1]);
            else knapsack[k][j]=knapsack[k][j-1];
            if(knapsack[k][j]>=M) return k;
        }
    }
}

int main(){
    fastio;
    cin>>N>>M;
    for(int j(1); j<=N; cin>>v[j++]);
    for(int j(1); j<=N; j++){
        cin>>w[j];
        max_cost_sum+=w[j];
    }
    cout<<f();
}
