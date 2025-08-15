#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define int long long
const int N=3000010;
using namespace std;
int n,poly,f[N][2],suc[N];
const int mo=998244353;
vector<int> G[N],g[N];
int u;
__gnu_pbds::gp_hash_table<int,int>ma;
bool cmp(int a,int b){
    if(a<u)a+=n;
    if(b<u)b+=n;
    return a<b;
}
//unordered_map<int,int> ma;
bool inside(int st,int ed,int x){
    if(st<ed){
        return st<x&&x<ed;
    }
    else{
        return x<ed || x>st;
    }
}
void dfs(int u){
    if(!g[u].size()){
        f[u][0]=1;f[u][1]=1;return;
    }
    int v1 = g[u][0],v2 = g[u][1];
    if(!f[v1][0])dfs(v1);
    if(!f[v2][0])dfs(v2);
    f[u][0]=(f[v1][0]*f[v2][1]+f[v1][1]*f[v2][0])%mo;
    f[u][1]=(f[u][0]+f[v1][1]*f[v2][1])%mo;
    //printf("f[%lld]=%lld,%lld\n",u,f[u][0],f[u][1]);
}
int X[N],Y[N];
void read(int &x){
    char c=getchar();
    x=0;
    for(; c<'0'||c>'9'; c=getchar());
    for(; c>='0'&&c<='9'; c=getchar()) x=(x<<1)+(x<<3)+(c^48);
}
signed main(){
    read(n);
    poly=n;
    for(int i=1;i<n;i++){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
        ma[i*N+(i+1)]=i;
        ma[(i+1)*N+i]=i+n;
    }
    G[1].push_back(n);
    G[n].push_back(1);
    ma[n*N+1]=n;
    ma[1*N+n]=n*2;
    for(int i=1;i<=n-3;i++){
        int u,v;
        read(X[i]);
        read(Y[i]);
        //scanf("%lld%lld",&X[i],&Y[i]);
        u=X[i];v=Y[i];
        G[u].push_back(v);
        G[v].push_back(u);
        ma[u*N+v]=i*2+n*2-1;
        ma[v*N+u]=i*2+n*2;
    }
    for(int i=1;i<=n;i++){
        u=i;
        sort(G[i].begin(),G[i].end(),cmp);
        for(int j=1;j<G[i].size();j++){
            int a = G[i][j-1],b=G[i][j];
            if(inside(a,b,i)){
                g[ma[a*N+b]].push_back(ma[a*N+i]);
                g[ma[a*N+b]].push_back(ma[i*N+b]);
                suc[ma[a*N+b]]=i;
            }
            else{
                g[ma[b*N+a]].push_back(ma[b*N+i]);
                g[ma[b*N+a]].push_back(ma[i*N+a]);
                suc[ma[b*N+a]]=i;
            }
            
        }
    }
    n=n*2+(n-3)*2;
    //for(int i=1;i<=n;i++){
    //    for(int v:g[i]){
    //        printf("g contains edge %d to %d\n",i,v);
    //    }
    //}
    //cout << "step2" << endl;
    for(int i=poly+1;i<=n;i++){
        if(!f[i][0])dfs(i);
    }
    //cout << "step3" << endl;
    int tmp[4][2],ans=0;
    for(int i=1;i<=poly-3;i++){
        int u = suc[ma[X[i]*N+Y[i]]],v=suc[ma[Y[i]*N+X[i]]];
        ans=0;
        tmp[0][0]=f[ma[X[i]*N+u]][0];tmp[0][1]=f[ma[X[i]*N+u]][1];
        tmp[1][0]=f[ma[u*N+Y[i]]][0];tmp[1][1]=f[ma[u*N+Y[i]]][1];
        tmp[2][0]=f[ma[Y[i]*N+v]][0];tmp[2][1]=f[ma[Y[i]*N+v]][1];
        tmp[3][0]=f[ma[v*N+X[i]]][0];tmp[3][1]=f[ma[v*N+X[i]]][1];
        int tt=1;
        for(int o=0;o<=3;o++){
            tt=1;
            for(int p=0;p<=3;p++){
                if(o==p)tt*=tmp[p][0];
                else tt*=tmp[p][1];
                tt %= mo;
            }
            ans += tt;
            ans %= mo;
        }
        printf("%lld\n",ans);
    }
}