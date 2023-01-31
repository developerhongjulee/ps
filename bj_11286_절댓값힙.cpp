#include<iostream>
#include<set>
#include<cmath>
using namespace std;
#define fastio ios:sync_with_stdio(false);cin.tie(0)
#define pii pair<int,int>
int n,x;
int main(){
	multiset<pii> mset;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x;
		if(x!=0){
			mset.insert({abs(x), x>0? true: false});
		}else if(mset.empty()){
			cout<<0<<'\n';
		}else{
			pii p = *mset.begin();
			int value = p.first*(p.second?1:-1); 
			cout<<value<<'\n';
			mset.erase(mset.begin());
		}
	}
}
