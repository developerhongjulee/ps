#include<iostream>
using namespace std;
#define INF 987654321
int T,n,m,x,y,c,dist[401][401];
int main(void){
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		fill_n(&dist[0][0], 401*401, INF);
        cin>>n>>m;
        for(int i=0; i<m; i++){
        	cin>>x>>y>>c;
            dist[x][y]=c;
        }
		for(int v2=1; v2<=n; v2++){
        	for(int v1=1; v1<=n; v1++){
            	for(int v3=1; v3<=n; v3++){
                	if(dist[v1][v3]>dist[v1][v2]+dist[v2][v3])
                        dist[v1][v3]=dist[v1][v2]+dist[v2][v3];
                }
            }
        }
        int ret=INF;
        for(int v=1; v<=n; v++) ret=min(ret, dist[v][v]); 
		cout<<'#'<<tc<<' '<<(ret==INF?-1:ret)<<'\n';
	}
	return 0;
}
