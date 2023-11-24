#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
int n,K,w[101],v[101], knapsack[100001][101];
int main(){
    fastio;
    cin>>n>>K;
    for(int j(1); j<=n; j++){
        cin>>w[j]>>v[j];
    }
    for(int j(1); j<=n; j++){
        for(int k(1); k<=K; k++){
            if(w[j]<=k) knapsack[k][j]=max(knapsack[k-w[j]][j-1]+v[j],knapsack[k][j-1]);
            else knapsack[k][j]=knapsack[k][j-1];
        }
    }
    cout<<knapsack[K][n];
}
