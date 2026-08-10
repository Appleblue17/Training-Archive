#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N=2200,M=12,NN=3e6+5,INF=1e18;
const double eps=1e-3;
int n_,n,m,s,v;

struct abc{
    int r;
    double a,b;
};
bool operator <(abc X,abc Y){
    if(X.r==Y.r) return X.a<Y.a;
    return X.r<Y.r;
}

abc p[N];
vector <abc> V[M];

bool chk(int r,double pos){
    int t=lower_bound(V[r].begin(),V[r].end(),(abc){r,pos-eps,pos-eps})-V[r].begin();
    if(!t) return 1;
    return (pos+eps>=V[r][t-1].b);
}

bool check(int r,int x,double k,int L,int R){
    for(int t=L;t<=R;t++){
        double nx=x+(t-r)*k;
        if(!chk(t,nx)) return 0;
    }
    return 1;
}


struct def{
    int L,R;
    int r,x;
    double k;
}q[NN];
int id;

void add(int L,int R,int r,int x,double k){
    q[++id]={L,R,r,x,k};
    // cout<<id<<": "<<L<<" "<<R<<" "<<r<<" "<<x<<" "<<k<<endl;
}

int dp[NN];
struct ghi{
    double pos1,pos2;
    int id,typ,rk;
}r[NN];
bool cmp1(ghi X,ghi Y){
    return X.pos1<Y.pos1;
}
bool cmp2(ghi X,ghi Y){
    return X.pos2>Y.pos2;
}
int rid;


int lowbit(int x){
    return x & (-x);
}
int c[NN];
void modify(int x,int k){
    while(x<NN) c[x]=min(c[x],k),x+=lowbit(x);
}
int query(int x){
    int tot=INF;
    while(x) tot=min(tot,c[x]),x-=lowbit(x);
    return tot;
}

signed main(){
    cin>>n_>>m>>s>>v;
    
    V[0].push_back({0,-INF*1.0,0});
    V[m+1].push_back({m+1,s*1.0,INF*1.0});
    for(int i=1;i<=n_;i++){
        double a,b; int r; cin>>a>>b>>r;
        if(a>=s) continue;
        b=min(b,s*1.0L);
        
        p[++n]={r,a,b};
    }
    
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++) V[p[i].r].push_back(p[i]);
    
    if(check(0,0,v,0,m+1)) return cout<<0,0;
    
    for(int i=1;i<=n;i++){
        int a=p[i].a,r=p[i].r;
        // cout<<"single "<<t<<" "<<i<<": "<<r<<" "<<pos<<" "<<id<<endl;
        
        for(int L=0;L<=m+1;L++){
            for(int R=L+1;R<=m+1;R++){
                if(check(r,a,v,L,R)) add(L,R,r,a,v);
            }
        }
        if(check(r,a,v,0,m+1)) return cout<<0,0;
    }
    for(int i=1;i<=n;i++){
        int b=p[i].b,r=p[i].r;
        
        for(int L=0;L<=m+1;L++){
            for(int R=L+1;R<=m+1;R++){
                if(check(r,b,v,L,R)) add(L,R,r,b,v);
            }
        }
        if(check(r,b,v,0,m+1)) return cout<<0,0;
    }
    for(int i=1;i<=n;i++){
        int a=p[i].a,r=p[i].r;
        for(int j=i+1;j<=n;j++){
            int bb=p[j].b,rr=p[j].r;
            if(r>=rr) continue;
            if(bb<=a) continue;
            double k=1.0*(bb-a)/(rr-r);
            if(k<v-eps) continue;
            
            // cout<<"double "<<t<<" "<<i<<": "<<r<<" "<<pos1<<" "<<id1<<", "<<rr<<" "<<pos2<<" "<<id2<<endl;
            if(check(r,a,k,r,rr)) add(r,rr,r,a,k);
            if(check(r,a,k,0,rr)) add(0,rr,r,a,k);
            if(check(r,a,k,r,m+1)) add(r,m+1,r,a,k);
            
            if(check(r,a,k,0,m+1)) return cout<<0,0;
        }
    }
    
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=id;i++){
        if(q[i].L==0) dp[i]=0;
    }
    
    // for(int i=1;i<=id;i++) cout<<dp[i]<<" ";
    // cout<<endl;
    for(int t=0;t<m;t++){
        // t -> t+1
        
        for(int fl=0;fl<=1;fl++){
            rid=0;
            for(int i=1;i<=id;i++){
                double pos1=q[i].x+(t-q[i].r)*q[i].k;
                double pos2=q[i].x+(t+1-q[i].r)*q[i].k;
                if(fl) pos1=-pos1,pos2=-pos2;
                if(q[i].L<=t && q[i].R>=t){
                    r[++rid]={pos1,pos2,i,0};
                }
                if(q[i].L<=t+1 && q[i].R>=t+1){
                    r[++rid]={pos1+eps,pos2-eps,i,1};
                }
            }
            
            sort(r+1,r+rid+1,cmp1);
            for(int i=1;i<=rid;i++) r[i].rk=i;
            sort(r+1,r+rid+1,cmp2);
            
            for(int i=1;i<=rid;i++) c[i]=INF;
            for(int i=1;i<=rid;i++){
                int id=r[i].id,rk=r[i].rk;
                if(r[i].typ) dp[id]=min(dp[id],query(rk)+1);
                else modify(rk,dp[id]);
            }
        }
        // cout<<endl;
        // for(int i=1;i<=id;i++) cout<<dp[i]<<" ";
        // cout<<endl;
    }
    
    int ans=INF;
    for(int i=1;i<=id;i++)
        if(q[i].R==m+1) ans=min(ans,dp[i]);
    if(ans==INF) cout<<-1;
    else cout<<ans;
}
