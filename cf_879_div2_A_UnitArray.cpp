#include<iostream>
#include<cmath>
using namespace std;
int t, n, a;
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	cin>>t;
	while(t--){
		int num_p=0, num_n=0, ret=0;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a;
			if(a>0) num_p++;
			else num_n++;	
		}
		if(num_p<num_n){
			int diff=(int)ceil(((double)num_n-(double)num_p)/2);
			num_p+=diff;
			num_n-=diff;
			ret+=diff;
		}
		if(num_n%2) ret++;
		cout<<ret<<'\n';
	}
}
