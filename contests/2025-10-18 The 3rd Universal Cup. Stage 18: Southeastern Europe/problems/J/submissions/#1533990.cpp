#include <bits/stdc++.h>
using namespace std;
const int N=110000,INF=1e9;
int n,num;
int a[N],rem[N];
vector<int> g[N];

bool check(int i){
    int c[5];
    c[2] = a[i];
    c[3] = a[(i)%n+1];
    c[4] = a[(i+1)%n+1];
    c[1] = a[(i-2+n)%n+1];
    c[0] = a[(i-3+n)%n+1];
    if(c[2]==c[0])return 1;
    if(c[2]==c[1])return 1;
    if(c[2]==c[3])return 1;
    if(c[2]==c[4])return 1;
    int cmp[6];
    cmp[0] = c[2]>c[1];cmp[1] = c[2]>c[3];if(cmp[0]+cmp[1] != 1)return 1;
    cmp[1] = c[2]>c[0];if(cmp[0]+cmp[1] != 1)return 1;
    cmp[0] = c[2]>c[4];cmp[1] = c[2]>c[3];if(cmp[0]+cmp[1] != 1)return 1;
    return 0;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        g[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        int ans = n - g[a[i]].size();
        if(rem[a[i]]){
            printf("%d ",rem[a[i]]);
            continue;
        }
        bool f=0;
        for(int v:g[a[i]]){
            if(check(v))f=1;
        }
        if(!f)ans++;
        rem[a[i]]=ans;
        printf("%d ",ans);
    }
    
}
