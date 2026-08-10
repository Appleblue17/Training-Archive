#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,INF=1e18;
int T,n,m;
int A[N],sm[N],ans;
vector<int> g[N];

inline void read(int& x){
    x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar())f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
        x=(x<<1)+(x<<3)+(c^48);
    x=(f)?(-x):x;
}   

void dfs(int u){
    sm[u]=0;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        dfs(v);
        sm[u] += sm[v];
        if(v > u && u != 1){
            ans += sm[v];
            //printf("sm[%lld]=%lld,ans updated.",v,sm[v]);
        }
    }
    sm[u] += A[u];
}

signed main(){
    cin>>T;
    while(T--){
        //cout << '*' << endl;
        cin >> n;
        
        int tmp=0;
        for(int i=1;i<=n;i++){
            //scanf("%lld",&A[i]);
            read(A[i]);
            g[i].clear();
            if(i != 1)
                tmp += A[i];
            //printf("tmp = %lld\n",tmp);
        }
        
        //cout << '*' << endl;
        for(int i=2;i<=n;i++){
            int x;
            read(x);
            //scanf("%lld",&x);
            g[x].push_back(i);
        }
        
        //printf("tmp = %lld\n",tmp);
        if(tmp < 0)tmp = -1;
        if(tmp > 0)tmp = 1;
        if(tmp != 0){
            printf("%lld\n",tmp);
            continue;
        }
        
        ans = 0;
        dfs(1);
        
        
        
        if(ans > 0)printf("-1\n");
        else if(ans < 0)printf("1\n");
        else printf("0\n");
        
    }
    
    
}