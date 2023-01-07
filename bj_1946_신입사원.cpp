#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(0);
using namespace std;
typedef pair<int,int> pii;
#define A first
#define B second
pii rnk[100000];
int T,n, ret;
int main(){
    fastio;
    cin>>T;
    while(T--){
        cin>>n;
        ret=n;
        for(int i=0; i<n; i++){
            cin>>rnk[i].A>>rnk[i].B;
        }
        sort(rnk, rnk+n);
        int localhigh=rnk[0].B;
        for(int i=1; i<n; i++){
            if(localhigh<rnk[i].B) ret--;
            else localhigh = rnk[i].B;
        }
        cout<<"%d\n";
    }
}