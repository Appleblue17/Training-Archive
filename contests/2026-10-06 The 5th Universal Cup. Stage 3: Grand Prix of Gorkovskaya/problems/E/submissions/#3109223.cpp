#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int T,L,R;


int pr[N],id;
int phi[N];
bool vis[N];
void init(int lim){
    phi[1]=1;
    for(int i=2;i<=lim;i++){
        if(!vis[i]) pr[++id]=i,phi[i]=i-1;
        for(int j=1;j<=id && i*pr[j]<=lim;j++){
            vis[i*pr[j]]=1;
            if(i%pr[j]) phi[i*pr[j]]=phi[i]*(pr[j]-1);
            else{
                phi[i*pr[j]]=phi[i]*pr[j];
                break;
            }
        }
    }
}


bool solve(){
    // if(R<=500){
    //     for(int i=L;i<=R;i++){
    //         for(int j=i+1;j<=R;j++){
    //             if(phi[i]==phi[j]){
    //                 cout<<i<<" "<<j<<endl;
    //                 return 1;
    //             }
    //         }
    //     }
    //     return 0;
    // }
    
    int x=(L-1)/3+1;
    while(x%3==0 || x%2==0) x++;
    if(x*4>R){
        for(int i=L;i<=R;i++){
            for(int j=i+1;j<=R;j++){
                if(phi[i]==phi[j]){
                    cout<<i<<" "<<j<<endl;
                    return 1;
                }
            }
        }
        return 0;
    }
    
    cout<<3*x<<" "<<4*x<<endl;
    return 1;
}

signed main(){
    init(N-5);
    cin>>T;
    while(T--){
        cin>>L>>R;
        if(!solve()) cout<<"-1 -1"<<endl;
    }
}