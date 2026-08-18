#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,INF=1e18;
int T,n,q;
int c[N],s[N];

int rd(){
    bool fl=0;
    char c=getchar();
    int tot=0;
    while(!isdigit(c)){
        if(c=='-') fl=1;
        c=getchar();
    }
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return fl?-tot:tot;
}

struct segtree{
    int f[N*4],laz[N*4];
    int (*func)(int, int);
    segtree(auto f) : func(f) {}
    
    void pushdown(int o){
        int x=laz[o]; laz[o]=0;
        f[o<<1]+=x; laz[o<<1]+=x;
        f[o<<1|1]+=x; laz[o<<1|1]+=x;
    }
    
    void build(int l,int r,int o,int *a){
        laz[o]=0;
        if(l==r){
            f[o]=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l,mid,o<<1,a);
        build(mid+1,r,o<<1|1,a);
        f[o]=func(f[o<<1],f[o<<1|1]);
    }
    
    void modify(int l,int r,int o,int L,int R,int x){
        if(L>R) return ;
        if(L<=l && r<=R){
            f[o]+=x;
            laz[o]+=x;
            return ;
        }
        pushdown(o);
        int mid=(l+r)>>1;
        if(L<=mid) modify(l,mid,o<<1,L,R,x);
        if(R>mid) modify(mid+1,r,o<<1|1,L,R,x);
        f[o]=func(f[o<<1],f[o<<1|1]);
    }
    
    void get(int l,int r,int o,int *a){
        if(l==r){
            a[l]=f[o];
            return ;
        }
        pushdown(o);
        int mid=(l+r)>>1;
        get(l,mid,o<<1,a);
        get(mid+1,r,o<<1|1,a);
    }
};

int my_min(int x,int y){ return (x<y)?x:y; }
int my_max(int x,int y){ return (x<y)?y:x; }
segtree MN(my_min),MX(my_max);

int tmp[N];

void modify(int pos,int x){
    if(pos<0) return ;
    if(pos%2==0){
        MN.modify(0,n,1,0,n,x);
        MX.modify(0,n,1,pos+1,n,x);
    }
    else{
        MN.modify(0,n,1,0,pos-1,x);
    }
}

int cur[N],g[N];
void solve(int opt){
    int mn=MX.f[1],mx=MN.f[1];
    if(mn>mx || mx<0){
        printf("No\n");
        return ;
    }
    else printf("Yes\n");
    
    if(!opt) return ;
    
    int x=mx;
    
    MN.get(0,n,1,tmp);
    for(int i=0;i<=n;i+=2) cur[i]=tmp[i];
    
    MX.get(0,n,1,tmp);
    for(int i=1;i<=n;i+=2) cur[i]=tmp[i];
    
    // cout<<mn<<" "<<mx<<endl;
    // cout<<" cur: ";
    // for(int i=0;i<=n;i++) cout<<cur[i]<<" "; cout<<endl; 
    
    for(int i=0;i<=n;i+=2) g[i]=cur[i]-x;
    for(int i=1;i<=n;i+=2) g[i]=-cur[i]+x;
    
    for(int i=1;i<=x;i++) putchar('L');
    for(int i=0;i<n;i++){
        putchar('R');
        for(int j=1;j<=g[i];j++) putchar('L'),putchar('R');
    }
    for(int i=1;i<=g[n];i++) putchar('R');
    for(int i=1;i<=n;i++) putchar('L');
    putchar('\n');
}


signed main(){
    T=rd();
    while(T--){
        n=rd(),q=rd();
        for(int i=0;i<=n;i++) c[i]=rd();
        for(int i=0;i<=n;i++) c[i]-=2;
        c[0]++,c[n]++;
        
        s[0]=c[0];
        for(int i=2;i<=n;i+=2) s[i]=s[i-2]+(c[i]-c[i-1]);
        
        s[1]=c[0]-c[1];
        for(int i=3;i<=n;i+=2) s[i]=s[i-2]+(c[i-1]-c[i]);
        
        // for(int i=0;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        
        for(int i=0;i<=n;i++) tmp[i]=INF;
        for(int i=0;i<=n;i+=2) tmp[i]=s[i];
        MN.build(0,n,1,tmp);
        
        for(int i=0;i<=n;i++) tmp[i]=-INF;
        for(int i=1;i<=n;i+=2) tmp[i]=s[i];
        MX.build(0,n,1,tmp);
        
        
        while(q--){
            int l=rd(),r=rd(),x=rd(),opt=rd();
            // cout<<" get "<<l<<" "<<r<<" "<<x<<" "<<opt<<endl;
            modify(r,x);
            modify(l-1,-x);
            
            solve(opt);
        }
    }
}