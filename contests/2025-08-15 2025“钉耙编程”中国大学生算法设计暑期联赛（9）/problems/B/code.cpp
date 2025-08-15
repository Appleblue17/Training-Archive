#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+5,M=12,mod=1e9+7,mod2=1e9+6,INF=1e9;

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1ll) tot=1ll*tot*a%mod;
        a=1ll*a*a%mod;
        x>>=1ll;
    }
    return tot;
}

struct abc{
    int x,y;
};
abc operator +(abc X,abc Y){
    return (abc){(X.x+Y.x)%mod,(X.y+Y.y)%mod2};
}
abc operator *(abc X,abc Y){
    return (abc){1ll*X.x*Y.x%mod,1ll*X.y*Y.y%mod2};
}
abc operator <<(abc X,abc Y){
    return (abc){1ll*X.x*ksm(2,Y.y)%mod,0};
}

struct def{
    int len=0,val=1;
    int opt[M];
    abc num[M];
    
    void pr(){
        cout<<len<<" "<<val<<": ";
        cout<<num[0].x;
        for(int i=1;i<len;i++){
            if(opt[i]==0) cout<<"<<";
            else if(opt[i]==1) cout<<"+";
            else cout<<"*";
            cout<<num[i].x;
        }
        cout<<endl;
    }
    
    abc cal(int t,int l,int r){
        abc tot;
        if(t==0) tot={1,0};
        if(t==1) tot={0,0};
        if(t==2) tot={1,1};
        
        if(l==r){
            if(!t && l) return tot<<num[l];
            return num[l];
        }
        
        vector <int> V={l};
        
        for(int i=l+1;i<=r;i++){
            if(opt[i]==t) V.push_back(i);
        }
        V.push_back(r+1);
        int sz=V.size();
        // if(sz==2) return cal(t+1,l,r);
        
        for(int i=0;i+1<sz;i++){
            int l=V[i],r=V[i+1]-1;
            abc ret=cal(t+1,l,r);
            
            if(t==0){
                if(!i && !l) tot=ret;
                else tot=tot<<ret;
            }
            if(t==1) tot=tot+ret;
            if(t==2) tot=tot*ret;
        }
        return tot;
    }
    int cal_solve(){
        abc ret=cal(0,0,len-1);
        return 1ll*ret.x*val%mod;
    }
};


def S;
void zip(def *A,int t,int l,int r,int d){
    if(l==r){
        S.num[S.len]=A->num[l];
        S.len++;
        return ;
    }
    // cout<<t<<" "<<l<<" "<<r<<" "<<d<<endl;
    
    vector <int> V={l};
    for(int i=l+1;i<=r;i++){
        if(A->opt[i]==t) V.push_back(i);
    }
    V.push_back(r+1);
    
    int sz=V.size();
    if(sz==2){
        zip(A,t+1,l,r,d);
        return ;
    }
    
    abc tot;
    if(d==0){
        zip(A,t+1,V[0],V[1]-1,-1);
        
        if(sz>3){
            tot=A->cal(t,V[1],V[sz-2]-1);
            
            if(!t){
                S.val=1ll*S.val*tot.x%mod;
            }
            else{
                S.opt[S.len]=t;
                S.num[S.len]=tot;
                S.len++;
            }
        }
        
        S.opt[S.len]=t;
        zip(A,t+1,V[sz-2],V[sz-1]-1,1);
    }
    if(d==-1){
        zip(A,t+1,V[0],V[1]-1,-1);
        
        tot=A->cal(t,V[1],V[sz-1]-1);
        S.opt[S.len]=t;
        S.num[S.len]=tot;
        S.len++;
    }
    if(d==1){
        tot=A->cal(t,V[0],V[sz-2]-1);
        S.num[S.len]=tot;
        S.len++;
        
        S.opt[S.len]=t;
        zip(A,t+1,V[sz-2],V[sz-1]-1,1);
    }
}

void zip_solve(def *A){
    S.len=0,S.val=A->val;
    zip(A,0,0,A->len-1,0);
    *A=S;
}

def merge(def A,def B,int opt){
    def T; T.val=1ll*A.val*B.val%mod;
    int len1=A.len,len2=B.len;
    T.len=len1+len2;
    
    for(int i=0;i<len1;i++){
        T.num[i]=A.num[i];
        T.opt[i]=A.opt[i];
    }
    for(int i=0;i<len2;i++){
        T.num[i+len1]=B.num[i];
        T.opt[i+len1]=B.opt[i];
    }
    T.opt[len1]=opt;
    
    // T.pr();
    // if(T.len==5) 
    zip_solve(&T);
    return T;
}



int n,ans[N];
int val[N];
char typ[N];
int X[N],Y[N],in[N];

vector <int> G[N];
queue <int> q;

def f[N];

signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        val[i]=-1;
        
        char opt;
        scanf("\n%c",&opt); typ[i]=opt;
        if(opt=='N'){
            int x; scanf("%d",&x);
            val[i]=x;
        }
        else{
            int x,y; scanf("%d%d",&x,&y);
            X[i]=x,Y[i]=y; in[i]+=2;
            G[x].push_back(i);
            G[y].push_back(i);
        }
    }
    
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    
    while(q.size()){
        int u=q.front(); q.pop();
        char opt=typ[u];
        int x=X[u],y=Y[u];
        
        if(opt=='N'){
            f[u].len=1;
            f[u].num[0]={val[u]%mod,val[u]%mod2};
        }
        else if(opt=='<'){
            f[u]=merge(f[x],f[y],0);
        }
        else if(opt=='+'){
            f[u]=merge(f[x],f[y],1);
        }
        else if(opt=='*'){
            f[u]=merge(f[x],f[y],2);
        }
        ans[u]=f[u].cal_solve();
        
        // cout<<u<<": "; f[u].pr();
        
        for(int v: G[u]){
            in[v]--;
            if(!in[v]) q.push(v);
        }
        // cout<<endl;
        
    }
    
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}