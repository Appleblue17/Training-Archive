#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,INF=1e9;

int rd(){
	char c=getchar();
	int tot=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
	return tot;
}

int T,n,m;
int a[N];

int pri[N],cnt;
bool pvis[N];
int mu[N];

vector<int> D[N];
int f[N];

void init(int lim){
	pvis[1]=1; mu[1]=1;
	for(int i=2;i<=lim;i++){
		if(!pvis[i]) pri[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt && i*pri[j]<=lim;j++){
			int x=i*pri[j];
			pvis[x]=1;
			if(i%pri[j]) mu[x]=-mu[i];
			else{
				mu[x]=0;
				break;
			}
		}
	}
	
	for(int i=1;i<=lim;i++)
		for(int j=i;j<=lim;j+=i)
			D[j].push_back(i);
	
	for(int i=1;i<=lim;i++)
		for(int j=i;j<=lim;j+=i){
			f[j]+=i*i*mu[j/i];
		}
}

vector <int> V[N];

signed main(){
	init(N-5);
	T=rd();
	
    while(T--){
		n=rd(),m=rd();
		for(int i=1;i<=n;i++) a[i]=rd();
		
		// for(int i=1;i<=m;i++) ans[i]=0;
		for(int i=1;i<N;i++) V[i].clear();
		
		for(int i=1;i<=n;i++){
			for(int t: D[a[i]]) V[t].push_back(i);
		}
		
		// for(int i=1;i<=m;i++){
		while(m--){
			int l=rd(),r=rd(),k=rd();
			int ans=0;
			for(int t: D[k]){
				if(!V[t].size()) continue;
				int L=lower_bound(V[t].begin(),V[t].end(),l)-V[t].begin();
				int R=upper_bound(V[t].begin(),V[t].end(),r)-V[t].begin()-1;
				int x=R-L+1;
				// cout<<t<<": "<<x<<endl;
				ans+=x*f[t];
			}
			printf("%lld\n",ans);
		}
    }
}