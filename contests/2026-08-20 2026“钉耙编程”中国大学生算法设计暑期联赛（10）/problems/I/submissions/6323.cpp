#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//#define int long long
int T, n, c, s, S[2], ans;
int cnt[4];
void proc(int o,int d){
    //printf("proc %d %d\n",o,d);
    if(d == 1){
        if(S[o] >= c)ans++;
        if(S[o] >= -c)ans++;
    }
    else{
        if(S[o] <= c)ans--;
        if(S[o] <= -c)ans--;
    }
    S[o] += d;
}
void solve(){
    cin>>n >> c;
    memset(cnt,0,sizeof(cnt));
    //printf("n=%d\n",n);
    for(int i=1;i<=n;i++){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        if(t == 0)continue;
        if(t == a && t == b)cnt[2]++;
        if(t != a && t != b)cnt[3]++;
        if(t == a && t != b)cnt[1]++;
        if(t != a && t == b)cnt[0]++;
    }
    
    ans = 0;
    S[0]=S[1]=0;
    
    if(cnt[0] < cnt[1])swap(cnt[0],cnt[1]);
    //cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << endl;
    s=cnt[2];
    while(cnt[2]){
        cnt[2]--;
        proc(0,1);proc(1,1);
    }
    
    //if(s <= c){
    //printf("c=%d,s=%d\n",c,s);
        for(int i=1;i<=c-s+1;i++){
            if(cnt[0] <= 0)break;
            proc(0,1);proc(1,-1);
            cnt[0]--;
        }
        while(cnt[0] > 0 && cnt[1] > 0){
            proc(0,-1);proc(1,1);
            cnt[1]--;
            proc(0,1);proc(1,-1);
            cnt[0]--;
        }
        while(cnt[0]>0){
            proc(0,1);proc(1,-1);
            cnt[0]--;
        }
        while(cnt[1]>0){
            proc(0,-1);proc(1,1);
            cnt[1]--;
        }
    //}
    //else{
        
    //}
    
    
    while(cnt[3]){
        proc(0,-1);proc(1,-1);
        cnt[3]--;
    }
    
    printf("%d\n",ans);
    
    
}
signed main(){
    //ios::sync_with_stdio(false);
    
    cin>>T;
    while(T--){
        solve();
    }
}