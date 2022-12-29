#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0)
using namespace std;
vector<int> adj_list[26];
void preorder(char v){
	if(v=='.') return;
	cout<<v;
	preorder(adj_list[v-'A'][0]+'A');
	preorder(adj_list[v-'A'][1]+'A');
}
void inorder(char v){
	if(v=='.') return;
	inorder(adj_list[v-'A'][0]+'A');
	cout<<v;
	inorder(adj_list[v-'A'][1]+'A');
}
void postorder(char v){
	if(v=='.') return;
	postorder(adj_list[v-'A'][0]+'A');
	postorder(adj_list[v-'A'][1]+'A');
	cout<<v;
}
int main(){
	fastio;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		char v,v1,v2;
		cin>>v>>v1>>v2;
		adj_list[v-'A'].push_back(v1-'A');
		adj_list[v-'A'].push_back(v2-'A');
	}
	preorder('A');cout<<'\n';
	inorder('A');cout<<'\n';
	postorder('A');
}
