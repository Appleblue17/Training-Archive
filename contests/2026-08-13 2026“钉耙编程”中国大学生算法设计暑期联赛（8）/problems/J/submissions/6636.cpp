#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,mod=998244353,inv2=(mod+1)/2;

int T,n;
int pw[N];
void gmod(int &x){
    x%=mod;
}

int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}


int a[N],s[N];
int pre[3][N];
int lst[3];

signed main(){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*3%mod;
    
    T=rd();
    while(T--){
        n=rd();
        for(int i=1;i<=n;i++) a[i]=rd(),s[i]=(s[i-1]+a[i])%3;
        
        // cout<<"s: ";
        // for(int i=1;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        
        pre[0][0]=1,pre[1][0]=pre[2][0]=0;
        for(int i=1;i<=n;i++){
            for(int t=0;t<3;t++) pre[t][i]=pre[t][i-1];
            pre[s[i]][i]++;
        }
        
        int ans=0;
        lst[0]=0,lst[1]=lst[2]=-1;
        for(int i=1;i<=n;i++){
            int x=s[i];
            lst[x]=i;
            
            int y=(x+1)%3,z=(x+2)%3;
            int tot=0;
            
            // z -> x, I am 1
            if(lst[z]>=0){
                int k=pre[z][lst[z]];
                gmod(tot+=(pw[k]+mod-1)%mod*inv2%mod);
            }
            
            // y -> x, I am 2
            if(lst[y]>=0){
                if(lst[z]<lst[y]){
                    // 0 ... 0 2 ... 2
                    int k=pre[y][lst[y]];
                    gmod(tot+=(pw[k]+mod-1)%mod);
                }
                else{
                    // 0 ... 0 1 ... 1 2 ... 2
                    int k=pre[y][lst[y]];
                    int d=pre[z][lst[z]]-pre[z][lst[y]];
                    gmod(tot+=(pw[k]+mod-1)%mod*inv2%mod*(pw[d]+1)%mod);
                }
            }
            // cout<<i<<": "<<tot<<endl;
            gmod(ans+=tot);
        }
        printf("%lld\n",ans);
    }
}