#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,mod=998244353;
int T,n;
char S_[N],L_[N];
int S[N],L[N];
 
int dp[N][2][2][2][2][2][2];
 
void gmod(int &x){
    x%=mod;
}
 
signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("\n%s %s",L_,S_);
        int lenS=strlen(S_),lenL=strlen(L_);
        n=max(lenS,lenL);
        for(int i=1;i<=n;i++) S[i]=L[i]=0;
        for(int i=0;i<lenS;i++) S[lenS-i]=S_[i]-'0';
        for(int i=0;i<lenL;i++) L[lenL-i]=L_[i]-'0';
         
        // for(int i=1;i<=n;i++) cout<<S[i]; cout<<endl;
        // for(int i=1;i<=n;i++) cout<<L[i]; cout<<endl;
         
        for(int i=1;i<=n+1;i++) memset(dp[i],0,sizeof(dp[i]));
        dp[n+1][0][0][0][0][0][0]=1;
        for(int i=n;i>=1;i--){
            for(int t=0;t<=1;t++){
            for(int x=0;x<=1;x++){
            for(int y=0;y<=1;y++){
                for(int p=0;p<=1;p++){
                for(int q=0;q<=1;q++){
                for(int r=0;r<=1;r++){
                    if(!dp[i+1][t][x][y][p][q][r]) continue;
                    for(int a=0;a<=1;a++){
                    for(int b=0;b<=1;b++){
                    for(int c=0;c<=1;c++){
                        if(!t && S[i]<a) continue;
                        int nt=t | (S[i]>a);
                         
                        if(!x && a<b) continue;
                        int nx=x | (a>b);
                        if(!y && a<c) continue;
                        int ny=y | (a>c);
                         
                        bool abc=a^b^c;
                        if(!p && abc>L[i]) continue;
                        int np=p | (abc<L[i]);
                         
                        bool nq=q,nr=0;
                        if(!q){
                            int sum=b+c;
                            if(sum==0){
                                if(r) continue;
                                else nr=a;
                            }
                            else if(sum==1){
                                if(r && a) continue;
                                else if(r && !a) nr=1;
                                else if(!r && a) nr=0;
                                else nq=1,nr=0;
                            }
                            else{
                                if(!r) nq=1,nr=0;
                                else nr=a;
                            }
                        }
                         
                        gmod(dp[i][nt][nx][ny][np][nq][nr]+=dp[i+1][t][x][y][p][q][r]);
                    }}}
                }}}
            }}}
        }
         
        int ans=0;
        for(int t=0;t<=1;t++){
            for(int p=0;p<=1;p++){
                    gmod(ans+=dp[1][t][1][1][p][1][0]);
                }
        }
         
         
        for(int i=1;i<=n+1;i++) memset(dp[i],0,sizeof(dp[i]));
        dp[n+1][0][0][0][0][0][0]=1;
        for(int i=n;i>=1;i--){
            for(int t=0;t<=1;t++){
            for(int x=0;x<=1;x++){
            for(int y=0;y<=1;y++){
                for(int p=0;p<=1;p++){
                for(int q=0;q<=1;q++){
                for(int r=0;r<=1;r++){
                    if(!dp[i+1][t][x][y][p][q][r]) continue;
                    for(int a=0;a<=1;a++){
                        int b=a;
                    for(int c=0;c<=1;c++){
                        if(!t && S[i]<a) continue;
                        int nt=t | (S[i]>a);
                         
                        if(!x && a<b) continue;
                        int nx=x | (a>b);
                        if(!y && a<c) continue;
                        int ny=y | (a>c);
                         
                        bool abc=a^b^c;
                        if(!p && abc>L[i]) continue;
                        int np=p | (abc<L[i]);
                         
                        bool nq=q,nr=0;
                        if(!q){
                            int sum=b+c;
                            if(sum==0){
                                if(r) continue;
                                else nr=a;
                            }
                            else if(sum==1){
                                if(r && a) continue;
                                else if(r && !a) nr=1;
                                else if(!r && a) nr=0;
                                else nq=1,nr=0;
                            }
                            else{
                                if(!r) nq=1,nr=0;
                                else nr=a;
                            }
                        }
                         
                        gmod(dp[i][nt][nx][ny][np][nq][nr]+=dp[i+1][t][x][y][p][q][r]);
                    }}
                }}}
            }}}
        }
        for(int t=0;t<=1;t++){
            for(int p=0;p<=1;p++){
                    gmod(ans+=dp[1][t][0][1][p][1][0]);
                }
        }
         
         
         
        for(int i=1;i<=n+1;i++) memset(dp[i],0,sizeof(dp[i]));
        dp[n+1][0][0][0][0][0][0]=1;
        for(int i=n;i>=1;i--){
            for(int t=0;t<=1;t++){
            for(int x=0;x<=1;x++){
            for(int y=0;y<=1;y++){
                for(int p=0;p<=1;p++){
                for(int q=0;q<=1;q++){
                for(int r=0;r<=1;r++){
                    if(!dp[i+1][t][x][y][p][q][r]) continue;
                    for(int a=0;a<=1;a++){
                        int b=a,c=a;
                        if(!t && S[i]<a) continue;
                        int nt=t | (S[i]>a);
                         
                        if(!x && a<b) continue;
                        int nx=x | (a>b);
                        if(!y && a<c) continue;
                        int ny=y | (a>c);
                         
                        bool abc=a^b^c;
                        if(!p && abc>L[i]) continue;
                        int np=p | (abc<L[i]);
                         
                        bool nq=q,nr=0;
                        if(!q){
                            int sum=b+c;
                            if(sum==0){
                                if(r) continue;
                                else nr=a;
                            }
                            else if(sum==1){
                                if(r && a) continue;
                                else if(r && !a) nr=1;
                                else if(!r && a) nr=0;
                                else nq=1,nr=0;
                            }
                            else{
                                if(!r) nq=1,nr=0;
                                else nr=a;
                            }
                        }
                         
                        gmod(dp[i][nt][nx][ny][np][nq][nr]+=dp[i+1][t][x][y][p][q][r]);
                    }
                }}}
            }}}
        }
        for(int t=0;t<=1;t++){
            for(int p=0;p<=1;p++){
                    gmod(ans+=dp[1][t][0][0][p][1][0]);
                }
        }
         
        printf("%lld\n",ans);
    }
     
     
}
