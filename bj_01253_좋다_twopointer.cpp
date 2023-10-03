#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
int n,ret,a[2000];
int main(){
    fastio;
    cin>>n;
    for(int i(0); i<n; cin>>a[i++]);
    sort(a,a+n);
    for(int k(0); k<n;k++){
        int i1=0,i2=n-1;
        while(i1<i2){
            if(i1==k){
                i1++; continue;
            }
            if(i2==k){
                i2--; continue;
            }
            int value=a[i1]+a[i2];
            if(value==a[k]){
                ret++;break;
            }
            else if(value<a[k]) i1++;
            else i2--;
        }
    }
    cout<<ret;
}