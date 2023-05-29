#include<bits/stdc++.h>
using namespace std;
#define COST first
#define V second
int n,m,k, p[10001];
vector<pair<int,int>> edgelist;
int find(int a){
	if(p[a]==a) return a;
	return p[a]=find(p[a]);
}
bool unionfun(int a,int b){
	a=find(a);b=find(b);
	if(a==b) return false;
	else{
		p[a]=b;return true;
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin>>n>>m>>k;
	for(int v=1; v<=n; v++){
		int cost;
		cin>>cost;
		edgelist.push_back({cost,v});
	}
	sort(edgelist.begin(), edgelist.end());
	for(int v=0; v<=n; v++) p[v]=v;
	int cnt=0;
	for(int i=0; i<m; i++){
		int v,w;
		cin>>v>>w;
		if(unionfun(v,w)) cnt++;
	}
	int cost_sum=0,flag=false;
	for(int i=0; i<n; i++){
		int cost=edgelist[i].COST;
		int v=edgelist[i].V;
		if(unionfun(0,v)){
			cnt++;
			cost_sum+=cost;
			if(cost_sum>k) break;
		}
		if(cnt==n){
			flag=true;break;
		}
	}
	if(flag) cout<<cost_sum;
	else cout<<"Oh no";
}
