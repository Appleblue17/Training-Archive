#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int T,n;

int ksm(int a,int x,int p){
    int tot=1;
    while(x){
        if(x & 1) tot=tot*a%p;
        a=a*a%p;
        x>>=1;
    }
    return tot;
}

int pw[N],ans[N];

mt19937 rng(123);


bool solve0(){
    int lim=n,tot=0;
    pw[0]=1;
    for(int i=1;i<lim;i++) pw[i]=pw[i-1]*10%n;
    
    for(int i=0;i<=lim;i++) ans[i]=0;
    
    for(int i=1;i<=n;i++){
        int pos=rng()%lim;
        while(ans[pos]==9) pos=rng()%lim;
        ans[pos]++;
        tot=(tot+pw[pos])%n;
    }
    
    int T=n*30;
    for(int i=1;i<=T;i++){
        auto chk=[&](int x,int y,int d){
            if(!d) return (ans[x]>0 && ans[y]<9);
            else return (ans[x]<9 && ans[y]>0);
        };
        
        int x=rng()%lim,y=rng()%lim,d=rng()%2;
        while(!chk(x,y,d)) x=rng()%lim,y=rng()%lim,d=rng()%2;
        
        if(!d){
            ans[x]--,ans[y]++;
            tot=(tot+n-pw[x])%n;
            tot=(tot+pw[y])%n;
        }
        else{
            ans[x]++,ans[y]--;
            tot=(tot+pw[x])%n;
            tot=(tot+n-pw[y])%n;
        }
        if(tot==0){
            // cout<<"OK!"<<endl;
            int tp=lim-1;
            while(tp>0 && !ans[tp]) tp--;
            for(int i=tp;i>=0;i--) putchar(ans[i]+'0');
            putchar('\n');
            return 1;
        }
    }
    return 0;
}

bool solve(){
    int lim=n,tot=0;
    pw[0]=1;
    for(int i=1;i<lim;i++) pw[i]=pw[i-1]*10%n;
    
    for(int i=0;i<=lim;i++) ans[i]=0;
    
    for(int i=1;i<=n;i++){
        int pos=rng()%lim;
        while(ans[pos]==9 || pos<=5) pos=rng()%lim;
        ans[pos]++;
        tot=(tot+pw[pos])%n;
    }
    
    int T=n*30;
    for(int i=1;i<=T;i++){
        auto chk=[&](int x,int y,int d){
            if(x<=5 || y<=5) return false;
            if(!d) return (ans[x]>0 && ans[y]<9);
            else return (ans[x]<9 && ans[y]>0);
        };
        
        int x=rng()%lim,y=rng()%lim,d=rng()%2;
        while(!chk(x,y,d)) x=rng()%lim,y=rng()%lim,d=rng()%2;
        
        if(!d){
            ans[x]--,ans[y]++;
            tot=(tot+n-pw[x])%n;
            tot=(tot+pw[y])%n;
        }
        else{
            ans[x]++,ans[y]--;
            tot=(tot+pw[x])%n;
            tot=(tot+n-pw[y])%n;
        }
        if(tot==0){
            // cout<<"OK!"<<endl;
            int tp=lim-1;
            while(tp>0 && !ans[tp]) tp--;
            for(int i=tp;i>=0;i--) putchar(ans[i]+'0');
            putchar('\n');
            return 1;
        }
    }
    return 0;
}

signed main(){
    // freopen("1.txt","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        if(!solve0()){
            if(!solve()) assert(0);
        }
    }
}
