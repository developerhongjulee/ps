#include<bits/stdc++.h>
using namespace std;
const int ROOT=1;//root 1부터 시작 
int unused=2;
const int MX = 10000*500+2; //문자열 최대 갯수*문자열 최대 길이:트라이의 최대 노드 수 
bool chk[MX]; //해당 정점이 문자열의 끝인지 여부 
int nxt[MX][26]; //자식 정점의 번호 
void init(){
	for(int i=0; i<MX; i++){
		fill(nxt[i], nxt[i]+26, -1);
	}
	fill(chk, chk+MX, false);
}
int ctoi(char c){
	return c-'a';
}
void insert(string& s){
	int cur=ROOT;//트라이에서 현재 가리키는 노드 인덱스 
	for(auto c:s){
		if(nxt[cur][ctoi(c)]==-1) nxt[cur][ctoi(c)]=unused++;
		cur=nxt[cur][ctoi(c)];
	}
	chk[cur]=true;//단어의 맨 끝인 노드에 check를 한다
}
bool findPrefix(string& s){
	int cur=ROOT;
	for(auto c:s){
		if(nxt[cur][ctoi(c)]==-1) return false;
		cur=nxt[cur][ctoi(c)];
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m, ret=0;
	cin>>n>>m;
	init();
	for(int i=0; i<n; i++){
		string str;
		cin>>str;
		insert(str);
	}
	for(int i=0; i<m; i++){
		string str;
		cin>>str;
		if(findPrefix(str)) ret++;
	}
	printf("%d", ret);
}
