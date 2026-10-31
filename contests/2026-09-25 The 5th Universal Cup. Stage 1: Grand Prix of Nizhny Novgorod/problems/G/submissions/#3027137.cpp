#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=5e5+5,mod=998244353;
int k,n,alc;
vector <int> P,Q;

mt19937 rng(123);

vector <int> ANS;

void check(){
    int s=0;
    for(int x: ANS){
        if((s^x)>s) s^=x;
    }
    cout<<"check: "<<s<<endl;
}

signed main(){
    cin>>k>>n;
    alc=(1<<k)-1;
    for(int i=1;i<=n;i++){
        int x; scanf("%d",&x);
        if(x>>(k-1) & 1) Q.push_back(x);
        else P.push_back(x);
    }
    // cout<<P.size()<<" "<<Q.size()<<endl;
    
    while(1){
        shuffle(P.begin(),P.end(),rng);
        
        int s=0;
        for(int x: P){
            if((s^x)>s) s^=x;
        }
        // cout<<s<<endl;
        
        for(int i=0;i<Q.size();i++){
            int x=Q[i];
            if((s^x)==(1<<(k-1))){
                for(int x: P) ANS.push_back(x);
                ANS.push_back(Q[i]);
                for(int j=0;j<Q.size();j++){
                    if(j!=i) ANS.push_back(Q[j]);
                }
                
                // check();
                
                for(int x: ANS) printf("%d ",x);
                return 0;
            }
        }
        
    }
    
    
}