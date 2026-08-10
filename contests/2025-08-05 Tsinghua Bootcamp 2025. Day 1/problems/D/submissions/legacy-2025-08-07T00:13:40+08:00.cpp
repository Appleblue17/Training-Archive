#include<bits/stdc++.h>
using namespace std;
#define rep(mac,i) for(int mc=mac,i=getbit(mac);mc;mc^=(1<<i),i=getbit(mc))

const int N=18,M=3300;
char S[M];
int G[N];

int n,s;
double anss=0;
int L[N],R[N],D[N];

inline int getbit(int x){
    return __lg(x & (-x));
}

int p[N],id;
int MAC,IMAC,K;
int a[N],pat[N];

int pre[N][N];
int len[N];

void dfs(int t,int sum,int tot,int A){
    if(sum>s) return ;
    if(t>=id){
        int m=s-sum;
        int w=K*K*2;
        long long ans=1ll*tot*w;
        
        rep(MAC,i){
            int x=K*a[i]+m-A;
            // cout<<K<<" "<<m<<" "<<sum<<endl;
            // cout<<"x"<<i<<": "<<1.0*x/K<<endl;
            if(!(L[i]*K<=x && x<=R[i]*K)) return ;
            int y=K*a[i]+(K-1)*m+A;
            ans+=1ll*x*y;
        }
        // cout<<MAC<<" "<<K<<": "<<sum<<" "<<tot<<": ";
        // for(int i=0;i<n;i++) cout<<pat[i]<<" "; cout<<endl;
        // for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
        // cout<<1.0*ans/w<<endl;
        
        anss=max(anss,1.0*ans/w);
        return ;
    }
    int u=p[t];
    int val=0;
    rep(G[u] & IMAC & ((1<<u)-1),i) val+=pat[i];
    
    
    for(int i=0;i<len[u];i++) a[pre[u][i]]+=L[u];
    pat[u]=L[u];
    dfs(t+1,sum+L[u],tot+val*L[u],A+len[u]*L[u]);
    
    for(int i=0;i<len[u];i++) a[pre[u][i]]+=D[u];
    pat[u]=R[u];
    dfs(t+1,sum+R[u],tot+val*R[u],A+len[u]*R[u]);
    
    for(int i=0;i<len[u];i++) a[pre[u][i]]-=R[u];
}

signed main(){
    int sR=0;
    scanf("%s",S+1);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&L[i]);
    for(int i=0;i<n;i++) scanf("%d",&R[i]),sR+=R[i],D[i]=R[i]-L[i];
    
    scanf("%d",&s);
    s=min(s,sR);
    
    int slen=strlen(S+1);
    for(int i=1;i<=slen;i+=3){
        int u=S[i]-'a',v=S[i+1]-'a';
        G[u] |= 1<<v;
        G[v] |= 1<<u;
    }
    
    for(int mac=1;mac<(1<<n);mac++){
        bool fl=1;
        rep(mac,i){
            if((G[i] & mac)!=(mac^(1<<i))){
                fl=0;
                break;
            }
        }
        if(!fl) continue;
        id=0;
        rep(((1<<n)-1)^mac,i){
            if(!(mac>>i & 1)) p[id++]=i;
        }
        
        
        MAC=mac;
        IMAC=((1<<n)-1)^mac;
        K=__builtin_popcount(mac);
        
        rep(IMAC,i){
            len[i]=0;
            rep(G[i] & mac,j) pre[i][len[i]++]=j;
        }
        
        dfs(0,0,0,0);
    }
    
    cout<<setprecision(10)<<fixed<<anss;
}