#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MP make_pair
const int N=2005,Q=5e5+5,mod=1e9+7,inv3=(mod+1)/3;
int n,q,ans[Q],w[Q];
int X[N],Y[N];

int ksm(int a,int x){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return tot;
}
void gmod(int &x){
    x%=mod;
}

struct frac{
    int x,y;
    frac(int A,int B){
        int g=abs(__gcd(B,A));
        if(B<0) g=-g;
        x=A/g,y=B/g;
    }
    frac(): x(1),y(0) {}
    int gval(){
        return (x%mod+mod)*ksm(y%mod+mod,mod-2)%mod;
    }
};
bool operator <(frac X,frac Y){
    return (__int128)X.x*Y.y<(__int128)X.y*Y.x;
}
bool operator ==(frac X,frac Y){
    return (__int128)X.x*Y.y==(__int128)X.y*Y.x;
}

struct qry{
    frac pos;
    int k,w,num;
}V[Q*2];
int id;

frac oper[N][N];
int p[N],rk[N];

priority_queue< pair<frac, int>, vector<pair<frac, int>>, greater<pair<frac, int> > > que;

void upd(int t){
    if(t<1 || t>=n) return ;
    int x=p[t],y=p[t+1];
    if(x>y) swap(x,y);
    if(oper[x][y].y) que.push(MP(oper[x][y],t));
}

int f[N][4];
int lst[N],sum[N];

int cal(int u,int x){
    int tot=0;
    for(int i=0,y=1;i<=3;i++,y=y*x%mod){
        gmod(tot+=f[u][i]*y%mod);
    }
    return tot;
}
int cal2(int u,int x){
    // deritive
    int tot=0;
    for(int i=0,y=1;i<=2;i++,y=y*x%mod){
        gmod(tot+=f[u][i+1]*y%mod*(i+1)%mod);
    }
    return tot;
}
void update(int u,int nw){
    gmod(sum[u]+=cal(u,nw)+mod-cal(u,lst[u]));
    lst[u]=nw;
}

void add(int *f,int x,int y,int w){
    int A=(x*x%mod+y*y%mod)%mod;
    int B=mod-x;
    int C=inv3;
    gmod(f[1]+=A*w%mod);
    gmod(f[2]+=B*w%mod);
    gmod(f[3]+=C*w%mod);
}

signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) scanf("%lld%lld",&X[i],&Y[i]);
    
    for(int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,[&](int x,int y){
        if(X[x]!=X[y]) return X[x]<X[y];
        return Y[x]>Y[y];
    });
    for(int i=1;i<=n;i++) rk[p[i]]=i;
    
    for(int i=1;i<=q;i++){
        int l,r,k;
        scanf("%lld%lld%lld",&l,&r,&k);
        if(l<r){
            w[i]=ksm(r-l,mod-2);
            V[++id]={(frac){l,1},k,mod-1,i};
            V[++id]={(frac){r,1},k,1,i};
        }
        else{
            V[++id]={(frac){l,1},k,0,i};
        }
    }
    sort(V+1,V+id+1,[&](qry X,qry Y){
        return X.pos<Y.pos;
    });
    
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int x=X[i],y=Y[i];
            int xx=X[j],yy=Y[j];
            if(x==xx) continue;
            frac pos={x*x+y*y-xx*xx-yy*yy,2*(x-xx)};
            oper[i][j]=pos;
        }
    }
    // for(int i=1;i<=n;i++) cout<<p[i]<<" "; cout<<endl;
    
    for(int i=1;i<n;i++){
        upd(i);
    }
    que.push(MP(frac(),0));
    
    for(int i=1;i<=n;i++){
        memcpy(&f[i],&f[i-1],sizeof(f[i-1]));
        add(f[i],X[p[i]],Y[p[i]],1);
    }
        // for(int i=0;i<=3;i++) cout<<f[1][i]<<" "; cout<<endl;
    
    int cur=0;
    while(que.size()){
        frac pos=que.top().first;
        int t=que.top().second;
        que.pop();
        
        while(cur+1<=id && V[cur+1].pos<pos){
            cur++;
            int u=V[cur].k;
            if(V[cur].w){
                int tot=sum[u];
                gmod(tot+=cal(u,V[cur].pos.gval())+mod-cal(u,lst[u]));
                
                gmod(ans[V[cur].num]+=tot*V[cur].w%mod);
                // cout<<"  query: "<<V[cur].pos.x<<"/"<<V[cur].pos.y<<": "<<tot<<endl;
            }
            else{
                gmod(ans[V[cur].num]+=cal2(u,V[cur].pos.gval()));
            }
        }
        if(!t) break;
        
        int x=p[t],y=p[t+1];  
        if(x>y) swap(x,y);
        if(!(oper[x][y]==pos)) continue;
        oper[x][y]={1,0};
        
        if(rk[x]>rk[y]) swap(x,y);
        
        update(t,pos.gval());
        
        add(f[t],X[x],Y[x],mod-1);
        add(f[t],X[y],Y[y],1);
        
        // cout<<"pos "<<pos.x<<"/"<<pos.y<<": "<<x<<" "<<y<<"  "<<rk[x]<<" "<<rk[y]<<endl;
        // cout<<" sum: "; for(int i=1;i<=n;i++) cout<<sum[i]<<" "; cout<<endl;
        // cout<<" f1: "; for(int i=0;i<=3;i++) cout<<f[1][i]<<" "; cout<<endl;
        
        swap(p[rk[x]],p[rk[y]]);
        swap(rk[x],rk[y]);
        
        upd(t-1); upd(t+1);
        
        // for(int i=1;i<=n;i++) cout<<p[i]<<" "; cout<<endl;
    }
    
    for(int i=1;i<=q;i++){
        if(!w[i]) printf("%lld\n",ans[i]);
        else printf("%lld\n",ans[i]*w[i]%mod);
    }
}
