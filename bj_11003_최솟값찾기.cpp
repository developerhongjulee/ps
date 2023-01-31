#include<queue>
#include<iostream>
#include<vector>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0)
#define pii pair<int,int>
int n,l,a;
int main(){
	fastio;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	cin>>n>>l;
	for(int i=1; i<=n; i++){
		cin>>a;
		pq.push({a, i});
		pii p = pq.top();
		while(p.second<i-l+1){
			pq.pop();
			p = pq.top();
		}
		cout<<p.first<<' ';
	}
}
