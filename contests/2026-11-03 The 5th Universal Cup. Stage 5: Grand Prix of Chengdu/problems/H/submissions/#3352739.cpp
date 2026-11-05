#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
const int N=505;
int T, n, m;
// int a[N];
// int asktimes;
bool ask(int x, int y){
    // ++asktimes;
    printf("? %d %d\n", x, y);
    fflush(stdout);
    bool ret;
    cin>>ret;
    // ret=a[x]>a[y];
    return ret;
}
int sgn[N];
int lp[N], rp[N];
int deg[N];
vector<int> e[N];
void solve(){
    // asktimes=0;
    scanf("%d", &n);
    // for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    bool flg=0;
    for(int i=1; i<n; ++i){
        sgn[i]=ask(i, i+1);
        if(sgn[i]) flg=1;
    }
    if(!flg){
        printf("!");
        for(int i=1; i<=n; ++i) printf(" %d", i);
        printf("\n");
        fflush(stdout);
        // cout<<"asktimes:"<<asktimes<<endl;
        return ;
    }
    for(int i=1; i<n; ++i){
        if(sgn[i]==0){
            if(!ask(i+1, i)){
                sgn[i]=2;
            }
        }
    }
    vector<int> rt;
    for(int l=1; l<=n; ){
        int r=l;
        while(r+1<=n&&sgn[r]==2){
            ++r;
        }
        rt.ep(l);
        lp[l]=l; rp[l]=r;
        l=r+1;
    }
    for(int i=1; i<=n; ++i) deg[i]=0, e[i].clear();
    for(int i=0; i+1<(int)rt.size(); ++i){
        int x=rt[i], y=rt[i+1];
        if(sgn[rp[x]]){
            ++deg[x]; e[y].ep(x);
        }
        else{
            ++deg[y]; e[x].ep(y);
        }
    }
    for(int i=0; i+2<(int)rt.size(); ++i){
        int x=rt[i], y=rt[i+2];
        if(ask(x, y)){
            ++deg[x]; e[y].ep(x);
        }
        else{
            ++deg[y]; e[x].ep(y);
        }
    }
    printf("!");
    queue<int> que;
    for(auto t:rt) if(!deg[t]){
        que.push(t);
    }
    while(!que.empty()){
        int x=que.front(); que.pop();
        for(int i=lp[x]; i<=rp[x]; ++i) printf(" %d", i);
        for(auto y:e[x]){
            --deg[y];
            if(!deg[y]) que.push(y);
        }
    }
    printf("\n");
    fflush(stdout);
    // cout<<"asktimes:"<<asktimes<<endl;
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}
