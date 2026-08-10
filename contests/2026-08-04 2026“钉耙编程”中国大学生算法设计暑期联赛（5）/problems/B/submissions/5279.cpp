#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,INF=1e18,mod=998244353,inv2=(mod+1)/2;
int T,n,m;
int p[N],q[N];
int id[N],pos[N];

int f[N];
void sol(int dep,int n,int a,int b,int c){
    if(!a || !n){
        f[dep]=(n+1)*(b/c)%mod;
        return ;
    }
    if(a>=c || b>=c){
        sol(dep+1,n,a%c,b%c,c);
        f[dep]=(f[dep+1]+(a/c)%mod*n%mod*(n+1)%mod*inv2%mod+(b/c)%mod*(n+1)%mod)%mod;
        return ;
    }
    int t=(a*n+b)/c;
    sol(dep+1,t-1,c,c-b-1,a);
    f[dep]=(t%mod*n%mod+mod-f[dep+1])%mod;
}
int wrapper(int n,int a,int b,int c){
    sol(0,n,a,b,c);
    return f[0];
}

int A,B,C,D;
bool check(int d){
    int s1=wrapper(d,C,0,D);
    int s2=wrapper(d,B,A-1,A);
    int s=(s1+mod-s2+d)%mod;
    return (s>0);
}

signed main(){
    cin>>T;
    while(T--){
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
        for(int i=1;i<=n;i++) scanf("%lld",&q[i]);
        for(int i=1;i<=n;i++) id[i]=i;
        sort(id+1,id+n+1,[&](int x,int y){
            return p[x]*q[y]>p[y]*q[x];
        });
        for(int i=1;i<=n;i++) pos[id[i]]=i;
        
        A=p[id[1]],B=q[id[1]],C=p[id[2]],D=q[id[2]];
        // cout<<"  => "<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
        
        int l=0,r=B,tot=r;
        if(A*C<B*D) tot=INF;
        else{
            while(l<=r){
                int mid=(l+r)>>1ll;
                int res=check(mid);
                // cout<<" check "<<mid<<" "<<res<<endl;
                if(res) tot=mid,r=mid-1;
                else l=mid+1; 
            }
            // cout<<"  tot = "<<tot<<endl;
        }
        
        while(m--){
            int k,x; scanf("%lld%lld",&k,&x);
            if(pos[k]>=2){
                x=x*p[k]/q[k];
            }
            // cout<<" x="<<x<<endl;
            
            if(x>=tot) printf("Yes\n");
            else printf("No\n");
        }
        
    }
    
}