#include<bits/stdc++.h>
using namespace std;
int n,a[1000], dp[1000];
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	dp[0]=1;
	for(int i=1; i<n; i++){
		int max_length=0;
		for(int j=0; j<i; j++){
			if(a[i]>a[j]&& dp[j]>max_length){
				max_length=dp[j];	
			}
		}
		dp[i]=max_length+1;
	}
	printf("%d", *max_element(dp,dp+n));
}
