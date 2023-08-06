#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
typedef vector<vector<int>> matrix;
const int MOD=1000;
matrix operator *(matrix& a, matrix& b){
    int n=a.size();
    matrix ret=matrix(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                ret[i][j]+=a[i][k]*b[k][j];
            }
            ret[i][j]%=MOD;
        }
    }
    return ret;
}
matrix pow(matrix& a, unsigned long long n){
    int m=a.size();
    matrix ret=matrix(m,vector<int>(m));
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
unsigned long long b;
int main(){
    cin>>n>>b;
    matrix mtx;
    for(int i=0; i<n; i++){
        mtx.push_back(vector<int>());
        for(int j=0; j<n; j++){
            int a;
            cin>>a;
            mtx[i].push_back(a);
        }
    }
    matrix ret=pow(mtx, b);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<ret[i][j]<<' ';
        cout<<'\n';
    }
}