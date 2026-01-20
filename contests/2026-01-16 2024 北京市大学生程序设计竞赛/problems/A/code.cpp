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
const int N=200, M=3e5;
int n, m;
char s[N];
int tr[N][2], idx=1, msk[N];
int val[N], nxt[N];
void build(){
    queue<int> que;
    nxt[1]=1;
    if(tr[1][0]) que.push(tr[1][0]), nxt[tr[1][0]]=1;
    else tr[1][0]=1;
    if(tr[1][1]) que.push(tr[1][1]), nxt[tr[1][1]]=1;
    else tr[1][1]=1;
    while(!que.empty()){
        int x=que.front(); que.pop();
        msk[x]|=msk[nxt[x]];
        for(int i=0; i<2; ++i){
            if(tr[x][i]){
                int v=tr[x][i];
                que.push(v);
                nxt[v]=tr[nxt[x]][i];
            }
            else{
                tr[x][i]=tr[nxt[x]][i];
            }
        }
    }
}
int sum[M];
vector<int> e[N];
int f[N][M];
int deg[N];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	read(n);
    for(int i=0; i<n; ++i){
        scanf("%s", s+1); read(val[i]);
        int p=1;
        for(int j=1; s[j]; ++j){
            if(!tr[p][s[j]-'0']) tr[p][s[j]-'0']=++idx;
            p=tr[p][s[j]-'0'];
        }
        msk[p]|=(1<<i);
    }
    for(int i=1; i<(1<<n); ++i) sum[i]=sum[i-(i&(-i))]+val[(int)log2(i&(-i))];
    build();
    for(int s=(1<<n)-2; s>=0; --s){
        set<pii> st[2];
        for(int i=1; i<=idx; ++i) if((s&msk[i])==msk[i]){
            f[i][s]=-1e9;
            deg[i]=0;
            for(int j=0; j<2; ++j){
                int ni=tr[i][j], ns=s|msk[ni];
                if(ns!=s){
                    f[i][s]=max(f[i][s], sum[ns-s]-f[ni][ns]);
                }
                else{
                    ++deg[i];
                    e[ni].ep(i);
                }
            }
            if(deg[i]<2) st[deg[i]].insert(mapa(f[i][s], i));
        }
        for(int i=1; i<=idx; ++i){
            if(!st[0].empty()){
                int x=(*st[0].begin()).se;
                st[0].erase(st[0].begin());
                for(auto y:e[x]){
                    if(deg[y]==0) continue;
                    --deg[y];
                    if(deg[y]==1){
                        f[y][s]=max(f[y][s], -f[x][s]);
                        st[1].insert(mapa(f[y][s], y));
                    }
                    else{
                        st[1].erase(st[1].find(mapa(f[y][s], y)));
                        f[y][s]=max(f[y][s], -f[x][s]);
                        st[0].insert(mapa(f[y][s], y));
                    }
                }
                continue;
            }
            if(!st[1].empty()){
                if((*st[1].rbegin()).fi<0) break;
                int x=(*st[1].rbegin()).se;
                st[1].erase((--st[1].end()));
                deg[x]=0;
                for(auto y:e[x]){
                    if(deg[y]==0) continue;
                    --deg[y];
                    if(deg[y]==1){
                        f[y][s]=max(f[y][s], -f[x][s]);
                        st[1].insert(mapa(f[y][s], y));
                    }
                    else{
                        st[1].erase(st[1].find(mapa(f[y][s], y)));
                        f[y][s]=max(f[y][s], -f[x][s]);
                        st[0].insert(mapa(f[y][s], y));
                    }
                }
                continue;
            }
            break;
        }
        for(int i=1; i<=idx; ++i) {
            e[i].clear();
            if(deg[i]) f[i][s]=0;
            // cout<<i<<' '<<s<<' '<<f[i][s]<<endl;
        }
    }
    read(m);
    while(m--){
        scanf("%s", s+1);
        int p=1, v=0;
        for(int i=1; s[i]; ++i) p=tr[p][s[i]-'0'], v|=msk[p];
        // cout<<p<<' '<<v<<endl;
        printf("%d\n", f[p][v]);
    }
	return 0;
}

