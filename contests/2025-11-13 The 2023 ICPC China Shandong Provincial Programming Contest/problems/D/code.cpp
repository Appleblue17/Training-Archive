#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;

int T,n;

struct abc{
    int v,w;
}a[N];

int p[N],pid;
int q[N],qid;

bool check(int k){
    pid=qid=0;
    
    for(int i=1;i<=n;i++){
        if(a[i].v<k){
            p[++pid]=a[i].w+k;
        }
        else{
            q[++qid]=a[i].v+a[i].w;
        }
    }
    sort(p+1,p+pid+1);
    sort(q+1,q+qid+1);
    
    int cur=1;
    for(int i=1;i<=pid;i++){
        while(cur<=qid && q[cur]<p[i]) cur++;
        if(cur>qid) return 0;
        cur++;
    }
    return 1;
}


signed main(){
    cin>>T;
    while(T--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].v,&a[i].w);
        
        int l=0,r=1e9,tot=l;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)) tot=mid,l=mid+1;
            else r=mid-1;
        }
        printf("%lld\n",tot);
    }
}
