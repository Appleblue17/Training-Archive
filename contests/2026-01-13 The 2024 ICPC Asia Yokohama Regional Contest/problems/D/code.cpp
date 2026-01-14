#include <bits/stdc++.h>
using namespace std;
#define ls(u) ch[u][0]
#define rs(u) ch[u][1]
// #define int long long
const int N=3e6+5,mod=998244353;
char A[N],B[N];
int len,n;
int ans=1;


struct tree{
    int ch[N][2],fat[N];
    int id,num;
    
    int L[N],R[N];
    int siz[N],dep[N];
    
    stack <int> st;
    
    void constr(char *S){
        id=n,num=0;
        
        for(int i=1;i<=len;i++){
            if(S[i]=='(') continue;
            else if(S[i]=='1') st.push(++num);
            else{
                int y=st.top(); st.pop();
                int x=st.top(); st.pop();
                // cout<<"HELLO "<<x<<" "<<y<<endl;
                id++;
                ch[id][0]=x,ch[id][1]=y;
                fat[x]=fat[y]=id;
                st.push(id);
            }
        }
        
        // for(int i=1;i<=id;i++) cout<<i<<": "<<ch[i][0]<<" "<<ch[i][1]<<endl;
        
    }
    
    void dfs0(int u){
        if(!u) return ;
        if(u<=n){
            siz[u]=1;
            L[u]=R[u]=u;
        }
        else{
            int ls=ch[u][0],rs=ch[u][1];
            dep[ls]=dep[u]+1;
            dfs0(ls);
            dep[rs]=dep[u]+1;
            dfs0(rs);
            L[u]=L[ls],R[u]=R[rs];
            siz[u]=siz[ls]+siz[rs];
        }
    }
    int lca(int x,int y){
        while(dep[x]>dep[y]) x=fat[x];
        while(dep[x]<dep[y]) y=fat[y];
        while(x!=y) x=fat[x],y=fat[y];
        return x;
    }
}P,Q;

void dfs(int u){
    if(u<=n) return ;
    dfs(P.ls(u));
    dfs(P.rs(u));
    
    int x=P.R[P.ls(u)];
    
    int v=Q.lca(x,x+1);
    
    int l=max(P.L[P.ls(u)],Q.L[Q.ls(v)]);
    int r=min(P.R[P.rs(u)],Q.R[Q.rs(v)]);
    
    // cout<<u<<" "<<x<<": "<<l<<" "<<r<<endl;
    
    ans=1ll*ans*(x-l+1)%mod*(r-x)%mod;
}


signed main(){
    scanf("%s\n%s",A+1,B+1);
    len=strlen(A+1);
    n=(len+2)/3;
    
    // cout<<len<<" "<<n<<endl;
    
    P.constr(A); P.dfs0(P.id);
    Q.constr(B); Q.dfs0(Q.id);
    
    
    // for(int i=1;i<=P.id;i++) cout<<P.f[i]<<" "; cout<<endl;
    // for(int i=1;i<=Q.id;i++) cout<<Q.f[i]<<" "; cout<<endl;
    dfs(P.id);
    
    cout<<ans;
}
