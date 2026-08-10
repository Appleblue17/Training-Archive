#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e14;
const int N=4e6;
int T, n, m, q;
ll b[1005][1005], c[1005][1005];
vector<ll> vec;
int qtp[N], qx[N], qy[N]; ll qv[N];
char inp[10];
int len;
int tag[N<<2];
void build(int p, int l, int r){
    tag[p]=0; 
    if(l==r) return ;
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
}
void down(int p){
    if(tag[p]!=0){
        tag[p<<1]+=tag[p];
        tag[p<<1|1]+=tag[p];
        tag[p]=0;
    }
}
void mdf(int p, int l, int r, int L, int R, int v){
    // if(p==1){
    //     cout<<L<<' '<<R<<' '<<v<<endl;
    // }
    if(L<=l&&r<=R){
        tag[p]+=v;
        return ;
    }
    int mid=(l+r)>>1;
    down(p);
    if(L<=mid) mdf(p<<1, l, mid, L, R, v);
    if(R>mid) mdf(p<<1|1, mid+1, r, L, R, v);
}
int get(int p, int l, int r, int x){
    if(l==r) return tag[p];
    int mid=(l+r)>>1;
    down(p);
    if(x<=mid) return get(p<<1, l, mid, x);
    else return get(p<<1|1, mid+1, r, x);
}
int id(ll x){
    return lower_bound(vec.begin(), vec.end(), x)-vec.begin()+1;
}
void solve(){
    scanf("%d%d%d", &n, &m, &q);
    vec.clear();
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%lld", &b[i][j]);
            vec.push_back(b[i][j]-1);
        }
    }
    for(int i=2; i<=n; ++i){
        for(int j=2; j<=m; ++j){
            ll v1=min(min(b[i][j-1], b[i-1][j]), min(b[i][j], b[i-1][j-1]))-1;
            vec.push_back(v1);
        }
    }
    for(int i=2; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            ll v1=min(b[i-1][j], b[i][j])-1;
            vec.push_back(v1);
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=2; j<=m; ++j){
            ll v1=min(b[i][j-1], b[i][j])-1;
            vec.push_back(v1);
        }
    }
    for(int i=0; i<=n+1; ++i){
        for(int j=0; j<=m+1; ++j){
            c[i][j]=b[i][j];
        }
    }
    ll cur=0;
    for(int i=1; i<=q; ++i){
        scanf("%s", inp+1);
        if(inp[1]=='s') {
            qtp[i]=1;
            scanf("%d%d%lld", &qx[i], &qy[i], &qv[i]);
            b[qx[i]][qy[i]]=qv[i]-cur;
            vec.push_back(b[qx[i]][qy[i]]-1);
            for(int ci=max(2, qx[i]); ci<=qx[i]+1&&ci<=n; ++ci){
                for(int cj=max(2, qy[i]); cj<=qy[i]+1&&cj<=m; ++cj){
                    ll v1=min(min(b[ci][cj-1], b[ci-1][cj]), min(b[ci][cj], b[ci-1][cj-1]))-1;
                    vec.push_back(v1);
                }
            }
            for(int ci=max(2, qx[i]); ci<=qx[i]+1&&ci<=n; ++ci){
                ll v1=min(b[ci][qy[i]], b[ci-1][qy[i]]);
                vec.push_back(v1);
            }
            for(int cj=max(2, qy[i]); cj<=qy[i]+1&&cj<=m; ++cj){
                ll v1=min(b[qx[i]][cj-1], b[qx[i]][cj]);
                vec.push_back(v1);
            }
        }
        else{
            qtp[i]=2;
            scanf("%lld", &qv[i]);
            cur+=qv[i];
        }
        vec.push_back(-cur);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    len=vec.size();
    build(1, 1, len);
    
    for(int i=0; i<=n+1; ++i){
        for(int j=0; j<=m+1; ++j){
            b[i][j]=c[i][j];
        }
    }
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            mdf(1, 1, len, 1, id(b[i][j]-1), 1);
        }
    }
    for(int i=2; i<=n; ++i){
        for(int j=2; j<=m; ++j){
            ll v1=min(min(b[i][j-1], b[i-1][j]), min(b[i][j], b[i-1][j-1]))-1;
            mdf(1, 1, len, 1, id(v1), 1);
        }
    }
    for(int i=2; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            ll v1=min(b[i-1][j], b[i][j])-1;
            mdf(1, 1, len, 1, id(v1), -1);
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=2; j<=m; ++j){
            ll v1=min(b[i][j-1], b[i][j])-1;
            mdf(1, 1, len, 1, id(v1), -1);
        }
    }
    cur=0;
    for(int i=1; i<=q; ++i){
        if(qtp[i]==1) {
            mdf(1, 1, len, 1, id(b[qx[i]][qy[i]]-1), -1);
            for(int ci=max(2, qx[i]); ci<=qx[i]+1&&ci<=n; ++ci){
                for(int cj=max(2, qy[i]); cj<=qy[i]+1&&cj<=m; ++cj){
                    ll v1=min(min(b[ci][cj-1], b[ci-1][cj]), min(b[ci][cj], b[ci-1][cj-1]))-1;
                    mdf(1, 1, len, 1, id(v1), -1);
                }
            }
            for(int ci=max(2, qx[i]); ci<=qx[i]+1&&ci<=n; ++ci){
                ll v1=min(b[ci][qy[i]], b[ci-1][qy[i]])-1;
                mdf(1, 1, len, 1, id(v1), 1);
            }
            for(int cj=max(2, qy[i]); cj<=qy[i]+1&&cj<=m; ++cj){
                ll v1=min(b[qx[i]][cj-1], b[qx[i]][cj])-1;
                mdf(1, 1, len, 1, id(v1), 1);
            }
            
            b[qx[i]][qy[i]]=qv[i]-cur;
            // cout<<"-------------------------"<<endl;
            
            mdf(1, 1, len, 1, id(b[qx[i]][qy[i]]-1), 1);
            for(int ci=max(2, qx[i]); ci<=qx[i]+1&&ci<=n; ++ci){
                for(int cj=max(2, qy[i]); cj<=qy[i]+1&&cj<=m; ++cj){
                    ll v1=min(min(b[ci][cj-1], b[ci-1][cj]), min(b[ci][cj], b[ci-1][cj-1]))-1;
                    mdf(1, 1, len, 1, id(v1), 1);
                }
            }
            for(int ci=max(2, qx[i]); ci<=qx[i]+1&&ci<=n; ++ci){
                ll v1=min(b[ci][qy[i]], b[ci-1][qy[i]])-1;
                mdf(1, 1, len, 1, id(v1), -1);
            }
            for(int cj=max(2, qy[i]); cj<=qy[i]+1&&cj<=m; ++cj){
                ll v1=min(b[qx[i]][cj-1], b[qx[i]][cj])-1;
                mdf(1, 1, len, 1, id(v1), -1);
            }
        }
        else{
            cur+=qv[i];
        }
        // cout<<"???"<<i<<' '<<id(-cur)<<' ';
        printf("%d\n", get(1, 1, len, id(-cur)));
    }
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}