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
const int N=1e5+5;
int T, n, m;
struct IO{
    static const int S=1<<21;
    char buf[S],*p1,*p2;int st[105],Top;
    ~IO(){clear();}
    inline void clear(){fwrite(buf,1,Top,stdout);Top=0;}
    inline void pc(const char c){Top==S&&(clear(),0);buf[Top++]=c;}
    inline char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    inline IO&operator >> (char&x){while(x=gc(),x==' '||x=='\n'||x=='\r');return *this;}
    template<typename T>inline IO&operator >> (T&x){
        x=0;bool f=0;char ch=gc();
       while(!isdigit(ch)){if(ch=='-') f^=1;ch=gc();}
        while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
        f?x=-x:0;return *this;
    }
    inline IO&operator << (const char c){pc(c);return *this;}
    template<typename T>inline IO&operator << (T x){
        if(x<0) pc('-'),x=-x;
        do{st[++st[0]]=x%10,x/=10;}while(x);
        while(st[0]) pc('0'+st[st[0]--]);return *this;
    }
}fin,fout;
int tr[N*32][2]; bool sum[N*32]; int dep[N*32], idx;
void solve(){
    idx=1;
    fin>>n;
    ll ans=0;
    for(int i=1, x; i<=n; ++i){
        fin>>x; --x;
        ans^=x;
        for(int j=0, c, p=1; j<31; ++j) {
            c=(x>>j)&1;
            if(!tr[p][c]) tr[p][c]=++idx, dep[idx]=j+1;
            p=tr[p][c]; sum[p]^=1;
        }
    }
    for(int i=1; i<=idx; ++i){
        if(sum[tr[i][0]]&&sum[tr[i][1]]) ans^=((1ll<<(dep[i]+1))-1);
        // cout<<dep[i]<<' '<<sum[tr[i][0]]<<' '<<sum[tr[i][1]]<<endl;
        tr[i][0]=tr[i][1]=sum[i]=0;
    }
    if(ans==0) fout.pc('N'), fout.pc('O');
    else fout.pc('Y'), fout.pc('E'), fout.pc('S');
    fout.pc('\n');
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	fin>>T;
	while(T--){
		solve();
	}
	return 0;
}