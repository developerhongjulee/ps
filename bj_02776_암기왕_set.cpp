#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
int T,n,a,m,b,ret;
int main(){
    fastio;
    cin>>T;
    while(T--){
        cin>>n;
        set<int> s;
        for(int i=0; i<n; i++){
            cin>>a;
            s.insert(a);
        }
        cin>>m;
        for(int i=0; i<m; i++){
            ret=0;
            cin>>b;
            if(s.find(b)!=s.end()) ret=1;
            cout<<ret<<'\n';
        }
    }
}