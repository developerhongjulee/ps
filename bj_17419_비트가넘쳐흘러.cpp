#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ret=0;
    string k;
    cin>>n>>k;
    for(auto b:k) ret+=b=='1';
    printf("%d", ret);
}
