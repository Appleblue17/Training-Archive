#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=33,mod=998244353,inv2=(mod+1)/2;
int T,n,ans1,ans2;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

int c[N],s[N];

void dfs(int t,int sum,bool iseq){
    // cout<<t<<" "<<sum<<endl;
    
    if(t<0){
        if(sum>0 && !iseq) gmod(ans2+=sum);
        return ;
    }
    
    if(s[t]<=abs(sum) && !iseq){
        if(sum>0){
            // cout<<t<<" "<<sum<<" "<<iseq<<endl;
            gmod(ans2+=sum%mod*(1ll<<(t+1))%mod);
        }
        return ;
    }
    
    if(!iseq){
        dfs(t-1,sum+c[t],0);
        dfs(t-1,sum-c[t],0);
    }
    else{
        if(!(n>>t & 1)){
            dfs(t-1,sum+c[t],1);
        }
        else{
            dfs(t-1,sum+c[t],0);
            dfs(t-1,sum-c[t],1);
        }
    }
}

signed main(){
    // freopen("2.txt","w",stdout);
    // freopen("J.txt","r",stdin);
    // freopen("1.txt","w",stdout);
    
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        
        ans1=n*n%mod*(n-1)%mod*inv2%mod;
        ans2=0;
        
        // for(int t=0;t<=30;t++){
        //     g[t]=0;
        //     for(int i=0;i<n;i++){
        //         g[t]+=(i>>t & 1);
        //     }
        // }
        
        for(int t=0;t<=30;t++){
            int r=n%(1ll<<(t+1));
            c[t]=(n-r)/2+max(0ll,r-(1<<t));
        }
        
        // for(int t=0;t<=30;t++) cout<<g[t]<<" "; cout<<endl;
        // for(int t=0;t<=30;t++) cout<<c[t]<<" "; cout<<endl;
        
        for(int t=0;t<=30;t++) c[t] <<= t;
        s[0]=c[0];
        for(int t=1;t<=30;t++) s[t]=s[t-1]+c[t];
        
        dfs(30,0,1);
        
        int ans=(ans1+ans2)%mod*ksm(n*n%mod,mod-2)%mod;
        printf("%lld\n",ans);
    }
}
