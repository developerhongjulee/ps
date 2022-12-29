#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[10001];
int n,xcnt, level_max, isRoot[10001];
set<int> l[10001];
void inorder(int v, int level){ //중위순회의 순서가 x좌표이다 
	if(v==-1) return;
	level_max=max(level_max, level);
	inorder(adj_list[v][0], level+1);
	l[level].insert(++xcnt);
	inorder(adj_list[v][1], level+1);
}
int main(){
	scanf("%d", &n);
	fill_n(isRoot, n+1, true);
	for(int i=0; i<n; i++){
		int v,v1,v2;
		scanf("%d %d %d", &v, &v1, &v2);
		adj_list[v].push_back(v1);
		adj_list[v].push_back(v2);
		isRoot[v1]=isRoot[v2]=false;
	}
	int root;
	for(int v=1; v<=n; v++){
		if(isRoot[v]){
			root=v;
			break;
		}
	}
	inorder(root,1);
	int ret=0, ret_level=0;
	for(int level=1; level<=level_max; level++){
		int cur=*l[level].rbegin()-*l[level].begin()+1;
		if(cur>ret){
			ret=cur;
			ret_level=level;
		}
	}
	printf("%d %d",ret_level, ret);
}
