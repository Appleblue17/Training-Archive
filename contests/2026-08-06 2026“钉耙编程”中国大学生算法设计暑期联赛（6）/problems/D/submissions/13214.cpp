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
const int N=2e6+5;
int T, n, m;
struct solver{
    int a[N];
    int sum[N][3];
    int jmp[N];
    int jmp3[N];
    inline bool chk(int x, int y, int z){
        return x!=y&&y!=z&&x!=z;
    }
    pii srk(int l, int r){
        if(r<l) return mapa(l, r);
        int s[3]={0, 0, 0};
        s[0]=sum[r][0]-sum[l-1][0];
        s[1]=sum[r][1]-sum[l-1][1];
        s[2]=sum[r][2]-sum[l-1][2];
        if(chk(s[0], s[1], s[2])) return mapa(l, r);
        if(s[0]==s[1]&&s[1]==s[2]){
            int nr=jmp3[r];
            if(nr<l){
                return mapa(l, l-1);
            }
            if(a[r]==a[r-1]&&a[r]==a[r-2]) return srk(l, r-3);
            return mapa(l, r-3);
        }
        if(s[0]==s[2]&&s[1]>s[0]){
            int op=1, op2=0;
            int cnt=0, nr=r;
            if(a[r]==op) cnt=r-jmp[r], nr=jmp[r];
            if(s[op]-cnt>s[op2]){
                return mapa(l, nr-1);
            }
            else{
                return srk(l, r-(s[op]-s[op2]));
            }
        }
        if(s[0]==s[1]&&s[2]>s[0]){
            int op=2, op2=0;
            int cnt=0, nr=r;
            if(a[r]==op) cnt=r-jmp[r], nr=jmp[r];
            if(s[op]-cnt>s[op2]){
                return mapa(l, nr-1);
            }
            else{
                return srk(l, r-(s[op]-s[op2]));
            }
        }
        if(s[2]==s[1]&&s[0]>s[1]){
            int op=0, op2=1;
            int cnt=0, nr=r;
            if(a[r]==op) cnt=r-jmp[r], nr=jmp[r];
            if(s[op]-cnt>s[op2]){
                return mapa(l, nr-1);
            }
            else{
                return srk(l, r-(s[op]-s[op2]));
            }
        }
        int op=0;
        if(s[0]==s[2]) op=1;
        if(s[0]==s[1]) op=2;
        if(a[r]==op) return mapa(l, jmp[r]-1);
        if(s[(op+1)%3]-1!=s[op]) return mapa(l, r-1);
        return srk(l, r-2);
    }
    void init(){
        for(int i=1; i<=n; ++i){
        for(int j=0; j<3; ++j) sum[i][j]=sum[i-1][j];
            ++sum[i][a[i]];
        }
        for(int i=1; i<=n; ++i){
            if(i!=1&&a[i]==a[i-1]) jmp[i]=jmp[i-1];
            else jmp[i]=i-1;
            if(i>=3&&chk(a[i], a[i-1], a[i-2])) jmp3[i]=jmp3[i-3];
            else jmp3[i]=i;
        }
    }
}S1, S2;
char s[N];
void solve(){
    read(n);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i){
        if(s[i]=='A') S1.a[i]=S2.a[n+1-i]=0;
        else if(s[i]=='B') S1.a[i]=S2.a[n+1-i]=1;
        else S1.a[i]=S2.a[n+1-i]=2;
    } 
    
    
    S1.init(); S2.init();
    int lst=0;
    read(m);
    for(int i=1, ql, qr; i<=m; ++i){
        read(ql); read(qr);
        ql=((ql^lst)-1)%n+1;
        qr=((qr^lst)-1)%n+1;
        if(ql>qr) swap(ql, qr);
        pii ans=mapa(0, -1);
        for(int l=ql, r=qr; l<=ql+2&&l<=r; ++l){
            pii ret=S1.srk(l, r);
            if(ret.se-ret.fi>ans.se-ans.fi){
                ans=ret;
            }
        }
        for(int r=qr, l=ql; r>=qr-2&&l<=r; --r){
            pii ret=S2.srk(n+1-r, n+1-l);
            swap(ret.fi, ret.se);
            ret.fi=n+1-ret.fi; ret.se=n+1-ret.se;
            if(ret.se-ret.fi>ans.se-ans.fi){
                ans=ret;
            }
        }
        if(ans.se<ans.fi) printf("%d %d\n", 0, 0), lst=0;
        else printf("%d %d\n", ans.fi, ans.se), lst=ans.se-ans.fi+1;
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	// read(T);
    T=1;
	while(T--){
		solve();
	}
	return 0;
}