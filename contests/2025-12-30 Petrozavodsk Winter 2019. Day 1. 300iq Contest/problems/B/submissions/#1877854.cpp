#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 7e5 + 5;
int n, m, a[N], argmn=1, b[N], f[N],la[N],larev[N];

vector<int> l;

int mx[N];
int M;
void change(int x, int v){
    assert(x>0&&x<=M);
    for(; x<=M; x+=(x&-x)) mx[x]=max(mx[x], v);
}
int query(int x){
    assert(x>0&&x<=M);
    int ret=-2e9;
    for(; x>0; x-=(x&-x)) ret=max(ret, mx[x]);
    return ret;
}

bool check(int x){
    l.clear();
    for(int i=1;i<=n;i++){
        l.push_back(a[i]);
        if(x-a[i]>0)l.push_back(x-a[i]);
    }
    sort(l.begin(),l.end());
    l.erase(unique(l.begin(),l.end()), l.end());
    M=l.size();
    for(int i=1;i<=n;i++){
        la[i] = lower_bound(l.begin(),l.end(),a[i])-l.begin();
        la[i]++;
        if(x-a[i]>0){
            larev[i] = lower_bound(l.begin(),l.end(),x-a[i])-l.begin();
            larev[i]++;
        }
        //printf("la[%lld]=%lld,larev[%lld]=%lld\n",i,la[i],i,larev[i]);fflush(stdout);
    }
    M++;
    for(int i=0;i<=M;i++)mx[i]=-2e9;
    //printf("M=%lld\n",M);
    
    f[1] = 1;
    //printf("la[1] = %lld\n",la[1]);
    change(la[1],1);
    for(int i=2;i<=n;i++){
        if(x - a[i] <= 0)continue;
        int tmp = query(larev[i]);
        //printf("query range %lld return %lld\n",larev[i],tmp);fflush(stdout);
        f[i] = tmp+1;
        //printf("check %lld,f[%lld]=%lld\n",x,i,f[i]);fflush(stdout);
        change(la[i],f[i]);
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        if(a[i]+a[1] <= x && f[i] == m){
            return 1;
        }
    }
    return 0;
}

signed main() {
    // freopen("Btest.in","r",stdin);
    // freopen("B.out","w",stdout);
    scanf("%lld%lld", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        if(b[i] < b[argmn]){
            argmn = i;
        }
    }
    //cout << argmn << endl;
    for(int i=1;i<=n;i++){
        a[i] = b[(i+argmn-2)%n+1];
        //printf("a[%lld]=%lld\n",i,a[i]);
    }
    
    int le=2,ri=2e9,mi=(le+ri)/2;
    while(le<ri){
        mi = (le+ri)/2;
        if(check(mi)){
            ri = mi;
        }
        else le = mi+1;
    }
    
    printf("%lld\n",le);
    
}
