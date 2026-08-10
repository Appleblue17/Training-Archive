#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;
 
void gmod(int &x){
    x%=mod;
    // x-=mod;
    // x+=x>>31 & mod;
}
 
int n;
char S[N];
int a[N];
 
 
int F[N][2],G[N][2]; // 0 - common; 1 - leap
int f[N][4][4][4][2][2];
int g[N][4][10][4];
 
bool isleapmonth[13]={0,1,0,1,0,1,0,1,1,0,1,0,1};
 
signed main(){
    // cout<<sizeof(f)/1024/1024;
    // return 0;
    scanf("%d",&n);
    scanf("\n%s",S+1);
    for(int i=1;i<=n;i++) a[i]=S[i]-'0';
     
    f[0][0][0][0][1][1]=1;
    for(int i=1;i<=n;i++){
        memcpy(f[i],f[i-1],sizeof(f[i]));
         
        for(int j=0;j<4;j++){
            for(int x=0;x<4;x++){
                for(int y=0;y<4;y++){
                    for(int p=0;p<2;p++){
                        for(int q=0;q<2;q++){
                            int val=f[i-1][j][x][y][p][q];
                            if(!val) continue;
                            int nx=x,ny=y,np=p,nq=q;
                             
                            if(j<=1){
                                nx=(nx*2+a[i])%4;
                                np &= (a[i]==0);
                            }
                            else{
                                ny=(ny*2+a[i])%4;
                                nq &= (a[i]==0);
                            }
                             
                            if(j<3) gmod(f[i][j+1][nx][ny][np][nq]+=val);
                            else{
                                if(!np || !nq){ // not 0000
                                    bool isleap=0;
                                    if(!ny){ // mod 4 = 0
                                        if(nq && !nx) isleap=1; // mod 400 = 0
                                        else if(!nq) isleap=1; // mod 100 != 0
                                    }
                                    gmod(F[i][isleap]+=val);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
     
    g[n+1][0][0][0]=1;
    for(int i=n;i>=1;i--){
        memcpy(g[i],g[i+1],sizeof(g[i]));
         
        for(int j=0;j<4;j++){
            for(int k=0;k<10;k++){
                for(int x=0;x<4;x++){
                    int val=g[i+1][j][k][x];
                    if(!val) continue;
                    int nx=x;
                     
                    if(j==1){
                        if(a[i]==0 && k==0) continue;
                         
                        if(a[i]<2) nx=0;
                        else if(a[i]==2){
                            if(k<=8) nx=0;
                            else nx=1;
                        }
                        else if(a[i]==3){
                            if(k==0) nx=2;
                            else if(k==1) nx=3;
                            else continue;
                        }
                        else continue;
                    }
                     
                    if(j<3) gmod(g[i][j+1][a[i]][nx]+=val);
                    else{
                        int month=a[i]*10+k;
                        if(month>=1 && month<=12){
                            if(month==2){
                                if(x==0) gmod(G[i][0]+=val);
                                if(x<=1) gmod(G[i][1]+=val);
                            }
                            else{
                                if(isleapmonth[month]){
                                    gmod(G[i][0]+=val);
                                    gmod(G[i][1]+=val);
                                }
                                else{
                                    if(x<=2){
                                        gmod(G[i][0]+=val);
                                        gmod(G[i][1]+=val);
                                    }
                                }
                            }
                             
                        }
                    }
                }
            }
        }
    }
     
    // for(int i=1;i<=n;i++) cout<<F[i][0]<<" "<<F[i][1]<<endl;
    // for(int i=1;i<=n;i++) cout<<G[i][0]<<" "<<G[i][1]<<endl;
     
    for(int i=1;i<=n;i++) gmod(F[i][0]+=F[i-1][0]),gmod(F[i][1]+=F[i-1][1]);
    int ans=0;
    for(int i=0;i<n;i++){
        gmod(ans+=1ll*F[i][0]*G[i+1][0]%mod);
        gmod(ans+=1ll*F[i][1]*G[i+1][1]%mod);
    }
    cout<<ans;
}
