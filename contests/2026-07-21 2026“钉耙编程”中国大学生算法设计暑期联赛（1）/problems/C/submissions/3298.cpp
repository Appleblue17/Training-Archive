#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,m,k;
int u[N], prm[N]; bool vis[N];
void pre(){
    u[1]=1;
    for(int i=2; i<N; ++i){
        if(!vis[i]){
            prm[++prm[0]]=i;
            u[i]=-1;
        }
        for(int j=1; j<=prm[0]&&i*prm[j]<N; ++j){
            vis[i*prm[j]]=1;
            if(i%prm[j]==0){
                u[i%prm[j]]=0;
                break;
            }
            u[i*prm[j]]=-u[i];
        }
    }
}
vector<int> e[N];
int dfn[N], sz[N], timer, lp[N], rp[N];
void dfs(int x, int fa){
    dfn[x]=++timer; sz[x]=1; lp[x]=dfn[x];
    for(auto y:e[x]) if(y^fa){
        dfs(y, x);
        sz[x]+=sz[y];
    }
    rp[x]=dfn[x]+sz[x]-1;
}
int f[N];
int curf[N];
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        e[i].clear();
    }
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    timer=0;
    dfs(1, 0);
    ll ans=0;
    for(int i=1; i*2<=n; ++i){
        for(int j=i; j<=n; j+=i) f[j/i]=0;
        vector<int> vv;
        for(int j=i; j<=n; j+=i){
            if(dfn[j]<=lp[i]||dfn[j]>rp[i]) continue;
            f[1]++;
            vv.push_back(j);
        }
        sort(vv.begin(), vv.end(), [&](int x, int y){return dfn[x]<dfn[y];});
        int it=0;
        for(auto son:e[i]) {
            if(dfn[son]<dfn[i]) continue;
            while(it<(int)vv.size()&&dfn[vv[it]]<lp[son]) ++it;
            while(it<(int)vv.size()&&dfn[vv[it]]<=rp[son]) curf[vv[it]]=son, ++it;
        }
        // cout<<"curf:"<<endl;
        // for(int j=i; j<=n; j+=i){
        //     cout<<curf[j]<<' ';
        // }
        // cout<<endl;
        for(int j=i; j<=n; j+=i){
            vector<int> vec;
            for(int k=j; k<=n; k+=j){
                if(dfn[k]<=lp[i]||dfn[k]>rp[i]) continue;
                vec.push_back(k);
            }
            sort(vec.begin(), vec.end(), [&](int x, int y){return dfn[x]<dfn[y];});
            
            for(int l=0, r; l<(int)vec.size(); l=r+1){
                r=l;
                while(r+1<(int)vec.size()&&curf[r]==curf[l]) ++r;
                f[j/i]+=l*(r-l+1);
            }
        }
        ll lstans=ans;
        cout<<i<<": "<<endl;
        for(int j=1; j*i<=n; ++j){
            ans+=f[j]*u[j];
            cout<<f[j]<<' ';
        }
        cout<<endl;
        // cout<<i<<": "<<ans-lstans<<endl;
    }
    cout<<"ans: ";
    printf("%lld\n", ans);
}
signed main(){
    pre();
    scanf("%d", &T);
    
    while(T--){
        solve();
    }
}
1: 
39 6 0 0 0 0 0 0 0 0 
2: 
3 0 0 0 0 
3: 
0 0 0 
4: 
0 0 
5: 
0 0 
ans: 36
1: 
7 0 0 0 0 
2: 
0 0 
ans: 7