#include<bits/stdc++.h>
#define INF 1e9
#define pii pair<int,int>
#define COST first
#define V second
using namespace std;
int n,m,adj_mtx[500][500],dist[500],s,d;
vector<int> p[500];
void dijkstra(){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	fill_n(dist,500,INF);
	dist[s]=0;
	pq.push({dist[s],s});
	while(!pq.empty()){
		auto cur=pq.top();pq.pop();
		int curV=cur.V, curdist=cur.COST;
		if(curdist>dist[curV]) continue;
		for(int nxtV=0; nxtV<n; nxtV++){
			if(adj_mtx[curV][nxtV]==0) continue;
			if(dist[nxtV]>dist[curV]+adj_mtx[curV][nxtV]){
				dist[nxtV]=dist[curV]+adj_mtx[curV][nxtV];
				pq.push({dist[nxtV], nxtV});
				p[nxtV].clear();
				p[nxtV].push_back(curV);
			}
			if(dist[nxtV]==dist[curV]+adj_mtx[curV][nxtV]){
				p[nxtV].push_back(curV);
			}
		}
	}
}
void bfs(){
	queue<int> q;
	q.push(d);
	bool visited[500]={0};
	visited[d]=true;
	while(!q.empty()){
		int curV=q.front();q.pop();
		for(int pV: p[curV]){
			adj_mtx[pV][curV]=0;
			if(!visited[pV]){
				q.push(pV);
				visited[pV]=true;
			}
		}
	}
}
int main(){
	while(true){
		scanf("%d %d", &n,&m);
		if(n==0&& m==0) break;
		memset(adj_mtx,0x00,sizeof(adj_mtx));
		for(int i=0; i<n; i++) p[i].clear();
		scanf("%d %d", &s,&d);
		for(int i=0; i<m; i++){
			int u,v,cost;
			scanf("%d %d %d", &u,&v,&cost);
			adj_mtx[u][v]=cost;
		}
		dijkstra();
		bfs();
		dijkstra();
		printf("%d\n", dist[d]==INF?-1:dist[d]);
	}
	
}
