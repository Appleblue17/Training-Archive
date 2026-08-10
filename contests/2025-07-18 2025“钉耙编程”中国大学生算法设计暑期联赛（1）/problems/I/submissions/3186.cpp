#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2100000,INF=1e9;
int T,n;
int a[N];
int ans,cur;
int id[N];
inline void read(int &x){
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48), c=getchar();
}
//priority_queue <int> P,Q;

bool cmp(int x,int y){
    return a[x]<a[y];
}

void solve(){
    if(n==1){
        printf("1\n");
        return;
    }
    ans=0;
    for(int i=1;i<=n;i++)id[i]=i;
    sort(id+1,id+n+1,[&](int x, int y){return a[x]<a[y];});
    //sort(id+1,id+n+1,cmp);
    /*for(int i=1;i<=n;i++){
        printf("id[%d]=%d\n",i,id[i]);
    }*/
    int mn=min(id[n],id[n-1]),mx=max(id[n],id[n-1]);
    cur=mx-mn+1;
    for(int i=n-1;i>=1;i--){
        if(id[i]<mn){
            cur += mn-id[i]-1;
            mn=id[i];
        }
        if(id[i]>mx){
            cur += id[i]-mx-1;
            mx = id[i];
        }
        if(mn < id[i] && id[i] < mx){
            cur--;
        }
        ans = max(ans,cur);
        //printf("i=%d,mn=%d,mx=%d,cur=%d\n",i,mn,mx,cur);
    }
    printf("%d\n",ans);
}

signed main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            read(a[i]);
            //cout << a[i] << endl;
        }
        
        solve();
        /*for(int i=1;i<=n/2;i++){
            swap(a[i],a[n-i+1]);
        }
        solve();
        printf("%d\n",ans);*/
    }
    
}