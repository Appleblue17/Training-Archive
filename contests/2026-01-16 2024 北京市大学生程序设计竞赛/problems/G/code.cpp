#include<bits/stdc++.h>
using namespace std;
const int N=2e7;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
int n, m;
int a[N];
int tr[N][2], idx=1, id[N];
// int X;
int qry(int p){
    cout<<"? "<<p<<endl;
    // pii mn=mapa(INT_MAX, -1);
    // for(int i=1; i<=n; ++i) if((a[i]^X)>(a[p]^X)) mn=min(mn, mapa(a[i]^X, i));
    // cout<<mn.se<<endl;
    // return mn.se;
    int ret; cin>>ret;
    return ret;
}
int pos[60];
int fndmx(int x, int d, int msk){
    if(d<0) return id[x];
    int c=(msk>>d)&1;
    if(tr[x][c^1]) return fndmx(tr[x][c^1], d-1, msk);
    else return fndmx(tr[x][c], d-1, msk);
}
int fndmn(int x, int d, int msk){
    if(d<0) return id[x];
    int c=(msk>>d)&1;
    if(tr[x][c]) return fndmn(tr[x][c], d-1, msk);
    else return fndmn(tr[x][c^1], d-1, msk);
}
void dfs(int x, int d){
    if(d<0) return ;
    if(tr[x][0]&&tr[x][1]){
        pos[d]=x;
    }
    if(tr[x][0]) dfs(tr[x][0], d-1);
    if(tr[x][1]) dfs(tr[x][1], d-1);
}
int main(){
    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        int p=1;
        for(int j=29, c; j>=0; --j){
            c=(a[i]>>j)&1;
            if(!tr[p][c]) tr[p][c]=++idx;
            p=tr[p][c];
        }
        id[p]=i;
    }
    dfs(1, 29);
    // X=3;
    while(m--){
        int retX=0;
        for(int i=0; i<30; ++i) if(pos[i]){
            if(qry(fndmx(tr[pos[i]][0], i-1, retX))!=fndmn(tr[pos[i]][1], i-1, retX)){
                retX|=(1<<i);
            }
        }
        cout<<"! "<<retX<<endl;
        // cout<<"realX: "<<X<<endl;
    }
}
