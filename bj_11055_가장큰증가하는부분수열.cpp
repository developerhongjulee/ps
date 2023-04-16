#include<bits/stdc++.h>
int n,a[1000], dp[1000];
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	dp[0]=a[0];
	for(int i=1; i<n; i++){
		int max_sum=0; 
		for(int j=0; j<i; j++){
			if(a[i]>a[j]&& dp[j]>max_sum){
				max_sum=dp[j];	
			}
		}
		dp[i]=max_sum+a[i];
	}
	printf("%d", *std::max_element(dp,dp+n));
}
