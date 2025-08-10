#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=110,M=1e6+5,K=11,INF=1e9;
int n,k,stx,sty,m;
char S[N][N],T[M];
int T_[M];

int fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int dis[N][N][4][4][K][K];
int dp[M][K];

bool check(pair<int,int> x){
    return S[x.first][x.second]=='b';
}

pair<int,int> getpos(int l,int L,int dir,int x){
    if(dir==0) return MP(l+x,L);
    else if(dir==1) return MP(l+x,L+k-1);
    else if(dir==2) return MP(l,L+x);
    else if(dir==3) return MP(l+k-1,L+x);
}

int ds[N][N];
queue < pair<int,int> > q;

signed main(){
    // cout<<(sizeof(dis)+sizeof(dp))/1024/1024;
    // return 0;
    
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("\n%s",S[i]+1);
    
    scanf("%d%d",&stx,&sty);
    scanf("%d",&m);
    scanf("\n%s",T+1);
    for(int i=1;i<=m;i++){
        if(T[i]=='L') T_[i]=0;
        else if(T[i]=='R') T_[i]=1;
        else if(T[i]=='U') T_[i]=2;
        else if(T[i]=='D') T_[i]=3;
    }
    
    for(int l=1;l<=n-k+1;l++){
        for(int L=1;L<=n-k+1;L++){
            int r=l+k-1,R=L+k-1;
            
            for(int d=0;d<4;d++){
                for(int t=0;t<k;t++){
                    pair<int,int> pos=getpos(l,L,d,t);
                    if(!check(pos)) continue;
                    
                    for(int i=l;i<=r;i++){
                        for(int j=L;j<=R;j++){
                            ds[i][j]=INF;
                        }
                    }
                    ds[pos.first][pos.second]=0;
                    q.push(pos);
                    
                    while(q.size()){
                        pair<int,int> u=q.front(); q.pop();
                        int x=u.first,y=u.second;
                        for(int s=0;s<4;s++){
                            int nx=x+fx[s][0],ny=y+fx[s][1];
                            if(nx>=l && nx<=r && ny>=L && ny<=R && check(MP(nx,ny)) && ds[nx][ny]==INF){
                                ds[nx][ny]=ds[x][y]+1;
                                q.push(MP(nx,ny));
                            }
                        }
                    }
                    
                    for(int e=0;e<4;e++){
                        for(int s=0;s<k;s++){
                            pair<int,int> npos=getpos(l,L,e,s);
                            dis[l][L][d][e][t][s]=ds[npos.first][npos.second];
                        }
                    }
                }
            }
            
            // if(l==3 && L==3){
            //     cout<<l<<" "<<L<<": "<<endl;
            //     for(int d=0;d<4;d++){
            //         for(int e=0;e<4;e++){
            //             cout<<"  "<<d<<" "<<e<<": "<<endl;
            //             for(int i=0;i<k;i++){
            //                 cout<<"    ";
            //                 for(int j=0;j<k;j++){
            //                     cout<<dis[l][L][d][e][i][j]<<" ";
            //                 }
            //                 cout<<endl;
            //             }
            //         }
            //     }
            // }
            
        }
    }
    
    T_[0]=T_[1];
    for(int t=1;t<=m;t++){
        int x=T_[t-1],y=T_[t];
        for(int i=0;i<k;i++) dp[t][i]=INF;
        
        int nstx=stx,nsty=sty;
        if(y==0) nsty--;
        else if(y==1) nsty++;
        else if(y==2) nstx--;
        else if(y==3) nstx++;
        
        // cout<<t<<" "<<x<<" "<<y<<": "<<nstx<<" "<<nsty<<endl;
        
        for(int i=0;i<k;i++){
            pair<int,int> pos=getpos(stx,sty,y,i),npos=getpos(nstx,nsty,y,i);
            // cout<<"  "<<i<<": "<<pos.first<<","<<pos.second<<" "<<npos.first<<","<<npos.second<<endl;
            if(!check(pos) || !check(npos)) continue;
            // cout<<"HELLO"<<endl;
            for(int j=0;j<k;j++){
                dp[t][i]=min(dp[t][i],dp[t-1][j]+dis[stx][sty][x][y][j][i]+1);
            }
        }
        // for(int i=0;i<k;i++) cout<<dp[t][i]<<" "; cout<<endl;
        stx=nstx,sty=nsty;
    }
    
    int ans=INF;
    for(int i=0;i<k;i++) ans=min(ans,dp[m][i]);
    cout<<ans;
}