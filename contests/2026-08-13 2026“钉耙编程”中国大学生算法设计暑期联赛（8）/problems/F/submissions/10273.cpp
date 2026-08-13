#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=51061;
int n,q;
int stk[151000];
struct lct{
	int s[2], fa;
	ll val, add, mul, sum, siz;
	int rev;
	#define s(p,x) tr[p].s[x]
	#define fa(p) tr[p].fa
	#define val(p) tr[p].val
	#define sum(p) tr[p].sum
	#define rev(p) tr[p].rev
	#define add(p) tr[p].add
	#define mul(p) tr[p].mul
	#define siz(p) tr[p].siz
	void build(){
		s[0]=s[1]=fa=add=rev=0;
		sum=mul=val=siz=1;
	}
}tr[151000];
void change_r(int p){
	swap(s(p, 0), s(p, 1));
	rev(p)^=1;
}
void change_m(int p, ll x){
	sum(p)=(sum(p)*x)%mod;
	val(p)=(val(p)*x)%mod;
	add(p)=(add(p)*x)%mod;
	mul(p)=(mul(p)*x)%mod;
}
void change_a(int p, ll x){
	sum(p)=(sum(p)+x*siz(p)%mod+mod)%mod;
	val(p)=(val(p)+x+mod)%mod;
	add(p)=(add(p)+x+mod)%mod;
}
void push_up(int p){
	sum(p)=(sum(s(p, 0))+sum(s(p, 1))+val(p))%mod;
	siz(p)=siz(s(p, 0))+siz(s(p, 1))+1;
}
void push_down(int p){
	if(mul(p)!=1){
		change_m(s(p, 0), mul(p));
		change_m(s(p, 1), mul(p));
		mul(p)=1;
	}
	if(add(p)){
		change_a(s(p, 0), add(p));
		change_a(s(p, 1), add(p));
		add(p)=0;
	}
	if(rev(p)){
		change_r(s(p, 0)); change_r(s(p, 1));
		rev(p)=0;
	}
}
bool isroot(int p){
	return s(fa(p), 0)!=p&&s(fa(p), 1)!=p;
}
void rotate(int x){
	int y=fa(x), z=fa(y);
	int k=s(y, 1)==x;
	if(!isroot(y)) s(z, s(z, 1)==y)=x;
	fa(x)=z;
	s(y, k)=s(x, k^1); fa(s(x, k^1))=y;
	s(x, k^1)=y; fa(y)=x;
	push_up(y); push_up(x);
}
void splay(int x){
	int r=x;
	stk[++stk[0]]=x;
	while(!isroot(r)) r=fa(r), stk[++stk[0]]=r;
	while(stk[0]) push_down(stk[stk[0]--]);
	while(!isroot(x)){
		int y=fa(x), z=fa(y);
		if(!isroot(y)){
			if((s(y, 1)==x)^(s(z, 1)==y)) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
}
void access(int x){
	int z=x;
	for(int y=0; x; y=x, x=fa(x)){
		splay(x);
		s(x, 1)=y; push_up(x);
	}
	splay(z);
}
void makeroot(int x){
	access(x);
	change_r(x);
}
int findroot(int x){
	access(x);
	while(s(x, 0)) push_down(x), x=s(x, 0);
	splay(x);
	return x;
}
void split(int x, int y){
	makeroot(x);
	access(y);
}
void link(int x, int y){
	makeroot(x);
	if(findroot(y)!=x) fa(x)=y;
}
void cut(int x, int y){
	makeroot(x);
	if(findroot(y)==x&&fa(y)==x&&(!s(y, 0))){
		s(x, 1)=fa(y)=0;
		push_up(x);
	}
}
signed main(){
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) tr[i].build();
	for(int i=1; i<n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		link(x, y);
	}
	static char c[10]; int x, y, w; ll z;
	while(q--){
		scanf("%s%d%d", c, &x, &y);
		switch(c[0]){
			case '+':{
				scanf("%lld", &z);
				split(x, y);
				change_a(y, z);
				push_up(y);
				break;
			}
			case '-':{
				scanf("%lld%d", &z, &w);
				cut(x, y); link(z, w);
				break;
			}
			case '*':{
				scanf("%lld", &z);
				split(x, y);
				change_m(y, z);
				push_up(y);
				break;
			}
			case '/':{
				split(x, y);
				printf("%lld\n", sum(y));
				break;
			}
		}
	}
	return 0;
}