#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 110
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
//mt19937_64 rng(GetTickCount());
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int mo=1e9+7;
using namespace std;
int g[N][N],val[N][N],ind[N],ps[N];//g and val points from people to item packs, ind is in degree for item packs.
vector<int> its[N];// for item pack ids
int n,m,vis[N];//vis marks item packs only.
void query(int i,int j,vector<int>& its){
	printf("? %d %d ",i,its.size());
	for(int v:its){
		printf("%d ",v);
	}
	printf("\n");fflush(stdout);
	int x=0;
	scanf("%d",&x);
	val[i][j] = x;
}
bool dfs(int u,int st){
	vis[u]=st;
	int psu = ps[u];//it's a copy
	for(int i=1;i<=n;i++){
		if(!g[psu][i])continue;
		int vitm = i;
		if(vis[vitm]){
			if(vis[vitm] == st){
				ps[st] = psu;
				return 1;
			}
			else{
				continue;
			}
		}
		else{
			//vis[vitm] = st;
			if(dfs(vitm,st)){
				ps[vitm] = psu;//use the copy when u == st
				return 1;
			}
		}
		
	}
	return 0;
}
void buildg(){
		for(int k=1;k<=n;k++){
			ind[k]=0;
			for(int j=1;j<=n;j++){
				//if(j == k)continue;
				
				if(val[ps[j]][k] > val[ps[j]][j]){
					g[ps[j]][k] = 1;
					ind[k]++;
					//printf("j=%d,k=%d,ps[j]=%d\n",j,k,ps[j]);
				}
				else{
					g[ps[j]][k] = 0;
				}
			}
		}
		/*for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				cout << val[k][j] << ' ';
			}
			cout << endl;
		}
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				cout << g[k][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		ps[i]=n-i+1;
	}
	for(int i=1;i<=m;i++){
		int u = -1;
		for(int j=1;j<=n;j++){
			if(ind[j] == 0)u = j;
		}
		its[u].push_back(i);
		//printf("assigned itm %d to item pack %d\n",i,u);
		for(int j=1;j<=n;j++){
			query(j,u,its[u]);
		}

		buildg();

		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				dfs(j,j);
			}
		}

		buildg();
	}
	int ans[510];
	for(int i=1;i<=n;i++){
		for(int v:its[i]){
			ans[v] = ps[i];
		}
	}
	printf("! ");
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");fflush(stdout);
}
signed main(){
	//int T;cin >> T;for(int i=1;i<=T;i++){
		solve();
	//}
}
