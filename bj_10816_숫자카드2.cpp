#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
vector<int> a;
int n,m;
int bsearch_l(int x){
    int l=0,r=n,mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(a[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l;
}
int bsearch_r(int x){
    int l=0, r=n,mid;
    while(l<r){
        mid=l+(r-l)/2;
        if(a[mid]>x) r=mid;
        else l=mid+1;
    }
    return l;
}
int main(){
    fastio;
    cin>>n;
    a.resize(n);
    for(int i(0); i<n; cin>>a[i++]);
    sort(a.begin(),a.end());
    cin>>m;
    while(m--){
        int x;
        cin>>x;
        cout<<bsearch_r(x)-bsearch_l(x)<<' ';
    }
}