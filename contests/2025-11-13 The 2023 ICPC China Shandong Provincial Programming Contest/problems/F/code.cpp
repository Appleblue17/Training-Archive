#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,mod=998244353;
int T,n;

struct abc{
    int l,r,c;
}a[N];
bool operator <(abc X,abc Y){
    if(X.l==Y.l) return X.r>Y.r;
    return X.l<Y.l;
}

int v[N],vid;

void gmod(int &x){
    x%=mod;
}


struct segtree{
    int f[N*4],tag[N*4];
    
    void upd(int o,int x){
        f[o]=f[o]*x%mod;
        tag[o]=tag[o]*x%mod;
    }
    void pushdown(int o){
        upd(o<<1,tag[o]);
        upd(o<<1|1,tag[o]);
        tag[o]=1;
    }
    
    void build(int l,int r,int o){
        f[o]=0,tag[o]=1;
        if(l==r) return ;
        int mid=(l+r)>>1;
        build(l,mid,o<<1);
        build(mid+1,r,o<<1|1);
    }
    
    void mdf(int l,int r,int o,int pos,int x){
        if(l==r){
            gmod(f[o]+=x);
            return ;
        }
        pushdown(o);
        
        int mid=(l+r)>>1;
        if(pos<=mid) mdf(l,mid,o<<1,pos,x);
        else mdf(mid+1,r,o<<1|1,pos,x);
        
        gmod(f[o]=f[o<<1]+f[o<<1|1]);
    }
    
    void modify(int l,int r,int o,int L,int R,int x){
        if(L>R) return ;
        if(L<=l && r<=R){
            upd(o,x);
            return ;
        }
        pushdown(o);
        
        int mid=(l+r)>>1;
        if(L<=mid) modify(l,mid,o<<1,L,R,x);
        if(R>mid) modify(mid+1,r,o<<1|1,L,R,x);
        
        gmod(f[o]=f[o<<1]+f[o<<1|1]);
    }
    
    int query(int l,int r,int o,int L,int R){
        if(L>R) return 0;
        if(L<=l && r<=R){
            return f[o];
        }
        pushdown(o);
        
        int mid=(l+r)>>1,tot=0;
        if(L<=mid) gmod(tot+=query(l,mid,o<<1,L,R));
        if(R>mid) gmod(tot+=query(mid+1,r,o<<1|1,L,R));
        return tot;
    }
}P,Q;

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        vid=0;
        
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].c);
            v[++vid]=a[i].l;
            v[++vid]=a[i].r;
        }
        sort(v+1,v+vid+1);
        vid=unique(v+1,v+vid+1)-v-1;
        
        for(int i=1;i<=n;i++){
            a[i].l=lower_bound(v+1,v+vid+1,a[i].l)-v;
            a[i].r=lower_bound(v+1,v+vid+1,a[i].r)-v;
        }
        
        sort(a+1,a+n+1);
        
        // cout<<n<<" "<<vid<<endl;
        
        P.build(1,vid,1);
        Q.build(1,vid,1);
        
        for(int i=1;i<=n;i++){
            int l=a[i].l,r=a[i].r,c=a[i].c;
            
            segtree &F=c?Q:P, &G=c?P:Q;
            
            F.modify(1,vid,1,r,vid,2);
            int tot=1;
            gmod(tot+=F.query(1,vid,1,1,r-1));
            gmod(tot+=G.query(1,vid,1,1,l-1));
            F.mdf(1,vid,1,r,tot);
        }
        
        int ans=(P.f[1]+Q.f[1]+1)%mod;
        printf("%lld\n",ans);
    }
    
}
