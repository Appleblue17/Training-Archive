#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5,mod=998244353;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
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
void gmod(int &x){
    x%=mod;
}
 
 
int T,n;
int p[N],ls[N],rs[N];
 
int sta[N],cur;
void ins(int x){
    int sav=cur;
    while(cur && p[sta[cur]]>p[x]) cur--;
    if(cur) rs[sta[cur]]=x;
    if(cur<sav)ls[x]=sta[cur+1];
    sta[++cur]=x;
}
 
int ans;
void solve(int l,int r,int x,int k,int len){
    gmod(ans+=C(n-k+len-1,len));
    if(l>=r) return ;
    solve(l,x-1,ls[x],k+(r-x+1),len+1);
    solve(x+1,r,rs[x],k+(x-l+1),len+1);
}
 
signed main() {
    init(N-5);
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
        cur=0; ans=1;
        for(int i=1;i<=n;i++) ins(i);
         
        // for(int i=1;i<=n;i++) cout<<ls[i]<<" "<<rs[i]<<endl;
        // cout<<sta[1]<<endl;
         
        solve(1,n,sta[1],0,1);
        printf("%lld\n",ans);
    }
}
