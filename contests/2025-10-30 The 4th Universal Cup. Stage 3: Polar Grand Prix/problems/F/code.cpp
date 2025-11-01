#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k;
double ans;
double f[2][N];
int id;

double cal(int i,int j){
    return 1.0*i*(i+1-j)/(i+1);
}

long long calc(int k){
    long long tot=0;
    for(int i=1;i<=m;i++){
        int l=i,r=ceil(k+1.0*(n-k)/m*i);
        if(l<=r) tot+=r-l+1;
    }
    return tot;
}

int main(){
    // freopen("1.txt","w",stdout);
    cin>>n>>m;
    
    k=min(n,(int)2e8/max(1,m));
    
    int L=0,R=k;
    for(int i=L;i<=R;i++) f[0][i]=i;
    id=0;
    
    for(int j=1;j<=m;j++){
        id^=1;
        
        int pos=round(1.0*n/m*j);
        while(L<pos-k) L++;
        while(R+1<=pos+k){
            R++;
            f[id^1][R]=cal(R,j-1);
        }
        
        f[id][L-1]=0;
        for(int i=L;i<=R;i++){
            f[id][i]=max(0.0,1.0*(i*f[id][i-1]+j*f[id^1][i]+i-j)/(i+j));
        }
        
        // cout<<j<<": "<<L<<" "<<R<<endl;
        
        while(L<=R && !f[id][L]) L++;
        if(L>R){
            cout<<0;
            return 0;
        }
        
        
        // cout<<j<<" "<<L<<" "<<R<<": "<<endl;
        // for(int i=L;i<=R;i++){
        //     cout<<setw(9)<<setprecision(6)<<fixed<<f[id][i]<<" ";
        // }
        // cout<<endl;
    } 
    
    cout<<setprecision(10)<<fixed<<f[id][n];
}


