#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
#define int long long
const int W=1e6,INF=1e18;

int m,n,g;
int a[11],ans[9];

bool vs[W+5];
int mp[10]={0,1,2,3,4,5,6,7,8,6};

int buc[9];
void upd(int x){
    memset(buc,0,sizeof(buc));
    while(x){
        buc[mp[x%10]]++;
        x/=10;
    }
    for(int i=0;i<9;i++) ans[i]=max(ans[i],buc[i]);
}

int p[20],id;
bool vis[20][2][2][20][1000];

int CUR;
void dfs(int t,bool iseq,bool isld,int c,int r){
    if(t<0){
        if(!r){
            ans[CUR]=max(ans[CUR],c);
        }
        return ;
    }
    if(t<=5 && isld) return ;
    if(vis[t][iseq][isld][c][r]) return ;
    vis[t][iseq][isld][c][r]=1;
    
    int lim=iseq?p[t]:9;
    for(int i=0;i<=lim;i++){
        bool niseq=iseq && (i==p[t]);
        bool nisld=isld && (i==0);
        int nc=c+(!(i==0 && isld) && mp[i]==CUR);
        int nr=(r*10%g+i)%g;
        
        dfs(t-1,niseq,nisld,nc,nr);
    }
}


signed main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i],g=__gcd(g,a[i]);
    
    ans[0]=1;
    upd(m);
    
    vs[0]=1;
    for(int i=0;i<W && i<=m;i++){
        if(vs[i]){
            for(int j=1;j<=n;j++){
                if(i+a[j]<W) vs[i+a[j]]=1;
            }
            upd(i);
        }
    }
    
    while(m){
        p[id++]=m%10;
        m/=10;
    }
    
    for(int i=0;i<9;i++){
        CUR=i;
        memset(vis,0,sizeof(vis));
        dfs(id,1,1,0,0);
    }
    
    for(int i=0;i<9;i++){
        if(ans[i]) cout<<i<<" "<<ans[i]<<endl;
    }
}
