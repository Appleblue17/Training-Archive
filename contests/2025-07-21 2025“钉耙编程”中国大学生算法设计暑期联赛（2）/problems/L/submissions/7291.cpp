#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=55,M=7.6e4,K=12.2e4;
int T,n,m,a[N],ans;

void dfs0(int dep,int sum){
    if(dep>n) return ;
    dfs0(dep+1,sum);
    
    sum^=a[dep];
    ans=max(ans,sum);
    dfs0(dep+2,sum);
}


int p[M],id1;
int q[K],id2;

int L,R;
void dfs(int dep,int sum,int alc,int *f,int &id){
    if(dep>R) return ;
    
    dfs(dep+1,sum,alc,f,id);
    
    sum^=a[dep];
    f[++id]=sum^alc;
    dfs(dep+2,sum,alc,f,id);
}


void sol(int t,int mac,int l,int r,int L,int R){
    if(l>r || L>R) return ;
    ans=max(ans,mac);
    if(t<0) return ;
    
    int A=l,B=r;
    while(A<=B){
        while(A<=B && (p[A]>>t & 1ll)) A++;
        while(A<=B && !(p[B]>>t & 1ll)) B--;
        if(A<=B) swap(p[A],p[B]);
    }
    int mid=B;
    
    A=L,B=R;
    while(A<=B){
        while(A<=B && (q[A]>>t & 1ll)) A++;
        while(A<=B && !(q[B]>>t & 1ll)) B--;
        if(A<=B) swap(q[A],q[B]);
    }
    int MID=B;
    
    // cout<<t<<" "<<mac<<": "<<endl;
    // cout<<l<<" "<<mid<<" | "; for(int i=l;i<=r;i++) cout<<(p[i]>>t & 1)<<" "; cout<<endl;
    // cout<<L<<" "<<MID<<" | "; for(int i=l;i<=r;i++) cout<<(q[i]>>t & 1)<<" "; cout<<endl;
    
    bool fl1=(l<=mid && MID+1<=R);
    bool fl2=(mid+1<=r && L<=MID);
    if(!fl1 && !fl2){
        sol(t-1,mac,l,mid,L,MID);
        sol(t-1,mac,mid+1,r,MID+1,R);
    }
    else{
        sol(t-1,mac | (1ll<<t),l,mid,MID+1,R);
        sol(t-1,mac | (1ll<<t),mid+1,r,L,MID);
    }
}


void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    ans=0;
    if(n<=5){
        dfs0(1,0);
        printf("%lld\n",ans);
        return ;
    }
    
    m=(n+1)/2;
    for(int A=0;A<=1;A++){
        for(int B=0;B<=1;B++){
            for(int C=0;C<=1;C++){
                int alc=((A==1)*a[1])^((B==1)*a[n])^((C==1)*a[m]);
                // cout<<A<<" "<<B<<" "<<C<<" "<<alc<<endl;
                
                id1=id2=0;
                L=A+2,R=m-1-C;
                // cout<<L<<" "<<R<<endl;
                p[++id1]=alc;
                dfs(L,0,alc,p,id1);
                
                L=m+1+C,R=n-B-1;
                // cout<<L<<" "<<R<<endl;
                dfs(L,0,0,q,id2);
                q[++id2]=0;
                // cout<<id1<<" "<<id2<<endl;
                
                // cout<<"p "; for(int i=1;i<=id1;i++) cout<<p[i]<<" "; cout<<endl;
                // cout<<"q "; for(int i=1;i<=id2;i++) cout<<q[i]<<" "; cout<<endl;
                
                sol(60,0,1,id1,1,id2);
            }
        }
    }
    
    printf("%lld\n",ans);
}

signed main(){
    // cout<<(sizeof(p)+sizeof(q))/1024;
    // return 0;
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}