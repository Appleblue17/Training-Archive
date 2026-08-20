#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=660,INF=1e18;

int rd(){
	char c=getchar();
	int tot=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
	return tot;
}

int T,n,m;
int G[N][N];

int f[N];

int dis[N];
bool bin[N];
int contract(int &s,int &t){
	int tot=0;
	for(int i=1;i<=n;i++) dis[i]=0;
	dis[0]=-INF;
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=n;j++){
			if(!bin[j] && dis[j]>dis[x]) x=j;
		}
		if(dis[x]<0) return tot;
		s=t,t=x,tot=dis[x];
		dis[x]=-INF;
		for(int j=1;j<=n;j++)
			if(!bin[j]) dis[j]+=G[x][j];
	}
	return tot;
}

int solve(){
	for(int i=1;i<=n;i++) bin[i]=0;
	int tot=INF;
	int s,t;
	for(int t=1;t<n;t++){
		int res=contract(s,t);
		// cout<<t<<": "<<res<<endl;
		bin[t]=1;
		tot=min(tot,res);
		
		for(int i=1;i<=n;i++)
			if(!bin[i]){
				G[s][i]+=G[i][t];
				G[i][s]+=G[i][t];
			}
	}
	return tot;
}

signed main(){
	T=rd();
    while(T--){
		n=rd(),m=rd();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=0;
		
        for(int i=1;i<=m;i++){
			int u=rd(),v=rd(),w=rd();
			G[u][v]+=w;
			G[v][u]+=w;
		}
		
		int ans=solve();
		cout<<ans*(n-1)<<endl;
    }
}