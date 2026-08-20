#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=660,M=4e5+5,INF=1e18;

int rd(){
	char c=getchar();
	int tot=0;
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
	return tot;
}

struct abc{
    int to,nxt,w,we;
}e[M*2],ep[M*2];
int head[N],headp[N],cnt=1,cntp;

void add(int u,int v,int w){
    e[++cnt]={v,head[u],w,w};
    head[u]=cnt;
}
void addp(int u,int v,int w){
    ep[++cntp]={v,headp[u],w};
    headp[u]=cntp;
}

//max_flow part
int T,n,m,q;
int dep[N],zu[N],mm[N],dis[N][20],fx[N][20];

void bfs(int x){
    queue<int>q;
    dep[x]=1;
    q.push(x);
    while(!q.empty()){
        int qd=q.front();
        q.pop();
        for(int i=head[qd];i;i=e[i].nxt){
            int v=e[i].to;
            if(dep[v] || e[i].w==0) continue;
            q.push(v);
            dep[v]=dep[qd]+1;
        }
    }
}
int dfs(int u,int mip,int t){
    if(u==t) return mip;
    int sum=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].to;
        if(e[i].w==0 || dep[u]!=dep[v]-1)continue;
        int qdd=dfs(v,min(mip,e[i].w),t);
        if(qdd!=0){
            mip-=qdd;
            e[i].w-=qdd;
            e[i^1].w+=qdd;
            sum+=qdd;
        }
        if(!mip) break;
    }
    if(!sum) dep[u]=INF;
    return sum;
}
int max_flow(int s,int t){
    int ans=0;
    while(1){
        memset(dep,0,sizeof(dep));
        bfs(s);
        if(!dep[t]) break;
        ans+=dfs(s,INF,t);
    }
    return ans;
}


void solve(int l,int r){
    if(l>=r)return ;
    int s=zu[l],t=zu[r],cnt1=l-1,cnt2=r+1;
    for(int i=1;i<=cnt;i++)e[i].w=e[i].we;
    int w=max_flow(s,t);
	cout<<l<<" "<<r<<": "<<s<<" "<<t<<" "<<w<<endl;
	
    addp(s,t,w);addp(t,s,w);
    for(int i=l;i<=r;i++){
        if(dep[zu[i]])cnt1++,mm[cnt1]=zu[i];
        else cnt2--,mm[cnt2]=zu[i];
    }
    for(int i=l;i<=r;i++)zu[i]=mm[i];
    solve(l,cnt1);
    solve(cnt2,r);
}

// lca + shortest edge
void dfsp(int u,int fa){
    dep[u]=dep[fa]+1;
    for(int i=1;i<=19;i++){
        dis[u][i]=dis[dis[u][i-1]][i-1];
        fx[u][i]=min(fx[u][i-1],fx[dis[u][i-1]][i-1]);
    }
    for(int i=headp[u];i;i=ep[i].nxt){
        int v=ep[i].to;
        if(v==fa)continue;
        dis[v][0]=u;
        fx[v][0]=ep[i].w;
        dfsp(v,u);
    }
}

int lca(int x,int y){
    int mn=INF;
    if(dep[x]<dep[y])swap(x,y);
    for(int t=19;t>=0;t--){
        if(dep[dis[x][t]]>=dep[y]){
            mn=min(mn,fx[x][t]);
            x=dis[x][t];
        }
        if(x==y) return mn;
    }
    for(int t=19;t>=0;t--){
        if(dis[x][t]!=dis[y][t]){
            mn=min(mn,min(fx[x][t],fx[y][t]));
            x=dis[x][t],y=dis[y][t];
        }
    }
    return min({mn,fx[x][0],fx[y][0]});
}



int fa[N];
int getf(int x){
	if(x==fa[x]) return x;
	return fa[x]=getf(fa[x]);
}
struct def{
	int u,v,w;
}edg[M];
int id;

signed main(){
	T=rd();
	while(T--){
		n=rd(),m=rd();
		
		for(int i=1;i<=n;i++) head[i]=headp[i]=0;
		cnt=1,cntp=0;
		
		for(int i=1;i<=m;i++){
			int u=rd(),v=rd(),w=rd();
			add(u,v,w);add(v,u,w);
		}
		
		for(int i=1;i<=n;i++) zu[i]=i;
		solve(1,n);
		
		for(int i=1;i<=n;i++) dep[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=19;j++) fx[i][j]=INF;
		dfsp(1,0);
		
		for(int i=1;i<=n;i++) fa[i]=i;
		
		id=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				edg[++id]={i,j,lca(i,j)};
			}
		}
		sort(edg+1,edg+id+1,[](def X,def Y){
			return X.w<Y.w;
		});
		int ans=0;
		for(int i=1;i<=id;i++){
			int u=edg[i].u,v=edg[i].v;
			int fu=getf(u),fv=getf(v);
			if(fu!=fv){
				ans+=edg[i].w;
				fa[fu]=fv;
			}
		}
		cout<<ans<<endl;
		
	}
}12312