#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5, B=200, M=350;
int T, n, m, q;
int a[N], c[N];
int cnt[N];
int lp[N], rp[N], bid[N];
bool isbig[N];
int rd(){
	char c=getchar();
	int tot=0; bool f=0;
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
	return f?-tot:tot;
}
struct DS{
    int sum[M];
    bool v[N];
    void init(int c){
        if(c==0){
            for(int i=1; i<=m; ++i) v[i]=0;
            for(int i=1; i<=bid[m]; ++i) sum[i]=0;
        }
        else{
            for(int i=1; i<=bid[m]; ++i) sum[i]=0;
            for(int i=1; i<=m; ++i) v[i]=isbig[i], sum[bid[i]]+=v[i], assert(sum[bid[i]]==0);
        }
    }
    void add(int x){
        v[x]=1; sum[bid[x]]++;
    }
    void del(int x){
        v[x]=0; sum[bid[x]]--;
    }
    int fnd(){
        for(int i=1; i<=bid[m]; ++i){
            if(!sum[i]) continue;
            for(int j=lp[i]; j<=rp[i]; ++j) if(v[j]) return j;
        }
        return 1e9;
    }
}D[B*2+10];
struct node{
    int l, r, k, id;
}f[N];
int ans[N];
int sum[N];
inline void add(int x){
    if(isbig[c[x]]) return ;
    if(a[x]==1){
        D[sum[c[x]]+B].del(c[x]);
        ++sum[c[x]];
    }
    else{
        --sum[c[x]];
        D[sum[c[x]]+B].add(c[x]);
    }
}
inline void del(int x){
    if(isbig[c[x]]) return ;
    if(a[x]==1){
        --sum[c[x]];
        D[sum[c[x]]+B].add(c[x]);
    }
    else{
        D[sum[c[x]]+B].del(c[x]);
        ++sum[c[x]];
    }
}
void solve(){
    n=rd(); m=rd(); q=rd();
    for(int i=1; i<=m; ++i) cnt[i]=0, isbig[i]=0;
    for(int i=1; i<=n; ++i) {
        c[i]=rd(); cnt[c[i]]++;
    }
    for(int i=1; i<=n; ++i){
        a[i]=rd();
    }
    for(int i=1; i<=m; ++i) bid[i]=(i-1)/M+1, isbig[i]=1;
    for(int i=1; i<=bid[m]; ++i){
        lp[i]=rp[i-1]+1; rp[i]=rp[i-1]+M;
    }
    rp[bid[m]]=m;
    for(int i=-B; i<=B; ++i){
        D[i+B].init(i>=0);
    }
    for(int i=1; i<=q; ++i){
        f[i].l=rd(); f[i].r=rd(); f[i].k=rd();
        f[i].id=i;
        ans[i]=1e9;
    }
    for(int o=1; o<=m; ++o) if(isbig[o]){
        for(int i=1; i<=n; ++i){
            if(c[i]!=o) sum[i]=sum[i-1];
            else sum[i]=sum[i-1]+a[i];
        }
        for(int i=1; i<=q; ++i){
            if(sum[f[i].r]-sum[f[i].l-1]<=f[i].k){
                ans[i]=min(ans[i], o); 
            }
        }
    }
    sort(f+1, f+q+1, [&](node x, node y){
        if((x.l>>8)!=(y.l>>8)) return x.l<y.l;
        return x.r<y.r;
    });
    for(int i=1; i<=m; ++i) sum[i]=0;
    int cl=1, cr=0;
    for(int o=1; o<=q; ++o){
        int l=f[o].l, r=f[o].r, id=f[o].id, k=f[o].k;
        while(cr<r){
            ++cr;
            add(cr);
        }
        while(cl>l){
            --cl;
            add(cl);
        }
        while(cr>r){
            del(cr);
            --cr;
        }
        while(cl<l){
            del(cl);
            ++cl;
        }
        ans[id]=min(ans[id], D[k+B].fnd());
    }
    for(int i=1; i<=q; ++i){
        if(ans[i]==1e9) ans[i]=-1;
        printf("%d\n", ans[i]);
    }
}
int main(){
    T=rd();
    while(T--){
        solve();
    }
}