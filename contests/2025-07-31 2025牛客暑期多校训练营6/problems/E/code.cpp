#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int B=350;
// const int B=2;
int n, m;
int p[N], revp[N];
int cl[N], cr[N];
int pos[N], lp[350], rp[350];
int cnt[350][350];
vector<int> occ[N];
typedef long long ll;
ll atag[350], aself[N];
ll sum[350], dt[350];
inline ll qryp(int x){
    return atag[pos[x]]+aself[x];
}
inline ll qry(int x){
    if(x==0) return 0;
    ll ret=sum[pos[x]-1];
    for(int i=lp[pos[x]]; i<=x; ++i){
        ret+=qryp(p[i]);
    }
    return ret;
}
int main(){
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &p[i]), occ[p[i]].push_back(i);
    for(int i=1; i<=n; ++i){
        cl[i]=cr[i-1]+1;
        cr[i]=cr[i-1];
        for(auto t:occ[i]){
            ++cr[i];
            p[t]=cr[i];
            revp[cr[i]]=t;
        }
    }
    for(int i=1; i<=n; ++i) pos[i]=(i-1)/B+1;
    for(int i=1; i<=pos[n]; ++i) lp[i]=rp[i-1]+1, rp[i]=rp[i-1]+B;
    rp[pos[n]]=n;
    for(int i=1; i<=pos[n]; ++i){
        for(int j=1; j<=pos[n]; ++j){
            cnt[i][j]=cnt[i][j-1];
            for(int k=lp[i]; k<=rp[i]; ++k){
                cnt[i][j]+=(p[k]>=lp[j]&&p[k]<=rp[j]);
            }
        }
    }
    for(int i=1; i<=pos[n]; ++i){
        for(int j=1; j<=pos[n]; ++j){
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    ll lstans=0;
    int tp; ll l, r, x;
    while(m--){
        scanf("%d%lld%lld", &tp, &l, &r);
        l^=lstans; r^=lstans;
        if(tp==1){
            scanf("%lld", &x);
            x^=lstans;
            l=cl[l]; r=cr[r];
            if(l>r) continue;
            if(pos[l]==pos[r]){
                for(int i=l; i<=r; ++i) aself[i]+=x, dt[pos[revp[i]]]++;
            }
            else{
                for(int i=l; i<=rp[pos[l]]; ++i) aself[i]+=x, dt[pos[revp[i]]]++;
                for(int i=lp[pos[r]]; i<=r; ++i) aself[i]+=x, dt[pos[revp[i]]]++;
                for(int i=pos[l]+1; i<pos[r]; ++i) atag[i]+=x;
                for(int i=1; i<=pos[n]; ++i) {
                    sum[i]+=x*(cnt[i][pos[r]-1]-cnt[i][pos[l]]);
                }
            }
            for(int i=1; i<=pos[n]; ++i) {
                dt[i+1]+=dt[i];
                sum[i]+=x*dt[i];
                dt[i]=0;
            }
        }
        else{
            lstans=qry(r)-qry(l-1);
            printf("%lld\n", lstans);
        }
    }
}
