#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
int n, K;
int a[N], b[N], w[N];
int d[N], s1[N], s2[N];
int lis[N], m;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
pii st[20][N]; int lg[N];
pii get(int l, int r){
    int t=lg[r-l+1];
    return max(st[t][l], st[t][r-(1<<t)+1]);
}
int tr[N];
void add(int x, int v){
    // cout<<"add:"<<x<<' '<<v<<endl;
    for(; x<N; x+=(x&-x)) tr[x]+=v;
}
int qry(int x){
    int ret=0;
    for(; x>0; x-=(x&-x)) ret+=tr[x];
    return ret;
}
int ans;
void solve(int l, int r, int o){
    if(l>r) return ;
    if(l==r){
        if(w[l]==0) ++ans;
        if(!o){
            add(d[l-1], 1);
        }
        return ;
    }
    int mid=get(l, r).se;
    int dt=max(0ll, w[mid])*(K+1);
    int len1=(mid-1)-l+1;
    int len2=r-(mid+1)+1;
    if(len1<=len2){
        solve(l, mid-1, 1);
        solve(mid+1, r, 0);
        add(d[r], 1);
        for(int i=l-1; i<mid; ++i){
            int rk=lis[d[i]]+dt;
            rk=lower_bound(lis+1, lis+m+1, rk)-lis-1;
            // cout<<l<<' '<<r<<' '<<mid<<' '<<i<<' '<<(r-mid+1)-qry(rk)<<endl;
            ans+=(r-mid+1)-qry(rk);
        }
        if(!o){
            for(int i=l; i<=mid; ++i) add(d[i-1], 1);
            add(d[r], -1);
        }
        else{
            for(int i=mid; i<=r; ++i) add(d[i], -1);
        }
    }
    else{
        solve(mid+1, r, 1);
        solve(l, mid-1, 0);
        add(d[mid-1], 1);
        for(int i=mid; i<=r; ++i){
            int rk=lis[d[i]]-dt;
            rk=upper_bound(lis+1, lis+m+1, rk)-lis-1;
            // cout<<l<<' '<<r<<' '<<mid<<' '<<i<<' '<<qry(rk)<<endl;
            ans+=qry(rk);
        }
        if(!o){
            for(int i=mid; i<r; ++i) add(d[i], 1);
        }
        else{
            for(int i=l-1; i<mid; ++i) add(d[i], -1);
        }
        
    }
}
signed main(){
    scanf("%lld%lld", &n, &K);
    for(int i=1; i<=n; ++i) scanf("%lld", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%lld", &b[i]);
    for(int i=1; i<=n; ++i){
        w[i]=a[i]-b[i];
        if(w[i]>=0) s1[i]=w[i];
        else s2[i]=-w[i];
        s1[i]+=s1[i-1];
        s2[i]+=s2[i-1];
        d[i]=s1[i]-s2[i]*K;
    }
    for(int i=0; i<=n; ++i) lis[++m]=d[i];
    sort(lis+1, lis+m+1);
    m=unique(lis+1, lis+m+1)-lis-1;
    for(int i=0; i<=n; ++i){
        d[i]=lower_bound(lis+1, lis+m+1, d[i])-lis;
    }
    for(int i=2; i<=n; ++i) lg[i]=lg[i>>1]+1;
    for(int i=1; i<=n; ++i) st[0][i]=mapa(w[i], i);
    for(int t=1; t<=lg[n]; ++t){
        for(int i=1; i+(1<<t)-1<=n; ++i) {
            st[t][i]=max(st[t-1][i], st[t-1][i+(1<<(t-1))]);
        }
    }
    solve(1, n, 0);
    printf("%lld\n", ans);
}

