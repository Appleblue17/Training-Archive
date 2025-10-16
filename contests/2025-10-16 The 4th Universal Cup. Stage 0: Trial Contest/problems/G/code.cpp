#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
const int N=2e6+5,INF=1e18;

int n,m,ans=-INF;
int U[N],V[N],W[N];
bool del[N];

queue <int> q;

pair<int,int> p[N];
map < pair<int,int>, int > mp;
int pid;

int get_id(int u,int v){
    if(!mp[MP(u,v)]){
        p[++pid]=MP(u,v);
        mp[MP(u,v)]=pid;
    }
    return mp[MP(u,v)];
}

vector <int> P[N];
int Q[N];

int deg[N];

void del_edge(int t){
    if(del[t]) return ;
    int u=U[t],v=V[t];
    if(u>v) swap(u,v);
    // cout<<" DEL "<<t<<endl;
    
    int id=get_id(u,v);
    
    deg[u]--;
    if(deg[u]==2) q.push(u);
    deg[v]--;
    if(deg[v]==2) q.push(v);
    
    Q[id]=0;
    del[t]=1;
}

void add_edge(int t){
    if(del[t]) return ;
    int u=U[t],v=V[t];
    if(u>v) swap(u,v);
    
    int id=get_id(u,v);
    // cout<<" id "<<u<<" "<<v<<" "<<id<<endl;
    
    if(Q[id]){
        int s=Q[id];
        ans=max(ans,W[s]+W[t]);
        if(!del[s] && W[s]>W[t]){
            // cout<<"don't add "<<U[t]<<" "<<V[t]<<" "<<W[t]<<endl;
            return ;
        }
        del_edge(s);
        // cout<<"del edge "<<U[s]<<" "<<V[s]<<" "<<W[s]<<endl;
    }
    
    P[u].push_back(t);
    P[v].push_back(t);
    deg[u]++;
    if(deg[u]==2) q.push(u);
    deg[v]++;
    if(deg[v]==2) q.push(v);
    
    Q[id]=t;
}

signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w; scanf("%lld%lld%lld",&u,&v,&w);
        U[i]=u,V[i]=v,W[i]=w;
        add_edge(i);
    }
    
    while(q.size()){
        int u=q.front(); q.pop();
        if(deg[u]!=2) continue;
        // cout<<"proc "<<u<<endl;
        
        vector <int> tmp;
        for(int t: P[u]){
            if(del[t]) continue;
            tmp.push_back(t);
        }
        assert(tmp.size()==2);
        
        int t=tmp[0],s=tmp[1];
        int x=U[t]^V[t]^u,y=U[s]^V[s]^u,w=W[t]+W[s];
        
        // cout<<" ? "<<t<<" "<<s<<endl;
        del_edge(t);
        del_edge(s);
        m++; U[m]=x,V[m]=y,W[m]=w;
        add_edge(m);
        // cout<<"add edge "<<x<<" "<<y<<" "<<w<<endl;
    }
    cout<<ans;
}
