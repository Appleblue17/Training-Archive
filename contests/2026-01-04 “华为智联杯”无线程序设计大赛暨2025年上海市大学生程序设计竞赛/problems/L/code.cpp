#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=4e6+5, N2=8e6+5, M=5e5+5;
void read(int &x){
    x=0; char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
}
void readdir(char &x){
    x=0; char c=getchar();
    while(c!='N'&&c!='S'&&c!='W'&&c!='E') c=getchar();
    x=c;
}
int n, m, q;
char s[N2];
vector<char> a[M];
int fa[N2]; 
inline int id(int x, int y, int o){
    return (x-1)*m+y+o*n*m;
}
int getf(int x){
    if(x==fa[x]) return x;
    return fa[x]=getf(fa[x]);
}
void merge(int x, int y){
    x=getf(x); y=getf(y);
    fa[x]=y;
}
unordered_map<int, int> h[N];
int col[N2], idx;
namespace task{
    int deg[N];
    int tim[N];
    vector<int> bin;
    vector<pair<int, int> > R[N];
    const int inf=2e9+1;
    vector<pair<int, int> > ask[N];
    int qry(int s, int t, int id){
        if(s==t) return 0;
        int ret=inf;
        if(h[s].find(t)!=h[s].end()) ret=h[s][t];
        if(tim[s]>tim[t]) swap(s, t);
        for(auto [x, w]:R[s]){
            if(h[x].find(t)!=h[x].end()){
                ret=min(ret, h[x][t]+w);
            }
        }
        ask[s].emplace_back(t, id);
        return ret;
    }
    int ans[N];
    int val[N];
    void solve(){
        for(int i=1; i<=idx; ++i) {
            deg[i]=h[i].size();
            if(deg[i]<=5){
                bin.push_back(i);
            }
        }
        for(int i=1; i<=idx; ++i){
            int x=bin.back(); bin.pop_back();
            tim[x]=i;
            for(auto [y, w]:h[x]){
                if(deg[y]<=5) continue;
                --deg[y];
                if(deg[y]<=5){
                    bin.push_back(y);
                }
            }
        }
        for(int i=1; i<=idx; ++i){
            for(auto [j, w]:h[i]) {
                if(tim[i]<tim[j]){
                    // cout<<"R:"<<i<<"->"<<j<<endl;
                    R[i].emplace_back(j, w);
                }
            }
        }
        int sx, ex, sy, ey; char op;
        for(int i=1; i<=q; ++i){
            read(sx); read(sy); readdir(op); read(ex); read(ey);
            int S, T1=id(ex, ey, 1), T2=id(ex, ey, 0);
            if(a[sx][sy]=='\\') {
                if(op=='N'||op=='E') S=id(sx, sy, 0);
                else S=id(sx, sy, 1);
            }
            else{
                if(op=='N'||op=='W') S=id(sx, sy, 0);
                else S=id(sx, sy, 1);
            }
            S=col[getf(S)]; T1=col[getf(T1)]; T2=col[getf(T2)];
            
            ans[i]=min(qry(S, T1, i), qry(S, T2, i));
        }
        for(int i=1; i<=idx; ++i) val[i]=inf;
        for(int i=1; i<=idx; ++i){
            vector<int> mdf;
            for(auto [x, w1]:h[i]){
                for(auto [y, w2]:R[x]){
                    if(val[y]==inf) mdf.push_back(y);
                    val[y]=min(val[y], w1+w2);
                }
            }
            for(auto [j, id]:ask[i]) ans[id]=min(ans[id], val[j]);
            
            for(auto t:mdf) val[t]=inf;
        }
        for(int i=1; i<=q; ++i){
            if(ans[i]==inf) ans[i]=-1;
            printf("%d\n", ans[i]);
        }
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    read(n); read(m); read(q);
    for(int i=1; i<=n; ++i){
        a[i].resize(m+1);
        scanf("%s", s+1);
        for(int j=1; j<=m; ++j){
            a[i][j]=s[j];
        }
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) for(int k=0; k<2; ++k) fa[id(i, j, k)]=id(i, j, k);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i][j]=='/'){
                if(i!=1){
                    merge(id(i, j, 0), id(i-1, j, 1));
                }
                if(j!=1){
                    if(a[i][j-1]=='/') merge(id(i, j, 0), id(i, j-1, 1));
                    else merge(id(i, j, 0), id(i, j-1, 0));
                }
                if(i!=n){
                    merge(id(i, j, 1), id(i+1, j, 0));
                }
                if(j!=m){
                    if(a[i][j+1]=='/') merge(id(i, j, 1), id(i, j+1, 0));
                    else merge(id(i, j, 1), id(i, j+1, 1));
                }
            }
            else{
                if(i!=1){
                    merge(id(i, j, 0), id(i-1, j, 1));
                }
                if(j!=m){
                    if(a[i][j+1]=='/') merge(id(i, j, 0), id(i, j+1, 0));
                    else merge(id(i, j, 0), id(i, j+1, 1));
                }
                if(i!=n){
                    merge(id(i, j, 1), id(i+1, j, 0));
                }
                if(j!=1){
                    if(a[i][j-1]=='/') merge(id(i, j, 1), id(i, j-1, 1));
                    else merge(id(i, j, 1), id(i, j-1, 0));
                }
            }
        }
    }
    for(int i=1; i<=n*m*2; ++i) if(getf(i)==i) col[i]=++idx;
    for(int i=1; i<=n; ++i){
        for(int j=1, w; j<=m; ++j){
            // for(int k=0; k<2; ++k)
            // cout<<i<<' '<<j<<' '<<k<<' '<<col[getf(id(i, j, k))]<<endl;
            read(w);
            if(getf(id(i, j, 0))!=getf(id(i, j, 1))){
                int x=col[getf(id(i, j, 0))], y=col[getf(id(i, j, 1))];
                if(h[x][y]==0){
                    h[x][y]=h[y][x]=w;
                }
                else{
                    h[x][y]=min(h[x][y], w);
                    h[y][x]=h[x][y];
                }
            }
        }
    }
    task::solve();
    return 0;
}
