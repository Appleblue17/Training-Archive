#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=55,B=4e4+5,mod=998244353;
int n,k;
int a[N],f[N];

void gmod(int &x){
    x%=mod;
}

void getmod(int *f,int m){
    for(int i=m;i>=k;i--){
        for(int j=1;j<=k;j++) gmod(f[i-j]+=1ll*f[i]*a[j]%mod);
        f[i]=0;
    }
}

struct abc{
    int F[N];
    abc(){
        memset(F,0,sizeof(F));
    }
    void pr(){
        for(int i=0;i<k;i++) cout<<F[i]<<" ";
        cout<<endl;
    }
};
int tmp[N*2];
abc operator *(abc X,abc Y){
    abc S;
    for(int i=0;i<=2*(k-1);i++) tmp[i]=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            gmod(tmp[i+j]+=1ll*X.F[i]*Y.F[j]%mod);
        }
    }
    getmod(tmp,2*(k-1));
    for(int i=0;i<k;i++) S.F[i]=tmp[i];
    return S;
}

abc pre1[B],pre2[B];

abc ans;

signed main(){
    // freopen("A0in.txt","r",stdin);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=k;i++) scanf("%lld",&a[i]);
    f[0]=1;
    for(int i=1;i<=k;i++){
        for(int t=1;t<=min(i,k);t++){
            gmod(f[i]+=a[t]*f[i-t]%mod);
        }
    }
    
    pre1[0].F[0]=1,pre2[0].F[0]=1;
    int lim=B-5;
    for(int t=1;t<=lim;t++){
        for(int i=1;i<=k;i++) pre1[t].F[i]=pre1[t-1].F[i-1];
        getmod(pre1[t].F,k);
        // cout<<t<<": ";
        // pre1[t].pr();
    }
    for(int t=1;t<=lim;t++){
        pre2[t]=pre2[t-1]*pre1[lim];
        // cout<<t<<": ";
        // pre2[t].pr();
    }

    ans.F[0]=1;
    for(int i=1;i<=n;i++){
        int x; scanf("%lld",&x);
        abc tot=pre1[x%lim]*pre2[x/lim];
        tot.F[0]++;
        ans=ans*tot;
    }
    // ans.pr();

    int anss=0;
    for(int i=0;i<k;i++) gmod(anss+=1ll*f[i]*ans.F[i]%mod);
    cout<<anss;
}