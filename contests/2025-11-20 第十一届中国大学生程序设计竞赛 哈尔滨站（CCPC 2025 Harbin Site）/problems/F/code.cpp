#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,mod=1e9+7;
int T,m,garbage;
int a[N];

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}

int s[N],inv[N],invs[N];

void gmod(int &x){
    x%=mod;
}
int f[N], g[N], h[N], ff[N], gg[N], hh[N], blk[N];
signed main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld%lld",&m,&garbage);
        for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
        for(int i=0; i<=m+2; ++i){
            f[i]=0; g[i]=0; h[i]=0; ff[i]=0; gg[i]=0; hh[i]=0; blk[i]=0;
        }
        gg[0]=1;
		for(int i=1; i<=m; ++i){
			gmod(h[i]+=f[i-1]);
			gmod(h[i]+=ff[i-1]);
			if(a[i-1]>1) gmod(h[i]+=h[i-1]);
			if(a[i-2]==1) gmod(h[i]+=h[i-2]);
			if(i>1) gmod(h[i]+=g[i-2]);
			if(i>1) gmod(h[i]+=gg[i-2]);
			
			gmod(hh[i]+=h[i-1]);
			gmod(hh[i]+=hh[i-1]);
			
			gmod(blk[i]+=f[i-1]);
			gmod(blk[i]+=g[i-1]);
			if(i>1) gmod(blk[i]+=blk[i-2]);
			
			gmod(ff[i]+=(ff[i-1]+gg[i-1])*(a[i]-1));
			gmod(f[i]+=(f[i-1]+g[i-1]+h[i-1])*(a[i]-1));
			if(i>2) gmod(f[i]+=h[i-2]*(a[i]-a[i-2]));
			if(i>2&&a[i]-a[i-2]-1>=0) gmod(f[i]+=hh[i-2]*(a[i]-a[i-2]-1));
			if(a[i]>1) gmod(f[i]+=h[i]*(a[i]-2));
			if(i>2&&a[i]-a[i-2]-1>=0) gmod(f[i]+=blk[i-2]*(a[i]-a[i-2]-1));
			
			
			gmod(gg[i]+=ff[i-1]+gg[i-1]);
			gmod(g[i]+=f[i-1]+g[i-1]+h[i-1]);
			if(i>1) gmod(g[i]+=h[i-2]);
			if(i>2&&a[i]>a[i-2]) gmod(g[i]+=hh[i-2]);
			if(a[i]>1) gmod(g[i]+=h[i]);
			if(i>2&&a[i]>a[i-2]) gmod(g[i]+=blk[i-2]);
			// cout<<ff[i]<<' '<<gg[i]<<' '<<f[i]<<' '<<g[i]<<' '<<h[i]<<endl;
		}
        int ans=0;
		for(int i=1; i<=m; ++i) gmod(ans+=h[i]);
		for(int i=m; i>=1; i-=2) gmod(ans+=f[i]+g[i]);
		gmod(ans+=ff[m]);
		gmod(ans+=gg[m]);
        printf("%lld\n", ans);
    }
    
}
