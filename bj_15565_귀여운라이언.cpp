#include<bits/stdc++.h>
#define INF 987654321
using namespace std;
int n,k,a[1000000];
int main(){
	scanf("%d %d", &n,&k);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	int i1=0, i2=0, cnt=a[i1]==1?1:0, ret=INF;
	while(true){
		if(cnt<k){
			if(i2+1==n) break;
			if(a[++i2]==1) cnt++;
		}
		else{
			if(a[i1++]==1) cnt--;
		}
		if(cnt==k) ret=min(ret,i2-i1+1);
	}
	printf("%d", ret==INF?-1:ret);
	
}
