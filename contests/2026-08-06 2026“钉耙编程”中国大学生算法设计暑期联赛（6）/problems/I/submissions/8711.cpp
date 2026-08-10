#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=6e5+5;
int T,n,m;
int a[N];

inline int rd(){
    int x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar())f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c^48);
    return (f)?(-x):x;
}

vector < pair<int,int> > V[N*2];
unordered_map <int,int> mp,mp2;

inline int cal(int x,int d){
    int t=(x>>d & 1);
    return x^(t<<d);
}

void solve(int d,int l,int r,int o,int pat){
    if(!d){
        // l=r
        V[o].push_back({a[pat],1});
        // cout<<"leaf "<<d<<" "<<l<<" "<<r<<" "<<o<<": "<<pat<<" "<<a[pat]<<endl;
        return ;
    }
    
    int mid=(l+r)>>1;
    int ls=(o<<1),rs=(o<<1|1);
    solve(d-1,l,mid,ls,pat);
    solve(d-1,mid+1,r,rs,pat^(1<<(d-1)));
    
    mp.clear(); mp2.clear();
    for(auto e: V[ls]){
        mp[e.first]+=e.second;
    }
    for(auto e: V[rs]){
        mp[e.first]+=e.second;
    }
    
    for(auto e: mp){
        int x=e.first,val=e.second;
        mp2[cal(x,d-1)]=max(mp2[cal(x,d-1)],val);
    }
    for(auto e: mp2){
        V[o].push_back({e});
    }
    
    // cout<<"  "<<d<<" "<<l<<" "<<r<<" "<<o<<": ";
    // for(auto e: mp[ls]){
    //     int x=e.first,val=e.second;
    //     cout<<x<<","<<val<<" ";
    // }
    // cout<<endl;
    
}


signed main(){
    // freopen("3.out","w",stdout);
    T=rd();
    while(T--){
        n=rd(); m=1<<n;
        for(int i=0;i<m;i++) a[i]=rd()^i;
        
        // for(int i=0;i<m;i++) cout<<a[i]<<" "; cout<<endl;
        
        for(int i=0;i<=m*2;i++) V[i].clear();
        solve(n,0,m-1,1,0);
        
        int ans=0;
        for(auto e: V[1]) ans=max(ans,e.second);
        printf("%d\n",ans);
    }
}