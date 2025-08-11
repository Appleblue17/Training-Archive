#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mo1=1e9+7,mo2=1e9+9,bas=1e9+1;

void read(int &x){
    char c=getchar();
    x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48), c=getchar();
}
int n,k;
int a[N],va[N],b[N],vb[N];
int pos[N];

bool bit[N];
int sm1[N],sm2[N];

inline int lowbit(int x){
    return x & (-x);
}
void add(int x){
    while(x<=n){
        bit[x]^=1;
        x += lowbit(x);
    }
}
bool query(int x){
    bool ret=0;
    while(x>0){
        ret ^= bit[x];
        x -= lowbit(x);
    }
    return ret;
}


bool solve(){
    read(n),read(k);
    for(int i=0;i<=n;i++) bit[i]=0;
    
    for(int i=1;i<=n;i++) read(a[i]),va[i]=a[i];
    for(int i=1;i<=n;i++) read(b[i]),vb[i]=b[i];
    sort(va+1,va+n+1);
    sort(vb+1,vb+n+1);
    
    for(int i=1;i<=n;i++) if(va[i]!=vb[i]) return 0;
    
    int vid=unique(va+1,va+n+1)-va-1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(va+1,va+vid+1,a[i])-va;
        b[i]=lower_bound(va+1,va+vid+1,b[i])-va;
    }
    
    bool fl=1;
    for(int i=1;i<n && fl;i++) if(va[i]==va[i+1]) fl=0;
    
    if(k%2==1 && fl){
        for(int i=1;i<=n;i++) pos[a[i]]=i;
        
        bool inv=0;
        for(int i=n;i>=1;i--){
            int x=pos[b[i]];
            inv ^= query(x);
            add(x);
        }
        if(inv){
            return 0;
        }
    }
    
    if(k<n) return 1;
    
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    
    // for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
    // for(int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
    
    //cout << '&' << endl;
    sm1[0]=sm2[0]=0;
    for(int i=1;i<=n*2;i++){
        sm1[i]=(1ll*sm1[i-1]*bas+a[i])%mo1;
        sm2[i]=(1ll*sm2[i-1]*bas+a[i])%mo2;
        //cout << a[i]<<" "<<sm1[i] << endl;
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        ans1 = (1ll*ans1*bas+b[i])%mo1;
        ans2 = (1ll*ans2*bas+b[i])%mo2;
    }
    
    int pwn1=1,pwn2=1;
    for(int i=1;i<=n;i++){
        pwn1=1ll*pwn1*bas%mo1;
        pwn2=1ll*pwn2*bas%mo2;
    }
    
    for(int i=n;i<=n*2;i++){
        // cout << (sm1[i]-1ll*sm1[i-n]*pwn1+mo1)%mo1 << ' ' << ans1 << endl;
        
        if((sm1[i]-1ll*sm1[i-n]*pwn1%mo1+mo1)%mo1 == ans1
            && (sm2[i]-1ll*sm2[i-n]*pwn2%mo2+mo2)%mo2 == ans2)
                return 1;
    }
    return 0;
}
signed main(){
    int T; read(T);
    while(T--){
        if(solve()) printf("YES\n");
        else printf("NO\n");
    }
}