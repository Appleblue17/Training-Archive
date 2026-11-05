#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int b[N],a[N],cur,id[N];
int n,m;
vector<int> g[N];
void dfs(int u,int fa){
    a[u] = cur;
    //printf("a[%d]=%d\n",u,cur);
    for(int v:g[u]){
        if(v == fa)continue;
        //dep[v] = dep[u]+1;
        cur++;
        dfs(v,u);
    }
    cur++;
}
void solvec(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        g[i].clear();
        a[i]=0;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cur = 0;
    for(int i=n;i>=1;i--){
        if(!a[i]){
            cur++;
            dfs(i,0);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
bool cmp(int i,int j){
    return b[i]<b[j];
}
vector<int> ans[2];
void add(int u,int v){
    if(u <= 0 || v <= 0)return;
    ans[0].push_back(u);
    ans[1].push_back(v);
}
stack<int> st;
void solved(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        id[i] = i;
    }
    ans[0].clear();ans[1].clear();
    while(!st.empty())st.pop();
    sort(id+1,id+n+1,cmp);
    
    for(int t=1;t<=n;t++){
        int i = id[t];
        
        if(t == 1){
            st.push(i);
            continue;
        }
        int k = b[i] - b[id[t-1]];
        //printf("t=%d,i=%d,k=%d\n",t,i,k);fflush(stdout);
        for(int j=1;j<=k-1;j++){
            st.pop();
        }
        int u = 0;
        if(!st.empty())u = st.top();
        add(u,i);
        st.push(i);
    }
    printf("%d\n",ans[0].size());
    for(int i=0;i<ans[0].size();i++){
        printf("%d %d\n",ans[0][i],ans[1][i]);
    }
}
signed main(){
    char s[10];
    int T;
    scanf("%s",s);
    if(s[0]=='c'){
        cin >> T;
        while(T--){
            solvec();
        }
    }
    else{
        cin >> T;
        while(T--){
            solved();
        }
    }
}