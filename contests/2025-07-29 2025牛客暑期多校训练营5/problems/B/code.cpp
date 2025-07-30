#pragma GCC optimize(2)
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
const int N=1e6+5,K=55,mod=998244353;
int T, n, m;
char s[N];
int id(char c){
    if(c>='a'&&c<='z') return c-'a';
    else return c-'A'+26;
}
struct node{
    int len, fa;
    int ch[52];
}sam[N];
int lst=1, cnt=1;
int endpos[N];
void extend(int x){
    int p=lst, np=lst=++cnt;
    endpos[np]=x;
    sam[np].len=sam[p].len+1;
    int c=id(s[x]);
    for(; p&&!sam[p].ch[c]; p=sam[p].fa) sam[p].ch[c]=np;
    if(!p) sam[np].fa=1;
    else {
        int q=sam[p].ch[c];
        if(sam[q].len==sam[p].len+1) sam[np].fa=q;
        else{
            int nq=++cnt;
            sam[nq]=sam[q]; sam[nq].len=sam[p].len+1;
            endpos[nq]=x;
            sam[q].fa=sam[np].fa=nq;
            for(; p&&sam[p].ch[c]==q; p=sam[p].fa) sam[p].ch[c]=nq;
        }
    }
}
vector<int> e[N];
 
  
void gmod(int &x){
    x%=mod;
}
  
struct abc{
    int M[K][K];
    abc(int x=0){
        for(int i=0;i<52;i++){
            for(int j=0;j<52;j++){
                M[i][j]=(i==j)*x;
            }
        }
    }
};
abc operator +(abc X,abc Y){
    abc S;
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            gmod(S.M[i][j]=1ll*X.M[i][j]+Y.M[i][j]);
        }
    }
    return S;
}
abc operator *(abc X,abc Y){
    abc S;
    for(int i=0;i<52;i++){
        for(int k=0;k<52;k++){
            for(int j=0;j<52;j++){
                gmod(S.M[i][k]+=1ll*X.M[i][j]*Y.M[j][k]%mod);
            }
        }
    }
    return S;
}
 
abc ksm(abc A,int x){
    abc T,P(1);
    abc I(1);
    for(int i=30;i>=0;i--){
        abc S=T*P;
        T=S+T;
        P=P*P;
         
        if(x>>i & 1){
            T=T*A+I,P=P*A;
        }
    }
    return T;
}
 
int a[N];
abc P;
 
int col;
int c[N];
int siz[N];
 
void dfs(int u,int fa){
    int len=sam[u].len;
    for(int i=0;i<52;i++) gmod(P.M[i][col]+=1);
     
    int R=endpos[u]-sam[fa].len;
    int L=endpos[u]-sam[u].len+1;
    gmod(c[R]+=1);
    gmod(c[L]+=mod-1);
    // cout<<u<<" "<<fa<<" "<<endpos[u]<<" "<<sam[u].len<<": "<<L<<" "<<R<<endl;
     
    siz[u]=sam[u].len-sam[fa].len;
    for(int v: e[u]){
        dfs(v,u);
        int x=a[endpos[v]-sam[u].len];
        gmod(P.M[x][col]+=mod-1);
        gmod(siz[u]+=siz[v]);
    }
}
 
int num[52];
 
int main(){
    read(n); read(m);
    scanf("%s", s+1);
    for(int i=1;i<=n;i++) a[i]=id(s[i]);
    for(int i=1; i<=n; ++i) extend(i);
    for(int i=2; i<=cnt; ++i) e[sam[i].fa].ep(i);
 
    for(int u: e[1]){
        col=a[endpos[u]];
        memset(c,0,sizeof(c));
        // cout<<col<<": ";
         
        dfs(u,1);
        num[col]=siz[u];
        // cout<<num[col]<<endl;
        for(int i=n;i>=1;i--) gmod(c[i]+=c[i+1]);
        // for(int i=1;i<=n;i++) cout<<c[i]<<" "; cout<<endl;
         
        for(int i=1;i<=n;i++){
            for(int j=0;j<52;j++){
                if(j!=a[i-1]) gmod(P.M[j][col]+=c[i]);
            }
        }
    }
     
    abc T=ksm(P,m);
     
    int ans=0;
    for(int i=0;i<52;i++){
        for(int j=0;j<52;j++){
            gmod(ans+=1ll*T.M[i][j]*num[i]%mod);
        }
    }
     
    cout<<(ans+1)%mod;
    return 0;
}
