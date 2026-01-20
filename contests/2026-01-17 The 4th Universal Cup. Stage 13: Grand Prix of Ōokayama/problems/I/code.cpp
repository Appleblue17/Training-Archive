#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=4005, M=4e6+5;
int st;
int T, n, m;
char s[N][N];
int sum[N][N];
int qu[7005], qd[7005], ql[7005], qr[7005];
int ans[7005];
int fa[M];
short mnu[M], mxd[M], mnl[M], mxr[M];
int id(int x, int y){
    x/=2; y/=2;
    return (x-1)*n+y;
}
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}
void merge(int x, int y){
    x=get(x); y=get(y);
    fa[x]=y; mnu[y]=min(mnu[y], mnu[x]); mnl[y]=min(mnl[y], mnl[x]); mxd[y]=max(mxd[y], mxd[x]); mxr[y]=max(mxr[y], mxr[x]);
}
bool ban[M];
int item[2005][2005], szitem[2005];
int qry[2005][7005], szqry[2005];
int bin[2005][9005], szbin[2005];
int que[10000], _que[10000], len; 
int tr[2005];
void add(int x){
    for(; x; x-=(x&-x)) tr[x]++;
}
void del(int x){
    for(; x; x-=(x&-x)) tr[x]--;
}
int ask(int x){
    int ret=0;
    for(; x<=n; x+=(x&-x)) ret+=tr[x];
    return ret;
}
void solve(int l, int r){
    if(l==r) return ;
    int mid=(l+r)>>1;
    bool ins=0;
    solve(l, mid); solve(mid+1, r);
    int it1=l, it2=mid+1;
    for(int i=l, r1, r2; i<=r; ++i){
        if(it1>mid){
            if(que[it2]>n*n){
                if(ins) ans[que[it2]-n*n]+=ask(ql[que[it2]-n*n]);
            }
            _que[i]=que[it2];
            ++it2;
        }
        else if(it2>r){
            if(que[it1]<=n*n){
                add(mnl[que[it1]]);
            }
            _que[i]=que[it1];
            ++it1;
        }
        else {
            r1=que[it1]<=n*n?mxr[que[it1]]:qr[que[it1]-n*n];
            r2=que[it2]<=n*n?mxr[que[it2]]:qr[que[it2]-n*n];
            if(r1<=r2){
                if(que[it1]<=n*n){
                    ins=1;
                    add(mnl[que[it1]]);
                }
                _que[i]=que[it1];
                ++it1;
            }
            else{
                if(que[it2]>n*n){
                    if(ins) ans[que[it2]-n*n]+=ask(ql[que[it2]-n*n]);
                }
                _que[i]=que[it2];
                ++it2;
            }
        }
    }
    for(int i=l; i<=mid; ++i) {
        if(que[i]<=n*n) del(mnl[que[i]]);
        que[i]=_que[i];
    }
    for(int i=mid+1; i<=r; ++i) que[i]=_que[i];
}
int ed;
signed main(){
    // cout<<(&st-&ed)/1024/1024<<endl;
    scanf("%d", &n);
    for(int i=1; i<=n*2+1; ++i){
        scanf("%s", s[i]+1);
    }
    for(int i=1; i<=n*2+1; ++i){
        for(int j=1; j<=n*2+1; ++j){
            if((i&1)^(j&1)) sum[i][j]=s[i][j]!='.';
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) fa[(i-1)*n+j]=(i-1)*n+j, mnu[(i-1)*n+j]=mxd[(i-1)*n+j]=i, mnl[(i-1)*n+j]=mxr[(i-1)*n+j]=j;
    for(int i=2; i<=n*2; i+=2){
        for(int j=2; j<=n*2; j+=2){
            if(j!=n*2&&s[i][j+1]=='.') merge(id(i, j), id(i, j+2));
            if(i!=n*2&&s[i+1][j]=='.') merge(id(i, j), id(i+2, j));
        }
    }
    for(int i=2; i<=n*2; i+=2){
        if(s[1][i]=='.') ban[get(id(2, i))]=1;
        if(s[n*2+1][i]=='.') ban[get(id(n*2, i))]=1;
        if(s[i][1]=='.') ban[get(id(i, 2))]=1;
        if(s[i][n*2+1]=='.') ban[get(id(i, n*2))]=1;
    }
    for(int i=1; i<=n*n; ++i) if(get(i)==i&&!ban[i]){
        item[mxd[i]][++szitem[mxd[i]]]=i;
        // cout<<mnu[i]<<' '<<mxd[i]<<' '<<mnl[i]<<' '<<mxr[i]<<endl;
    }
    scanf("%d", &m);
    for(int i=1; i<=m; ++i){
        scanf("%d%d%d%d", &qu[i], &qd[i], &ql[i], &qr[i]);
        ans[i]=((qd[i]-qu[i])/2+1)*(((qr[i]-ql[i])/2+1));
        ans[i]-=sum[qd[i]][qr[i]]-sum[qu[i]-1][qr[i]]-sum[qd[i]][ql[i]-1]+sum[qu[i]-1][ql[i]-1];
        qu[i]=(qu[i]+1)/2; qr[i]/=2; ql[i]=(ql[i]+1)/2;
        // cout<<qu[i]<<' '<<qd[i]/2<<' '<<ql[i]<<' '<<qr[i]<<endl;
        qry[qd[i]/2][++szqry[qd[i]/2]]=i;
        // cout<<ans[i]<<endl;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=szitem[i]; ++j){
            bin[mnu[item[i][j]]][++szbin[mnu[item[i][j]]]]=item[i][j];
        }
        for(int k=1; k<=szqry[i]; ++k){
            for(int j=i; j>=qu[qry[i][k]]; --j){
                bin[j][++szbin[j]]=qry[i][k]+n*n;
            }
        }
    }
    for(int i=1; i<=n; ++i){
        len=0;
        for(int j=1; j<=szbin[i]; ++j){
            que[++len]=bin[i][j]; 
        }
        if(len==0) continue ;
        solve(1, len);
    }
    for(int i=1; i<=m; ++i){
        printf("%d\n", ans[i]);
    }
}
