#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int T,n;
int a[N],b[N],id[N];

bool cmp(int x,int y){
    if(a[x] == a[y])return x<y;
    else return a[x] < a[y]; 
}

int rd(){
    char c=getchar();
    int tot=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}

int bit[N];

#define lowbit(x) (x&(-x))

void add(int x){
    for(;x<N;x+=lowbit(x)){
        bit[x]++;
    }
}

int query(int x){
    int ans=0;
    for(;x>0;x-=lowbit(x)){
        ans+=bit[x];
    }
    return ans;
}

//const int M = 2e5+2;

int ans=0;

void calc(){
    
    memset(bit,0,sizeof(bit));
    
    for(int l=2, r; l<n; l=r+1){
        r=l;
        while(r+1<n&&a[id[r+1]]==a[id[l]]) ++r;
        for(int i=l; i<=r; ++i){
            ans+=query(b[id[i]]-1);
        }
        for(int i=l; i<=r; ++i){
            //cout << id[i] << endl;
            //cout<<b[id[i]]<<endl;
            add(b[id[i]]);
        }
        // ans += query(b[i]+M);
        // add(b[i]+M);
    }

    printf("%lld\n",ans);
    
    
}

void solve(){
    n=rd();
    n+=2;
    ans=0;
    a[1] = a[n] = 0;
    for(int i=2;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=2;i<n;i++){
        b[i] = a[i-1]+a[i+1];
        id[i] = i;
    }
    for(int i=2;i<n-1;i++){
        if((a[i+2]-a[i-1]) * (a[i+1]-a[i]) > 0){
            ans++;
        }
    }
    sort(id+2,id+n);
    
    calc();
    
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    T=rd();
    while(T--){
        solve();
    }
    
}