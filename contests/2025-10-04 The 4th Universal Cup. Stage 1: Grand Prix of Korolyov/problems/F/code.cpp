#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10,INF=1e18;
int n,m,a[N],l[N],r[N],pos[N],vis[N],fa[N];

typedef pair<int,int> pii;
#define mapa make_pair 
#define fi first 
#define se second 
multiset<pii> sl,sr;
int findfa(int x){
    if(fa[x]==x)return x;
    return fa[x] = findfa(fa[x]);
}
struct edg{
    int u,v,w;
    edg(int u,int v,int w):u(u),v(v),w(w){}
    friend bool operator < (edg a,edg b){return a.w < b.w;}
};
int ans1,ans2;
void bf(){
    
    vector<edg> e;
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            for(int k=0;k<=n;k++)vis[k]=0;
            for(int k=l[i];k<=r[i];k++){
                vis[a[k]]=1;
            }
            for(int k=l[j];k<=r[j];k++){
                vis[a[k]]=1;
            }
            int k=0;
            for(k=0;k<=n;k++)if(!vis[k])break;
            //printf("add edge %lld %lld %lld\n",i,j,k);
            e.push_back(edg(i,j,k));
        }
        
    }
    sort(e.begin(),e.end());
    int ans=0;
    for(edg t:e){
        int fu = findfa(t.u);
        int fv = findfa(t.v);
        if(fu != fv){
            fa[fu] = fv;
            ans += t.w;
        }
    }
    ans2 = ans;
}
void solve(){
    sl.clear();sr.clear();
    /*scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pos[a[i]]=i;
    }*/
    for(int i=1;i<=m;i++){
        int tl,tr;
        tl = l[i];tr = r[i];
        //scanf("%lld%lld",&l,&r);
        sr.insert(mapa(-tr,-tl));
        //printf("sr insert %lld,%lld\n",-r[i],-l[i]);
        sl.insert(mapa(tl,tr));
    }
    int ans=0,C=0;
    for(int i=0;i<n;i++){
        multiset<pii>::iterator itl,itr,it,it2;
        int L=0,R=n,cnt=0;
        it = sr.upper_bound(mapa(-pos[i],n*2));
        while(it != sr.end()){
            //cout << it->fi << ' ' << it->se << endl;
            L = max(L,-(it->se));
            R = min(R,-(it->fi));
            //printf("L=%lld,R=%lld in sr\n",L,R);
            sl.erase(sl.find(mapa(-(it->se),-(it->fi))));
            it2 = it;
            it++;
            sr.erase(it2);
            cnt++;
        }
        it = sl.upper_bound(mapa(pos[i],n*2));
        while(it != sl.end()){//copied
            //cout << it->fi << ' ' << it->se << endl;
            L = max(L,(it->fi));
            R = min(R,(it->se));
            //printf("L=%lld,R=%lld in sl\n",L,R);
            sr.erase(sr.find(mapa(-(it->se),-(it->fi))));
            it2=it;
            it++;
            sl.erase(it2);
            cnt++;
        }
        if(L > R){
            L = n+1;R = 0;
        }
        if(cnt != 0){
            cnt--;
            sl.insert(mapa(L,R));
            sr.insert(mapa(-R,-L));
        }
        
        C += cnt;
        
        //printf("i=%lld,cnt=%lld\n",i,cnt);
        
        ans += cnt*i;
    }
    if(C < m-1){
        ans += (m-C-1)*n;
    }
    ans1 = ans;
    printf("%lld\n",ans);
}
signed main(){
    /*freopen("F.in","r",stdin);
    int T,TT=0;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            scanf("%lld%lld",&l[i],&r[i]);
            fa[i]=i;
        }
        TT++;
        solve();
        bf();
        if(ans1 != ans2){
            printf("WA at TT=%lld,ans1=%lld,ansbf=%lld\n",TT,ans1,ans2);
        }
    }*/
    scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            scanf("%lld%lld",&l[i],&r[i]);
            fa[i]=i;
        }
    solve();
}
