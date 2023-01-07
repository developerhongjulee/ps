#include<bits/stdc++.h>
typedef pair<int,int> pii;
#define S second
using namespace std;
int main(){
    auto compare = [](pii& e1, pii& e2)->bool {return e1.S<e2.S;};
    priority_queue<pii, vector<pii>, decltype(compare)> pq(compare);
    
}