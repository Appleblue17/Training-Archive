#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e6+5;
int T, n, m, q;
vector<pii> g[N];
int tag[N];
int qy[N], qz[N];
vector<int> e[N];
int stk[N], top; bool ins[N];
int dfn[N], tim, low[N], id[N], scccnt;
void tarjan(int x){
	low[x]=dfn[x]=++tim;
	stk[++top]=x; ins[x]=true;
	for(auto y:e[x]){
		if(!dfn[y]) tarjan(y), low[x]=min(low[x], low[y]);
		else if(ins[y]) low[x]=min(low[x], dfn[y]);
	}
	if(low[x]==dfn[x]){
		scccnt++;
		do{
			id[x]=scccnt;
			x=stk[top--]; ins[x]=false;
		}while(low[x]!=dfn[x]);
	}
}
void in(int x, int y){
	e[x].ep(y);
}
void solve(){
	read(n); read(m); read(q);
	for(int i=1; i<=n+m; ++i) g[i].clear();
	for(int i=1; i<=m; ++i) tag[i]=0;
	for(int i=1, a, b; i<=q; ++i){
		read(a); read(b); read(qy[i]); read(qz[i]);
		g[a].ep(b+n, i);
		g[b+n].ep(a, i);
		if(qy[i]==1&&qz[i]==0) tag[b]=1;
	}
	for(int i=1; i<=(n+m)*2; ++i) e[i].clear(), dfn[i]=0;
	tim=0; scccnt=0; top=0;
	for(int i=1; i<=n; ++i){
		for(auto [j, id]:g[i]){
			j-=n;
			if((0&qy[id])!=qz[id]){
				in(i, j+n+n+m);
			}
			if((1&qy[id])!=qz[id]){
				in(i+n+m, j+n+n+m);
			}
			if(tag[j]){
				if((0^qy[id])!=qz[id]){
					in(i, j+n);
				}
				if((1^qy[id])!=qz[id]){
					in(i+n+m, j+n);
				}
			}
			else{
				if((0|qy[id])!=qz[id]){
					in(i, j+n);
				}
				if((1|qy[id])!=qz[id]){
					in(i+n+m, j+n);
				}
			}
		}
	}
	
	for(int j=1; j<=m; ++j){
		for(auto [i, id]:g[j+n]){
			if((0&qy[id])!=qz[id]){
				in(j+n, i+n+m);
			}
			if((1&qy[id])!=qz[id]){
				in(j+n, i);
			}
			if(tag[j]){
				if((0^qy[id])!=qz[id]){
					in(j+n+n+m, i+n+m);
				}
				if((1^qy[id])!=qz[id]){
					in(j+n+n+m, i);
				}
			}
			else{
				if((0|qy[id])!=qz[id]){
					in(j+n+n+m, i+n+m);
				}
				if((1|qy[id])!=qz[id]){
					in(j+n+n+m, i);
				}
			}
		}
	}
	for(int i=1; i<=(n+m)*2; ++i) if(!dfn[i]) tarjan(i);
	for(int i=1; i<=n+m; ++i){
		if(id[i]==id[i+n+m]){
			printf("NO\n");
			return ;
		}
	}
	printf("YES\n");
	for(int i=1; i<=n; ++i){
		putchar(48^(id[i]>id[i+n+m]));
	}
	putchar('\n');
	for(int i=n+1; i<=n+m; ++i){
		if(id[i]<id[i+n+m]) putchar('&');
		else if(tag[i-n]) putchar('^');
		else putchar('|');
	}
	putchar('\n');
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}