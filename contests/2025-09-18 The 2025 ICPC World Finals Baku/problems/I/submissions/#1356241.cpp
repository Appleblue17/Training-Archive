#include<bits/stdc++.h>
using namespace std;
const int N=55;

int n,X;
int A[N];
bool buc[N];
int inter(){
    memset(buc,0,sizeof(buc));
    int tot=0;
    for(int i=1;i<=n;i++){
        if(!buc[A[i]]) tot++,buc[A[i]]=1;
    }
    
    return tot;
}

void qry(int x,int y){
    cout<<x<<" "<<y<<endl;
    cin>>X;
    // A[x]=(A[x]+y)%n;
    // X=inter();
    // cout<<" > "<<X<<endl;
}

mt19937 rng(114514);

int p[N][N],f[N][N];
void cal(int t){
    int st=X,mx=0;
    for(int i=0;i<n;i++){
        p[t][i]=X;
        mx=max(mx,X);
        qry(t,1);
    }
    if(mx==st){
        for(int i=0;i<n;i++) f[t][i]=(p[t][i]==st-1);
        f[t][0]=1;
    }
    else{
        for(int i=0;i<n;i++) f[t][i]=(p[t][i]==st);
    }
    
    // cout<<" finish "<<t<<": ";
    // for(int i=0;i<n;i++) cout<<f[t][i]<<" "; cout<<endl;
}

bool check(){
    cal(1);
    for(int d=1;d<n;d++){
        if(n%d) continue;
        bool fl=1;
        for(int i=0;i<n && fl;i++){
            if(f[1][i]!=f[1][(i+d)%n]) fl=0;
        }
        if(fl) return 0;
    }
    return 1;
}

int ans[N];
int main(){
    // cin>>n;
    // for(int i=1;i<=n;i++) cin>>A[i];
    // X=inter();
    
    cin>>n>>X;
    
    while(1){
        if(check()) break;
        for(int i=2;i<=n;i++){
            int x=rng()%n;
            qry(i,x);
        }
        // for(int i=1;i<=n;i++) cout<<A[i]<<" "; cout<<endl;
    }
    
    for(int t=2;t<=n;t++){
        cal(t);
        for(int d=0;d<n;d++){
            bool fl=1;
            for(int i=0;i<n && fl;i++){
                if(f[t][i]!=f[1][(i+d)%n]) fl=0;
            }
            if(fl){
                ans[t]=d;
                break;
            }
        }
    }
    
    // cout<<"! ";
    // for(int t=1;t<=n;t++) cout<<ans[t]<<" "; cout<<endl;
    
    for(int t=1;t<=n;t++){
        qry(t,(n-ans[t])%n);
    }
    
}
