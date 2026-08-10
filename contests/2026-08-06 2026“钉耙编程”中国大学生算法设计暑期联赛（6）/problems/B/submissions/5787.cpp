#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+5,INF=1e18;
int T,n,lim=1e7,B=1000;
bool a[N];
int g[N],s[N];

bool notpr[N];
int pr[N],pid,phi[N];

void init(int lim){
    phi[1]=1;
    for(int i=2;i<=lim;i++){
        if(!notpr[i]) pr[++pid]=i,phi[i]=i-1;
        for(int j=1;j<=pid && pr[j]<=lim/i;j++){
            notpr[i*pr[j]]=1;
            if(i%pr[j]) phi[i*pr[j]]=phi[i]*(pr[j]-1);
            else{
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            }
        }
    }
}

signed main(){
    freopen("3.out","w",stdout);
    init(lim);
    
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=lim;i++) a[i]=g[i]=s[i]=0;
        
        for(int i=1;i<=n;i++){
            int x; scanf("%lld",&x);
            a[x]=1;
        }
        
        for(int i=1;i<=lim;i++){
            for(int j=1;j<=lim/i;j++){
                if(a[i*j]) g[i]=max(g[i],i*phi[i*j]/phi[i]);
            }
        }
        // for(int i=1;i<=10;i++) cout<<g[i]<<" "; cout<<endl;
        
        for(int i=1;i<=lim;i++){
            for(int j=1;j<=lim/i;j++){
                s[i*j]=max(s[i*j],g[i]);
            }
        }
        
        // for(int i=1;i<=30;i++) cout<<s[i]<<" "; cout<<endl;
        for(int i=0;i<B;i++){
            int tot=0;
            for(int j=1,x=i;x<=lim;j++,x+=B) tot^=j*s[x]*x;
            printf("%lld\n",tot);
        }
    }
    
}21321