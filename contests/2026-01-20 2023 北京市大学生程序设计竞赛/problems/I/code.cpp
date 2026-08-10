#include<bits/stdc++.h>
using namespace std;
const int N=670,M=1100,mod=1e9+7;
int n,L,ans;
int LEN[N];
char S[N][N];

void gmod(int &x){
    x%=mod;
}

bool mat[N][N][N];
bool pre[N][N];

vector <int> dp[M][N];

int main(){
    // cout<<sizeof(mat)/1024/1024;
    // return 0;
    
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++){
        scanf("\n%s",S[i]);
        int len=strlen(S[i]);
        LEN[i]=LEN[i+n]=len;
        
        for(int j=0;j<len;j++) S[i+n][len-1-j]=S[i][j];
    }
    
    for(int i=1;i<=n*2;i++){
        int len=LEN[i];
        for(int t=0;t<len;t++){
            for(int j=1;j<=n*2;j++){
                if((i<=n)==(j<=n)) continue;
                bool fl=1;
                
                for(int pos1=t,pos2=0;pos1<len && pos2<LEN[j];pos1++,pos2++){
                    if(S[i][pos1]!=S[j][pos2]){
                        fl=0;
                        break;
                    }
                }
                mat[i][t][j]=fl;
            }
        }
    }
    
    for(int i=1;i<=n*2;i++){
        int len=LEN[i];
        for(int t=0;t<=len;t++){
            bool fl=1;
            for(int j=t;j<len;j++){
                if(S[i][j]!=S[i][len+t-1-j]){
                    fl=0;
                    break;
                }
            }
            pre[i][t]=fl;
        }
    }
    
    for(int t=0;t<L;t++){
        for(int i=0;i<=n*2;i++){
            dp[t][i].resize(LEN[i]+1);
        }
    }
    
    dp[0][0][0]=1;
    for(int k=0;k<L;k++){
        for(int i=0;i<=n*2;i++){
            int len=LEN[i];
            for(int t=0;t<=len;t++){
                int val=dp[k][i][t];
                if(!val) continue;
                // cout<<k<<" "<<i<<" "<<t<<": "<<val<<endl;
                
                int Llim=1,Rlim=n;
                if(i>=1 && i<=n) Llim=n+1,Rlim=n*2;
                
                for(int j=Llim;j<=Rlim;j++){
                    int leni=len-t;
                    int lenj=LEN[j];
                    if(k+lenj>L) continue;
                    if(i && !mat[i][t][j]) continue;
                    
                    // if(k==1 && i==1 && j==3) cout<<"HELLO"<<" "<<mat[i][t][j]<<endl;
                    if(k+lenj==L){
                        if(leni<lenj){
                            // cout<<"  A "<<j<<" ! "<<j<<" "<<leni<<endl;
                            if(pre[j][leni]) gmod(ans+=val);
                        }
                        else{
                            // cout<<"  B "<<j<<" ! "<<i<<" "<<lenj+t<<endl;
                            if(pre[i][lenj+t]) gmod(ans+=val);
                        }
                        continue;
                    }
                    if(leni>lenj){
                        // cout<<"  A "<<j<<" -> "<<k+lenj<<" "<<i<<" "<<t+lenj<<endl;
                        gmod(dp[k+lenj][i][t+lenj]+=val);
                    }
                    else if(leni<lenj){
                        // cout<<"  B "<<j<<" -> "<<k+lenj<<" "<<j<<" "<<leni<<endl;
                        gmod(dp[k+lenj][j][leni]+=val);
                    }
                    else{
                        // cout<<"  C "<<j<<" -> "<<k+lenj<<" "<<0<<" "<<0<<endl;
                        gmod(dp[k+lenj][0][0]+=val);
                    }
                }
            }
        }
    }
    cout<<ans;
}
