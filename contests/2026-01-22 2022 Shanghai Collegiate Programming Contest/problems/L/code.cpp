#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=2e5+5;
const int B=450;
char s[N], t[N];
int n, m;
const int p1=998244353, p2=993244853;
struct hsh{
    int x, y;
    inline hsh operator +(const hsh &t){
        return (hsh){(x+t.x)%p1, (y+t.y)%p2};
    }
    inline hsh operator -(const hsh &t){
        return (hsh){(x-t.x+p1)%p1, (y-t.y+p2)%p2};
    }
    inline hsh operator *(const hsh &t){
        return (hsh){(int)((ll)x*t.x%p1), (int)((ll)y*t.y%p2)};
    }
    inline void operator +=(const hsh &t){
        x=(x+t.x)%p1, y=(y+t.y)%p2;
    }
    inline ll toll(){
        return (ll)x*p2+y;
    }
}hs[N], pw[N];
inline ll get(int l, int r){
    return (hs[r]-hs[l-1]*pw[r-l+1]).toll();
}
unordered_map<ll, int> h;
int temv[N], temlen[N]; ll temhs[N]; int tot;
int f[N];
int main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    pw[0]=(hsh){1, 1}; pw[1]=(hsh){131, 13331};
    for(int i=1; i<=n; ++i){
        hs[i]=hs[i-1]*pw[1]+(hsh){s[i], s[i]};
        pw[i]=pw[i-1]*pw[1];
    }
    // cout<<pw[1].x<<' '<<pw[1].y<<endl;
    scanf("%d", &m);
    for(int i=1, v, w; i<=m; ++i){
        scanf("%s", t+1);
        scanf("%d", &v);
        w=strlen(t+1);
        if(w>n) continue;
        hsh cur=(hsh){0, 0};
        for(int j=1; j<=w; ++j) cur=(cur*pw[1]+(hsh){t[j], t[j]});
        if(w<=B) h[cur.toll()]=v;
        else {
            ++tot; temv[tot]=v; temlen[tot]=w; temhs[tot]=cur.toll();
        }
    }
    f[0]=1;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=tot; ++j){
            if(i>=temlen[j]&&get(i-temlen[j]+1, i)==temhs[j]){
                f[i]=((ll)temv[j]*f[i-temlen[j]]+f[i])%mod;
            }
        }
        ll tem;
        for(int j=i; j>=i-B+1&&j>=1; --j){
            tem=get(j, i);
            // cout<<j<<' '<<i<<' '<<tem<<endl;
            if(h.find(tem)!=h.end()){
                f[i]=((ll)h[tem]*f[j-1]+f[i])%mod;
            }
        }
        f[i]=(f[i]+f[i-1])%mod;
        printf("%d ", f[i]);
    }
}
