#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N=5500;
const double INF=1e18,eps=1e-7;
int n_,n,m,s,v;

struct abc{
    double a,b;
    int r;
};
bool operator <(abc X,abc Y){
    if(X.r==Y.r) return X.a<Y.a;
    return X.r<Y.r;
}

abc p[N];
vector <abc> V[13];

vector <int> trans[N];

bool chk(int r,double pos){
    int t=lower_bound(V[r].begin(),V[r].end(),(abc){pos-eps,pos-eps,r})-V[r].begin();
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

void add(int u,int v){
    // cout<<"  add "<<u<<" "<<v<<endl;
    trans[v].push_back(u);
}

int dp[N];

signed main(){
    cin>>n_>>m>>s>>v;
    V[0].push_back({-INF,0,0});
    V[m+1].push_back({s*1.0,INF,m+1});
    for(int i=1;i<=n_;i++){
        double a,b; int r; cin>>a>>b>>r;
        if(a>=s) continue;
        b=min(b,s*1.0L);
        
        p[++n]={a,b,r};
        V[r].push_back(p[n]);
    }
    if(!n){
        if(v*(m+1)<=s) cout<<0;
        else cout<<-1;
        return 0;
    }
    
    sort(p+1,p+n+1);
    for(int t=0;t<=m+1;t++) sort(V[t].begin(),V[t].end());
    
    for(int t=1;t<=n;t++){
        int a=p[t].a,b=p[t].b,r=p[t].r;
        for(int i=0;i<=1;i++){
            int pos=(i==0)?a:b;
            int id=t*2-1+i;
            // cout<<"single "<<t<<" "<<i<<": "<<r<<" "<<pos<<" "<<id<<endl;
            
            if(check(r,pos,v,0,r)) add(0,id);
            if(check(r,pos,v,r,m+1)) add(id,n*2+1);
            if(check(r,pos,v,0,m+1)){
                cout<<0;
                return 0;
            }
        }
    }
    for(int t=1;t<=n;t++){
        int a=p[t].a,b=p[t].b,r=p[t].r;
        for(int s=t+1;s<=n;s++){
            int aa=p[s].a,bb=p[s].b,rr=p[s].r;
            if(r>=rr) continue;
            
            for(int i=0;i<=1;i++){
                for(int j=0;j<=1;j++){
                    int pos1=(i==0)?a:b;
                    int pos2=(j==0)?aa:bb;
                    int id1=t*2-1+i,id2=s*2-1+j;
                    double k=1.0*(pos2-pos1)/(rr-r);
                    if(pos1>=pos2) continue;
                    if(k<v-eps) continue;
                    
                    // cout<<"double "<<t<<" "<<i<<": "<<r<<" "<<pos1<<" "<<id1<<", "<<rr<<" "<<pos2<<" "<<id2<<endl;
                    if(check(r,pos1,k,r,rr)) add(id1,id2);
                    if(check(r,pos1,k,0,rr)) add(0,id2);
                    if(check(r,pos1,k,r,m+1)) add(id1,n*2+1);
                    
                    if(check(r,pos1,k,0,m+1)){
                        cout<<0;
                        return 0;
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=n*2+1;i++){
        dp[i]=INF;
        for(int j: trans[i]){
            dp[i]=min(dp[i],dp[j]+1);
        }
        // cout<<i<<": "<<dp[i]<<endl;
    }
    if(dp[n*2+1]>=1e9) cout<<-1;
    else cout<<dp[n*2+1]-1;
}
