#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
int n;
int b[N];
__int128 calc(int x){
    if(x==-1) return -1;
    int t=1, pw=1;
    while((__int128)pw*n<=x) ++t, pw*=n;
    __int128 ret=0;
    if(t>0){
        ret=(t-1)*pw-(pw-1)/(n-1);
    }
    ret+=(x-pw+1)*t;
    return ret;
}
int a[N];
bool check(int x){
    if(x==-1) return false;
    int t=0, pw=1;
    while((__int128)pw*n<=x) ++t, pw*=n;
    for(int i=t; i>=0; --i){
        int k=x/pw;
        if(k==0){
            a[0]+=x+1;
            pw/=n;
            continue;
        }
        for(int j=0; j<n; ++j) a[j]+=k*i*pw/n;
        for(int j=1; j<k; ++j) a[j]+=pw;
        a[k]+=(x-k*pw+1);
        int pw2=1;
        for(int j=0; j<i; ++j) a[0]-=pw2, pw2*=n;
        x-=k*pw; 
        if(i!=t) a[0]+=(pw*n-1)/(n-1);
        pw/=n;
    }
    // for(int i=0; i<n; ++i) cout<<a[i]<<endl;
    for(int i=0; i<n; ++i) if(a[i]!=b[i]) return false;
    return true;
}
signed main(){
    scanf("%lld", &n);
    int sum=0;
    for(int i=0; i<n; ++i) scanf("%lld", &b[i]), sum+=b[i];
    int L=1, R=1e14, mid, ret=-1;
    while(L<=R){
        mid=(L+R)/2ll;
        // cout<<L<<' '<<R<<endl;
        if(calc(mid)>=sum){
            ret=mid; R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    if(calc(ret)!=sum) ret=-1;
    if(!check(ret)) ret=-1;
    printf("%lld\n", ret);
}