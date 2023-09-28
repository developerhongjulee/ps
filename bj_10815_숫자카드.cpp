#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
int n,a[500000],m;
int main(){
    fastio;
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a, a+n);
    cin>>m;
    for(int i=0; i<m; i++){
        int b, ret=0;
        cin>>b;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(b==a[mid]){
                ret=1;
                break;
            }
            if(b<a[mid]) r=mid-1;
            else l=mid+1;
        }
        cout<<ret<<' ';
    }
}