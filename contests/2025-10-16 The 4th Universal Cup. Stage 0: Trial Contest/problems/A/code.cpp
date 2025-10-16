#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;

int A,B;
int P=1,Q=1;
int f[N];

void cal(int x,int w){
    for(int i=2;i*i<=x;i++){
        if(x%i) continue;
        while(x%i==0) x/=i,f[i]+=w;
    }
    if(x>1) f[x]+=w;
}

signed main(){
    cin>>A>>B;
    cal(A,1);
    cal(B,-1);
    
    for(int i=10000;i>=2;i--){
        if(f[i]==0) continue;
        if(f[i]>0){
            if(f[i]%2==0){
                for(int t=1;t<=f[i]/2+1;t++) P*=i;
                Q*=i;
            }
            else{
                for(int t=1;t<=(f[i]+1)/2;t++) P*=i;
                cal(i-1,-1);
            }
        }
        else{
            f[i]=-f[i];
            if(f[i]%2==0){
                for(int t=1;t<=f[i]/2+1;t++) Q*=i;
                P*=i;
            }
            else{
                for(int t=1;t<=(f[i]+1)/2;t++) Q*=i;
                cal(i-1,1);
            }
        }
    }
    cout<<P<<" "<<Q;
}
