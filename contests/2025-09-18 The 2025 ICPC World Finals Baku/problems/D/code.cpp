#include<bits/stdc++.h>
using namespace std;
const int N=220,M=11000,INF=1e9;

int n,m,l;
int p[4];
int mp[24][4],id;

int dp[M][24];
char S[N][N],T[M];

int fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int cal(int x,int y,int k){
    for(int i=0;i<4;i++){
        int t=mp[k][i];
        int nx=x+fx[t][0],ny=y+fx[t][1];
        if(nx>=1 && nx<=n && ny>=1 && ny<=m && S[nx][ny]!='#') return t;
    }
    return -1;
}
char trans(char c){
    switch(c){
        case 'N': return 0;
        case 'E': return 1;
        case 'S': return 2;
        case 'W': return 3;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("\n%s",S[i]+1);
    }
    scanf("\n%s",T+1);
    l=strlen(T+1);
    
    for(int i=0;i<4;i++) p[i]=i;
    
    do{
        for(int i=0;i<4;i++) mp[id][i]=p[i];
        id++;
    }while(next_permutation(p,p+4));
    
    int x,y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S[i][j]=='S') x=i,y=j;
        }
    }
    
    for(int t=1;t<=l;t++){
        // cout<<t<<": "<<x<<" "<<y<<endl;
        
        int d=trans(T[t]);
        for(int i=0;i<24;i++) dp[t][i]=INF;
        for(int i=0;i<24;i++){
            // cout<<"  "<<i<<" "<<cal(x,y,i)<<" "<<d<<endl;
            if(cal(x,y,i)!=d) continue;
            for(int j=0;j<24;j++){
                dp[t][i]=min(dp[t][i],dp[t-1][j]+(i!=j));
            }
        }
        
        x+=fx[d][0],y+=fx[d][1];
        
        // for(int i=0;i<24;i++) cout<<dp[t][i]<<" "; cout<<endl;
    }
    
    int ans=INF;
    for(int i=0;i<24;i++) ans=min(ans,dp[l][i]);
    cout<<ans;
}
