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
int p[N];
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
}bs, pw[N];
int pos[N];
int a[N];
hsh hsp[N], hsa[N];
int pre[N], suf[N];
int pretag[N], suftag[N];
vector<pii> e[N];
hsh geta(int l, int r){
	return hsa[r]-hsa[l-1]*pw[r-l+1];
}
hsh getp(int l, int r){
	return hsp[r]-hsp[l-1]*pw[r-l+1];
}
int preocc[N], sufocc[N];
int fr[N][2], frid[N][2], frtp[N][2], dis[N][2], disfr[N][2];
vector<int> vec;
void back(int x, int id){
	if(x==1) return ;
	vec.ep(frid[x][id]);
	back(fr[x][id], frtp[x][id]);
}
int sumflag[N];
void solve(){
	read(n); read(m); read(q);
	for(int i=1; i<=n; ++i) {
		read(p[i]), pos[p[i]]=i;
		hsp[i]=hsp[i-1]*bs+(hsh){p[i], p[i]};
		pre[i]=suf[i]=0; pretag[i]=0; suftag[i]=0;
		e[i].clear();
	}
	for(int i=1; i<=m; ++i){
		read(a[i]);
		hsa[i]=hsa[i-1]*bs+(hsh){a[i], a[i]};
	}
	for(int i=1; i+n-1<=m; ++i){
		sumflag[i]=sumflag[i-1];
		if(geta(i, i+n-1)==getp(1, n)){
			sumflag[i]++;
		}
	}
	for(int i=1; i<=m; ++i){
		if(a[i]==p[1]){
			preocc[i]=i;
		}
		else{
			preocc[i]=preocc[i-1];
		}
	}
	sufocc[m+1]=m+1;
	for(int i=m; i>=1; --i){
		if(a[i]==p[n]){
			sufocc[i]=i;
		}
		else{
			sufocc[i]=sufocc[i+1];
		}
	}
	int sp=0;
	for(int i=1, l, r; i<=q; ++i){
		read(l); read(r);
		int it=pos[a[l]];
		if(r-l+1>=n&&sumflag[r-n+1]-sumflag[l-1]>0){
			sp=i; continue;
		}
		if(it+(r-l+1)-1<=n&&geta(l, r)==getp(it, it+(r-l+1)-1)){
			e[it].ep(it+(r-l+1), i);
			continue;
		}
		if(preocc[r]>=l){
			int cl=preocc[r], cr=r;
			if(cr-cl+1<=n&&geta(cl, cr)==getp(1, cr-cl+1)){
				if(pre[cr-cl+1]==0) pre[cr-cl+1]=i;
				else pretag[cr-cl+1]=i;
			}
		}
		if(sufocc[l]<=r){
			int cl=l, cr=sufocc[l];
			if(cr-cl+1<=n&&geta(cl, cr)==getp(n-(cr-cl+1)+1, n)){
				if(suf[n-(cr-cl+1)+1]==0) suf[n-(cr-cl+1)+1]=i;
				else suftag[n-(cr-cl+1)+1]=i;
			}
		}
	}
	if(sp!=0){
		printf("1\n%d\n", sp);
		return ;
	}
	for(int i=1; i<=n+1; ++i){
		dis[i][0]=dis[i][1]=1e9;
	}
	dis[1][0]=0; disfr[1][0]=0;
	for(int i=1; i<=n; ++i){
		if(pre[i]!=0){
			dis[i+1][0]=1; disfr[i+1][0]=pre[i]; fr[i+1][0]=1; frid[i+1][0]=pre[i];
			if(pretag[i]!=0){
				dis[i+1][1]=1; disfr[i+1][1]=pretag[i]; fr[i+1][1]=1; frid[i+1][1]=pretag[i];
			}
		}
	}
	for(int x=1; x<=n; ++x){
		// cout<<x<<':'<<dis[x][0]<<' '<<dis[x][1]<<endl;
		for(auto edg:e[x]){
			int y=edg.fi;
			if(dis[y][0]>dis[x][0]+1){
				if(disfr[y][0]!=disfr[x][0]) {
					dis[y][1]=dis[y][0]; disfr[y][1]=disfr[y][0]; fr[y][1]=fr[y][0]; frid[y][1]=frid[y][0]; frtp[y][1]=frtp[y][0];
				}
				dis[y][0]=dis[x][0]+1; disfr[y][0]=disfr[x][0]; fr[y][0]=x; frid[y][0]=edg.se; frtp[y][0]=0;
			}
			else if(dis[y][1]>dis[x][0]+1&&(!(dis[y][0]==dis[x][0]+1&&disfr[y][0]==disfr[x][0]))){
				dis[y][1]=dis[x][0]+1; disfr[y][1]=disfr[x][0]; fr[y][1]=x; frid[y][1]=edg.se; frtp[y][1]=0;
			}
			
			if(dis[y][0]>dis[x][1]+1){
				if(disfr[y][0]!=disfr[x][1]) {
					dis[y][1]=dis[y][0]; disfr[y][1]=disfr[y][0]; fr[y][1]=fr[y][0]; frid[y][1]=frid[y][0]; frtp[y][1]=frtp[y][0];
				}
				dis[y][0]=dis[x][1]+1; disfr[y][0]=disfr[x][1]; fr[y][0]=x; frid[y][0]=edg.se; frtp[y][0]=1;
			}
			else if(dis[y][1]>dis[x][1]+1&&(!(dis[y][0]==dis[x][1]+1&&disfr[y][0]==disfr[x][1]))){
				dis[y][1]=dis[x][1]+1; disfr[y][1]=disfr[x][1]; fr[y][1]=x; frid[y][1]=edg.se; frtp[y][1]=1;
			}
			
		}
		int y=n+1;
		if(suf[x]!=0){
			if(dis[y][0]>dis[x][0]+1&&suf[x]!=disfr[x][0]){
				if(disfr[y][0]!=disfr[x][0]) {
					dis[y][1]=dis[y][0]; disfr[y][1]=disfr[y][0]; fr[y][1]=fr[y][0]; frid[y][1]=frid[y][0]; frtp[y][1]=frtp[y][0];
				}
				dis[y][0]=dis[x][0]+1; disfr[y][0]=disfr[x][0]; fr[y][0]=x; frid[y][0]=suf[x]; frtp[y][0]=0;
			}
			else if(dis[y][1]>dis[x][0]+1&&suf[x]!=disfr[x][0]&&(!(dis[y][0]==dis[x][0]+1&&disfr[y][0]==disfr[x][0]))){
				dis[y][1]=dis[x][0]+1; disfr[y][1]=disfr[x][0]; fr[y][1]=x; frid[y][1]=suf[x]; frtp[y][1]=0;
			}
			if(dis[y][0]>dis[x][1]+1&&suf[x]!=disfr[x][1]){
				if(disfr[y][0]!=disfr[x][1]) {
					dis[y][1]=dis[y][0]; disfr[y][1]=disfr[y][0]; fr[y][1]=fr[y][0]; frid[y][1]=frid[y][0]; frtp[y][1]=frtp[y][0];
				}
				dis[y][0]=dis[x][1]+1; disfr[y][0]=disfr[x][1]; fr[y][0]=x; frid[y][0]=suf[x]; frtp[y][0]=1;
			}
			else if(dis[y][1]>dis[x][1]+1&&suf[x]!=disfr[x][1]&&(!(dis[y][0]==dis[x][1]+1&&disfr[y][0]==disfr[x][1]))){
				dis[y][1]=dis[x][1]+1; disfr[y][1]=disfr[x][1]; fr[y][1]=x; frid[y][1]=suf[x]; frtp[y][1]=1;
			}
			
			if(suftag[x]!=0){
				if(dis[y][0]>dis[x][0]+1&&suftag[x]!=disfr[x][0]){
					if(disfr[y][0]!=disfr[x][0]) {
						dis[y][1]=dis[y][0]; disfr[y][1]=disfr[y][0]; fr[y][1]=fr[y][0]; frid[y][1]=frid[y][0]; frtp[y][1]=frtp[y][0];
					}
					dis[y][0]=dis[x][0]+1; disfr[y][0]=disfr[x][0]; fr[y][0]=x; frid[y][0]=suftag[x]; frtp[y][0]=0;
				}
				else if(dis[y][1]>dis[x][0]+1&&suftag[x]!=disfr[x][0]&&(!(dis[y][0]==dis[x][0]+1&&disfr[y][0]==disfr[x][0]))){
					dis[y][1]=dis[x][0]+1; disfr[y][1]=disfr[x][0]; fr[y][1]=x; frid[y][1]=suftag[x]; frtp[y][1]=0;
				}
				if(dis[y][0]>dis[x][1]+1&&suftag[x]!=disfr[x][1]){
					if(disfr[y][0]!=disfr[x][1]) {
						dis[y][1]=dis[y][0]; disfr[y][1]=disfr[y][0]; fr[y][1]=fr[y][0]; frid[y][1]=frid[y][0]; frtp[y][1]=frtp[y][0];
					}
					dis[y][0]=dis[x][1]+1; disfr[y][0]=disfr[x][1]; fr[y][0]=x; frid[y][0]=suftag[x]; frtp[y][0]=1;
				}
				else if(dis[y][1]>dis[x][1]+1&&suftag[x]!=disfr[x][1]&&(!(dis[y][0]==dis[x][1]+1&&disfr[y][0]==disfr[x][1]))){
					dis[y][1]=dis[x][1]+1; disfr[y][1]=disfr[x][1]; fr[y][1]=x; frid[y][1]=suftag[x]; frtp[y][1]=1;
				}
				
			}
		}
	}
	if(min(dis[n+1][0], dis[n+1][1])==1e9){
		printf("-1\n");
		return ;
	}
	printf("%d\n", min(dis[n+1][0], dis[n+1][1]));
	vec.clear();
	if(dis[n+1][0]<=dis[n+1][1]){
		back(n+1, 0);
	}
	else{
		back(n+1, 1);
	}
	reverse(vec.begin(), vec.end());
	for(auto t:vec) printf("%d ", t);
	putchar('\n');
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	bs=(hsh){300007, 300017};
	pw[0]=(hsh){1, 1};
	for(int i=1; i<N; ++i) pw[i]=pw[i-1]*bs;
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
