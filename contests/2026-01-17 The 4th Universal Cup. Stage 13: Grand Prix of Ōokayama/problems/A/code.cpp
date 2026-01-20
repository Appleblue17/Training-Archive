#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=6e5+5,INF=1e9;

int n,ans[N];
int p[N];
int st[22][N];


int gmin(int l,int r){
    int k=__lg(r-l+1);
    return min(st[k][l],st[k][r-(1<<k)+1]);
}

int lson[N],rson[N];
int sta[N],cur;
void ins(int x){
    int sav=cur;
    while(cur && p[sta[cur]]>p[x]) cur--;
    if(cur) rson[sta[cur]]=x;
    if(cur<sav) lson[x]=sta[cur+1];
    sta[++cur]=x;
}


int dp[N];
int L[N],R[N];
void dfs(int l,int r,int x){
    if(l>r) return ;
    L[x]=l,R[x]=r;
    if(l==r){
        dp[x]=0;
        return ;
    }
    int ls=lson[x],rs=rson[x];
    dfs(l,x-1,ls);
    dfs(x+1,r,rs);
    if(p[ls]<p[rs]) dp[x]=dp[rson[ls]]+1;
    else dp[x]=dp[lson[rs]]+1;
}

signed main(){
    scanf("%lld",&n);
    p[0]=INF;
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]),st[0][i]=p[i];
    for(int i=1;i<=n;i++) ins(i);
    
    for(int t=1;t<=20;t++){
        for(int i=1;i+(1<<t)-1<=n;i++){
            st[t][i]=min(st[t-1][i],st[t-1][i+(1<<(t-1))]);
        }
    }
    
    dfs(1,n,sta[1]);
    
    for(int x=1;x<=n;x++){
        int A=L[x]-1,B=R[x]+1;
        if(A<1 || B>n) continue;
        
        int l,r,tot1,tot2;
        l=1,r=A-1,tot1=A;
        while(l<=r){
            int mid=(l+r)>>1;
            if(gmin(mid,A-1)>max(p[A],p[B])) tot1=mid,r=mid-1;
            else l=mid+1;
        }
        
        l=B+1,r=n,tot2=B;
        while(l<=r){
            int mid=(l+r)>>1;
            if(gmin(B+1,mid)>max(p[A],p[B])) tot2=mid,l=mid+1;
            else r=mid-1;
        }
        
        int val=dp[x];
        if(val) ans[val+1]+=(A-tot1+1)*(tot2-B+1);
        
        // cout<<x<<": "<<A<<" "<<B<<" , "<<val<<": "<<tot1<<" "<<tot2<<endl;
    }
    int tot=n*(n-1)/2;
    for(int i=2;i<=n;i++) tot-=ans[i];
    ans[1]=tot;
    
    for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    
}
