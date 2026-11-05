#include<bits/stdc++.h>
using namespace std;
const int N=550;
int T,n;
int a[N];

namespace Judger{
    const bool DEBUG=0;
    int cnt=0;
    int s[N];
    void init(){
        if(!DEBUG) return ;
        for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
        cnt=0;
    }
    
    bool ask(int x,int y){
        cnt++;
        printf("? %d %d\n",x,y);
        fflush(stdout);
        int res;
        if(DEBUG){
            res=(a[x]>a[y]);
            // cout<<"> "<<res<<endl;
        }
        else scanf("%d",&res);
        return res;
    }
    
    void check(vector <int> &S){
        if(!DEBUG) return ;
        if(S.size()!=n) cout<<"Wrong size != n: "<<S.size()<<endl;
        for(int i=0;i+1<S.size();i++){
            if(s[S[i]]>s[S[i+1]]) cout<<" Wrong order: "<<i<<" "<<s[S[i]]<<" > "<<s[S[i+1]]<<endl;
        }
        if(cnt>2*n-3) cout<<"Query Exceed: "<<cnt<<" > "<<2*n-3<<endl;
    }
}
using Judger::ask;

vector <int> ANS;

bool f[N],g[N];

vector <int> solve0(vector <int> &V,int st){
    // cout<<" sub input: "; for(int x: V) cout<<x<<" "; cout<<endl;
    
    int m=V.size();
    
    int k=-1;
    for(int i=st+1;i<m;i++){
        if(ask(V[i-1],V[i])){
            k=i;
            break;
        }
    }
    if(k==-1) return V;
    
    vector <int> P,Q,S;
    for(int i=k+1;i<m;i++){
        if(ask(V[k],V[i])) P.push_back(V[i]); // a[V[i]]=0
        else Q.push_back(V[i]);
    }
    
    S.push_back(V[k]);
    for(int x: P) S.push_back(x);
    for(int i=0;i<k;i++) S.push_back(V[i]);
    for(int x: Q) S.push_back(x);
    assert(S.size()==V.size());
    // cout<<" sub output: "; for(int x: S) cout<<x<<" "; cout<<endl;
    return S;
}


void solve(){
    int k=-1;
    for(int i=2;i<=n;i++){
        if(ask(i,i-1)){ // a[i-1]<a[i]
            k=i;
            break;
        }
    }
    if(k==-1){
        for(int i=n;i>=1;i--) ANS.push_back(i);
        return ;
    }
    // cout<<" get k = "<<k<<endl;
    
    vector <int> P,Q,V0,V;
    for(int i=k+1;i<=n;i++){
        if(!ask(i,k-1)){ // a[i]<=a[1]
            if(ask(k-1,i)) Q.push_back(i); // a[1]>a[i]
            else P.push_back(i); // a[i]=a[1]
        }
        else V0.push_back(i);
    }
    // cout<<" P: "; for(int x: P) cout<<x<<" "; cout<<endl;
    // cout<<" Q: "; for(int x: Q) cout<<x<<" "; cout<<endl;
    
    int d=k-2;
    while(d>0 && ask(k,d)) d--; // until a[d]>=a[k]
    
    // cout<<"d = "<<d<<endl;
    V.push_back(k);
    for(int i=d;i>=1;i--) V.push_back(i);
    for(int x: V0) V.push_back(x);
    // cout<<" V: "; for(int x: V) cout<<x<<" "; cout<<endl;
    
    for(int x: Q) ANS.push_back(x);
    for(int x: P) ANS.push_back(x);
    for(int i=k-1;i>d;i--) ANS.push_back(i);
    
    vector <int> S=solve0(V,d);
    for(int x: S) ANS.push_back(x);
}


signed main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d", &n);
        Judger::init();
        
        ANS.clear();
        solve();
        
        printf("! ");
        for(int x: ANS) printf("%d ",x);
        printf("\n");
        fflush(stdout);
        
        Judger::check(ANS);
        
    }
}