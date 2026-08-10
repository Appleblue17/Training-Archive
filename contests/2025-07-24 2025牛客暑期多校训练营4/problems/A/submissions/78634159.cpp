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
ll a[N][N],ans[N][N*4];
ll t,n,m,x,y,k;
const ll dice[4][4] = {{3,3,-3,-3},{0,0,0,0},{1,1,-1,-1},{3,1,-2,-2}};
//0 < 3,3 < 2
const ll offset=5e8;
char s[N];
bool check(int x,int y){
    int cnt=0;
    for(int i=1;i<=n*4;i++){
        for(int j=1;j<=n*4;j++){
            if(ans[x][i] > ans[y][j])cnt+=2;
            else if(ans[x][i]==ans[y][j])cnt++;
        }
    }
    cout << cnt << endl;
    if(cnt>16*n*n)return 1;
    else return 0;
}
void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n*4;j++){
            ans[i][j]=offset;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=n;j++){
            a[i][j]=s[j]-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int di=0;
            if(a[i][j])di=0;
            else di=2;
            if(i==j)di=3;
            for(int d=1;d<=4;d++){
                ans[j][(i-1)*4+d] = dice[di][d-1]+offset;
                if(d<=2)ans[j][(i-1)*4+d]+=4*i;
                else ans[j][(i-1)*4+d]-=4*i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",4*n);
        for(int j=1;j<=n*4;j++){
            printf("%lld ",ans[i][j]);
        }
        putchar('\n');
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("i=%d,j=%d\n",i,j);fflush(stdout);
            assert(check(i,j)==a[i][j]);
        }
    }*/
}
int main(){
    solve();
}
