#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
typedef long long ll;
typedef vector<vector<ll>> matrix;
const int MOD = 1000000007;
matrix operator * (matrix &a, matrix &b){
    int n=a.size();
    matrix c(n,vector<ll>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
            c[i][j]%=MOD;
        }
    }
    return c;
}

matrix pow(matrix &a, int n){
    int m=a.size();
    matrix ret=matrix(m,vector<ll>(m));
    for(int i=0; i<m; i++){
        ret[i][i]=1;
    }
    while(n){
        if(n&1) ret=ret*a;
        a=a*a;
        n=n>>1;
    }
    return ret;
}
int n;
matrix a = {
        {0,1,1,0,0,0,0,0},
        {1,0,1,1,0,0,0,0},
        {1,1,0,1,1,0,0,0},
        {0,1,1,0,1,1,0,0},
        {0,0,1,1,0,1,1,0},
        {0,0,0,1,1,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,0,1,1,0}
};
int main(){
    fastio;
    cin>>n;
    matrix ret=pow(a,n);
    cout<<ret[0][0]<<'\n';
}