#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false), cin.tie(0)
int T,n,a,m;
int main(){
    fastio;
    cin>>T;
    while(T--){
        cin>>n;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> list;
        for(int i=0; i<n; i++){
            cin>>a;
            pq.push(a);
        }
        while(!pq.empty()){list.push_back(pq.top());pq.pop();}
        cin>>m;
        for(int i=0; i<m; i++){
            int b,l=0,r=list.size()-1,ret=0;
            cin>>b;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(b==list[mid]){
                    ret=1;
                    break;
                }
                if(b<list[mid]) r=mid-1;
                else l=mid+1;
            }
            cout<<ret<<'\n';
        }
    }
}