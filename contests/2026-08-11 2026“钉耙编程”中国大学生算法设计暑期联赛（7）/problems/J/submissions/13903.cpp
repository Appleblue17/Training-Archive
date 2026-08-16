#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5,mod=998244353;

int T,n;
char S[N];
int s[N];

void gmod(int &x){
    x%=mod;
}

int lst[N];
int ch0[N],ch1[N];
int dp[N];


signed main(){
    // cout<<sizeof(dp)/1024/1024;
    // return 0;
    scanf("%lld",&T);
    while(T--){
        scanf("\n%s",S+1);
        n=strlen(S+1);
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+((S[i]=='1')?1:-1);
        }
        
        // for(int i=1;i<=n;i++) cout<<s[i]<<" "; cout<<endl;
        
        int m=n+5;
        for(int i=0;i<=2*m;i++) lst[i]=-1;
        
        int R=n; int lim=0;
        for(int i=n-1;i>=0;i--){
            
            ch0[i]=lst[s[i]-1+m];
            ch1[i]=lst[s[i]+1+m];
            
            if(S[i]==S[i+1]){
                if(!lim){
                    lim=i;
                }
                while(R>i){
                    lst[s[R]+m]=R;
                    R--;
                }
            }
        }
        if(!lim){
            printf("1\n");
            continue;
        }
        
        // for(int i=0;i<=n;i++) cout<<ch0[i]<<" "; cout<<endl;
        // for(int i=0;i<=n;i++) cout<<ch1[i]<<" "; cout<<endl;
        int len=n-lim;
        
        int ans=0;
        for(int i=0;i<=n;i++) dp[i]=0;
        dp[0]=1;
        for(int i=0;i<n;i++){
            // cout<<i<<":"<<dp[i]<<" | ";
            if(ch0[i]!=-1){
                if(S[i+1]!='0'){
                    // cout<<"ch0="<<ch0[i]<<"; ";
                    gmod(dp[ch0[i]]+=dp[i]);
                }
                if(s[n]==s[i]-1) gmod(ans+=dp[i]);//,cout<<"ans ";
            }
            
            if(ch1[i]!=-1){
                if(S[i+1]!='1'){
                    // cout<<"ch1="<<ch1[i]<<"; ";
                    gmod(dp[ch1[i]]+=dp[i]);
                }
                if(s[n]==s[i]+1) gmod(ans+=dp[i]);//,cout<<"ans ";
            }
            // cout<<endl;
            
            gmod(dp[i+1]+=dp[i]);
        }
        // cout<<"dp[n] = "<<dp[n]<<endl;
        
        // gmod(ans+=dp[n-1]);
        // cout<<" ans = "<<ans<<endl;
        
        // cout<<"lim = "<<lim<<endl;
        for(int i=n-1;i>=lim;i-=2) gmod(ans+=dp[i]);
        // if(len>2 && lim) gmod(ans+=dp[n-1-((len-1)/2)*2]);
        
        printf("%lld\n",ans);
    }
    
}