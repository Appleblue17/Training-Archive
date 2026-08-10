#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int T,n;
int a[N],b[N];

vector <int> ANSFIX;
int ANSLOW;

int col[N],cid;
vector <int> iG[N];
int rt[N],dis[N];


bool vis[N];

void dfs0(int u){
	
	vis[u]=1;
	
	for(int v: iG[u]){
		if(col[v]) continue;
		rt[v]=rt[u];
		dis[v]=dis[u]+1;
		col[v]=col[u];
		dfs0(v);
	}
	vis[u]=0;
}

void solve(){
	for(int i=1;i<=n;i++) col[i]=0,iG[i].clear();
	ANSFIX.clear();
	ANSLOW=0;
	cid=0;
	
	for(int i=1;i<=n;i++){
		if(col[i]) continue;
		cid++;
		stack <int> st;
		int x=i;
		while(1){
			col[x]=cid;
			st.push(x);
			x=a[x];
			if(col[x]){
				while(st.size()){
					int u=st.top(); st.pop();
					rt[u]=u; dis[u]=0;
					dfs0(u);
					if(u==x) break;
				}
				break;
			}
		}
		
	}
	
	
}

int main(){
	freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		solve();
	}	
	return 0;
}