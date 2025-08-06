#pragma GCC optimize(2)
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
const int N=1e6+105;
int T, n, m;
char t[N/2], s[N];
int sz[N/2];
int mxlen;
int tr[N][26], idx;
int fa[N], tag[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x, int y){
	x=get(x); y=get(y);
	if(x!=y) fa[x]=y;
}
int nxt[N];
void build(){
	queue<int> q;
	for(int i=0; i<26; ++i) q.push(tr[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0; i<26; ++i){
			int &c=tr[t][i];
			if(!c) c=tr[nxt[t]][i];
			else{
				nxt[c]=tr[nxt[t]][i];
				q.push(c);
			}
		}
	}
}
const int p1=998244353, p2=993244853;
struct hsh{
	int x, y;
	hsh(int _x=0, int _y=0){x=_x; y=_y;}
	inline hsh operator +(const hsh &t){
		return (hsh){(x+t.x)%p1, (y+t.y)%p2};
	}
	inline hsh operator -(const hsh &t){
		return (hsh){(x-t.x+p1)%p1, (y-t.y+p2)%p2};
	}
	inline hsh operator *(const hsh &t){
		return (hsh){(int)((ll)x*t.x%p1), (int)((ll)y*t.y%p2)};
	}
	inline void operator +=(const hsh &t){
		x=(x+t.x)%p1, y=(y+t.y)%p2;
	}
	inline bool operator ==(const hsh &t){
		return x==t.x&&y==t.y;
	}
}bs, pw[N/2];
vector<int> e[N];
int info[N];
vector<int> id[N/2];
void dfs(int x){
	for(auto y:e[x]){
		if(tag[y]){
			info[y]=tag[y];
		}
		else{
			info[y]=info[x];
		}
		dfs(y);
	}
}
int mat[N/2];
int f[N/2][19];
pair<hsh, int> g[N/2][19];
int rk[N/2];
vector<pair<hsh, int> > hs[N/2];
inline hsh str(int l, int r){
	hsh ret=(hsh){0, 0};
	for(int t=18; t>=0; --t){
		if(f[l][t]<=r+1){
			ret=ret*pw[g[l][t].se]+g[l][t].fi;
			l=f[l][t];
		}
	}
	if(l!=r+1){
		ret=ret*pw[hs[mat[l]][r-l+1].se]+hs[mat[l]][r-l+1].fi;
	}
	return ret;
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	bs=(hsh){131, 13331};
	pw[0]=(hsh){1, 1};
	for(int i=1; i<N/2; ++i) pw[i]=pw[i-1]*bs;
	scanf("%s", t+1);
	read(n); read(m);
	for(int i=1; i<=n+26; ++i) fa[i]=i;
	for(int i=0; i<26; ++i){
		tr[0][i]=i+1; tag[i+1]=i+1; sz[i+1]=1; 
	}
	idx=26;
	for(int i=27; i<=n+26; ++i){
		scanf("%s", s+1);
		int p=0;
		int len=strlen(s+1);
		for(int j=len; j>=1; --j) {
			if(!tr[p][s[j]-'a']) tr[p][s[j]-'a']=++idx;
			p=tr[p][s[j]-'a'];
			id[i].push_back(p);
		}
		reverse(id[i].begin(), id[i].end());
		tag[p]=i;
		mxlen=max(mxlen, len);
		sz[i]=len;
		rk[i-26]=i;
	}
	build();
	for(int i=1, x, y; i<=m; ++i){
		read(x); read(y);
		merge(x, y);
	}
	for(int i=1; i<=26; ++i){
		hs[i].resize(2);
		hs[i][1].se=1;
		hs[i][1].fi=(hsh){get(i), get(i)};
	}
	for(int i=1; i<=idx; ++i) e[nxt[i]].push_back(i);
	dfs(0);
	int lent=strlen(t+1); int p=0;
	f[lent+1][0]=lent+1;
	for(int i=lent; i>=1; --i){
		p=tr[p][t[i]-'a'];
		int w=info[p];
		f[i][0]=i+sz[w];
		g[i][0]=mapa((hsh){get(w), get(w)}, 1);
		mat[i]=w;
	}
	for(int t=1; t<19; ++t){
		for(int i=1; i<=lent+1; ++i){
			f[i][t]=f[f[i][t-1]][t-1];
			g[i][t].se=g[i][t-1].se+g[f[i][t-1]][t-1].se;
			g[i][t].fi=g[i][t-1].fi*pw[g[f[i][t-1]][t-1].se]+g[f[i][t-1]][t-1].fi;
		}
	}
	n+=26;
	sort(rk+1, rk+n+1, [&](int x, int y){return sz[x]<sz[y];});
	for(int i=1; i<=n; ++i){
		int p=rk[i];
		hs[p].resize(sz[p]+1);
		for(int j=1; j<=sz[p]; ){
			int q=info[id[p][j-1]];
			if(q==p) q=info[nxt[id[p][j-1]]];
			for(int k=1; k<sz[q]; ++k){
				hs[p][j+k-1].se=hs[p][j-1].se+hs[q][k].se;
				hs[p][j+k-1].fi=hs[p][j-1].fi*pw[hs[q][k].se]+hs[q][k].fi;
			}
			hs[p][j+sz[q]-1].se=hs[p][j-1].se+1;
			hs[p][j+sz[q]-1].fi=hs[p][j-1].fi*bs+(hsh){get(q), get(q)};
			j+=sz[q];
		}
		id[p].clear();
		id[p].shrink_to_fit();
	}
	int q;
	scanf("%d", &q);
	while(q--){
		int l1, r1, l2, r2;
		read(l1); read(r1); read(l2); read(r2);
		if(str(l1, r1)==str(l2, r2)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
