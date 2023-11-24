#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
int c,n,w[20],v[20],knapsack[100001],ret; //용량이 k인 배낭으로 이룰 수 있는 최대 가치
int main(){
    // 물건의 무게: 홍보할 때 드는 비용: w[]
    // 물건의 가치: 해당 비용으로 얻을 수 있는 고객의 수: v[]
    // 최대 가치가 c 이상인 최소 k
    fastio;
    cin>>c>>n;
    for(int i(0); i<n; i++){
        cin>>w[i]>>v[i];
    }
    knapsack[0]=0;
    for(int k=1; k<=100000; k++){
        for(int i=0; i<n; i++){
            if(k<w[i]) continue;
            knapsack[k]=max(knapsack[k], knapsack[k-w[i]]+v[i]);
        }
        if(knapsack[k]>=c){
            ret=k;
            break;
        }
    }
    cout<<ret;
}