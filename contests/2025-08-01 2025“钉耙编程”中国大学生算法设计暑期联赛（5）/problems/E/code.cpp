#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1100,INF=1e9;
int T,A,B,C,D;
int la,lb,lc,ld;
int a[N],b[N],c[N],d[N];

int dp[2][N][N];
int id;
int sa,sb;

void trans(char ch,int num){
    id^=1;
    int na=sa,nb=sb;
    if(ch=='B') na+=2,nb++;
    else if(ch=='C') na+=3,nb++;
    else if(ch=='D') na+=4,nb+=2;
    
    for(int i=0;i<=na;i++)
        for(int j=0;j<=nb;j++)
            dp[id][i][j]=-INF;
    
    for(int i=0;i<=sa;i++){
        for(int j=0;j<=sb;j++){
            int val=dp[id^1][i][j];
            if(dp[id^1][i][j]<0) continue;
            if(ch=='B'){
                dp[id][i+2][j]=max(dp[id][i+2][j],val);
                dp[id][i][j+1]=max(dp[id][i][j+1],val);
            }
            else if(ch=='C'){
                if(num<=lc) dp[id][i][j]=max(dp[id][i][j],val+c[num]);
                dp[id][i+3][j]=max(dp[id][i+3][j],val);
                dp[id][i+1][j+1]=max(dp[id][i+1][j+1],val);
            }
            else if(ch=='D'){
                if(num<=ld) dp[id][i][j]=max(dp[id][i][j],val+d[num]);
                dp[id][i+4][j]=max(dp[id][i+4][j],val);
                dp[id][i+2][j+1]=max(dp[id][i+2][j+1],val);
                dp[id][i][j+2]=max(dp[id][i][j+2],val);
            }
        }
    }
    
    sa=na,sb=nb;
}


signed main() {
    cin>>T;
    while(T--){
        scanf("%d%d%d%d",&A,&B,&C,&D);
        scanf("%d",&la);
        for(int i=1;i<=la;i++) scanf("%d",&a[i]);
        sort(a+1,a+la+1,greater<int>());
        for(int i=1;i<=la;i++) a[i]+=a[i-1];
        
        scanf("%d",&lb);
        for(int i=1;i<=lb;i++) scanf("%d",&b[i]);
        sort(b+1,b+lb+1,greater<int>());
        for(int i=1;i<=lb;i++) b[i]+=b[i-1];
        
        scanf("%d",&lc);
        for(int i=1;i<=lc;i++) scanf("%d",&c[i]);
        sort(c+1,c+lc+1,greater<int>());
        // for(int i=1;i<=lc;i++) c[i]+=c[i-1];
        
        scanf("%d",&ld);
        for(int i=1;i<=ld;i++) scanf("%d",&d[i]);
        sort(d+1,d+ld+1,greater<int>());
        // for(int i=1;i<=ld;i++) d[i]+=d[i-1];
        
        sa=0,sb=0;
        id=0;
        dp[id][0][0]=0;
        for(int i=1;i<=B;i++) trans('B',i);
        for(int i=1;i<=C;i++) trans('C',i);
        for(int i=1;i<=D;i++) trans('D',i);
        
        int ans=0;
        for(int i=0;i<=sa;i++){
            for(int j=0;j<=sb;j++){
                // if(dp[id][i][j]>=0) cout<<i<<" "<<j<<" "<<dp[id][i][j]<<endl;
                
                int x=min(la,i+A),y=min(lb,j);
                ans=max(ans,dp[id][i][j]+a[x]+b[y]);
            }
        }
        printf("%d\n",ans);
    }
}