#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=66;
int n;
int A[N],cnt;
int ans[N];

mt19937_64 rng(123);
int rd(){
    return rng() & ((1ll<<n)-1);
}

struct bas{
    int d[N];
    bas(){
        memset(d,0,sizeof(d));
    }
    bool ins(int x){
        for(int t=n-1;t>=0;t--){
            if(!(x>>t & 1ll)) continue;
            if(!d[t]){
                d[t]=x;
                for(int i=t+1;i<n;i++){
                    if(d[i]>>t & 1ll) d[i]^=x;
                }
                return 1;
            }
            x^=d[t];
        }
        return 0;
    }
    int cal(int x){
        int tot=0;
        for(int i=0;i<n;i++){
            if(x>>i & 1) tot^=d[i];
        }
        return tot;
    }
    bool check(int x){
        for(int t=n-1;t>=0;t--){
            if(x>>t & 1ll){
                if(!d[t]) return 0;
                x^=d[t];
            }
        }
        return 1;
    }
    int gen(){
        int tot=0;
        while(!tot){
            tot=cal(rd());
        }
        return tot;
    }
    
    void pr(){
        cout<<"pr"<<endl;
        for(int t=n-1;t>=0;t--){
            for(int i=n-1;i>=0;i--) putchar((d[t]>>i & 1)+'0');
            cout<<endl;
        }
        
    }
}F[N],G;

int qry(int *B){
    cout<<"? ";
    for(int i=1;i<=n;i++) cout<<B[i]<<" "; cout<<endl;
    int ret=0;
    
    cin>>ret;
    
    // bas tmp;
    // for(int i=1;i<=n;i++) ret+=tmp.ins(A[i]^B[i]);
    // ret=(1ll<<ret);
    
    
    ret=__lg(ret);
    // cout<<" > "<<ret<<endl;
    cnt++;
    return ret;
}


int p[N],id;

int V[N];

int bias[N];

vector <int> P;

map <int,int> mp;

signed main(){
    cin>>n;
    // for(int i=1;i<=n;i++) cin>>A[i];
    // for(int i=1;i<=n;i++) A[i]=0;
    
    
    for(int i=1;i<=n;i++) P.push_back(i);
    int rk=qry(V);
    while(rk<n){
        int pos=rng()%P.size();
        int x=P[pos];
        cnt++;
        V[x]=rd();
        int nrk=qry(V);
        if(nrk>rk){
            rk=nrk;
            P.erase(P.begin()+pos);
        }
        else V[x]=0;
    }
    
    
    // cout<<"begin: "; for(int i=0;i<n;i++) cout<<V[i]<<" "; cout<<endl;
    // return 0;
    for(int i=0;i<n;i++) F[n].ins(1ll<<i);
    // F[n].pr();
    
    for(int t=n;t>=1;t--){
        int b=0;
        while(1){
            int x=F[t].gen();
            V[t]^=x;
            int ret=qry(V);
            V[t]^=x;
            
            if(ret<n){
                b=x;
                break;
            }
        }
        
        bias[t]=b;
        // cout<<" get b: "<<b<<endl;
        id=0;
        for(int i=0;i<n;i++)
            if(F[t].d[i]) p[id++]=F[t].d[i];
        assert(id==t);
        
        G=bas();
        for(int i=1;i<=t-1;i++){
            
            
            // int c=0;
            mp.clear();
            while(1){
                // c++;
                int x=0;
                do{
                    x=rng() & ((1ll<<id)-1);
                }while(G.check(x) || mp[x]);
                mp[x]=1;
                
                int y=0;
                for(int j=0;j<id;j++) if(x>>j & 1ll) y^=p[j];
                
                // cout<<" ask "<<x<<" "<<y<<endl;
                
                V[t]^=(b^y);
                int ret=qry(V);
                // cnt++;
                V[t]^=(b^y);
                if(ret<n){
                    // cout<<"  ! "<<x<<" "<<y<<endl;
                    G.ins(x);
                    // G.pr();
                    break;
                }
            }
            // cout<<i<<": "<<c<<endl;
        }
        
        for(int i=0;i<n;i++){
            if(G.d[i]){
                int x=G.d[i],y=0;
                for(int j=0;j<id;j++) if(x>>j & 1ll) y^=p[j];
                
                F[t-1].ins(y);
            }
        }
        
        // cout<<" result of "<<t<<": "<<endl;
        // F[t-1].pr();
        
        // for(int i=0;i<n;i++) cout<<V[i]<<" "; cout<<endl;
    }
    
    for(int t=1;t<=n;t++){
        V[t]^=bias[t];
        
        int tot=0;
        for(int i=1;i<t;i++){
            V[i]^=ans[i];
            int ret=qry(V);
            V[i]^=ans[i];
            if(ret==n-1) tot^=ans[i];
        }
        
        V[t]^=bias[t];
        ans[t]=bias[t]^tot;
        
        // cout<<" ! find "<<t<<" = "<<ans[t]<<endl;
    }
    
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<(ans[i]^V[i])<<" "; cout<<endl;
    
    // cout<<cnt;
}
