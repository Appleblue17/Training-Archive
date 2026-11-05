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
int asktimes;
bool ask(int x, int y){
    ++asktimes;
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
    asktimes=0;
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
    for(int i=1; i<=n; ++i) deg[i]=0, e[i].clear();
    for(int i=1; i+1<=n; ++i){
        if(sgn[i]){
            ++deg[i]; e[i+1].ep(i);
        }
        else{
            ++deg[i+1]; e[i].ep(i+1);
        }
    }
    for(int i=1; i+2<=n; ++i){
        if(ask(i, i+2)){
            ++deg[i]; e[i+2].ep(i);
        }
        else{
            ++deg[i+2]; e[i].ep(i+2);
        }
    }
    printf("!");
    queue<int> que;
    for(int i=1; i<=n; ++i) if(!deg[i]) que.push(i);
    while(!que.empty()){
        int x=que.front(); que.pop();
        printf(" %d", x);
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
