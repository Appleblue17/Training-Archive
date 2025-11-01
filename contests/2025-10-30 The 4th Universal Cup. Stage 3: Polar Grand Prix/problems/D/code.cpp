#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=1e6+5;
int T,n,m,q;

struct abc{
    int to,nxt,w;
}e[N*2];
int head[N],cnt;
void add(int u,int v,int w){
    e[++cnt]={v,head[u],w};
    head[u]=cnt;
}

int a[N],b[N],p[N];

unordered_map <int, int> mp[N];
long long cal(int u,int v){
    return 1ll*u*(n+1)+v;
}

bool vis[N];
int que[N], hh, tt;
bool check(int k){
    for(int i=0;i<n;i++) vis[i]=0;
    hh=1, tt=0;
    que[++tt]=0; vis[0]=1;
    while(hh<=tt){
        int u=que[hh++];
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to,w=e[i].w;
            if(vis[v]) continue;
            if(p[w] && p[w]<=k) continue;
            que[++tt]=v;
            vis[v]=1;
        }
    }
    
    for(int i=0;i<n;i++) if(!vis[i]) return 0;
    return 1;
}

mt19937 rng(123);
int main(){
    // freopen("1.txt","w",stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d",&n,&m,&q);
        for(int i=0;i<n;i++) head[i]=0, mp[i].clear();
        for(int i=1;i<=m;i++) p[i]=0;
        cnt=0;
        
        for(int i=1;i<=m;i++){
            int u,v; scanf("%d%d",&u,&v);
            // int u=0,v=i-1;
            add(u,v,i);
            add(v,u,i);
            if(u>v) swap(u, v);
            mp[u][v]=i;
        }
        // return 0;
        
        for(int i=1;i<=q;i++){
            scanf("%d%d",&a[i],&b[i]);
            // a[i]=rng()%n,b[i]=rng()%n;
        }
        
        int x=0,y=0;
        for(int i=1;i<=q;i++){
            int u=(x+a[i])%n,v=(y+b[i])%n;
            if(u>v) swap(u, v);
            int s=mp[u][v];
            if(!p[s]) p[s]=i;
            
            x=(x*2+1)%n;
            y=(y*3+1)%n;
        }
        int l=0,r=q,tot=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)) tot=mid,l=mid+1;
            else r=mid-1;
        }
        for(int i=1;i<=tot;i++){
            putchar('1'); putchar('\n');
        }
        for(int i=1;i<=q-tot;i++){
            putchar('0'); putchar('\n');
        }
    }
}
