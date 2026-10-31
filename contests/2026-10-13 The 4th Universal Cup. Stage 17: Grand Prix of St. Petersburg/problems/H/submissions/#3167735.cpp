#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m;
int a[N];
int p[N];

void prufer(){
    int len=0;
    priority_queue<int> pq;
    for(int i=1; i<=n; ++i){
        if(a[i]==1) pq.push(i);
        else{
            for(int j=1; j<a[i]; ++j) p[++len]=i;
        }
    } 
    printf("YES\n");
    for(int i=1; i<=len; ++i){
        int x=pq.top(); pq.pop();
        printf("%d %d\n", x, p[i]);
        --a[p[i]];
        if(a[p[i]]==1) pq.push(p[i]);
    }
    int x=pq.top(); pq.pop();
    int y=pq.top(); pq.pop();
    printf("%d %d\n", x, y);
}
void solve(){
    scanf("%d%d", &n, &m);
    int sum=0, cnt=0;
    if(n==1){
        scanf("%d", &a[1]);
        if(a[1]==0||a[1]==-1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
        return ;
    }
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        if(a[i]==0) a[i]=m;
        if(a[i]==-1) ++cnt;
        else sum+=a[i];
    }
    if(sum+cnt>2*n-2){
        printf("NO\n");
        return ;
    }
    if(cnt==0&&(sum+2-2*n)%m!=0){
        printf("NO\n");
        return ;
    }
    if(cnt!=0){
        int res=2*n-2-sum;
        for(int i=1; i<=n; ++i){
            if(a[i]==-1){
                --cnt;
                a[i]=min(n-1, res-cnt);
                res-=a[i];
            }
        }
    }
    else{
        int res=2*n-2-sum;
        for(int i=1; i<=n; ++i){
            int w=min(res, n-1-a[i]);
            w/=m; w*=m;
            a[i]+=w; res-=w;
        }
    }
    prufer();
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}