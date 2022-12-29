#include<bits/stdc++.h>
#define pii pair<int,int>
#define V first
#define COST second
using namespace std;
int n, max_ret;
vector<pii> adj_list[100001];
int dfs(int v, int p){
	int dfs_max1=0, dfs_max2=0;
	for(pii& e: adj_list[v]){
		if(e.V==p) continue;
		int dfsvalue=dfs(e.V,v)+e.COST;
		if(dfsvalue>dfs_max1){
			dfs_max2=dfs_max1;
			dfs_max1=dfsvalue;
		}
		else if(dfsvalue>dfs_max2) dfs_max2=dfsvalue;
	}
	max_ret=max(max_ret, dfs_max1+dfs_max2);
	return dfs_max1;
}
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int v;
		scanf("%d", &v);
		while(true){
			int u;
			scanf("%d",&u);
			if(u==-1) break;
			int cost;
			scanf("%d", &cost);
			adj_list[v].push_back({u,cost});
		}
	}
	dfs(1,0);
	printf("%d", max_ret);
}
