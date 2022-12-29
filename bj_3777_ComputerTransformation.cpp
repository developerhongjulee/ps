#include<bits/stdc++.h>
using namespace std;
int n,ans[5]={0,0,1,1,3}, p[999];
int main(){
	fill(p,p+999, -1);
	while(cin>>n){
		if(n<=4) printf("%d\n", ans[n]);
		else printf("%d\n", (p[n-3]==-1?p[n-3]=(int)pow(2,n-3):p[n-3])+(p[n-5]==-1?p[n-5]=(int)pow(2,n-5):p[n-5]));
	}
}
