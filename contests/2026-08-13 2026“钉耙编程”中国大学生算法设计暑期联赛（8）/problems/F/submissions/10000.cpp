#include<bits/stdc++.h>
using namespace std;
const int N=4e4+5,M=22,INF=1e9;
int T,n,q;
int rd(){
    int tot=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

int col[N];
int lst[N],tmp[M];

int ans[N];


vector < pair<int,int> > Q[N]; // {num, y}
bool V[M][M]; // c

int f[M][M];

void upd(int dis,int c,int pos){
    if(dis<=20 && f[c][dis]>pos){
        f[c][dis]=pos;
        V[dis][c]=1;
    }
}

int lcol[N][M],rcol[N][M];

int main(){
    T=rd();
    while(T--){
        n=rd(); q=rd();
        for(int i=1;i<=n;i++){
            Q[i].clear();
        }
        
        for(int i=1;i<=n;i++) col[i]=rd();
        for(int i=1;i<=20;i++) tmp[i]=-1;
        for(int i=1;i<=n;i++){
            lst[i]=tmp[col[i]];
            tmp[col[i]]=i;
        }
        
        for(int i=1;i<=20;i++) tmp[i]=-1;
        for(int i=n;i>=1;i--){
            int nxt=tmp[col[i]];
            if(nxt==-1){
                for(int c=1;c<=20;c++) lcol[i][c]=rcol[i][c]=-1;
            }
            else{
                for(int c=1;c<=20;c++) lcol[i][c]=lcol[nxt][c],rcol[i][c]=rcol[nxt][c];
            }
            if(i>1) lcol[i][col[i-1]]=i-1;
            if(i<n) rcol[i][col[i+1]]=i+1;
            tmp[col[i]]=i;
            
            // cout<<i<<": ";
            // for(int c=1;c<=6;c++) cout<<rcol[i][c]<<" "; cout<<endl;
        }
        
        for(int i=1;i<=q;i++){
            int x=rd(),y=rd();
            if(x>y) swap(x,y);
            Q[x].push_back({i,y});
        }
        
        for(int u=1;u<=n;u++){
            for(int c=1;c<=20;c++)
                for(int i=0;i<=20;i++) f[c][i]=INF;
                
            for(int i=0;i<=20;i++)
                for(int c=1;c<=20;c++)
                    V[i][c]=0;
            f[col[u]][0]=u;
            V[0][col[u]]=1;
            
            for(int d=0;d<20;d++){
                for(int c=1;c<=20;c++){
                    if(!V[d][c]) continue;
                    int pos=f[c][d];
                    
                    // cout<<" start "<<d<<": "<<c<<" "<<pos<<endl;
                    
                    int las=lst[pos];
                    if(las!=-1){
                        int nd=d+(pos-las)*2;
                        upd(nd,c,las);
                    }
                    
                    for(int nc=1;nc<=20;nc++){
                        int npos=lcol[pos][nc];
                        if(npos!=-1) upd(d+3,nc,npos); //,cout<<" <-"<<npos<<endl;
                    }
                    for(int nc=1;nc<=20;nc++){
                        int npos=rcol[pos][nc];
                        if(npos!=-1) upd(d+1,nc,npos); //,cout<<" ->"<<npos<<endl;
                    }
                    
                }
            }
            
            // for(int c=1;c<=8;c++){
            //     cout<<c<<": ";
            //     for(int i=0;i<=8;i++){
            //         if(f[c][i]==INF) cout<<"INF ";
            //         else cout<<f[c][i]<<" ";
            //     }
            //     cout<<endl;
            // }
            
            for(auto e: Q[u]){
                int num=e.first,y=e.second,c=col[y];
                int s=0;
                while(s<=19 && f[c][s]>y) s++;
                ans[num]=y-u+s;
            }
        }
        
        for(int i=1;i<=q;i++) printf("%d ",ans[i]);
        printf("\n");
    }
}