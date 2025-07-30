#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define N 110
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
//mt19937_64 rng(GetTickCount());
template <typename T>inline void read(T &x){
    x=0;char c=getchar();bool f=0;
    for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
    for(;c>='0'&&c<='9';c=getchar())
    x=(x<<1)+(x<<3)+(c^48);
    x=(f?-x:x);
}
const int mo=1e9+7;
using namespace std;
int a[N],k[N],b[N],c[N],tt[N],f[N][N][N];
int m,s,t,n;
int turn(int required,int perturn){
    return (required-1+perturn)/perturn;
}
bool check(int p){
    //printf("check %d start\n",p);fflush(stdout);
    memset(f,-48,sizeof(f));
    f[0][0][0]=0;
    for(int i=0;i<=t;i++){
        for(int j=0;j<=n;j++){
            for(int z=0;z<=t;z++){
                if(f[i][j][z]>=s)return 1;
                if(i != t && z != t)
                    f[i+1][j][z+1]=max(f[i+1][j][z+1],f[i][j][z]+tt[j]);
                if(i+turn(a[j+1],tt[j]) <= t && z+turn(a[j+1],tt[j])<= t && j != n)
                    f[i+turn(a[j+1],tt[j])][j+1][z+turn(a[j+1],tt[j])]=max(f[i+turn(a[j+1],tt[j])][j+1][z+turn(a[j+1],tt[j])],f[i][j][z]);
                /*int ttt = turn(a[j+1]-c[j+1],tt[j]);
                if(z-turn(b[j+1],p)+turn(a[j+1]-c[j+1],tt[j]) < 0){
                    int ttt = turn(a[j+1]-c[j+1],tt[j]) - (z-turn(b[j+1],p)+turn(a[j+1]-c[j+1],tt[j]));
                }*/
                //printf("i=%d,j=%d,z=%d,transition to %d,%d,%d\n",i,j,z,i+turn(a[j+1]-c[j+1],tt[j]),j+1,z-turn(b[j+1],p)+turn(a[j+1]-c[j+1],tt[j]));
                if(p==0)continue;
                if(z-turn(b[j+1],p)+turn(a[j+1]-c[j+1],tt[j]) >= 0 && i+turn(a[j+1]-c[j+1],tt[j])<=t && j!=n)
                    f[i+turn(a[j+1]-c[j+1],tt[j])][j+1][z-turn(b[j+1],p)+turn(a[j+1]-c[j+1],tt[j])]=max(f[i+turn(a[j+1]-c[j+1],tt[j])][j+1][z-turn(b[j+1],p)+turn(a[j+1]-c[j+1],tt[j])],f[i][j][z]);
                 
                //printf("f[%d][%d][%d]=%d\n",i,j,z,f[i][j][z]);fflush(stdout);
            }
        }
    }
    //printf("check %d failed\n",p);
    return 0;
}
void solve(){
    scanf("%d",&m);
    scanf("%d",&s);
    scanf("%d",&t);
    scanf("%d",&n);
    tt[0]=m;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i],&k[i],&b[i],&c[i]);
        tt[i]=tt[i-1]+k[i];
    }
    int le=0,ri=10010,mi;
    while(le<ri){
        mi=(le+ri)/2;
        if(check(mi)){
            ri = mi;
        }
        else le = mi+1;
    }
    //check(0);
    if(ri > 10000)printf("-1\n");
    else printf("%d\n",le);
}
int main(){
    //int T;
    //scanf("%d",&T);
    //for(int i=1;i<=T;i++){
        solve();
    //}
}
