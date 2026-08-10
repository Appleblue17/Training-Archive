#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;

int n,m,w,h,u[N],d[N],x[N],y[N];

int ce(int a,int b){
    //printf("called ce %lld %lld\n",a,b);
    if(b == 0){
        //printf("divide 0\n");
        return 0;
    }
    int c = a/b+2;
    while(c*b>=a)c--;
    c++;
    return c;
}

int fl(int a,int b){
    //printf("called fl %lld %lld\n",a,b);
    if(b == 0){
        //printf("divide 0\n");
        return 0;
    }
    int c = a/b-2;
    while(c*b<=a)c++;
    c--;
    return c;
}


void solve(){
    
    scanf("%lld%lld%lld%lld",&n,&m,&w,&h);
    for(int i=0;i<=w;i++){
        u[i]=h+2;
        d[i]=-h-2;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
        u[x[i]] = min(u[x[i]],y[i]);
    }
    int id=1;
    for(int i=0;i<=w;i++){
        
        while(id<n && i >= x[id+1])id++;
        //cout << id << ' ' << n << endl;
        
        //cout << '*' << endl;
        if(id != n)u[i] = min(u[i],ce((i-x[id])*(y[id+1]-y[id]),(x[id+1]-x[id]))+y[id]);
        u[i]--;
        if(abs(u[i])%2 != abs(i)%2)u[i]--;
        //printf("u[%lld]=%lld\n",i,u[i]);fflush(stdout);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&x[i],&y[i]);
        d[x[i]]=max(d[x[i]],y[i]);
    }
    id=1;
    for(int i=0;i<=w;i++){
        while(id<n && i >= x[id+1])id++;
        //if(id==n)break;
        if(id != n)d[i] = max(d[i],fl((i-x[id])*(y[id+1]-y[id]),(x[id+1]-x[id]))+y[id]);
        d[i]++;
        if(abs(d[i])%2 != abs(i)%2)d[i]++;
        //printf("d[%lld]=%lld\n",i,d[i]);
    }
    bool f=1;
    int L=0,R=0;
    for(int i=1;i<=w;i++){
        L--;
        R++;
        L = max(L,d[i]);
        R = min(R,u[i]);
        if(L > R)f=0;
    }
    if(!f)printf("impossible");
    else printf("%lld %lld",L,R);
}

signed main(){
    solve();
}
