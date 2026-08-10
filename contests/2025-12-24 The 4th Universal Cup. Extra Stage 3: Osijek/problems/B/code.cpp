#include <bits/stdc++.h>
using namespace std;
const int N=66,M=1e5+5,LEN=1e6+5,INF=1e9;

struct nod{
    int to,nxt,f;
}e[M*2];
int head[N],cnt=1;
void add(int u,int v,int f){
    e[++cnt]={v,head[u],f};
    head[u]=cnt;
}
void qadd(int u,int v,int f){
    add(u,v,f);
    add(v,u,0);
}


int siz,st,ed;
int dis[N];
queue <int> q;
bool bfs(){
    for(int i=1;i<=siz;i++) dis[i]=INF;
    dis[st]=0;
    q.push(st);
    
    while(q.size()){
        int u=q.front(); q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(!e[i].f || dis[v]<INF) continue;
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    return (dis[ed]<INF);
}

int cur[N];
int dfs(int u,int flow){
    if(u==ed) return flow;
    int del=flow;
    for(int i=cur[u];i && del;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].to;
        if(e[i].f && dis[v]==dis[u]+1){
            int x=dfs(v,min(del,e[i].f));
            del-=x;
            e[i].f-=x,e[i^1].f+=x;
        }
    }
    return flow-del;
}
int dinic(){
    int tot=0;
    while(bfs()){
        for(int i=1;i<=siz;i++) cur[i]=head[i];
        tot+=dfs(st,INF);
    }
    return tot;
}


int recl[N],recr[N],rec[N][N];

int T,n;
char S[LEN];
int buc[N][N];


bool check(int k){
    for(int i=1;i<=26;i++){
        int id=recl[i];
        e[id^1].f=k,e[id].f=0;
    }
    for(int i=1;i<=26;i++){
        int id=recr[i];
        e[id^1].f=k,e[id].f=0;
    }
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            int id=rec[i][j];
            if(i<=n) e[id^1].f=buc[i][j];
            else e[id^1].f=k;
            e[id].f=0;
        }
    }
    
    int ret=dinic();
    // cout<<k<<": "<<ret<<endl;
    return (ret==26*k);
}

int match[N];

int main(){
    // freopen("B.out","w",stdout);
    st=26*2+1,ed=26*2+2; siz=ed;
    for(int i=1;i<=26;i++){
        qadd(st,i,0);
        recl[i]=cnt;
        qadd(i+26,ed,0);
        recr[i]=cnt;
    }
    for(int i=1;i<=26;i++){
        for(int j=1;j<=26;j++){
            qadd(i,j+26,0);
            rec[i][j]=cnt;
        }
    }
    
    scanf("%d",&T);
    while(T--){
        memset(buc,0,sizeof(buc));
        
        
        scanf("%d",&n);
        int mn=INF;
        for(int i=1;i<=n;i++){
            scanf("\n%s",S+1);
            int len=strlen(S+1);
            mn=min(mn,len);
            for(int j=1;j<=len;j++){
                buc[i][S[j]-'a'+1]++;
            }
        }
        
        int l=1,r=mn,tot=0;
        while(l<=r){
            int mid=(l+r)>>1;
            
            if(check(mid)) tot=mid,l=mid+1;
            else r=mid-1;
        }
        
        printf("%d\n",tot);
        
        check(tot);
        
        
        
        for(int i=1;i<=26;i++){
            for(int j=1;j<=26;j++){
                int id=rec[i][j];
                e[id^1].f=e[id].f;
                e[id].f=0;
            }
        }
        
        while(1){
            for(int i=1;i<=26;i++){
                int id=recl[i];
                e[id^1].f=1,e[id].f=0;
            }
            for(int i=1;i<=26;i++){
                int id=recr[i];
                e[id^1].f=1,e[id].f=0;
            }
            
            int ret=dinic();
            if(ret<26) break;
            
            int mn=INF;
            for(int i=1;i<=26;i++){
                for(int j=1;j<=26;j++){
                    int id=rec[i][j];
                    if(e[id].f){
                        match[i]=j;
                        e[id].f=0;
                        mn=min(mn,e[id^1].f);
                        break;
                    }
                }
            }
            
            for(int i=1;i<=26;i++){
                int j=match[i];
                int id=rec[i][j];
                e[id^1].f-=mn;
            }
            
            for(int t=1;t<=mn+1;t++){
                for(int i=1;i<=n;i++) putchar(match[i]-1+'a');
                putchar('\n');
            }
        }
    }
    
}
