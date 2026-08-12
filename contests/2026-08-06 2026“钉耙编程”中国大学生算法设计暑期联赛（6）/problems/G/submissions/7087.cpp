#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=11,M=2e6+5,INF=1e18,mod=1e8+7;
int T,n,m;

inline void rd(int& x){
    x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar())f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c^48);
    x=(f)?(-x):x;
}
inline void wt(int x){
    if(x>=10) wt(x/10);
    putchar('0'+x%10);
}

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

const int fx[6][6]={
    {0,1,0,0,0,1},
    {0,1,0,0,0,-1},
    {0,1,1,0,1,1},
    {0,1,-1,0,1,-1},
    {0,1,0,1,0,1},
    {1,1,1,1,1,1}
};

bool INV(int a[N][N],int b[N][N],int n){
	for(int i=1;i<=n;i++) b[i][i]=1;
	for(int k=1;k<=n;k++){
		int st=0;
		for(int i=k;i<=n;i++){
			if(a[i][k]){
				st=i;
				break;
			}
		}
		if(!st) return 0;
		if(st!=k)
			for(int j=1;j<=n;j++) swap(a[k][j],a[st][j]),swap(b[k][j],b[st][j]);
		for(int i=1;i<=n;i++){
			if(k==i) continue;
			int x=a[i][k]*ksm(a[k][k],mod-2)%mod;
			for(int j=1;j<=n;j++)
				a[i][j]=(a[i][j]+mod-a[k][j]*x%mod)%mod,
				b[i][j]=(b[i][j]+mod-b[k][j]*x%mod)%mod;
		}
	}
	for(int k=n;k>=1;k--){
		int x=ksm(a[k][k],mod-2);
		for(int j=1;j<=n;j++) a[k][j]=a[k][j]*x%mod,b[k][j]=b[k][j]*x%mod;
	}
	return 1;
}

int a[N][N],b[N][N];

int pw[N];
int f[M],g[M],h[M];

int A[N],B[N];

void fwt(int* f,int n,int w[N][N]){
    
    for(int k=1;k<n;k*=6){
        for(int i=0;i<n;i+=k*6){
            for(int j=i;j<i+k;j++){
                for(int x=0;x<6;x++) A[x]=f[j+k*x],B[x]=0;
                
                for(int y=0;y<6;y++){
                    for(int x=0;x<6;x++) gmod(B[y]+=A[x]*w[x+1][y+1]%mod);
                }
                
                for(int x=0;x<6;x++) f[j+k*x]=B[x];
            }
        }
    }
}

signed main(){
    // for(int t=0;t<6;t++){
    //     for(int i=0;i<6;i++){
    //         for(int j=0;j<6;j++){
    //             int k=i*j%6;
    //             if(fx[t][k]!=fx[t][i]*fx[t][j]){
    //                 cout<<"! "<<t<<" "<<i<<" "<<j<<endl;
    //             }
    //         }
    //     }
    // }
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*6;
    
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
            a[i][j]=(fx[j-1][i-1]+mod)%mod;
    int ret=INV(a,b,6);
    
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++)
            a[i][j]=(fx[j-1][i-1]+mod)%mod;
    
    // for(int i=1;i<=6;i++){
    //     for(int j=1;j<=6;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=1;i<=6;i++){
    //     for(int j=1;j<=6;j++){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    
    rd(T);
    while(T--){
        rd(n);
        for(int i=0;i<pw[n];i++) rd(f[i]);
        for(int i=0;i<pw[n];i++) rd(g[i]);
        fwt(f,pw[n],a);
        fwt(g,pw[n],a);
        for(int i=0;i<pw[n];i++) h[i]=f[i]*g[i]%mod;
        fwt(h,pw[n],b);
        
        // cout<<"f: "; for(int i=0;i<pw[n];i++) wt(f[i]),putchar(' ');
        // putchar('\n');
        // cout<<"g: "; for(int i=0;i<pw[n];i++) wt(g[i]),putchar(' ');
        // putchar('\n');
        // cout<<"h: "; for(int i=0;i<pw[n];i++) wt(h[i]),putchar(' ');
        // putchar('\n');
        // cout<<"h: "; for(int i=0;i<pw[n];i++) cout<<h[i]<<" ",putchar(' ');
        // putchar('\n');
        
        for(int i=0;i<pw[n];i++) wt(h[i]),putchar(' ');
        putchar('\n');
    }
}