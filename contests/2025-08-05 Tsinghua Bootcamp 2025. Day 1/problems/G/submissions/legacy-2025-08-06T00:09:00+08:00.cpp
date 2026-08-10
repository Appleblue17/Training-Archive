#include<bits/stdc++.h>
using namespace std;
const int N=110,M=12,K=6e5+5,I=6600,INF=1e9;
int n,m;
char S[N][M];

int dim[11]={2,2,3,3,4,4,5,5,6,6};
int pw[11];

int pat[M];

bool check(){
    for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){        
    for(int p=j+1;p<m;p++){
    for(int q=p+1;q<m;q++){
        if(pat[i] && pat[j] && pat[p] && pat[q] && pat[i]==pat[p] && pat[j]==pat[q] && pat[i]!=pat[j]) return 0;
    }}}}
    return 1;
}

int id,mp[K],p[I],p0[I];
int convert(int *f){
    int tot=0;
    for(int i=0;i<10;i++){
        assert(f[i]<dim[i]);
        tot+=f[i]*pw[i];
    }
    return tot;
}
int convert0(int *f){
    int tot=0;
    for(int i=0;i<10;i++){
        if(f[i]) tot |= 1<<i;
    }
    return tot;
}
void iconvert(int *f,int mac){
    for(int i=0;i<10;i++){
        f[i]=mac%dim[i];
        mac/=dim[i];
    }
}

void dfs(int dep,int cur){
    if(dep>=m){
        if(check()){
            id++;
            int mac=convert(pat),mac0=convert0(pat);
            p[id]=mac;
            mp[mac]=id;
            p0[id]=mac0;
            // cout<<mac<<endl;
            // for(int i=0;i<m;i++) cout<<pat[i]; cout<<endl;
        }
        return ;
    }
    pat[dep]=0;
    dfs(dep+1,cur);
    
    if(dep && pat[dep-1]){
        pat[dep]=pat[dep-1];
        dfs(dep+1,cur);
    }
    else{
        for(int i=1;i<=cur+1;i++){
            pat[dep]=i;
            dfs(dep+1,max(i,cur));
        }
    }
}

int a[M],b[M];
int buc[M];

vector <int> G[M*2];
bool vis[M*2];
int lst[M*2],deg[M*2],col[M*2];
int alcv,alce;
void dfss(int u,int c){
    if(vis[u]) return ;
    vis[u]=1;
    alcv++,alce+=deg[u];
    col[u]=c;
    for(int v: G[u]){
        if(!vis[v]) dfss(v,c);
    }
}

vector <int> V[I];
int f[N][I],g[N][I];
int pre[I];

int ans[N];
bool ed[I];

int ANS[N][M];

signed main(){
    pw[0]=1;
    for(int i=1;i<=10;i++) pw[i]=pw[i-1]*dim[i-1];
    
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("\n%s",S[i]);
    
    dfs(0,0);
    
    V[0].push_back(0); ed[0]=1;
    for(int t=1;t<=id;t++){
        iconvert(a,p[t]);
        int mx=0;
        for(int i=0;i<m;i++) mx=max(mx,a[i]);
        
        for(int i=1;i<=mx;i++) buc[i]=0;
        for(int i=0;i<m;i++){
            if(a[i]) buc[a[i]] |= 1<<i;
        }
        
        // 1 = prefix 0000000
        // 0 = not prefix 0000000
        if(t==1) V[t].push_back(1);
        else{
            if(mx==1) V[t].push_back(0),ed[t]=1;
        }
        
        for(int mac=1;mac<(1<<m);mac++){
            bool fl=1;
            if(!(mx==1 && !mac)){
                for(int i=1;i<=mx && fl;i++){
                    if((mac & buc[i])==0) fl=0;
                }
            }
            if(!fl) continue;
            
            for(int i=0;i<m*2;i++){
                G[i].clear();
                vis[i]=col[i]=deg[i]=0;
                lst[i]=-1;
            }
            for(int i=0;i+1<m;i++){
                if((mac>>i & 1) && (mac>>(i+1) & 1)){
                    G[m+i].push_back(m+i+1);
                    G[m+i+1].push_back(m+i);
                    deg[m+i]++,deg[m+i+1]++;
                }
            }
            for(int i=0;i<m;i++){
                if(a[i]){
                    int c=a[i];
                    if(lst[c]==-1) lst[c]=i;
                    else{
                        int x=lst[c];
                        G[i].push_back(x);
                        G[x].push_back(i);
                        deg[i]++,deg[x]++;
                    }
                }
                
                if(a[i] && (mac>>i & 1)){
                    G[i].push_back(m+i);
                    G[m+i].push_back(i);
                    deg[i]++,deg[m+i]++;
                }
            }
            
            int cid=0;
            for(int i=0;i<m && fl;i++){
                if((mac>>i & 1) && !vis[m+i]){
                    cid++;
                    alcv=alce=0;
                    dfss(m+i,cid);
                    if(alce!=(alcv-1)*2) fl=0;
                }
            }
            if(!fl) continue;
            
            for(int i=0;i<m;i++) b[i]=col[i+m];
            int nmac=convert(b);
            
            V[t].push_back(mp[nmac]);
        }
    }
    
    memset(f,0x7f,sizeof(f));
    int s=0;
    for(int i=0;i<m;i++){
        if(S[1][i]=='#') s |= 1<<i;
    }
    
    for(int t=1;t<=id;t++){
        memset(vis,0,sizeof(vis));
        iconvert(b,p[t]);
        bool fl=1;
        for(int i=0;i<m && fl;i++){
            if(b[i] && (!i || !b[i-1])){
                if(vis[b[i]]) fl=0;
                vis[b[i]]=1;
            }
        }
        
        if(fl) f[1][t]=__builtin_popcount(p0[t]^s);
    }
    
    for(int t=2;t<=n;t++){
        int s=0;
        for(int i=0;i<m;i++){
            if(S[t][i]=='#') s |= 1<<i;
        }
        for(int i=0;i<=id;i++) pre[i]=__builtin_popcount(p0[i]^s);
        
        for(int i=0;i<=id;i++){
            for(int j: V[i]){
                int val=f[t-1][i]+pre[j];
                if(val<f[t][j]){
                    f[t][j]=val;
                    g[t][j]=i;
                }
            }
        }
    }
    
    int mn=INF,nw;
    for(int i=0;i<=id;i++){
        if(!ed[i]) continue;
        if(f[n][i]<mn){
            mn=f[n][i];
            nw=i;
        }
    }
    
    ans[n]=nw;
    for(int t=n-1;t>=1;t--){
        nw=g[t+1][nw];
        ans[t]=nw;
    }
    
    for(int t=1;t<=n;t++){
        int mac=p0[ans[t]];
        for(int i=0;i<m;i++){
            ANS[t][i+1]=(mac>>i & 1);
            if(mac>>i & 1) putchar('#');
            else putchar('.');
        }
        putchar('\n');
    }
}