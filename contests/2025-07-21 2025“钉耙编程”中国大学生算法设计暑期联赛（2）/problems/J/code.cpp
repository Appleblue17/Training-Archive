#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=3e5+5;
int T,m,k;
int t[N],c[N];
vector < pair<int,int> > ANS;

int buc[N];
int id;
int num[N],tag[N],len[N],ans[N];
vector <int> V[N];

struct abc{
	int l,a,id;
};
bool operator <(abc X,abc Y){
	int A=X.l+1,B=X.l-X.a+1;
	int C=Y.l+1,D=Y.l-Y.a+1;
	
	if(1ll*A*D!=1ll*C*B) return 1ll*A*D<1ll*C*B; // A/B<C/D
	else{
		int x=X.id,y=Y.id;
		if(tag[x]!=tag[y]) return tag[x]<tag[y];
		else{
			if(tag[x]) return x>y;
			else return x<y;
		}
	}
}
priority_queue <abc> que;

void solve(){
	scanf("%d%d",&m,&k);
	for(int i=1;i<=m;i++){
		buc[i]=0;
		V[i].clear();
	}
	id=0;
	
	for(int i=1;i<=k;i++) scanf("%d",&t[i]),buc[t[i]]++;
	for(int i=1;i<=m;i++) scanf("%d",&c[i]);
	
	for(int i=1;i<=m;i++){
		if(c[i]<buc[i]){
			for(int t=1;t<=m;t++){
				if(c[t]) ANS.push_back(MP(c[t],t));
			}
			return ;
		}
	}
	for(int i=1;i<=m;i++) c[i]-=buc[i];
    
	for(int l=1,r;l<=k;l=r+1){
		r=l;
		while(r+1<=k && t[l]==t[r+1]) r++;
		
		id++;
		int x=t[l];
		V[x].push_back(id);
		len[id]=r-l+1;
		tag[id]=(t[r+1]>t[r]);
		num[id]=x;
		ans[id]=len[id];
        
        // cout<<id<<": "<<num[id]<<" "<<len[id]<<" "<<tag[id]<<endl;
	}
	
	for(int x=1;x<=m;x++){
		if(!buc[x]) continue;
        
		while(que.size()) que.pop();
		for(int id: V[x]){
            que.push((abc){ans[id],len[id],id});
        }
		
        for(int i=1;i<=c[x];i++){
            int id=que.top().id; que.pop();
            ans[id]++;
            que.push((abc){ans[id],len[id],id});
        }
	}
    // for(int i=1;i<=id;i++) cout<<ans[i]<<" "; cout<<endl;
    
    // cout<<" ? "<<c[5]<<" "<<buc[5]<<endl;
    
    int mx=0,cur=1;
    num[id+1]=m;
    for(int i=1;i<=id+1;i++){
        int x=num[i];
        while(cur<=x){
            if(!buc[cur] && c[cur]) ANS.push_back(MP(c[cur],cur));
            cur++;
        }
        if(i>id) break;
        ANS.push_back(MP(ans[i],num[i]));
    }
    
}

int main(){
	scanf("%d",&T);
	while(T--){
		ANS.clear();
		solve();
        
		printf("%d\n",ANS.size());
		for(pair<int,int> x: ANS) printf("%d %d\n",x.first,x.second);
	}
}