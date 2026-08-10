#include<bits/stdc++.h>
using namespace std;
#define int long long
#define int128 __int128
const int N=1100,INF=1e18;
int T,n;
int a[N],b[N];


int lowbit(int x){
	return x & (-x);
}
int pre_offset[N];
int pre_len[N];
int pre[N][N];

void init(int lim){
	for(int k=1;k<=lim;k++){
		for(int i=0;i<k;i++) pre[k][i]=-1;
		
		int d=__lg(lowbit(k));
		pre_offset[k]=d;
		
		for(int i=0;i<d;i++) pre[k][1<<i]=i;
		
		int x=(1<<d)%k;
		int id=d;
		while(pre[k][x]==-1){
			pre[k][x]=id;
			pre_len[k]++;
			
			x=x*2%k;
			id++;
		}
	}
	
	// for(int k=1;k<=10;k++){
	// 	cout<<k<<": "<<pre_offset[k]<<" "<<pre_len[k]<<" | ";
	// 	for(int i=0;i<k;i++) cout<<pre[k][i]<<" "; cout<<endl;
	// }
}


int ANSREQ[N];
int ANSLOW,ANSFIX;
bool nosol;

int get_ceil_lg(int x){
	int t=__lg(x);
	while((1ll<<t)<x) t++;
	return t;
}

void wtval(int &pos,int val){
	if(pos!=-1 && pos!=val) nosol=1;
	else pos=val;
}

void wtreq(int u,int x){
	// cout<<"  <- req "<<u<<" "<<x<<endl;

	int val=pre[u][x];
	int len=pre_len[u];
	int offset=pre_offset[u];
	if(val==-1){
		// cout<<"  -> nosol"<<endl;
		nosol=1;
	}
	else if(val<offset){
		// cout<<"  -> fix = "<<val<<endl;
		wtval(ANSFIX,val);
	}
	else{
		// cout<<"  -> req "<<len<<" = "<<val<<endl;
		ANSLOW=max(ANSLOW,offset);
		wtval(ANSREQ[len],val%len);
	}
}

void wtfix(int x){
	// cout<<"  <- fix "<<x<<endl;
	int t=__lg(x);
	if((1ll<<t)==x) wtval(ANSFIX,t);
	else cout<<"NOSOL!\n",nosol=1;
}

int col[N],cid;
vector <int> iG[N];
int rt[N],dis[N];

vector <int> V; // temp, roots
int pos[N];
bool vis[N];

void dfs0(int u,int fa){
	vis[u]=1;
	// cout<<"  vis: "<<u<<" "<<rt[u]<<" "<<dis[u]<<endl;
	
	int x=b[u];
	if(col[x]!=col[u]){
		// cout<<"??? "<<u<<endl;
		nosol=1;
	}
	else{
		if(rt[x]==x){
			// on the cycle
			int len=V.size();
			int offset=(pos[rt[x]]+len-pos[rt[u]])%len+dis[u];
			ANSLOW=max(ANSLOW,get_ceil_lg(dis[u]));
			wtreq(len,offset%len);
		}
		else{
			if(!vis[x]) nosol=1;
			else{
				wtfix(dis[u]-dis[x]);
			} 
		}
	}
	
	for(int v: iG[u]){
		if(v==fa) continue;
		col[v]=col[u];
		rt[v]=rt[u]; dis[v]=dis[u]+1;
		dfs0(v,u);
	}
	vis[u]=0;
}


namespace exCRT{
	int128 x[N],y[N];
	int128 exgcd(int128 dep,int128 a,int128 b){
		if(!b){
			x[dep]=1;
			y[dep]=0;
			return a;
		}
		int128 tot=exgcd(dep+1,b,a%b);
		x[dep]=y[dep+1];
		y[dep]=x[dep+1]-(a/b)*y[dep+1];
		return tot;
	}

	int128 ksj(int128 a,int128 x,int128 mod){
		if(x<0) x=(x%mod+mod)%mod;
		int128 tot=0;
		while(x){
			if(x & 1ll) tot=(tot+a)%mod;
			a=(a+a)%mod;
			x>>=1ll;
		}
		return tot;
	}

	int128 floor(int128 x,int128 y){
		int128 t=x/y;
		while(y*t<x) t++;
		while(y*t>=x) t--;
		return t;
	}
	int128 lcm(int128 x,int128 y){
		return x/__gcd(x,y)*y;
	}
	
	pair<int128,int128> solve(int n,int *p,int *m){
		if(!n) return {0,1};
		int128 t=p[1],M=m[1];
		for(int128 i=2;i<=n;i++){
			int128 a=M,b=m[i],c=(p[i]+(m[i]-t))%m[i];
			
			int128 g=exgcd(1,a,b);
			int128 dx=b/g,dy=a/g;
			int128 x0=ksj(x[1],c/g,b/g);
			int128 k=floor(t+M*x0,M*dx);
			t=t+(x0-k*dx)*M;
			M=lcm(M,m[i]);
		}
		return {t,M};
	}
}

int crt_p[N],crt_m[N],id;


int128 solve(){
	for(int i=1;i<=n;i++) col[i]=0,iG[i].clear();
	for(int i=1;i<=n;i++) ANSREQ[i]=-1;
	ANSLOW=ANSFIX=-1; nosol=0;
	cid=0;
	
	for(int i=1;i<=n;i++) iG[a[i]].push_back(i);
	
	for(int i=1;i<=n;i++){
		if(col[i]) continue;
		// cout<<"hello "<<i<<endl;
		
		cid++;
		stack <int> st;
		V.clear();
		
		int x=i;
		while(1){
			col[x]=cid;
			// cout<<"   get "<<x<<" "<<cid<<endl;
			st.push(x);
			x=a[x];
			if(col[x]){
				while(st.size()){
					int u=st.top(); st.pop();
					V.push_back(u);
					if(u==x) break;
				}
				break;
			}
		}
		reverse(V.begin(),V.end());
		
		// cout<<"V: ";
		// for(int u: V) cout<<u<<" ";
		// cout<<endl;
		
		for(int i=0;i<(int)V.size();i++){
			int u=V[i];
			pos[u]=i;
			rt[u]=u,dis[u]=0;
		}
		for(int i=0;i<(int)V.size();i++){
			int u=V[i];
			dfs0(u,V[(i+V.size()-1)%V.size()]);
		}
	}
	
	// cout<<"nosol = "<<nosol<<endl;
	// cout<<"REQ: "; for(int i=1;i<=n;i++) cout<<ANSREQ[i]<<" "; cout<<endl;
	// cout<<"LOW = "<<ANSLOW<<endl;
	// cout<<"FIX = "<<ANSFIX<<endl;
	
	if(nosol) return -1;
	
	if(ANSFIX!=-1){
		// check
		if(ANSFIX<ANSLOW) return -1;
		for(int i=1;i<=n;i++){
			if(ANSREQ[i]!=-1 && ANSFIX%i!=ANSREQ[i]) return -1;
		}
		return ANSFIX;
	}
	
	id=0;
	for(int i=2;i<=n;i++){
		if(ANSREQ[i]!=-1){
			id++;
			crt_m[id]=i,crt_p[id]=ANSREQ[i];
		}
	}
	auto res = exCRT::solve(id,crt_p,crt_m);
	int128 ANS=res.first,M=res.second;
	while(ANS<ANSLOW) ANS+=M;
	
	return ANS;
}

void wt(int128 x){
	if(x<0){
		putchar('-');
		wt(-x);
		return ;
	}
	if(x>=10) wt(x/10);
	putchar(x%10+'0');
}

signed main(){
	freopen("9test.in","r",stdin);
	init(N-5);
	
	cin>>T;
	while(T--){
		// cout<<" case "<<T<<endl;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
		int128 ans=solve();
		wt(ans);
		printf("\n");
	}
	return 0;
}