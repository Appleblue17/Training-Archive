#include<bits/stdc++.h>
using namespace std;
const int N=2200,Q=1e6+5;
int n,q;
int A[N][N],B[N][N];

int OPT[Q],VAL[Q],ANS[Q];

int rev(int x){
    int tot=0;
    while(x){
        tot=tot*10+x%10;
        x/=10;
    }
    return tot;
}


map<int,int> mp;
int p[N],e[N],id;
void decom(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i) continue;
        while(n%i==0){
            mp[i]++;
            n/=i;
        }
    }
    if(n>1) mp[n]++;
}


vector < pair<int,int> > G[N*2];
void add(int u,int v,int w){
    G[u].push_back({v,w});
    G[v].push_back({u,w});
}
bool FL;
int cid;
int col[N*2],bel[N*2];

void dfs(int u){
    bel[u]=cid;
    for(auto e: G[u]){
        int v=e.first,w=e.second;
        if(col[v]==-1){
            col[v]=col[u]^w;
            dfs(v);
        }
        else{
            if(col[v]!=(col[u]^w)) FL=0;
        }
    }
}

bool nw[N*2];
int buc[N*2][2],ans;

void upd(int pos,int val,int w){
    int c=bel[pos];
    ans-=(buc[c][0]==0)+(buc[c][1]==0);
    if(val==col[pos]) buc[c][1]+=w;
    else buc[c][0]+=w;
    ans+=(buc[c][0]==0)+(buc[c][1]==0);
}

int main(){
    cin>>n>>q;
    int g=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x=i+j,y=i-j+n;
            int val; scanf("%d",&val);
            A[x][y]=val;
            B[x][y]=rev(val);
            // cout<<A[x][y]<<" "<<B[x][y]<<endl;
        }
    }
    
    decom(A[2][n]);
    decom(B[2][n]/__gcd(A[2][n],B[2][n]));
    for(auto tmp: mp){
        int q=tmp.first;
        for(int i=1,x=q;i<=tmp.second;i++,x*=q){
            p[++id]=x;
            e[id]=q;
        }
    }
    
    // for(int i=1;i<=id;i++) cout<<p[i]<<" ";
    // cout<<endl;
    
    for(int i=1;i<=q;i++){
        char c; int x;
        scanf("\n%c %d",&c,&x);
        if(c=='+') OPT[i]=0,VAL[i]=x;
        else OPT[i]=1,VAL[i]=x+n;
        
        ANS[i]=1;
    }
    
    n*=2;
    for(int t=1;t<=id;t++){
        int d=p[t];
        
        for(int i=1;i<=n*2;i++){
            G[i].clear();
            col[i]=-1;
            bel[i]=0;
            nw[i]=0;
            buc[i][0]=buc[i][1]=0;
        }
        FL=1;
        for(int i=1;i<=n && FL;i++){
            for(int j=1;j<=n && FL;j++){
                bool x=(A[i][j]%d==0),y=(B[i][j]%d==0);
                if(!x && !y) FL=0;
                if(x && !y) add(i,j+n,0);
                // , cout<<"add "<<i<<" "<<j<<" "<<0<<endl;
                if(!x && y) add(i,j+n,1);
                // , cout<<"add "<<i<<" "<<j<<" "<<1<<endl;
            }
        }
        if(!FL) continue;
        
        cid=0;
        for(int i=1;i<=n*2 && FL;i++){
            if(col[i]!=-1) continue;
            cid++;
            col[i]=0; bel[i]=cid;
            dfs(i);
        }
        if(!FL) continue;
        
        // for(int i=1;i<=n*2;i++) cout<<col[i]<<" "; cout<<endl;
        // for(int i=1;i<=n*2;i++) cout<<bel[i]<<" "; cout<<endl;
        
        ans=cid*2;
        // cout<<ans<<endl;
        for(int i=1;i<=n*2;i++) upd(i,0,1);
        // cout<<ans<<": "; for(int i=1;i<=cid;i++) cout<<buc[i][0]<<"/"<<buc[i][1]<<" ";
        // cout<<endl;
        
        for(int i=1;i<=q;i++){
            int u=VAL[i]+OPT[i]*n;
            // cout<<"upd "<<u<<endl;
            
            upd(u,nw[u],-1);
            nw[u]^=1;
            upd(u,nw[u],1);
            // cout<<ans<<": "; for(int i=1;i<=cid;i++) cout<<buc[i][0]<<"/"<<buc[i][1]<<" ";
            // cout<<endl;
            if(ans==cid) ANS[i]*=e[t];
        }
    }
    
    for(int i=1;i<=q;i++) printf("%d\n",ANS[i]);
}
