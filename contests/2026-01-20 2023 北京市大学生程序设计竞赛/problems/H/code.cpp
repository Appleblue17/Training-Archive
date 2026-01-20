#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+5;

int a[N],id[N],sgn[N];

bool cmp(int i,int j){
    return a[i]<a[j];
}

signed main(){
    int n;
    scanf("%lld",&n);
    for(int i=1;i<=n*2;i++){
        scanf("%lld",&a[i]);
        id[i]=i;
    }
    
    sort(id+1,id+n*2+1,cmp);
    
    int ans=0,sub=0,lm1=0,rm1=0;
    bool sa=0;
    lm1 = a[id[n]],rm1 = a[id[n+1]];
    for(int i=1;i<=n*2;i++){
        if(a[i]<=lm1)sgn[i]=-1;
        else sgn[i]=1;
        if(i<=n)ans += a[id[n*2+1-i]]-a[id[i]];
        //printf("%lld %lld\n",a[id[n*2+1-i]],a[id[i]]);
    }
    bool f=0;
    for(int i=1;i<=n*2;i+=2){
        if(a[i]==lm1 && a[i+1]==rm1)sa=1;
        if(a[i]==rm1 && a[i+1]==lm1)sa=1;
        if(sgn[i] == 1 && sgn[i+1] == -1)sub += a[i]-a[i+1];
        if(sgn[i] == sgn[i+1])f=1;
    }
    
    //printf("ans=%lld,sub=%lld,sa=%lld\n",ans,sub,sa);
    
    if(f){
        printf("%lld\n",ans);
    }
    else{
        
        sub = min(sub,ans-sub);
        int fans = ans-sub*2;
        
        if(n != 1){
            
            if(sa){
                fans = max(fans,ans-2*min(a[id[n+2]]-a[id[n]],a[id[n+1]]-a[id[n-1]]));
            }
            else{
                fans = max(fans,ans - 2*(rm1-lm1));
            }
            
            
        }
        
        printf("%lld\n",fans);
        
    }
    
    
    
}
