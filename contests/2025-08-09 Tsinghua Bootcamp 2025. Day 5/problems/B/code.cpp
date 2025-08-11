#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Pii pair<int,int>
#define MP make_pair
const int N=4e5+5,mod=998244353;
int n,m;
vector <int> P0,P1,Q0,Q1;
int s0,s1;

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
int mul[N];
void init(int lim){
    mul[0]=1;
    for(int i=1;i<=lim;i++) mul[i]=mul[i-1]*i%mod;
}

signed main(){
    init(N-5);
    
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        int x; char typ;
        scanf("%lld %c",&x,&typ);
        if(typ=='D') P0.push_back(x),s0+=x;
        else P1.push_back(x);
    }
    for(int i=1;i<=m;i++){
        int x; char typ;
        scanf("%lld %c",&x,&typ);
        if(typ=='D') Q0.push_back(x),s1+=x;
        else Q1.push_back(x);
    }
    
    int tot1=0,tot2=0;
    if(P1.size()){
        for(int x: P1){
            if(s0+x>s1){
                gmod(tot1+=mul[P1.size()-1]);
            }
        }
    }
    else tot1=1;
    
    if(Q1.size()){
        for(int x: Q1){
            if(s1+x>s0){
                gmod(tot2+=mul[Q1.size()-1]);
            }
        }
    }
    else tot2=1;
    // cout<<tot1<<" "<<tot2<<endl;
    
    int ans=tot1*tot2%mod*mul[P0.size()]%mod*mul[Q0.size()]%mod;
    cout<<ans;
}