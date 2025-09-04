#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N=5e6+5;
int n, m;
char s[N];
int sum[N];
struct info{
    int l, r;
    int mxl, mxr;
    int llen, rlen;
    friend info operator +(info x, info y){
        info z;
        z.l=x.l; z.r=y.r;
        if(x.mxr-x.mxl>y.mxr-y.mxl){
            z.mxl=x.mxl; z.mxr=x.mxr;
        }
        else{
            z.mxl=y.mxl; z.mxr=y.mxr;
        }
        if(x.llen==x.r-x.l+1&&s[y.l]==s[x.r]){
            z.llen=x.llen+y.llen;
        }
        else{
            z.llen=x.llen;
        }
        if(y.rlen==y.r-y.l+1&&s[y.l]==s[x.r]){
            z.rlen=x.rlen+y.rlen;
        }
        else{
            z.rlen=y.rlen;
        }
        if(x.rlen+y.llen>z.mxr-z.mxl+1&&s[x.r]==s[y.l]){
            z.mxl=x.r-x.rlen+1;
            z.mxr=y.l+y.llen-1;
        }
        return z;
    }
}tr[N<<2];
vector<int> vec[N<<2];
struct node{
    ll ans;
    int cnt1, cnt2;//+, -
};
vector<node> val[N<<2];
int seq[N];
int lim[N];
bool cmp(int x, int y){
    return lim[x]<lim[y];
}
void build(int p, int l, int r){
    if(l==r){
        tr[p].l=tr[p].r=tr[p].mxl=tr[p].mxr=l;
        tr[p].llen=tr[p].rlen=1;
        node tem;
        tem.ans=0, tem.cnt1=0, tem.cnt2=0;
        lim[l]=sum[l-1]-sum[l]-(s[l]=='0');
        if(s[l]=='0') {
            tem.ans-=l-l+1;
            tem.cnt2++;
        }
        else{
            tem.ans+=l-l+1;
            tem.cnt1++;
        }
        vec[p].push_back(lim[l]);
        val[p].push_back(tem);
        if(s[l]=='0') {
            tem.ans+=l-l+1;
            tem.cnt2--;
            tem.ans+=l-l+1;
            tem.cnt1++;
        }
        else{
            tem.ans-=l-l+1;
            tem.cnt1--;
            tem.ans-=l-l+1;
            tem.cnt2++;
        }
        vec[p].push_back(1e9);
        val[p].push_back(tem);
        return ;
    }
    int mid=(l+r)>>1;
    build(p<<1, l, mid); build(p<<1|1, mid+1, r);
    tr[p]=tr[p<<1]+tr[p<<1|1];
    for(int i=l; i<=r; ++i) seq[i]=i, lim[i]=sum[l-1]-sum[i]-(s[i]=='0');
    sort(seq+l, seq+r+1, cmp);
    node tem;
    tem.ans=0, tem.cnt1=0, tem.cnt2=0;
    for(int i=l; i<=r; ++i) {
        if(s[i]=='0') {
            tem.ans-=i-l+1;
            tem.cnt2++;
        }
        else{
            tem.ans+=i-l+1;
            tem.cnt1++;
        }
    }
    for(int L=l; L<=r; ){
        vec[p].push_back(lim[seq[L]]);
        val[p].push_back(tem);
        int R=L;
        while(R+1<=r&&lim[seq[R+1]]==lim[seq[L]]) ++R;
        for(int i=L; i<=R; ++i){
            if(s[seq[i]]=='0') {
                tem.ans+=seq[i]-l+1;
                tem.cnt2--;
                tem.ans+=seq[i]-l+1;
                tem.cnt1++;
            }
            else{
                tem.ans-=seq[i]-l+1;
                tem.cnt1--;
                tem.ans-=seq[i]-l+1;
                tem.cnt2++;
            }
        }
        L=R+1;
    }
    vec[p].push_back(1e9);
    val[p].push_back(tem);
}
vector<int> qbin;
void qry(int p, int l, int r, int L, int R){
    if(L>R) return ;
    if(L<=l&&r<=R){
        qbin.push_back(p);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) qry(p<<1, l, mid, L, R);
    if(R>mid) qry(p<<1|1, mid+1, r, L, R);
}
mt19937 rnd(time(0));
signed main(){
    scanf("%lld%lld", &n, &m);
    scanf("%s", s+1);
    for(int i=1; i<=n; ++i){
        if(s[i]=='1') sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1]-1;
    }
    build(1, 1, n);
    // for(int i=1; i<=n; ++i){
    //     for(int j=i; j<=n; ++j){
    //         qbin.clear();
    //         qry(1, 1, n, i, j);
    //         info tem=tr[qbin[0]];
    //         for(int k=1; k<(int)qbin.size(); ++k){
    //             tem=tem+tr[qbin[k]];
    //         }
    //         cout<<i<<' '<<j<<' '<<tem.mxl<<' '<<tem.mxr<<endl;
    //     }
    // }
    int l, r;
    while(m--){
        scanf("%lld%lld", &l, &r);
        qbin.clear();
        qry(1, 1, n, l, r);
        info tem=tr[qbin[0]];
        for(int k=1; k<(int)qbin.size(); ++k){
            tem=tem+tr[qbin[k]];
        }
        vector<int> pos;
        if(tem.llen!=r-l+1&&s[l]==s[r]&&tem.llen+tem.rlen>tem.mxr-tem.mxl+1){
            if(tem.llen==tem.rlen){
                pos.push_back(l);
            }
            else if(tem.llen==tem.rlen-1){
                pos.push_back(l);
                pos.push_back(r);
            }
            else if(tem.llen==tem.rlen+1){
                pos.push_back(l);
                pos.push_back(l+1);
            }
            else if(tem.llen<tem.rlen){
                int dt=tem.rlen-tem.llen;
                dt/=2;
                if((tem.llen+tem.rlen)&1){
                    pos.push_back(r-dt+1);
                    pos.push_back(r-dt);
                }
                else{
                    pos.push_back(r-dt+1);
                }
            }
            else{
                int dt=tem.llen-tem.rlen;
                dt/=2;
                if((tem.llen+tem.rlen)&1){
                    pos.push_back(l+dt-1);
                    pos.push_back(l+dt);
                }
                else{
                    pos.push_back(l+dt-1);
                }
                
            }
        }
        else{
            if((tem.mxr-tem.mxl+1)&1){
                pos.push_back((tem.mxl+tem.mxr)/2);
                pos.push_back((tem.mxl+tem.mxr)/2+1);
            }
            else{
                pos.push_back((tem.mxl+tem.mxr)/2+1);
            }
        }
        for(int i=1; i<=100; ++i){
            pos.push_back(rnd()%(r-l+1)+l);
        }
        ll res=1e18;
        for(auto p:pos){
            qbin.clear();
            qry(1, 1, n, p, r);
            qry(1, 1, n, l, p-1);
            int csum=0, clen=0; ll cans=0;
            for(auto t:qbin){
                int rk=lower_bound(vec[t].begin(), vec[t].end(), csum)-vec[t].begin();
                // cout<<tr[t].l<<' '<<tr[t].r<<endl;
                // for(auto u:vec[t]) cout<<u<<' ';
                // cout<<endl;
                // for(auto u:val[t]) cout<<u.ans<<' ';
                // cout<<endl;
                cans+=val[t][rk].ans;
                cans+=1ll*clen*val[t][rk].cnt1;
                cans-=1ll*clen*val[t][rk].cnt2;
                csum+=sum[tr[t].r]-sum[tr[t].l-1];
                clen+=tr[t].r-tr[t].l+1;
            }
            res=min(res, cans);
        }
        printf("%lld\n", res);
    }
}
