#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=110,INF=1e18;
int T,n,p;

// namespace Judge{
//     int seed,alice,cnt;
//     int gen(){
//         seed=seed*n%p;
//         // cout<<" > "<<seed<<" "<<seed%n<<endl;
//         return seed%n;
//     }
//     int tell(int bob){
//         cnt++;
//         int ret=0;
//         if(alice<bob) ret=0;
//         else if(alice==bob) ret=1;
//         else ret=2;
//         int rd=gen();
//         cout<<" > "<<(ret^rd)<<endl;
//         return ret^rd;
//     }
// }

void stop(){
    exit(0);
}

int gen(int &seed){
    seed=seed*n%p;
    // cout<<" > "<<seed<<" "<<seed%n<<endl;
    return seed%n;
}

int qry(int x){
    cout<<"? "<<x<<endl;
    
    int ret;
    // ret=Judge::tell(x);
    cin>>ret;
    if(ret==-1) stop();
    return ret;
}

inline int floor(int x,int y){
    return x/y;
}
inline int ceil(int x,int y){
    if(!x) return 0;
    return (x-1)/y+1;
}

int k=39;
int a[N];

int reg[N];

int solve(){
    for(int i=1;i<=k;i++){
        int x=(n-a[i+1])%n;
        for(int t=0;t<n;t++){
            if(p*t%n==x) reg[i]=t;
        }
    }
    
    int L=ceil(p*reg[k],n),R=floor(p*(reg[k]+1),n);
    for(int i=k;i>=1;i--){
        if(i==1) break;
        L=ceil(L+reg[i-1]*p,n);
        R=floor(R+reg[i-1]*p,n);
    }
    
    for(int i=L;i<=R;i++){
        if(i%n==a[1]) return i;
    }
    return -1;
}

int SOLVE(){
    for(int i=1;i<=k+1;i++) a[i]=qry(1);
    
    int seed=-1,cas;
    for(int t=2;t>=1 && seed==-1;t--){
        for(int i=1;i<=k+1;i++) a[i]^=t;
        seed=solve();
        if(seed!=-1) cas=t;
        for(int i=1;i<=k+1;i++) a[i]^=t;
    }
    
    // cout<<"guess seed: "<<cas<<" "<<seed<<endl;
    if(cas==1) return 1;
    
    for(int i=1;i<=k;i++) gen(seed); 
    
    // cout<<seed<<" "<<Judge::seed;
    int l=1,r=INF;
    while(l<=r){
        int mid=(l+r)>>1ll;
        int ret=qry(mid)^gen(seed);
        if(ret==1) return mid;
        if(ret==0) r=mid-1;
        else l=mid+1;
    }
    return 1;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>p;
        // cin>>Judge::seed>>Judge::alice;
        // Judge::cnt=0;
        
        int ans=SOLVE();
        cout<<"! "<<ans<<endl;
        int verd; cin>>verd;
        if(verd==-1) stop();
    }
}
