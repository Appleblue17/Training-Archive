#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e5+5, M=5e6+5;
int T, n, m;
char s[M], t[M];
int len[N];
struct node{
	int len, cnt[26];
	bool operator <(const node &x)const{
		return len<x.len;
	}
}a[N];
void solve(){
	read(n);
	for(int i=1; i<=n; ++i){
		scanf("%s", s);
		len[i]=strlen(s);
		for(int j=0; j<26; ++j) a[i].cnt[j]=0;
		for(int j=0; j<len[i]; ++j) ++a[i].cnt[s[j]-'a'];
		a[i].len=len[i];
	}
	priority_queue<node> pq;
	for(int i=n; i>=1; --i){
		while(!pq.empty()&&pq.top().len>len[i]){
			node cur=pq.top(); pq.pop();
			for(int j=0; j<26; ++j){
				cur.cnt[j]-=(cur.len/len[i])*a[i].cnt[j];
				if(cur.cnt[j]<0){
					printf("NO\n");
					return ;
				}
			}
			cur.len%=len[i];
			if(cur.len) pq.push(cur);
		}
		pq.push(a[i]);
	}
	m=0;
	while(!pq.empty()){
		a[++m]=pq.top(); pq.pop();
	}
	reverse(a+1, a+m+1);
	for(int i=m; i>1; --i){
		for(int j=0; j<26; ++j){
			a[i].cnt[j]-=a[i-1].cnt[j];
			if(a[i].cnt[j]<0){
				printf("NO\n");
				return ;
			}
		}
	}
	printf("YES\n");
	len[0]=len[1];
	for(int i=m; i>=1; --i){
		for(int j=0; j<26; ++j){
			while(a[i].cnt[j]--){
				t[--len[0]]='a'+j;
			}
		}
	}
	for(int i=0; i<len[1]; ++i) putchar(t[i]);
	putchar('\n');
	for(int i=2; i<=n; ++i){
		for(int j=0; j<len[i]; ++j){
			s[j]=t[j%len[i-1]];
		}
		for(int j=0; j<len[i]; ++j){
			putchar(s[j]); t[j]=s[j];
		}
		putchar('\n');
	}
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}

