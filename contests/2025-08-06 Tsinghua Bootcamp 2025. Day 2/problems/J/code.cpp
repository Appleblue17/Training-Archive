#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,mod=1e9+7,INF=1e18;

mt19937_64 rng(114514);

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
int ksm(int a,int x,int p){
    int tot=1;
    while(x){
        if(x & 1) tot=(__int128)tot*(__int128)a%p;
        a=(__int128)a*(__int128)a%p;
        x>>=1;
    }
    return tot;
}

int mul[N],inv[N];
void init(int lim){
    mul[0]=inv[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
    inv[lim]=ksm(mul[lim],mod-2);
    for(int i=lim-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
int C(int m,int n){
    if(m<0 || n<0 || m<n) return 0;
    return mul[m]*inv[n]%mod*inv[m-n]%mod;
}

int px[22]={2,3,5,7,11,13,17,19,23,29,31,37};
bool millar_rabin(int n){
    if(n<3 || n%2==0) return n==2;
    if(n%3==0) return n==3;
    int u=n-1,t=0;
    while(u%2==0) u/=2,t++;
    
    for(int i=0;i<12;i++){
        int a=px[i]%n;
        if(!a || a==1 || a==n-1) continue;
        int v=ksm(a,u,n);
        if(v==1) continue;
        int s;
        for(s=0;s<t;s++){
            if(v==n-1) break;
            v=(__int128)v*(__int128)v%n;
        }
        if(s==t) return 0;
    }
    return 1;
}

inline int f(int x,int c,int n){
    return ((__int128)x*(__int128)x%n+c)%n;
}
int pollard_rho(int n){
    if(n==4) return 2;
    int c=rng()%(n-1)+1;
    int t=f(0,c,n);
    int r=f(t,c,n);
    while(t!=r){
        int d=__gcd(abs(t-r),n);
        if(d>1) return d;
        t=f(t,c,n);
        r=f(f(r,c,n),c,n);
    }
    return n;
}
int pr_solve(int n){
    if(n==1) return 0;
    if(millar_rabin(n)) return 0;
    int x=pollard_rho(n);
    while(x==n) x=pollard_rho(n);
    return x;
}

int p[N],e[N],id;
map <int,int> mp;
void add(int n){
    if(!mp[n]){
        mp[n]=++id;
        p[id]=n;
    }
    e[mp[n]]++;
}
void defactor(int n){
    if(n==1) return ;
    
    // cout<<n<<" "<<millar_rabin(n)<<endl;
    if(millar_rabin(n)){
        add(n);
        return ;
    }
    int x=pr_solve(n);
    defactor(x);
    defactor(n/x);
}

int n,k,ans;
int pat[N];
int ID(int x){
    return (x & 1)?mod-1:1;
}
void dfs(int dep,int s,int mu,int d){
    if(dep>id){
        ans=(ans+ID(mu)*C(d+k-1,k)%mod)%mod;
        return ;
    }
    for(int i=0;i<=e[dep];i++,s*=p[dep]){
        if(i>=e[dep]-1){
            pat[dep]=i;
            int nmu=mu;
            dfs(dep+1,s,mu+(e[dep]-i),d*(i+1));
        }
    }
}

signed main(){
    init(N-5);
    cin>>n>>k;
    defactor(n);
    // for(int i=1;i<=id;i++) cout<<p[i]<<" "<<e[i]<<endl;
    // return 0;
    dfs(1,1,0,1);
    cout<<ans;
}