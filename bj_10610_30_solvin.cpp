#include<bits/stdc++.h>
using namespace std;
int cnt[10], sum;
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    string s;
    cin>>s;
    for(auto c:s){
        int n=c-'0';
        cnt[n]++;
        sum+=n;
    }
    if(!cnt[0]) cout<<-1;
    else if(sum%3==0){
        for(int i=9; i>=0; i--){
            for(int j=0; j<cnt[i]; j++) cout<<i;
        }
    }
    else{
        
    }

}