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
    
    for(int l=3, r; l<=n-2; l=r+1){
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

bool f=0;

void bf(){
    int j = 2;
    //for(int i=2;i<=n-1;i++){
    //    printf("a[%lld]=%lld\n",i,a[i]);
    //}
    for(int i=4;i<=n-1;i++){
        if(i == n-1 && f)return;
        int yc=0,nc=0;
        yc += (a[j+1]-a[j])*(a[j+1]-a[j]);
        yc += (a[i]-a[i-1])*(a[i]-a[i-1]);
        if(i != n-1){
            yc += (a[i]-a[i+1])*(a[i]-a[i+1]);
        }
        
        swap(a[j],a[i]);
        nc += (a[j+1]-a[j])*(a[j+1]-a[j]);
        nc += (a[i]-a[i-1])*(a[i]-a[i-1]);
        if(i != n-1){
            nc += (a[i]-a[i+1])*(a[i]-a[i+1]);
        }
        swap(a[j],a[i]);
        //printf("j=%lld,i=%lld,yc=%lld,nc=%lld,f=%lld\n",j,i,yc,nc,f);
        if(nc > yc){
            ans++;
            
        }
    }
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
        //printf("a[%lld]=%lld,b[%lld]=%lld\n",i,a[i],i,b[i]);
    }
    for(int i=2;i<=n-2;i++){
        if(i != 2 && i != n-2 && (a[i+1]-a[i])*(b[i+1]-b[i]) > 0)ans--;
        int yc = 0,nc = 0;
        if(i != n-2){
            yc += (a[i+2]-a[i+1])*(a[i+2]-a[i+1]);
            nc += (a[i+2]-a[i])*(a[i+2]-a[i]);
        }
        if(i != 2){
            yc += (a[i]-a[i-1])*(a[i]-a[i-1]);
            nc += (a[i+1]-a[i-1])*(a[i+1]-a[i-1]);
        }
        
        if(nc > yc){
            //printf("xl i=%lld\n",i);
            ans++;
        }
    }
    //cout << '*' << endl;
    //cout << ans << endl;
    f=0;
    bf();
    //cout << ans << endl;
    for(int i=2;i<=n/2;i++){
        swap(a[i],a[n-i+1]);
    }
    f=1;
    bf();
    for(int i=2;i<=n/2;i++){
        swap(a[i],a[n-i+1]);
    }
    //cout << '(' << endl;
    //cout << ans << endl;
    if(n-1 > 3){
        sort(id+3,id+n-1,cmp);
    }
    
    //cout << ')' << endl;
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