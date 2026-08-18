#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=550,INF=1e18;
int T,n,a[N];

int rd(){
    bool fl=0;
    char c=getchar();
    int tot=0;
    while(!isdigit(c)){
        if(c=='-') fl=1;
        c=getchar();
    }
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return fl?-tot:tot;
}

unordered_map <int,int> mp;
int buc[N];

int p[N];
bool vis[N];

vector <int> G[N];

int TOT=0;
void dfs(int u){
    if(vis[u]) return ;
    vis[u]=1;
    TOT+=buc[u];
    for(int v: G[u]){
        if(!vis[v]) dfs(v);
    }
}

bool check(int x,int y,int xx,int yy){
    // cout<<"check "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
    x=a[x],y=a[y],xx=a[xx],yy=a[yy];
    // cout<<"check "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
    if(x==xx || y==yy) return 0;
    
    for(int i=1;i<=n;i++) G[i].clear(),vis[i]=0;
    for(int i=1;i<=n;i++){
        int t=a[i];
        int A=(yy-y)*(t-x),B=xx-x;
        if(A%B || !B) continue;
        int d=y+A/B;
        
        int s=mp[d];
        if(s) G[i].push_back(s),G[s].push_back(i);
    }
    
    for(int u=1;u<=n;u++){
        int tot=0;
        if(vis[u]) continue;
        TOT=0;
        dfs(u);
        if(TOT & 1) return 0;
    }
    // cout<<"OK"<<endl;
    return 1;
}

bool solve(){
    sort(a+1,a+n+1);
    
    for(int i=3;i<=n;i++){
        for(int j=4;j<=n;j++){
            if(i==j) continue;
            if(check(1,i,2,j)) return 1;
            if(check(1,i,j,2)) return 1;
        }
    }
    
    // 1,2
    for(int j=4;j<=n;j++){
        if(check(1,2,3,j)) return 1;
        if(check(1,2,j,3)) return 1;
    }
    return 0;
}

signed main(){
    T=rd();
    while(T--){
        n=rd()*2;
        
        mp.clear();
        for(int i=1;i<=n;i++) buc[i]=0;
        
        for(int i=1;i<=n;i++) a[i]=rd(),mp[a[i]]=i;
        for(int i=1;i<=n;i++){
            buc[mp[a[i]]]++;
        }
        
        if(solve()) printf("YES\n");
        else printf("NO\n");
    }
}