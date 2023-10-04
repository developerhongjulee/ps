#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int n;
long a[5000];
int main(){
    fastio;
    cin>>n;
    for(int i(0); i<n; cin>>a[i++]);
    sort(a,a+n);
    long min_value=3000000001;
    int ret_i1,ret_i2,ret_i3;
    for(int i1(0); i1<=n-3; i1++){
        int i2=i1+1, i3=n-1;
        while(i2<i3){
            long value=a[i1]+a[i2]+a[i3];
            if(min_value>abs(value)){
                min_value=abs(value);
                ret_i1=i1;
                ret_i2=i2;
                ret_i3=i3;
                if(min_value==0) break;
            }
            if(value>0) i3--;
            else i2++;
        }
    }
    cout<<a[ret_i1]<<' '<<a[ret_i2]<<' '<<a[ret_i3];
}