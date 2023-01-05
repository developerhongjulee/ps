#include<bits/stdc++.h>
#define IDX(x) ((x)%(n))
using namespace std;
int T,n,m,k,h[100000];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; i++) scanf("%d", &h[i]);
		int value=0;
		for(int i=0; i<m; i++) value+=h[i];
		if(n==m){
			printf("%d\n", value<k? 1:0);
			continue;
		}
		int i=0,ret=0;
		for(int i=0; i<n; i++){
			if(value<k) ret++;
			value-=h[i];
			value+=h[IDX(i+m)];
		}
		printf("%d\n", ret);
	}
}
