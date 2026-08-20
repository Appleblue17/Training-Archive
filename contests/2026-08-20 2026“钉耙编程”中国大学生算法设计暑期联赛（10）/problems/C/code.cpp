#include<bits/stdc++.h>
using namespace std;
const int N=2200,M=3e5+5,INF=1e9;

struct nod{
    int to,nxt,f;
}e[M];
int head[N],cnt;
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
void clear(){
	for(int i=2;i<=cnt;i+=2) e[i].f+=e[i^1].f, e[i^1].f=0;
}

int T,n,k;
char S[N];

int sav[N];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("\n%d%d",&n,&k);
        st=n+k+1,ed=n+k+2,siz=ed;
        
        for(int i=1;i<=siz;i++) head[i]=0;
        cnt=1;
        
        for(int i=1;i<=n;i++) qadd(st,i,1);
        
        for(int i=1;i<=n;i++){
            scanf("\n%s",S+1);
            for(int j=1;j<=k;j++)
                if(S[j]=='1') qadd(i,j+n,1);
        }
        
        for(int j=1;j<=k;j++){
            qadd(j+n,ed,0);
            sav[j]=cnt^1;
        }
        
        for(int ans=0;;ans++){
            for(int j=1;j<=k;j++) e[sav[j]].f++;
            int res=dinic();
            if(res<k){
                printf("%d\n",ans);
                break;
            }
        }
        
    }
    
    
}