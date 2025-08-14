#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+5,M=1e6+5;
int T,n;
int a[N];
 
vector <int> V[M];
int mp[N];
 
int f[N*4],g[N*4],tag[N*4];
void upd(int o,int x){
    tag[o]+=x;
    f[o]+=x;
}
void pushdown(int o){
    int ls=o<<1,rs=o<<1|1;
    upd(ls,tag[o]);
    upd(rs,tag[o]);
    tag[o]=0;
}
void pushup(int o){
    int ls=o<<1,rs=o<<1|1;
    if(f[ls]>f[rs]) f[o]=f[ls],g[o]=g[ls];
    else f[o]=f[rs],g[o]=g[rs];
}
void build(int l,int r,int o){
    f[o]=g[o]=tag[o]=0;
    if(l==r){
        f[o]=0;
        g[o]=l;
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,o<<1);
    build(mid+1,r,o<<1|1);
    pushup(o);
}
void modify(int l,int r,int o,int L,int R,int x){
    if(L<=l && r<=R){
        upd(o,x);
        return ;
    }
    pushdown(o);
    int mid=(l+r)>>1;
    if(L<=mid) modify(l,mid,o<<1,L,R,x);
    if(R>mid) modify(mid+1,r,o<<1|1,L,R,x);
    pushup(o);
}
 
 
signed main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mp[i]=V[a[i]].size();
            V[a[i]].push_back(i);
        }
        build(1,n,1);
         
        int ans=-1,A,B;
        for(int i=1;i<=n;i++){
            int j=mp[i],x=a[i];
            if(j && j+1<V[x].size()){
                // cout<<"modify "<<V[x][j]+1<<" "<<V[x][V[x].size()-1]<<" "<<"-1"<<endl;
                modify(1,n,1,V[x][j]+1,V[x][V[x].size()-1],-1);
            }
            j++;
            if(j+1<V[x].size()){
                // cout<<"modify "<<V[x][j]+1<<" "<<V[x][V[x].size()-1]<<" "<<"1"<<endl;
                modify(1,n,1,V[x][j]+1,V[x][V[x].size()-1],1);
            }
             
            int mx=f[1],mxer=g[1];
            if(mx>ans){
                ans=mx,A=i+1,B=mxer;
            }
        }
        printf("%d\n%d %d\n",ans,A,B);
         
        for(int i=1;i<=n;i++) V[a[i]].clear();
         
    }
     
}
