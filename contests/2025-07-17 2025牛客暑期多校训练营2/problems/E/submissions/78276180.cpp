#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e7+5,M=3e6+5,B=50;
 
bool vis[N];
int pr[M],pid;
void init(int lim){
    for(int i=2;i<=lim;i++){
        if(!vis[i]) pr[++pid]=i;
        for(int j=1;j<=pid && i*pr[j]<=lim;j++){
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
}
 
int cal_sqrt(int n){
    int x=sqrt(n);
    while(x*x>n) x--;
    while((x+1)*(x+1)<=n) x++;
    return x;
}
 
 
namespace MIN25{
    const int N=1e5+5;
    int n,m;
    int mp[N],g[N],s[N],id;
    int ind1[N],ind2[N];
    int getpos(int x){
        if(x<=m) return ind1[x];
        else return ind2[n/x];
    }
    int cal(int n_){
        n=n_;
        m=cal_sqrt(n);
         
        id=0;
        for(int l=1,r;l<=n;l=r+1){
            r=n/(n/l);
            int tmp=n/l;
            mp[++id]=tmp;
            if(tmp<=m) ind1[tmp]=id;
            else ind2[n/tmp]=id;
            g[id]=tmp-1;
        }
         
        for(int k=1;pr[k]<=m;k++){
            for(int i=1;i<=id && pr[k]*pr[k]<=mp[i];i++){//g(i,k)
                int tmp=getpos(mp[i]/pr[k]);
                g[i]-=g[tmp]-(k-1);
            }
        }
        return g[1];
    }
}
 
int chk(int n,int lim){
    int tot=0;
    int x=n;
    for(int i=1;pr[i]*pr[i]<=x;i++){
        if(x%pr[i]) continue;
        if(n*n-pr[i]<=lim) tot++;
        while(x%pr[i]==0) x/=pr[i];
    }
    if(x>1 && n*n-x<=lim) tot++;
    return tot;
}
 
 
int val[B+5];
int solve(int n){
    int m=cal_sqrt(n);
     
    int ans=0;
    // for(int i=1;pr[i]<=m;i++){
    //     ans+=m/pr[i];
    // }
    for(int i=1;pr[i]<=m/B;i++){
        ans+=m/pr[i];
    }
    for(int t=1;t<=B;t++){
        val[t]=MIN25::cal(m/t);
    }
    for(int t=1;t<B;t++){
        ans+=(val[t]-val[t+1])*t;
    }
    for(int x=m+1;x*x<=n+m+5;x++){
        ans+=chk(x,n);
    }
     
    return ans;
}
 
signed main(){
    init(N);
     
    int L,R;
    cin>>L>>R;
    cout<<solve(R)-solve(L-1);
}
