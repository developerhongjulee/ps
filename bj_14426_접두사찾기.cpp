#include<bits/stdc++.h>
using namespace std;
const int ROOT=1;//root 1���� ���� 
int unused=2;
const int MX = 10000*500+2; //���ڿ� �ִ� ����*���ڿ� �ִ� ����:Ʈ������ �ִ� ��� �� 
bool chk[MX]; //�ش� ������ ���ڿ��� ������ ���� 
int nxt[MX][26]; //�ڽ� ������ ��ȣ 
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
	int cur=ROOT;//Ʈ���̿��� ���� ����Ű�� ��� �ε��� 
	for(auto c:s){
		if(nxt[cur][ctoi(c)]==-1) nxt[cur][ctoi(c)]=unused++;
		cur=nxt[cur][ctoi(c)];
	}
	chk[cur]=true;//�ܾ��� �� ���� ��忡 check�� �Ѵ�
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
