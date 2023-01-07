#include<bits/stdc++.h>
using namespace std;
int n,arr[100001], ret;
int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &arr[i]);
    sort(arr+1, arr+n+1, greater<>());
    ret=arr[1];
    for(int i=2; i<=n; i++) ret=max(ret, arr[i]*i);
    printf("%d", ret);
}