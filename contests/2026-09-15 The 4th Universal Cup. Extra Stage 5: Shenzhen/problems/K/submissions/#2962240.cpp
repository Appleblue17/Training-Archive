#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
int T, n;
mt19937 rnd(1234);
struct frc{
    ll x, y;
    frc(int _x=0, int _y=1){x=_x; y=_y;}
    frc operator +(const frc &t)const{
        frc ret;
        ret.y=y*t.y/__gcd(y, t.y);
        ret.x=x*ret.y/y+t.x*ret.y/t.y;
        return ret;
    }
    bool operator <(const frc &t)const{
        return x*t.y<y*t.x;
    }
    bool operator <=(const frc &t)const{
        return x*t.y<=y*t.x;
    }
};
struct node{
    int ls, rs;
    int siz, slf, pri;
    frc val, sum;
}tr[N];
void up(int rt){
    tr[rt].siz=tr[rt].slf+tr[tr[rt].ls].siz+tr[tr[rt].rs].siz;
    tr[rt].sum=(frc){tr[rt].val.x*tr[rt].slf, tr[rt].val.y}+tr[tr[rt].ls].sum+tr[tr[rt].rs].sum;
}
int Merge(int x, int y){
    if(x==0||y==0) return x+y;
    if(tr[x].pri<tr[y].pri){
        tr[x].rs=Merge(tr[x].rs, y);
        up(x);
        return x;
    }
    tr[y].ls=Merge(x, tr[y].ls);
    up(y);
    return y;
}
void Split(int rt, frc v, int &x, int &y){
    if(rt==0){
        x=y=0;
        return ;
    }
    if(tr[rt].val<=v){
        x=rt;
        Split(tr[rt].rs, v, tr[x].rs, y);
        up(x);
    }
    else{
        y=rt;
        Split(tr[rt].ls, v, x, tr[y].ls);
        up(y);
    }
}
void Split2(int rt, frc v, int &x, int &y){
    if(rt==0){
        x=y=0;
        return ;
    }
    if(tr[rt].val<v){
        x=rt;
        Split2(tr[rt].rs, v, tr[x].rs, y);
        up(x);
    }
    else{
        y=rt;
        Split2(tr[rt].ls, v, x, tr[y].ls);
        up(y);
    }
}
int rt;
int idx;
int add(int rt, frc v){
    int A, B, C;
    Split(rt, v, B, C);
    Split2(B, v, A, B);
    if(B==0){
        ++idx;
        B=idx;
        tr[B].ls=tr[B].rs=0;
        tr[B].val=v; tr[B].slf=0; tr[B].sum=(frc){0, 1}; tr[B].pri=rnd();
    }
    // cout<<tr[A].val.x<<' '<<tr[A].val.y<<' '<<tr[B].val.x<<' '<<tr[B].val.y<<' '<<tr[C].val.x<<' '<<tr[C].val.y<<endl;
    ++tr[B].slf; tr[B].sum=tr[B].sum+tr[B].val;
    return Merge(Merge(A, B),C);
}
int del(int rt, frc v){
    int A, B, C;
    Split(rt, v, B, C);
    Split2(B, v, A, B);
    --tr[B].slf; tr[B].sum=tr[B].sum+(frc){-tr[B].val.x, tr[B].val.y};
    if(tr[B].slf==0) return Merge(A, C);
    return Merge(Merge(A, B),C);
}
frc get(int rt, int lim){
    if(!rt) return (frc){0, 1};
    cout<<tr[rt].val.x<<' '<<tr[rt].val.y<<' '<<tr[rt].slf<<' '<<tr[rt].sum.x<<' '<<tr[rt].sum.y<<endl;
    if(tr[tr[rt].rs].siz>=lim){
        return get(tr[rt].rs, lim);
    }
    frc ret=tr[tr[rt].rs].sum; lim-=tr[tr[rt].rs].siz;
    if(tr[rt].slf>=lim){
        ret=ret+(frc){tr[rt].val.x*lim, tr[rt].val.y};
        return ret;
    }
    ret=ret+(frc){tr[rt].val.x*tr[rt].slf, tr[rt].val.y};
    lim-=tr[rt].slf;
    return ret+get(tr[rt].ls, lim);
}
ll ans=0;
int W, bias;
vector<int> bin;
void calc(){
    int t=bin.size()+bias;
    for(int j=0; j<(int)bin.size(); ++j){
        rt=add(rt, (frc){1ll*bin[j]*(t-bias-j), t});
    }
    frc res=get(rt, W);
    // cout<<res.x<<' '<<res.y<<' '<<t<<endl;
    ans+=res.x*t/res.y;
    
    for(int j=0; j<(int)bin.size(); ++j){
        rt=del(rt, (frc){1ll*bin[j]*(t-bias-j), t});
    }
    for(int j=0; j<(int)bin.size(); ++j){
        rt=add(rt, (frc){bin[j],1});
    }
    bin.clear();
}
void solve(){
    scanf("%d", &n);
    rt=idx=0;
    W=0; bias=0;
    ans=0;
    char s[2]; int x;
    for(int i=1; i<=n; ++i){
        scanf("%s", s+1);
        if(s[1]=='F'){
            scanf("%d", &x);
            bin.push_back(x);
        }
        else{
            calc();
            ++W; bias=1;
        }
    }
    calc();
    printf("%lld\n", ans);
    // exit(0);
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}