#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, T;
char s[N];
int rk[2][N], dp[N];
int his[N];
int c[N], sa[N], y[N];
int tr[N];
void upd(int x, int v){
    for(; x<=n; x+=(x&-x)) if(v>tr[x]) tr[x]=v;
}
int get(int x){
    int ret=0;
    for(; x; x-=(x&-x)) if(tr[x]>ret) ret=tr[x];
    return ret;
}
void solve(){
    scanf("%s", s+1); n=strlen(s+1);
    int st=1;
    while(st<=n&&s[st]=='0') ++st;
    if(st==n+1){
        printf("1\n");
        return ;
    }
    int add=0;
    if(s[1]=='0') add=1;
    for(int i=st; i<=n; ++i) s[i-st+1]=s[i];
    n-=st-1;
    for(int i=n+1; i<=n*2; ++i) s[i]=0;
    int lim=1;
    while((lim+1)*(lim+2)<=2*n) ++lim;
    lim=min(lim, n);
	++lim;
	for(int i='0'; i<='9'; ++i) c[i]=0;
	for(int i=1; i<=n; ++i) c[s[i]]++;
	for(int i='1'; i<='9'; ++i) c[i]+=c[i-1];
	for(int i=n; i>=1; --i) y[c[s[i]]--]=i;
	int cur=1, pre=0;
	for(int o=0; o<2; ++o) for(int i=0; i<=n; ++i) rk[o][i]=1, sa[i]=i, dp[i]=0;
	int ans=0;
	for(int i=0; i<=n; ++i) his[i]=0;
	for(int len=1; len<=lim; ++len){
		for(int i=0; i<=n; ++i) c[i]=0, tr[i]=0, dp[i]=0;
		for(int i=0; i<len-1; ++i) rk[pre][i]=0;
		for(int i=0; i<n; ++i) c[rk[pre][i]]++;
		for(int i=1; i<=n; ++i) c[i]+=c[i-1];
		for(int i=n; i>=1; --i) sa[c[rk[pre][y[i]-1]]--]=y[i];
		rk[cur][sa[1]]=1; 
		int num=1;
		for(int i=2; i<=n; ++i) rk[cur][sa[i]]=(rk[pre][sa[i]-1]==rk[pre][sa[i-1]-1]&&s[sa[i]]==s[sa[i-1]])?num:++num;
		// for(int i=len; i<=n; ++i){
		// 	cout<<rk[cur][i]<<' ';
		// }
		// cout<<endl;
		int premx=0;
		for(int i=len; i<=n; ++i){
			premx=max(premx, his[i-len]);
			if(i-len>=len&&((len==1&&add==0)||s[i-len-len+1]!='0')) upd(rk[cur][i-len], dp[i-len]);
			if(len!=1&&s[i-len+1]=='0') continue;
			if(len==1&&s[i-len+1]=='0'&&add==1) continue;
			dp[i]=max(premx, get(rk[cur][i]-1))+1;
			ans=max(ans, dp[i]);
		}
		for(int i=len; i<=n; ++i) his[i]=max(his[i], dp[i]);
		
		swap(cur, pre);
	}
    printf("%d\n", ans+add);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}