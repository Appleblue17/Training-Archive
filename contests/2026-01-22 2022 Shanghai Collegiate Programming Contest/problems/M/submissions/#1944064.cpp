#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],vis[N],ans[N];
vector<int> e[N];
int stk[N],top;
bool ins[N];
int dfn[N],tim,low[N],id[N],scccnt;
void tarjan(int x){
    low[x]=dfn[x]=++tim;
    stk[++top]=x;ins[x]=1;
    for(auto y:e[x]){
        if(!dfn[y])tarjan(y),low[x]=min(low[x],low[y]);
        else if(ins[y])low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){
        scccnt++;
        do{
            id[x]=scccnt;
            x=stk[top--];ins[x]=0;
        }while(low[x]!=dfn[x]);
    }
}
vector<int> scc[N];
int main(){
    cin >> n >> m;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<n;i++){
            e[a[i]].push_back(a[i+1]);
            //printf("add edge %d,%d\n",a[i],a[i+1]);
        }
    }
    tarjan(a[1]);
    for(int i=1;i<=n;i++){
        scc[id[i]].push_back(i);
        //printf("id[%d]=%d\n",i,id[i]);
    }
    int sm=0;
    for(int i=n;i>=1;i--){
        if(!vis[id[a[i]]]){
            vis[id[a[i]]]=1;
            sm += scc[id[a[i]]].size();
        }
        ans[a[i]]=sm;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]-1);
    }
}
