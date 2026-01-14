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
const int N=2e6+5;
int n, m;
char s[805][805];
int id[805][805], idx;
vector<int> v[2];
int ex[N], ey[N], ecnt, ea[N], eb[N];
bool eins[N];
int S, T, tot=1;
int lin[N], to[N], nxt[N], val[N], eid[N];
int way[N];
int col[N];
void in(int x, int y, int id){
	if(id==0){
		to[++tot]=y; val[tot]=1; eid[tot]=id;
		nxt[tot]=lin[x]; lin[x]=tot;
		to[++tot]=x; val[tot]=0; eid[tot]=id;
		nxt[tot]=lin[y]; lin[y]=tot;
		return ;
	}
	if(col[x]) swap(x, y);
	ea[id]=x; eb[id]=y;
	// cout<<x<<' '<<y<<endl;
	to[++tot]=y; val[tot]=1; eid[tot]=id;
	nxt[tot]=lin[x]; lin[x]=tot;
	to[++tot]=x; val[tot]=0; eid[tot]=id;
	nxt[tot]=lin[y]; lin[y]=tot;
}
int dep[N];
bool bfs(){
	for(int i=1; i<=T; ++i) dep[i]=0;
	queue<int> q;
	q.push(S);
	dep[S]=1; way[S]=lin[S];
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=lin[x]; i; i=nxt[i]){
			int y=to[i];
			if(val[i]&&(!dep[y])){
				dep[y]=dep[x]+1;
				way[y]=lin[y];
				if(y==T) return 1;
				q.push(y);
			}
		}
	}
	return 0;
}
int dfs(int x, int now){
	if(x==T) return now;
	int ret=0;
	for(int i=way[x]; i&&ret<now; i=nxt[i]){
		int y=to[i];
		way[x]=i;
		if(val[i]&&dep[y]==dep[x]+1){
			int res=dfs(y, min(val[i], now-ret));
			if(res==0) dep[y]=0;
			val[i]-=res;
			val[i^1]+=res;
			ret+=res;
		}
	}
	return ret;
}
int dx[2]={1, 0}, dy[2]={0, 1};
int fa[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
bool merge(int x, int y){
	// cout<<x<<' '<<y<<endl;
	x=get(x); y=get(y);
	if(x==y) return false;
	fa[x]=y; return true;
}
bool vvis[N];
void work(int x){
	vvis[x]=1;
	for(int i=lin[x], y=to[i]; i; i=nxt[i], y=to[i]) if(val[i]==0&&!vvis[y]){
		merge(x, y);
		eins[eid[i]]=1;
		work(y);
	}
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n); read(m);
	for(int i=1; i<=n*2+1; ++i){
		scanf("%s", s[i]+1);
		if(!(i&1)){
			for(int j=2; j<=m*2+1; j+=2){
				if(s[i][j]=='.'){
					id[i][j]=++idx; fa[idx]=idx;
					v[((i/2)^(j/2))&1].ep(idx);
				}
			}
		}
	}
	if(v[0].size()==v[1].size()){
		printf("No\n");
		return 0;
	}
	if(v[0].size()>v[1].size()) v[0].swap(v[1]);
	S=idx+1; T=S+1;
	for(auto t:v[1]) col[t]=1, in(t, T, 0);
	for(auto t:v[0]) in(S, t, 0);
	for(int i=2; i<=n*2+1; i+=2){
		for(int j=2; j<=m*2+1; j+=2){
			if(s[i][j]=='.'){
				for(int k=0, ii, jj; k<2; ++k){
					ii=i+dx[k]; jj=j+dy[k];
					if(s[ii][jj]=='.'){
						++ecnt;
						ex[ecnt]=ii; ey[ecnt]=jj;
						in(id[i][j], id[ii+dx[k]][jj+dy[k]], ecnt);
					}
				}
			}
		}
	}
	int flow=0;
	while(bfs()){
		int fl=dfs(S, v[0].size());
		flow+=fl;
		while(fl){
			fl=dfs(S, v[0].size());
			flow+=fl;
		}
	}
	if(flow!=(int)v[0].size()){
		printf("No\n");
		return 0;
	}
	vvis[S]=vvis[T]=1;
	for(auto t:v[1]){
		bool flag=0;
		for(int i=lin[t]; i; i=nxt[i]) if(to[i]==T) flag=val[i];
		if(flag) work(t);
	}
	for(int i=1; i<=idx; ++i) if(!vvis[i]){
		printf("No\n");
		return 0;
	}
	// for(int i=1; i<=idx; ++i) cout<<i<<' '<<get(i)<<endl;
	for(int i=1; i<=ecnt; ++i){
		if(eins[i]) {
			// cout<<ex[i]<<' '<<ey[i]<<endl;
			continue;
		}
		if(!merge(ea[i], eb[i])){
			// cout<<ex[i]<<' '<<ey[i]<<endl;
			s[ex[i]][ey[i]]='#';
		}
	}
	for(int i=1; i<=idx; ++i) if(get(i)!=get(1)){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(int i=1; i<=n*2+1; ++i){
		printf("%s\n", s[i]+1);
	}
	return 0;
}

