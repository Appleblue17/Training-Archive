#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3300,M=1e5+5,INF=1e9;
int T,n,len;
int alc=(1<<16)-1;
char S[N];
int w[N];

bool f[M];
void FWTand(bool *f,int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=(k<<1)){
            for(int j=0;j<k;j++){
                int x=i+j,y=i+j+k;
                f[x] |= f[y];
            }
        }
    }
}


signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("\n%s",S+1);
        for(int i=0;i<17;i++) scanf("%d",&w[i]);
        scanf("%d",&len);
        
        len=max(len,2);
        if(len%2==1) len++;
        
        memset(f,0,sizeof(f));
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            bool fl=1; int mac=0;
            for(int t=1;t<=len/2 && fl;t++){
                int x=S[l+t-1]-'a',y=S[r-t+1]-'a';
                if(x==y) fl=0;
                else mac |= (1<<min(x,y));
            }
            // if(fl) cout<<mac<<endl;
            if(fl) f[alc^mac]=1;
        }
        
        FWTand(f,1<<16);
        
        int ans=INF;
        for(int mac=0;mac<(1<<16);mac++){
            if(f[mac]) continue;
            int tot=0;
            for(int i=0;i<16;i++){
                if(mac>>i & 1) tot+=w[i];
            }
            ans=min(ans,tot);
        }
        
        printf("%lld\n",ans);
    }
}