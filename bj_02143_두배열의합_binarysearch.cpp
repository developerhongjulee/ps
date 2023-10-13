#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false),cin.tie(0)
int32_t T, n,m,psum_a[1001],psum_b[1001];
vector<int32_t> a,b;
map<int64_t,int> numOfX;
int bsearch_l(int64_t x,vector<int32_t>& v){
    int l=0, r=v.size();
    while(l<r){
        int mid=l+(r-l)/2;
        if(v[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l;
}
int bsearch_u(int64_t x,vector<int32_t>& v){
    int l=0, r=v.size();
    while(l<r){
        int mid=l+(r-l)/2;
        if(v[mid]>x) r=mid;
        else l=mid+1;
    }
    return l;
}
int32_t getNumOfX(int64_t x, vector<int32_t>& v){
    auto itr = numOfX.find(x);
    if(itr!=numOfX.end()) return itr->second;
    int32_t num=bsearch_u(x,v)-bsearch_l(x,v);
    numOfX[x]=num;
    return num;
}
int main(){
    fastio;
    cin>>T;
    cin>>n;
    for(int i(1); i<=n; i++){
        cin>>psum_a[i];
        psum_a[i]+=psum_a[i-1];
    }
    cin>>m;
    for(int i(1); i<=m; i++){
        cin>>psum_b[i];
        psum_b[i]+=psum_b[i-1];
    }
    for(int i(1); i<=n; i++){
        for(int j(0); j<i; j++){
            a.push_back(psum_a[i]-psum_a[j]);
        }
    }
    for(int i(1); i<=m; i++){
        for(int j(0); j<i; j++){
            b.push_back(psum_b[i]-psum_b[j]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int64_t ret=0;
    for(int32_t avalue: a) ret+=getNumOfX((int64_t)T-avalue,b);
    cout<<ret;
}