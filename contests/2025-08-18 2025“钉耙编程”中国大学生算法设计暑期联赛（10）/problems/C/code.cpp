#include<bits/stdc++.h>
using namespace std;
const int N=1100,mod=998244353;
int T,n,m;
int a[N][N],b[N][N],c[N][N];

int ksm(int a,int x){
	int tot=1;
	while(x){
		if(x&1) tot=1ll*tot*a%mod;
		a=1ll*a*a%mod;
		x>>=1ll;
	}
	return tot;
} 

int det(int a[N][N]){
	int tot=1;
	for(int k=1;k<=n;k++){
		int st=0;
		for(int i=k;i<=n;i++){
			if(a[i][k]){
				st=i;
				break;
			}
		}
		if(!st) return 0;
		for(int j=1;j<=n;j++) swap(a[k][j],a[st][j]);
		if(st!=k) tot=mod-tot;
		for(int i=k+1;i<=n;i++){
			int t=1ll*a[i][k]*ksm(a[k][k],mod-2)%mod;
			for(int j=k;j<=n;j++) a[i][j]=(a[i][j]+mod-1ll*a[k][j]*t%mod)%mod;
		}
		tot=1ll*tot*a[k][k]%mod;
	}
	return tot;
}

mt19937 rng(time(0));


int solve(){
    int x=det(a);
    int tot=1,ans=-1;
    for(int i=1;i<=m;i++){
        tot=1ll*tot*x%mod;
        if(tot==1){
            ans=i;
            break;
        }
    }
    return ans;
}

int v[N],f[N],g[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        
        int ans=-1;
        for(int i=1;i<=n;i++) v[i]=f[i]=rng()%mod;
        for(int t=1;1ll*t*n*n<=4e8 && ans==-1;t++){
            for(int i=1;i<=n;i++) g[i]=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    g[j]=(g[j]+1ll*a[i][j]*f[i]%mod)%mod;
                }
            }
            for(int i=1;i<=n;i++) f[i]=g[i];
            bool fl=1;
            for(int i=1;i<=n && fl;i++) if(f[i]!=v[i]) fl=0;
            if(fl){
                ans=t;
                break;
            }
        }
        if(ans!=-1) cout<<ans<<endl;
        else cout<<solve()<<endl;
    }
	
	
}