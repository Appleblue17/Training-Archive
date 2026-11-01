#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 1000010
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
const int mo=1e9+7;
using namespace std;
int id[N];//id projects pu to u: id[x]=u for who p[u] = x
int t,n,m,deg[N],del[N],lpos,ans2[N],b[N],a[N];//b handels projections between print targets and index
vector<int> g[N],ans;
queue<int> q;
void prin(int x){
	vector<char> t;
	for(int i=0;i<=15;i++){
		t.push_back(x%2);
		x/=2;
	}
	while(!t.empty()){
		printf("%c",t.back()+'0');
		t.pop_back();
	}
}
char s[N];
void rd(int &x,int st){
	x=0;
	for(int i=st;i<=st+15;i++){
		x = x*2+s[i]-'0';
	}
}
int rn;
void de(int v){
			del[v]=1;
			for(int w:g[v]){
				if(rn == 1){
					if(a[w] <= n/2)continue;
				}
				else{
					if(s[w]=='0')continue;
				}
				deg[w]--;
				//printf("deleting v=%d,w=%d,deg=%d\n",v,w,deg[w]);
				if(deg[w] == 1){
					q.push(w);
					//printf("added %d while deleting %d\n",w,v);
					//b[1].push_back(w);
				}
			}
}
void sf(){
	rn=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
	lpos=n;
	int tcnt=0;
	for(int t=1;t<=n;t++){
		scanf("%d",&a[t]);
		if(a[t] > n/2){
			tcnt++;
			b[t] = tcnt;
			//printf("b[%d]=%d\n",t,tcnt);
			id[a[t]] = t;
			printf("1");
		}
		else printf("0");
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=n/2)continue;
		//printf("deg[%d]=%d\n",i,deg[i]);
		if(deg[i] < 2){
			q.push(i);
		}
	}
	for(int t=1;t<=n/2;t++){
		while(!q.empty()){
			int u = q.front();q.pop();
			//printf("removed u=%d deg<=1\n",u);
			for(int v:g[u]){
				if(del[v])continue;
				de(v);
				//printf("de v=%d\n",v);
			}
			del[u]=1;
		}
		while(del[id[lpos]] && lpos > n/2){
			lpos--;
		}
		if(lpos <= n/2)break;//done,all R half deleted
		int u = id[lpos];//u is index
		ans.push_back(b[u]);
		//printf("ans add u=%d,b[u]=%d\n",u,b[u]);
		del[u] = 1;
		for(int v:g[u]){
			if(!del[v]){
				de(v);
				//printf("removed u=%d,v=%d,deg>1\n",u,v);
			}
		}
	}
	for(int v:ans){
		//cout << ' ' << v;
		prin(v);
	}
}
void ss(){
	rn=2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++;
		deg[y]++;
		del[i]=0;
	}
	scanf("%s",s+1);
	int pos=n+1,len = strlen(s),tcnt=0;
	for(int i=1;i<=n;i++){
		if(s[i] == '1'){
			tcnt++;
			b[tcnt] = i;//from order to index
			if(deg[i] <= 1){
				q.push(i);
				//printf("%d\n",i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		//printf("b[%d]=%d,deg[%d]=%d\n",i,b[i],i,deg[i]);
	}
	int L=1,R=n;
	while(1){
		if(L > n/2 || R <= n/2)break;
		while(!q.empty()){
			
			int u = q.front();q.pop();
			if(del[u])continue;
			for(int v:g[u]){
				if(del[v])continue;
				de(v);
				ans2[v] = L;L++;
				//printf("removed u=%d,v=%d,deg<=1\n",u,v);
			}
			del[u]=1;
			ans2[u] = R;R--;
		}
		if(L > n/2 || R <= n/2)break;
		int u;
		rd(u,pos);//u is order
		pos+=16;
		u = b[u];//now u is index
		//printf("failed to remove further, removed %d with deg>1\n",u);
		for(int v:g[u]){
			if(!del[v]){
				de(v);
				ans2[v]=L;L++;
				//printf("deleted %d and assigned ans2[%d]=%d\n",v,v,ans2[v]);
			}
		}
		del[u]=1;
		ans2[u]=R;R--;
	}
	for(int i=1;i<=n;i++){
		//printf("del[%d]=%d,ans2[%d]=%d\n",i,del[i],i,ans2[i]);
	}
	int j=1;
	while(L <= n/2){
		while(del[j])j++;
		ans2[j] = L;L++;j++;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans2[i]);
	}
}
signed main(){
	char s[10];
	scanf("%s",s);
	if(s[0] == 'f'){
		sf();
	}
	else{
		ss();
	}
}