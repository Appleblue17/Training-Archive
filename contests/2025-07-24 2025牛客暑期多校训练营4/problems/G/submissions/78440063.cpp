#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,mod=998244353;
 
int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1ll;
    }
    return tot;
}
 
int pw[N];
void init(int lim){
    pw[0]=1;
    for(int i=1;i<=lim;i++) pw[i]=pw[i-1]*2%mod;
}
 
int n,ans;
char S[N];
int s[N],pre[N],suf[N];
 
signed main(){
    init(N-5);
     
    scanf("%s",S+1);
    n=strlen(S+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1];
        if(S[i]=='(') s[i]++;
        else s[i]--;
        pre[i]=pre[i-1]+(S[i]=='(');
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+(S[i]==')');
    }
     
    int alc=pw[suf[1]];
    for(int i=1;i<=n;i++){
        if(S[i]=='(') alc=(alc+pw[pre[i]-1]*pw[suf[i+1]]%mod)%mod;
    }
     
    for(int l=1,r;l<=n;l=r+1){
        r=l;
        if(s[l]<2) continue;
        while(r+1<=n && s[r+1]>=2) r++;
         
        for(int i=l;i<=r+1;i++){
            if(S[i]=='('){
                // cout<<i<<" "<<r<<": "<<pw[pre[i]-1]<<" "<<(pw[suf[i+1]]+mod-pw[suf[r+2]])%mod<<endl;
                ans=(ans+pw[pre[i]-1]*(pw[suf[i+1]]+mod-pw[suf[r+2]])%mod)%mod;
            }
        }
    }
     
    // cout<<alc<<" "<<ans<<endl;
    cout<<(alc+mod-ans)%mod*ksm(pw[n],mod-2)%mod;
}
