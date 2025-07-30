#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,INF=2e9;
 
int T,n,k,s,t;
 
int cal(int n,int k,int s,int t,int f){
    // cout<<n<<" "<<k<<" "<<s<<" "<<t<<" "<<f<<endl;
    if(k%2==0 && abs(s-t)%2==1) return INF;
    if(k%2==1){
        if(f==-1) f=abs(s-t)%2;
        else if(f!=abs(s-t)%2) return INF;
    }
     
    int tot=INF;
     
    if(s*2>=n){
        s=n-s,t=n-t;
    }
    if(s<k && t<k){
        if(t>=k-s && t<=k+s) tot=1;
        else tot=2;
    }
    else{
        // cout<<"AHS"<<endl;
        // cout<<s<<" "<<t<<" "<<k<<endl;
        tot=(abs(s-t)+k-1)/k;
    }
    if(f>=0 && tot%2!=f) tot++;
    return tot;
}
 
int solve(int n,int k,int s,int t){
    if(s==t) return 0;
    if(n==k){
        if(s+t==n) return 1;
        return -1;
    }
     
    int ret=INF;
    if(k*2>n){
        ret=min(ret,cal(n,n-k,s,t,0));
        ret=min(ret,cal(n,n-k,s,n-t,1));
    }
    else{
        ret=cal(n,k,s,t,-1);
    }
    if(ret==INF) return -1;
    return ret;
}
 
signed main(){
    cin>>T;
    while(T--){
        scanf("%d%d%d%d",&n,&k,&s,&t);
        int ret=solve(n,k,s,t);
        printf("%d\n",ret);
    }
     
}
