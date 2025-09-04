#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,W=1e9;

int n,a[N];
mt19937 rng(0);

pair <int,int> b[N*20];
int id;
int f[N];

signed main(){
    // freopen("1.txt","w",stdout);
    scanf("%lld",&n);
    int mn=W,mx=0,sp;
    
    for(int i=0;i<n;i++){
        // a[i]=rng()%(W-1)+1;
        scanf("%lld",&a[i]);
        
        if(a[i]<mn) mn=a[i],sp=i;
        mx=max(mx,a[i]);
    }
    // cout<<mn<<" "<<sp<<endl;
    
    mx-=mn;
    for(int i=0;i<n;i++){
        if(i==sp) continue;
        int x=a[i]-mn;
        for(int t=1;t<=n && x*t<=mx;t++){
            b[++id]=make_pair(x*t,(i+n-sp)%n*t%n);
        }
    }
    // cout<<id<<endl;
    // return 0;
    sort(b+1,b+id+1);
    
    f[0]=0;
    for(int i=1;i<n;i++) f[i]=W;
    
    for(int t=1;t<=min(id,700ll);t++){
        int w=b[t].first,v=b[t].second;
        // cout<<w<<" "<<v<<endl;
        
        for(int i=0;i<n;i++){
            f[(i+v)%n]=min(f[(i+v)%n],f[i]+w);
        }
    }
    
    int tot=0,sum=0;
    for(int i=0;i<n;i++){
        tot+=f[i];
        sum^=f[i];
    }
    // cout<<tot<<endl<<sum<<endl;
    
    for(int i=0;i<n;i++) printf("%lld ",mn*n+f[i]);
}
