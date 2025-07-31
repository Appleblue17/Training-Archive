#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int B=350;
const int B2=1000;
// const int B=2;
// const int B2=2;
int n, m;
int p[N];
int pos[N], lp[N], rp[N];
int pos2[N], lp2[N], rp2[N];
vector<int> vec[N];
vector<int> occ[N];
vector<int> bignum;
typedef long long ll;
ll atag[N], aself[N];
ll sum[N];
inline ll qryp(int x){
    return atag[pos[x]]+aself[x];
}
inline ll qry(int x){
    if(x==0) return 0;
    ll ret=sum[pos2[x]-1];
    for(int i=lp2[pos2[x]]; i<=x; ++i){
        ret+=qryp(p[i]);
    }
    return ret;
}
int main(){
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i) scanf("%d", &p[i]);
    for(int i=1; i<=n; ++i) pos[i]=(i-1)/B+1;
    for(int i=1; i<=pos[n]; ++i) lp[i]=rp[i-1]+1, rp[i]=rp[i-1]+B;
    rp[pos[n]]=1;
    for(int i=1; i<=n; ++i) pos2[i]=(i-1)/B2+1;
    for(int i=1; i<=pos2[n]; ++i) lp2[i]=rp2[i-1]+1, rp2[i]=rp2[i-1]+B2;
    rp2[pos2[n]]=1;
    for(int i=1; i<=pos2[n]; ++i){
        for(int j=lp2[i]; j<=rp2[i]; ++j) vec[i].push_back(p[j]);
        sort(vec[i].begin(), vec[i].end());
    }
    ll lstans=0;
    int tp; ll l, r, x;
    while(m--){
        scanf("%d%lld%lld", &tp, &l, &r);
        l^=lstans; r^=lstans;
        if(tp==1){
            scanf("%lld", &x);
            x^=lstans;
            if(pos[l]==pos[r]){
                for(int i=l; i<=r; ++i) aself[i]+=x;
            }
            else{
                for(int i=l; i<=rp[pos[l]]; ++i) aself[i]+=x;
                for(int i=lp[pos[r]]; i<=r; ++i) aself[i]+=x;
                for(int i=pos[l]+1; i<pos[r]; ++i) atag[i]+=x;
            }
            int pre=0;
            for(int i=1; i<=pos2[n]; ++i) {
                int p1=upper_bound(vec[i].begin(), vec[i].end(), r)-vec[i].begin();
                int p2=lower_bound(vec[i].begin(), vec[i].end(), l)-vec[i].begin();
                pre+=p1-p2;
                sum[i]+=x*pre;
            }
        }
        else{
            lstans=qry(r)-qry(l-1);
            printf("%lld\n", lstans);
        }
    }
}
