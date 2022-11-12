#include<iostream>
#include<cmath>
using namespace std;
int n,b,h[10000], ret;
void bt(int k,int value){
	if(value>=b){
		ret=min(ret,value);
		return;
	}
	if(k==n) return;
	bt(k+1,value);
	bt(k+1,value+h[k]);
}
int main(int argc, char** argv){
	int T;
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		ret=200000;
		cin>>n>>b;
		for(int i=0; i<n; i++) cin>>h[i];
		bt(-1,0);
		printf("#%d %d\n", tc, ret-b);
	}
	return 0;
}
