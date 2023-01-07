#include<bits/stdc++.h>
using namespace std;
int T,n,h[100000], ret;
int main(){
    scanf("%d", &T);
    while(T--){
        ret=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &h[i]);
        sort(h,h+n);
        deque<int> dq;
        dq.push_back(h[0]);
        for(int i=1; i<n; i++){
            if(i%2){
                ret=max(h[i]-*dq.begin(), ret);
                dq.push_front(h[i]);
            }
            else{
                ret=max(h[i]-*dq.rbegin(), ret);
                dq.push_back(h[i]);
            }
        }
        printf("%d\n", ret);
    }
}