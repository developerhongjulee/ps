#include<bits/stdc++.h>
using namespace std;
int n,a[1000], dp[1000], p[1000];
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	dp[0]=1, p[0]=-1;
	for(int i=1; i<n; i++){
		int max_length=0, max_length_parent=-1;
		for(int j=0; j<i; j++){
			if(a[i]>a[j]&& dp[j]>max_length){
				max_length=dp[j];
				max_length_parent=j;
			}
		}
		dp[i]=max_length+1;
		p[i]=max_length_parent;
	}
	int max_length=0, max_length_parent=-1;
	for(int i=0; i<n; i++){
		if(dp[i]>max_length){
			max_length=dp[i];
			max_length_parent=i;
		}
	}
	printf("%d\n", max_length);
	int idx=max_length_parent;
	deque<int> ret;
	while(idx!=-1){
		ret.push_front(a[idx]);
		idx=p[idx];
	}
	for(int a: ret) printf("%d ", a);
}
