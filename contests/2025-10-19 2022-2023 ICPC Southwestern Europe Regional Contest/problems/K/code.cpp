#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans[N];
char S[N];
vector<int> g[N],id[N];
void add(int u,int v,int w){
    g[u].push_back(v);g[v].push_back(u);
    id[u].push_back(w);id[v].push_back(w);
}
int A,B;

void solve(){
    //cout << "solve" << endl;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        g[i].clear();id[i].clear();
    }
    for(int i=1;i<=m;i++){
        ans[i]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d",&u,&v);
        add(u,v,i);
    }
    //cout << '*' << endl;
    int na=-1;
    for(int i=1;i<=n;i++){
        if(g[i].size() != n-1){
            na=i;
        }
    }
    //cout << na << endl;
    int ansk=2;
    if(na == -1){
        na=1;
        for(int v:id[1]){
            ans[v]=2;
        }
        ans[id[1][0]]=3;
        ansk=3;
    }
    else{
        for(int v:id[na]){
            //cout << v << endl;
            ans[v]=2;
        }
    }
    //cout << '*' << endl;
    printf("%d\n",ansk);
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    putchar('\n');
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--)solve();
    
}
