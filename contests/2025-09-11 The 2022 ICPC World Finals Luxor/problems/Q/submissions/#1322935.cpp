#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;

int n;
int p[N];

int lowbit(int x){
    return x & (-x);
}
int c[N];
void modify(int x,int k){
    while(x<N) c[x]+=k,x+=lowbit(x);
}
int query(int x){
    int tot=0;
    while(x) tot+=c[x],x-=lowbit(x);
    return tot;
}
int qry(int l,int r){
    return query(r)-query(l-1);
}

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
    p[0]=n+1;
    
    for(int i=1;i<=n;i++) modify(i,1);
    
    int ans=0;
    for(int i=0;i<n;i++){
        int x=p[i],y=p[i+1];
        modify(y,-1);
        
        int tot1=0,tot2=0;
        if(x<y){
            tot1+=qry(x,y)+qry(y,n);
            // if(i>0){
            //     int z=p[i-1];
            //     if(z<x) tot2+=1;
            //     else if(x<z && z<y) tot2+=0;
            //     else tot2+=0;
            // }
        }
        else{
            tot1+=qry(y,x)+qry(x,n);
            // if(i>0){
            //     int z=p[i-1];
            //     if(z<y) tot2+=1;
            //     else if(y<z && z<x) tot2+=1;
            //     else tot2+=1;
            // }
        }
        
        ans+=tot1+tot2;
        
        // cout<<i<<": "<<tot1<<" "<<tot2<<endl;
    }
    cout<<ans*0.5+n;
}
