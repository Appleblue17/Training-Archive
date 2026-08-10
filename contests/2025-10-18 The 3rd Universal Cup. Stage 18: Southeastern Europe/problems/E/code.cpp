#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,mod=998244353;
int T,n,a[N];

namespace task1{
    bool vis[N];
    int pat[N];
    int ans;
    
    void dfs(int dep){
        if(dep>n){
            bool fl=1;
            for(int i=1;i<=n && fl;i++){
                for(int j=i+1;j<=n && fl;j++){
                    if(abs(i-j)+abs(pat[i]-pat[j])>n) fl=0;
                }
            }
            ans+=fl;
            return;
        }
        if(a[dep]!=-1){
            pat[dep]=a[dep];
            dfs(dep+1);
        }
        else{
            for(int i=1;i<=n;i++){
                if(!vis[i]){
                    pat[dep]=i;
                    vis[i]=1;
                    dfs(dep+1);
                    vis[i]=0;
                }
            }
        }
    }
    void solve(){
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=-1) vis[a[i]]=1;
        }
        ans=0;
        dfs(1);
        printf("%lld\n",ans);
    }
    
}

void gmod(int &x){
    x%=mod;
}

namespace task2{
    bool chk(int x,int y){
        for(int i=1;i<=n;i++)
            if(i!=x && a[i]==y) return 0;
        return (a[x]==-1 || a[x]==y);
    }
    
    int c[N];
    bool vis[N];
    int p[N],id;
    
    int cal(int l,int r){
        if(l>r) return 0;
        l=max(l,2ll); r=min(r,n-1);
        return c[r]-c[l-1];
    }
    
    int L[N],R[N];
    int LL[N],RR[N];
    void pre(){
        for(int i=1;i<=n;i++) vis[i]=0,c[i]=1;
        for(int i=1;i<=n;i++) L[i]=R[i]=LL[i]=RR[i]=-1;
        
        for(int i=2;i<=n-1;i++){
            int x=a[i];
            if(x==-1 || x==1 || x==n) continue;
            vis[x]=1; c[i]=0;
        }
        for(int i=1;i<=n;i++) c[i]+=c[i-1];
    }
    int proc(){
        for(int i=2;i<=n-1;i++){
            int x=a[i];
            if(x==-1 || x==1 || x==n) continue;
            if(L[x]!=-1){
                if(!(L[x]<=i && i<=R[x]) && !(LL[x]<=i && i<=RR[x])) return 0;
            }
        }
        
        id=0;
        for(int i=1;i<=n;i++){
            if(L[i]==-1 || vis[i]) continue;
            int tot=cal(L[i],R[i])+cal(LL[i],RR[i]);
            p[++id]=tot;
        }
        
        sort(p+1,p+id+1);
        int tot=1;
        for(int i=1;i<=id;i++) tot=tot*(p[i]-i+1)%mod;
        
        return tot;
    }
    
    int sol(){
        int m=(n+1)/2;
        if(!chk(1,m) || !chk(m,1) || !chk(n,m-1) || !chk(m+1,n)) return 0;
        pre();

        for(int i=2;i<=m-2;i++){
            L[i]=m-i+1, R[i]=m-1;
            LL[i]=m+2, RR[i]=m+i;
        }
        for(int i=m+1;i<=n-1;i++){
            L[i]=i-m+1, R[i]=m-1;
            LL[i]=m+2, RR[i]=n-(i-m)+1;
        }
        return proc();
    }
    
    int sol2(int X,int Y){
        int m=(n+1)/2;
        if(!chk(1,m) || !chk(m,1) || !chk(n,m+1) || !chk(m+1,n)) return 0;
        pre();
        for(int i=2;i<=m-1;i++){
            L[i]=m-i+1, R[i]=m-1;
            LL[i]=m+2, RR[i]=m+i-X;
        }
        for(int i=m+2;i<=n-1;i++){
            L[i]=i-m+Y, R[i]=m-1;
            LL[i]=m+2, RR[i]=n-(i-m)+1;
        }
        return proc();
    }
    
    int tmp[N];
    void solve(){
        int ans=0;
        for(int fl1=0;fl1<=1;fl1++){
            for(int fl2=0;fl2<=1;fl2++){
                for(int fl3=0;fl3<=1;fl3++){
                    int ret=sol();
                    gmod(ans+=ret);
                    
                    for(int i=1;i<=n;i++){
                        if(a[i]!=-1) a[i]=n+1-a[i];
                    }
                }
                
                reverse(a+1,a+n+1);
            }
            
            for(int i=1;i<=n;i++) tmp[i]=-1;
            for(int i=1;i<=n;i++){
                if(a[i]!=-1) tmp[a[i]]=i;
            }
            for(int i=1;i<=n;i++) swap(a[i],tmp[i]);
        }
        
        for(int fl2=0;fl2<=1;fl2++){
            for(int fl3=0;fl3<=1;fl3++){
                int ret=(sol2(0,1)+sol2(1,0)+mod-sol2(1,1))%mod;
                gmod(ans+=ret);
                
                for(int i=1;i<=n;i++){
                    if(a[i]!=-1) a[i]=n+1-a[i];
                }
            }
            
            reverse(a+1,a+n+1);
        }
        
        printf("%lld\n",ans);
    }
}

namespace task3{
    bool chk(int x,int y){
        for(int i=1;i<=n;i++)
            if(i!=x && a[i]==y) return 0;
        return (a[x]==-1 || a[x]==y);
    }
    
    int c[N];
    bool vis[N];
    int p[N],id;
    
    int cal(int l,int r){
        if(l>r) return 0;
        l=max(l,2ll); r=min(r,n-1);
        return c[r]-c[l-1];
    }
    
    int L[N],R[N];
    int LL[N],RR[N];
    void pre(){
        for(int i=1;i<=n;i++) vis[i]=0,c[i]=1;
        for(int i=1;i<=n;i++) L[i]=R[i]=LL[i]=RR[i]=-1;
        
        for(int i=2;i<=n-1;i++){
            int x=a[i];
            if(x==-1 || x==1 || x==n) continue;
            vis[x]=1; c[i]=0;
        }
        for(int i=1;i<=n;i++) c[i]+=c[i-1];
    }
    int proc(){
        for(int i=2;i<=n-1;i++){
            int x=a[i];
            if(x==-1 || x==1 || x==n) continue;
            if(L[x]!=-1){
                if(!(L[x]<=i && i<=R[x]) && !(LL[x]<=i && i<=RR[x])) return 0;
            }
        }
        
        id=0;
        for(int i=1;i<=n;i++){
            if(L[i]==-1 || vis[i]) continue;
            int tot=cal(L[i],R[i])+cal(LL[i],RR[i]);
            p[++id]=tot;
        }
        
        sort(p+1,p+id+1);
        int tot=1;
        for(int i=1;i<=id;i++) tot=tot*(p[i]-i+1)%mod;
        
        return tot;
    }
    
    int sol(int X,int Y){
        int m=n/2;
        if(!chk(1,m) || !chk(m,1) || !chk(n,m+1) || !chk(m+1,n)) return 0;
        
        pre();
        for(int i=2;i<=m-1;i++){
            L[i]=m-i+1, R[i]=m-1;
            LL[i]=m+2, RR[i]=m+i+1-X;
        }
        for(int i=m+2;i<=n-1;i++){
            L[i]=i-m-1+Y, R[i]=m-1;
            LL[i]=m+2, RR[i]=n-(i-m)+1;
        }
        
        return proc();
    }
    
    int sol2(){
        int m=n/2;
        if(!chk(1,m) || !chk(m,1) || !chk(n,m-1) || !chk(m+1,n)) return 0;
        
        pre();
        for(int i=2;i<=m-2;i++){
            L[i]=m-i+1, R[i]=m-1;
            LL[i]=m+2, RR[i]=min(n-1,m+i+1);
        }
        for(int i=m+1;i<=n-1;i++){
            L[i]=i-m+1, R[i]=m-1;
            LL[i]=m+2, RR[i]=n-(i-m)+1;
        }
        
        return proc();
    }
    
    int sol3(){
        int m=n/2;
        if(!chk(1,m) || !chk(m+1,1) || !chk(n,m+1) || !chk(m,n)) return 0;
        
        pre();
        for(int i=2;i<=m-1;i++){
            L[i]=m-i+1, R[i]=m-1;
            LL[i]=m+2, RR[i]=m+i;
        }
        for(int i=m+2;i<=n-1;i++){
            L[i]=i-m, R[i]=m-1;
            LL[i]=m+2, RR[i]=n-(i-m)+1;
        }
        
        return proc();
    }
    
    int sol4(){
        int m=n/2;
        if(!chk(1,m) || !chk(m+2,1) || !chk(n,m-1) || !chk(m+1,n)) return 0;
        
        pre();
        for(int i=2;i<=m-2;i++){
            L[i]=m-i+1, R[i]=m;
            LL[i]=m+3, RR[i]=m+i+1;
        }
        for(int i=m+1;i<=n-1;i++){
            L[i]=i-m+1, R[i]=m;
            LL[i]=m+3, RR[i]=n-(i-m)+1;
        }
        
        return proc();
    }
    
    int tmp[N];
    void solve(){
        int ans=0;
        for(int fl3=0;fl3<=1;fl3++){
            int ret=(sol(0,2)+mod-sol(1,2)+sol(2,0)+mod-sol(2,1)+sol(1,1))%mod;
            gmod(ans+=ret);
            
            for(int i=1;i<=n;i++){
                if(a[i]!=-1) a[i]=n+1-a[i];
            }
        }
        
        for(int fl1=0;fl1<=1;fl1++){
            for(int fl2=0;fl2<=1;fl2++){
                for(int fl3=0;fl3<=1;fl3++){
                    int ret=sol2();
                    gmod(ans+=ret);
                    
                    for(int i=1;i<=n;i++){
                        if(a[i]!=-1) a[i]=n+1-a[i];
                    }
                }
                
                reverse(a+1,a+n+1);
            }
            
            for(int i=1;i<=n;i++) tmp[i]=-1;
            for(int i=1;i<=n;i++){
                if(a[i]!=-1) tmp[a[i]]=i;
            }
            for(int i=1;i<=n;i++) swap(a[i],tmp[i]);
        }
        
        for(int fl2=0;fl2<=1;fl2++){
            for(int fl3=0;fl3<=1;fl3++){
                int ret=sol4();
                gmod(ans+=ret);
                
                for(int i=1;i<=n;i++){
                    if(a[i]!=-1) a[i]=n+1-a[i];
                }
            }
            
            reverse(a+1,a+n+1);
        }
        
        for(int fl1=0;fl1<=1;fl1++){
            int ret=sol3();
            gmod(ans+=ret);
            
            for(int i=1;i<=n;i++) tmp[i]=-1;
            for(int i=1;i<=n;i++){
                if(a[i]!=-1) tmp[a[i]]=i;
            }
            for(int i=1;i<=n;i++) swap(a[i],tmp[i]);
        }
        
        printf("%lld\n",ans);
    }
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        
        if(n<=6) task1::solve();
        else if(n%2==1) task2::solve();
        else task3::solve();
    }
}


