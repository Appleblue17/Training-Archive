#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=3e5+5;
int n,k,d;
int a[N];

struct abc{
    int A,B,k;
    double eval(double x){
        return A+k*x;
    }
}p[N];
int id;
bool cmp1(abc X,abc Y){
    if(X.A==Y.A) return X.k>Y.k;
    return X.A>Y.A;
}
double cal(abc X,abc Y){
    int p=Y.A-X.A,q=X.k-Y.k;
    assert(q!=0);
    return 1.0*p/q;
}

int q[N],qid;
double pos[N],val[N];

double solve(){
    double tot=0;
    qid=0;
    for(int i=1;i<=id;i++){
        if(qid && p[i].B<=p[q[qid]].B) continue;
        while(qid>=2){
            int x=q[qid-1],y=q[qid];
            if(p[y].k==p[i].k) qid--;
            else if(cal(p[x],p[i])>=cal(p[y],p[i])) qid--;
            else break;
        }
        q[++qid]=i;
    }
    // cout<<" q: ";
    // for(int i=1;i<=qid;i++) cout<<q[i]<<" "; cout<<endl;
    
    pos[0]=0; val[0]=p[1].eval(0);
    for(int i=1;i<qid;i++){
        pos[i]=cal(p[q[i]],p[q[i+1]]);
        val[i]=p[q[i]].eval(pos[i]);
    }
    pos[qid]=1; val[qid]=p[q[qid]].eval(1);
    // for(int i=0;i<=qid;i++) cout<<pos[i]<<" "<<val[i]<<endl;
    
    for(int i=0;i<qid;i++){
        tot+=1.0*(pos[i+1]-pos[i])*(val[i+1]+val[i])/2;
    }
    return tot;
}


signed main(){
    cin>>n>>k;
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);
    
    double ans=0;
    for(int t=0;t<k;t++){
        id=0;
        for(int i=t;i<n;i+=k) p[++id]={a[i],a[i+1],a[i+1]-a[i]};
        sort(p+1,p+id+1,cmp1);
        
        // cout<<"start "<<t<<endl;
        // for(int i=1;i<=id;i++) cout<<p[i].A<<","<<p[i].B<<" "; cout<<endl;
        
        double tot=solve();
        // cout<<"  -> "<<tot<<endl;
        ans+=tot*id;
    }
    cout<<setprecision(9)<<fixed<<ans;
}
