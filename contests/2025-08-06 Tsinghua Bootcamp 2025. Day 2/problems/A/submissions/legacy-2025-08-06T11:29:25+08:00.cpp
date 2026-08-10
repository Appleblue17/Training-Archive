#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,mod=998244353,INF=1e9;
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

int T,n,a[N];

vector <int> V[N];
int vis[N],pos[N];

int p[N],id;
int s[N];

int solve(){
    for(int i=3;i<n;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]) return 0;
    }
    id=0;
    
    for(int i=2;i<=n;i++) V[a[i]].push_back(i);
    
    for(int i=1;i<=n;i++){
        if(V[i].size()>2) return 0;
        if(V[i].size()==2){
            int x=V[i][0],y=V[i][1];
            if(abs(x-y)>1) return 0;
            else{
                vis[i]=1;
                pos[min(x,y)]=i;
                // cout<<"get "<<i<<" "<<min(x,y)<<endl;
            }
        }
    }
    
    int tot=1;
    for(int l=1,r;l<=n;l=r+1){
        r=l;
        if(pos[l]) continue;
        while(r+1<=n && !pos[r+1]) r++;
        
        // cout<<"seg "<<l<<" "<<r<<endl; 
        
        for(int i=max(2ll,l);i<=min(n-1,r);i++){
            int x=a[i],y=a[i+1];
            if(x>y){
                // cout<<"put1 "<<i-1<<" "<<x<<endl;
                if(pos[i-1]){
                    if(pos[i-1]!=x) return 0;
                }
                else{
                    if(vis[x]) return 0;
                    vis[x]=1;
                    pos[i-1]=x;
                }
            }
            if(x<y){
                // cout<<"put2 "<<i+1<<" "<<y<<endl;
                if(pos[i+1]){
                    if(pos[i+1]!=y) return 0;
                }
                else{
                    if(vis[y]) return 0;
                    vis[y]=1;
                    pos[i+1]=y;
                }
            }
        }
        
        vector <int> TMP;
        for(int i=l;i<=r;i++){
            if(!pos[i]) TMP.push_back(i);
        }
        // cout<<"siz "<<TMP.size()<<endl;
        if(TMP.size()==1){
            int t=TMP[0];
            // cout<<t<<": "<<a[t]<<" "<<a[t+1]<<endl;
            p[++id]=min(a[t],a[t+1]);
        }
        else if(TMP.size()==2){
            // cout<<" ! "<<TMP[0]<<" "<<TMP[1]<<endl;
            
            int t=max(TMP[0],TMP[1]),val=a[t];
            // cout<<" tmp "<<t<<" "<<val<<endl;
            if(val==1) return 0;
            tot=tot*2%mod;
            p[++id]=val;
            if(vis[val]) return 0;
            vis[val]=1;
        }
        else assert(0);
    }
    
    sort(p+1,p+id+1);
    // cout<<"p"<<" "; for(int i=1;i<=id;i++) cout<<p[i]<<" "; cout<<endl;
    // cout<<"vis"<<" "; for(int i=1;i<=n;i++) if(!vis[i]) cout<<i<<" "; cout<<endl;
    
    for(int i=1;i<=n;i++) s[i]=s[i-1]+(vis[i]==0);
    for(int i=1;i<=id;i++){
        tot=tot*(s[p[i]]-i+1)%mod;
    }
    
    return tot;
}

signed main(){
    // freopen("1.txt","w",stdout);
    init(N-5);
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=0;i<=n+1;i++){
            V[i].clear();
            pos[i]=vis[i]=0;
        }
        
        for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
        a[1]=a[n+1]=INF;
        
        int ans=solve();
        printf("%lld\n",ans);
    }
}