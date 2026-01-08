#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e5+5,M=10,INF=1e9;
const char fx[11]="luolikong";

struct nod{
    int to,nxt,f,w;
}e[N*M];
int head[N],cnt=1;
void add(int u,int v,int f,int w){
    e[++cnt]={v,head[u],f,w};
    head[u]=cnt;
}
void qadd(int u,int v,int f,int w){
    add(u,v,f,w);
    add(v,u,0,-w);
}

int siz,st,ed;
int dis[N],pred[N],flow[N];
bool vis[N];
queue <int> q;
bool spfa(){
    for(int i=1;i<=siz;i++) dis[i]=-INF,vis[i]=0;
    dis[st]=0; flow[st]=INF;
    q.push(st); vis[st]=1;
    while(q.size()){
        int u=q.front(); q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(e[i].f && dis[u]+e[i].w>dis[v]){
                dis[v]=dis[u]+e[i].w;
                pred[v]=i;
                flow[v]=min(flow[u],e[i].f);
                if(!vis[v]) q.push(v),vis[v]=1;
            }
        }
    }
    return (dis[ed]>-INF);
}

int totflow,totans;
void ek(){
    totflow=totans=0;
    while(spfa()){
        int fl=flow[ed];
        totflow+=fl;
        totans+=fl*dis[ed];
        int x=ed;
        while(x!=st){
            int i=pred[x];
            e[i].f-=fl;
            e[i^1].f+=fl;
            x=e[i^1].to;
        }
    }
}
void clear(){
    for(int i=1;i<=siz;i++) head[i]=0;
    cnt=1;
}



int n,ans;
char S[N];
int LEN[N];
int pre[N][M];
int anchor[N];


int p[N],id;

vector < pair <int,int> > cand[N];

int mp[N],ct;

signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("\n%s",S+1);
        int len=strlen(S+1);
        LEN[i]=len;
        
        // cout<<i<<": ";
        for(int j=0;j<9;j++){
            int nw=j;
            for(int t=1;t<=len;t++){
                if(S[t]==fx[nw]) nw++;
            }
            pre[i][j]=nw;
            
            // cout<<pre[i][j]<<" ";
            
            if(nw==j) anchor[i] |= 1<<j;
        }
        // cout<<"  "<<anchor[i]<<endl;
    }
    
    
    for(int mac=1;mac<(1<<9);mac+=2){
        // if(mac!=89) continue;
        for(int i=1;i<=n;i++) mp[i]=0;
        ct=0;
        
        int alc=0;
        for(int i=1;i<=n;i++){
            if(anchor[i] & mac) alc+=LEN[i];
        }
        
        id=0;
        for(int i=1;i<9;i++){
            if(mac>>i & 1) p[++id]=i;
        }
        
        // cout<<id<<endl;
        
        for(int t=0;t<id;t++){
            cand[t].clear();
            
            int l=p[t],r=p[t+1];
            for(int i=1;i<=n;i++){
                if(pre[i][l]!=r) continue;
                int w=LEN[i];
                if(anchor[i] & mac) w=0;
                cand[t].push_back(make_pair(-w,i));
            }
            
            sort(cand[t].begin(),cand[t].end());
            int lim=min((int)cand[t].size(),id);
            cand[t].resize(lim);
            for(int i=0;i<lim;i++){
                int u=cand[t][i].second;
                if(!mp[u]) mp[u]=++ct;
            }
        }
        
        st=id+ct+1,ed=siz=id+ct+2;
        for(int i=0;i<id;i++) qadd(st,i+1,1,0);
        for(int t=0;t<id;t++){
            for(auto e: cand[t]){
                int u=e.second,w=-e.first;
                // cout<<u<<endl;
                qadd(t+1,id+mp[u],1,w);
            }
        }
        for(int i=1;i<=ct;i++) qadd(id+i,ed,1,0);
        
        ek();
        // cout<<alc<<endl;
        // cout<<totflow<<" "<<totans<<endl;
        
        if(totflow==id) ans=max(ans,alc+totans);
        
        clear();
    }
    cout<<ans;
}
