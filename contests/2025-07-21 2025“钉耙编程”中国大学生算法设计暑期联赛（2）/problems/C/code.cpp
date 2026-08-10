#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5.1e5+6;
const ll mo=998244353;
ll n,m,ansp,ansm;
ll f[N][50],fm[N],gm[N],ans[N],mxans;
ll in[N];
vector<ll> a;
vector<ll> G[N],va[N];

ll ksm(int a,int b){
    ll ret=1,base=a;
    while(b>0){
        if(b&1)ret=ret*base%mo;
        base=base*base%mo;
        b/=2;
    }
    return ret;
}

bool cmp(ll p1,ll m1,ll p2,ll m2){
    bool f=0;
    if(m1 < m2){
        swap(m1,m2);
        swap(p1,p2);
        f=1;
    }
    if(p1*m2 == 0)return 0^f;
    if(m1-m2 >= 60)return 1^f;

    __int128 z = (__int128)p1*m2*((__int128)1 << (m1-m2))-p2*m1;

    if(z >= 1e18)return 1^f;

    if(m2 >= 60 && z != 0)return (z>0)^f;
    
    //printf("%lld %lld %lld %lld\n",p1,m1,p2,m2);
    //if(z < 0)printf("!!\n");
    /*__int128 tt=z;
    while(tt){
        putchar(tt%10+'0');
        tt/=10;
    }
    putchar('\n');*/

    if(z != 0)return (z*(1<<m2)-p1*m2+p2*m1>0)^f;
    else return (-p1*m2+p2*m1>0)^f;
}

/*bool cmp(int p1,int m1,int p2,int m2){
    if(m1 < m2){
        return !cmp(p2,m2,p1,m1);
    }
    if((long long)p1*m2 == 0)return 0;
    if(m1-m2 >= 60)return 1;

    __int128 z = (__int128)p1*m2*((__int128)1 << (m1-m2))-p2*m1;

    if(z >= 1e18)return 1;

    if(z == 0)return p2*m1-p1*m2>0;

    if(m2 >= 60)return (z>0);

    return (z*(1<<m2)-p1*m2+p2*m1>0);
}*/

/*bool cmp(int a,int b,int c,int d){  //抄的
    if(b<d) return !cmp(c,d,a,b);
    __int128 p=((__int128)1<<(b-d))*d*a-b*c,q=d*a-b*c;
    if(p<0){
        p=-p,q=-q;
        if(p==0)    return !(q>=0);
        if(d>=50)   return 1;
        if(q>=0)    return !(p<=(q>>d));
        if(q<0)     return 1;
    }
    if(p==0)    return q>=0;
    if(d>=50)   return 0;
    if(q>=0)    return p<=(q>>d);
    return 0;
}*/


void solve(){
    scanf("%lld%lld", &n, &m);
    ansp = ansm = 0;
    ansm=1;
    for(int i=0;i<=n;i++){
        in[i]=0;
        va[i].clear();
        gm[i]=0;
        ans[i]=0;
        G[i].clear();
        fm[i]=-1e9;
        for(int j=0;j<=30;j++){
            f[i][j]=-1e9;
        }
    }
    mxans=0;
    a.clear();
    for(int i=1;i<=m;i++){
        int x,y,p;
        
        scanf("%d%d%d",&x,&y,&p);
        in[y]++;
        G[x].push_back(y);
        va[x].push_back(p);
    }
    queue<ll> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0)q.push(i);
    }
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        a.push_back(u);
        for(int v:G[u]){
            in[v]--;
            if(in[v]==0)q.push(v);
        }
    }
    for(int i=n-1;i>=0;i--){
        int u = a[i];
        //printf("i=%d,u=%d\n",i,u);
        gm[u]=0;
        for(int j=0;j<G[u].size();j++){
            int v = G[u][j];
            int w = va[u][j];
            gm[u] = max(gm[u],gm[v]+1);
            if(w != 0)fm[u] = max(fm[u],max(gm[v],fm[v])+1);
            else fm[u] = max(fm[u],fm[v]+1);
        }
        //printf("fm[%d]=%d,gm[%d]=%d\n",u,fm[u],u,gm[u]);
        //if(fm[u]<0){
        //    
        //    continue;
        //}
        
        for(int j=0;j<G[u].size();j++){
            ll v = G[u][j];
            ll w = va[u][j];
            
            for(int j=0;j+fm[u]-fm[v]-1 <= 40 && fm[u]-fm[v]+j-1>=0;j++){

                f[u][fm[u]-fm[v]+j-1] = max(f[u][j+fm[u]-fm[v]-1],f[v][j]+w);
            
            }
            if(w!=0 && fm[u]-gm[v]-1<=40)f[u][fm[u]-gm[v]-1] = max(f[u][fm[u]-gm[v]-1],w);
        }

        for(int j=0;j<=40;j++)if(fm[u]-j>=0)ans[fm[u]-j] = max(ans[fm[u]-j],f[u][j]);
        
    }
    mxans=0;
    for(int i=1;i<=n;i++)if(ans[i])mxans=i;
    for(int i=mxans;i>max(0ll,mxans-40);i--){
        if(ans[i]<=0)continue;
        if(cmp(ans[i],i,ansp,ansm)){
            ansp = ans[i];
            ansm = i;
            //printf("changed to %lld,%lld\n",ansp,ansm);
        }
    }
    //cout << ansp << ' ' << ansm << endl;
    ll fans=ansp;
    fans = fans*ksm(10000,mo-2)%mo;
    fans = fans*ksm(ansm,mo-2)%mo;
    fans = fans*(ksm(2,ansm)-1+mo)%mo;
    printf("%lld\n",fans);
    
}
int main(){
    //cout << cmp(1,160,2,159);//0
    //cout << cmp(0,160,2,1);
    //cout << cmp(2,1,0,160);
    //cout << cmp(4e8,4e4,3e8,1e5);//0
    //freopen("1173C.in","r",stdin);
    //freopen("out1.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
}