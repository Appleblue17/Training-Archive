#include<bits/stdc++.h>
using namespace std;
const int N=110;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair

void solve(){
    int n;
    vector<int> ans;
    vector<pii> a;
    scanf("%d",&n);
    a.push_back(mapa(1,n));
    for(int i=1;i<=n-3;i++){
        printf("? %d %d\n",i,i+2);fflush(stdout);
        int x=0;
        scanf("%d",&x);
        a.push_back(mapa(i+1,x));
    }
    a.push_back(mapa(n-1,n));
    while(1){
        int u=-1;
        for(int i=0;i<a.size();i++){
            if(a[i].se == 0)u = i;
        }
        if(u == -1){
            break;
        }
        ans.push_back(a[u-1].fi);ans.push_back(a[u+1].fi);
        a[u-1].se--;a[u+1].se--;a.erase(u+a.begin());
    }
    for(pii v:a){
        if(v.fi == 1 || v.fi == n-1)continue;
        ans.push_back(v.fi);ans.push_back(n);
    }
    printf("! ");
    for(int v:ans){
        printf("%d ",v);
    }
    putchar('\n');fflush(stdout);
    int r=0;
    scanf("%d",&r);
    if(r == 0)exit(0);
    
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}
