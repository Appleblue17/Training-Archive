// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MP make_pair
const int N=1e6+5,mo1=1e9+7,mo2=1e9+9;

typedef long long ll;

struct node{
    int x,id;
    int f=0;//1=l,-1=r
} a[N];

ll ksm(ll a,ll b,ll mo){
    ll ret=1,base=a;
    while(b>0){
        if(b&1)ret = ret*base%mo;
        base = base*base%mo;
        b/=2;
    }
    return ret%mo;
}


ll n;

inline void read(ll &x){
    x=0; char c=getchar();
    bool flag=0;
    if(c=='-') flag=1;
    while(c<'0'||c>'9') {
        c=getchar();
        if(c=='-') flag=1;
    }
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c-'0'), c=getchar();
    if(flag) x=-x;
}

bool cmp(node a,node b){
    if(a.x != b.x)return a.x < b.x;
    else return a.f > b.f;
}

unordered_map<int,int> ma;

void solve(){
    ma.clear();
    read(n);
    for(int i=1;i<=n;i++){
        int l,r;
        scanf("%lld%lld",&l,&r);
        a[i*2-1].x = l;
        a[i*2-1].id = i;
        a[i*2-1].f=1;
        a[i*2].x=r;
        a[i*2].id=i;
        a[i*2].f=-1;
    }
    sort(a+1,a+n*2+1,cmp);
    ll cur1=0,cur2=0;
    ma[0]=1;
    ll last=-1;
    for(int i=1;i<=n*2;i++){
        //printf("a[%lld] : x=%lld,id=%lld,f=%lld\n",i,a[i].x,a[i].id,a[i].f);
        if(a[i].x*2-a[i].f != a[i-1].x*2-a[i-1].f){
            ma[cur1*(1e9+9)+cur2]=1;
            //printf("added cur\n");
        }
        cur1 = (cur1 + a[i].f*ksm(2,a[i].id,mo1)+mo1)%mo1;
        cur2 = (cur2 + a[i].f*ksm(2,a[i].id,mo2)+mo2)%mo2;
        
            
        last = a[i].x;
    }
    printf("%lld\n",ma.size());
    
}

signed main(){
    //freopen("I.in","r",stdin);
    //freopen("I.out","w",stdout);
    ll T;
    read(T);
    while(T--){solve();}
}