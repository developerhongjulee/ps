#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define DIST first
#define V second
#define INF 987654321
int T,n,d,c, dist[10001];
void dijkstra(vector<pii> adj_list[], int c){
	fill_n(dist+1, n+1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[c]=0;
	pq.push({0,c});
	while(!pq.empty()){
		auto cur=pq.top();pq.pop();
		if(dist[cur.V]<cur.DIST) continue;
		for(auto nxt: adj_list[cur.V]){
			if(dist[cur.V]+nxt.DIST<dist[nxt.V]){
				dist[nxt.V]=dist[cur.V]+nxt.DIST;
				pq.push({dist[nxt.V], nxt.V});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin>>T;
	while(T--){
		vector<pii> adj_list[10001];
		cin>>n>>d>>c;
		for(int i=0; i<d; i++){
			int a,b,s;
			cin>>a>>b>>s;
			adj_list[b].push_back({s,a});
		}
		dijkstra(adj_list, c);
		int cnt=0, max_time=0;
		for(int i=1; i<=n; i++){
			if(dist[i]!=INF){
				cnt++;
				max_time=max(max_time, dist[i]);	
			}
		}
		cout<<cnt<<' '<<max_time<<'\n';
	}
	
}
