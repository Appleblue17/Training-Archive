#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int T, n, m, a[N], b[N], f[N], k;
vector<int> g[N];
void add(int u,int v,int c){
    int fu = f[u],fv = f[v];
    if(fu == fv){
        if(a[u]+a[v]){
            int nx = (c-b[u]-b[v])/(a[u]+a[v]);
            // to make fu = nx;
            for(int i=0;i<g[fv].size();i++){
                int w = g[fv][i];
                b[w] = nx*a[w]+b[w];
                a[w]=0;
                f[w]=w;
            }
            g[fv].clear();
            k++;
        }
        else{
            if(b[u]+b[v] == c){
                k++;
            }
            return;
        }
    }
    else{
        if(a[u] == 0 && a[v] == 0){
            if(b[u] + b[v] == c){
                k++;
            }
            return;
        }
        else if(a[u] == 0 || a[v] == 0){
            if(a[v] == 0){
                swap(u,v);
                swap(fu,fv);
            }
            //assert a[u] = 0
            int x = b[u];
            int nx = (c-b[v]-x)*a[v];//to make b[f[v]] = nx;
            //to make a[fv] = 0;b[fv] = nx;
            for(int i=0;i<g[fv].size();i++){
                int w = g[fv][i];
                b[w] = nx*a[w]+b[w];
                a[w]=0;
                f[w]=w;
                
            }
            g[fv].clear();
            k++;
            
        }
        else{
            if(g[fu].size()<g[fv].size()){
                swap(u,v);swap(fu,fv);
            }
            //assert g[u].size()<g[v].size()
            int nb = (c-b[u]-b[v])*a[v];
            int na = -a[u]*a[v];
            // to make fv = na*fu + nb
            for(int i=0;i<g[fv].size();i++){
                int w = g[fv][i];
                int ya = a[w];
                a[w] = ya*na;
                b[w] = ya*nb + b[w];
                f[w] = fu;
                g[fu].push_back(w);
            }
            g[fv].clear();
            k++;
            
        }
    }
}
void solve(){
    scanf("%lld%lld", &n, &m);
    k=0;
    for(int i=1;i<=n;i++){
        a[i]=1;b[i]=0;f[i]=i;
        g[i].clear();g[i].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int x,y,z,u,v,c;
        scanf("%lld%lld%lld",&x,&y,&z);
        u = (x+k-1)%n+1;
        v = (y+k-1)%n+1;
        int m = 1e9;
        c = ((z+k)%m)+1;
        int yk = k;
        if(1)add(u,v,c*2);
        else add(x,y,z*2);
        if(k != yk){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
        for(int i=1;i<=n;i++){
            //printf("i=%lld,a=%lld,b=%lld,f=%lld,g=",i,a[i],b[i],f[i]);
            //for(auto v:g[i]){
            //    printf("%lld ",v);
            //}
            //putchar('\n');
        }
    }
    
}
signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}