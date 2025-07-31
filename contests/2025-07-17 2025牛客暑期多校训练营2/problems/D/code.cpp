#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define MAXN 510
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
//mt19937_64 rng(GetTickCount());
template <typename T>inline void read(T &x){
    x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
    x=(x<<1)+(x<<3)+(c^48);
    x=(f?-x:x);
}
const int mo=1e9+7;
using namespace std;
ll n,v;
vector<ll> val[510];
vector<ll> h[510],d[510];
vector<ll> w,r;
ll f[510],ans,cnt;
ll findkmn(vector<ll> a,ll k){
    /*printf("find k=%lld in ",k);
    for(ll v:a){
        printf("%lld ",v);
    }
    cout << endl;*/
    if(a.size()<=5){
        sort(a.begin(),a.end());
        return a[k-1];
    }
    ll x = rand()*rand()%a.size();
    vector<ll> lo,hi;
    for(ll v:a){
        if(v<a[x])lo.push_back(v);
        else if(v == a[x]){
            if(rand()&1)lo.push_back(v);
            else hi.push_back(v);
        }
        else hi.push_back(v);
    }
    if(lo.size()>=k)return findkmn(lo,k);
    else return findkmn(hi,k-lo.size());
}
void solve(){
    cnt=0;
    ans=0;
    scanf("%lld",&n);
    scanf("%lld",&v);
    for(int i=0;i<=500;i++){
        h[i].clear();d[i].clear();
    }
    for(int i=1;i<=n;i++){
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        h[B].push_back(A);
        d[B].push_back(C);
    }
    for(int u=0;u<=v;u++){
        for(int i=1;i<=500;i++){
            val[i].clear();
        }
        w.clear();r.clear();
        for(int i=1;i<=v-u;i++){
            for(int j=0;j<h[i].size();j++){
                ll va = h[i][j]-u*d[i][j];
                //if(va >= 0){
                val[i].push_back(-va);
                //}
            }
            if(val[i].size()==0)continue;
            ll kmn=0;
            if((v-u)/i >= val[i].size())kmn = 1e15;
            else{
                kmn = findkmn(val[i],(v-u)/i);
                //printf("return value %lld\n",kmn);
            }
            //if(val[i].size())sort(val[i].begin(),val[i].end());
            int km=0;
            for(int j=0;j<val[i].size();j++){
                if(val[i][j] > kmn)continue;
                km++;
                if(km>(v-u)/i)break;
                w.push_back(i);
                r.push_back(-val[i][j]);
                //printf("u=%d,w push %d,r push %lld\n",u,i,-val[i][j]);fflush(stdout);
            }
        }
 
        for(int j=0;j<=v-u;j++){
            f[j]=-(ll)1e15;
        }
         
        f[0]=0;
        for(int i=0;i<w.size();i++){
            for(int j=v-u;j>=w[i];j--){
                f[j] = max(f[j],f[j-w[i]]+r[i]);
            }
        }
        cnt += w.size()*(v-u);
        //printf("cnt=%d\n",cnt);
        ans = max(ans,f[v-u]);
        //if(cnt >= 5e7)break;
    }
    printf("%lld\n",ans);
}
int main(){
    //freopen("108299D.in","r",stdin);
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve();
    }
}
