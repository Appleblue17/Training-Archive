#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,b) for(int i=a;i<=b;i++)
#define wt int tt=d;while(tt--)
inline ll rd() {
	ll x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x*f;
}
#define d rd()
#define pb push_back
ll n,m;
const ll mod=998244353;
ll qp(ll a,ll b){
	ll ans=1;while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;b>>=1;
	}return ans;
}
const ll i3=qp(3,mod-2);
struct mat{int a[2][2];}C;
void add(int &x,int &y){
	x+=y;
	(x>=mod)?x-=mod:0;
}
void add(mat &a,mat &b){
	add(a.a[0][0],b.a[0][0]);
	add(a.a[0][1],b.a[0][1]);
	add(a.a[1][0],b.a[1][0]);
	add(a.a[1][1],b.a[1][1]);
}
mat operator * (mat &a,mat &b){
	C.a[0][0]=(1ll*a.a[0][0]*b.a[0][0]+1ll*a.a[0][1]*b.a[1][0])%mod;
	C.a[0][1]=(1ll*a.a[0][0]*b.a[0][1]+1ll*a.a[0][1]*b.a[1][1])%mod;
	C.a[1][0]=(1ll*a.a[1][0]*b.a[0][0]+1ll*a.a[1][1]*b.a[1][0])%mod;
	C.a[1][1]=(1ll*a.a[1][0]*b.a[0][1]+1ll*a.a[1][1]*b.a[1][1])%mod;
	return C;
}void clear(mat &a){
	a.a[0][0]=a.a[0][1]=a.a[1][0]=a.a[1][1]=0;
}
mat A[500010],B[500010];
mat t[2][500010];
#define lb(x) (x&(-x))
void clear(int o,int p){
	while(p<=n){
		clear(t[o][p]);
		p+=lb(p);
	}
}
void add(int o,int p,int x){
	while(p<=n){
		if(o==0)add(t[o][p],A[x]);
		else add(t[o][p],B[x]);
		p+=lb(p);
	}
}mat ask(int o,int p){
	mat res;clear(res);
	while(p){
		add(res,t[o][p]);
		p-=lb(p);
	}return res;
}
int ncnt,lst;
int Len[1000010];
int tre[1000010][26];
int Fa[1000010];
int v[1000010];
int SAMadd(int c){
	int u=++ncnt,p=lst;
	lst=u,Len[u]=Len[p]+1;
	for(;p&&!tre[p][c];p=Fa[p])tre[p][c]=u;
	if(!p)Fa[u]=1;
	else{
		int q=tre[p][c];
		if(Len[q]==Len[p]+1)Fa[u]=q;
		else{
			int Splt=++ncnt;
			for(int i=0;i<26;i++)
				tre[Splt][i]=tre[q][i];
			Fa[Splt]=Fa[q],
			Len[Splt]=Len[p]+1,Fa[q]=Fa[u]=Splt;
			for(;p&&tre[p][c]==q;p=Fa[p])tre[p][c]=Splt;
		}
	}
	return u;
}char c[500010];
vector<int>e[1000010];
vector<int>node;
int sz[1000010],son[1000010];
void getnode(int u){
	if(v[u])node.pb(v[u]);
	for(auto v:e[u])getnode(v);
}void clearbit(int u){
	if(v[u])clear(1,v[u]),clear(0,n-v[u]+1);
	for(auto v:e[u])clearbit(v);
}void scan(int u){
	sz[u]=1;
	for(auto v:e[u]){
		scan(v);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
int res[1000010];
void addnode(int x){
	add(0,n-x+1,x);
	add(1,x,x);
}
void dfs(int u){
	for(auto v:e[u]){
		if(v==son[u])continue;
		dfs(v);clearbit(v);
	}if(!son[u]){
		if(v[u])addnode(v[u]);
		return;
	}
	dfs(son[u]);
	for(auto v:e[u]){
		if(v==son[u])continue;
		getnode(v);
		for(auto x:node){
			mat f=ask(1,x-1);f=A[x]*f;
			mat g=ask(0,n-x);g=g*B[x];
			add(res[Len[u]],f.a[0][1]);
			add(res[Len[u]],g.a[0][1]);
		}for(auto x:node)addnode(x);
		node.clear();
	}if(v[u]){
		int x=v[u];
		mat f=ask(1,x-1);f=A[x]*f;
		mat g=ask(0,n-x);g=g*B[x];
		add(res[Len[u]],f.a[0][1]);
		add(res[Len[u]],g.a[0][1]);
		addnode(x);
	}node.clear();
}
void solve(){
	n=d;scanf("%s",c+1);
	reverse(c+1,c+n+1);
	ncnt=1;lst=1;
	f(i,1,n){
		SAMadd(c[i]-'a');
		v[lst]=i;
	}
	f(i,1,ncnt){
		if(Fa[i])e[Fa[i]].pb(i);
	}scan(1);dfs(1);f(i,1,n)clear(t[0][i]),clear(t[1][i]);
	for(int i=n-1;i>=1;i--)res[i]=(res[i]+res[i+1])%mod;
	f(i,1,n)printf("%lld\n",res[i]);
	
	f(i,1,ncnt){
		f(j,0,25)tre[i][j]=0;
		Fa[i]=Len[i]=v[i]=0;e[i].clear();
		sz[i]=son[i]=0;
	}
	f(i,1,n)res[i]=0;
}
int main(){
	A[1].a[0][1]=A[1].a[1][1]=1;A[1].a[1][0]=3;
	B[1].a[0][0]=mod-i3,B[1].a[0][1]=i3,B[1].a[1][0]=1;
	f(i,2,300000)A[i]=A[i-1]*A[1],B[i]=B[i-1]*B[1];
	wt solve();
	return 0;
}