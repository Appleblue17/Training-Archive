#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e9;
const int N=2e5+5;
int n, m,a[N],s[N];
int f[1100][1100];
 
bool bf(int S){
    for(int j=1;j<=n;j++){
        for(int i=1;i+j-1<=n;i++){
            f[i][j] = !(f[i][j-1]&f[i+1][j-1]);
            if(s[i+j-1]-s[i-1]<=S)f[i][j]=1;
            if(j == 1 && s[i]-s[i-1]>S)f[i][j]=0;
            //printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
        }
    }
    return f[1][n];
}
 
void solve(){
    //freopen("C.in","r",stdin);
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    int q;
    scanf("%lld",&q);
    while(q--){
        int S;
        scanf("%lld",&S);
        int le=0,ri=n/2,mi;
        while(le<ri){
            mi = (le+ri+1)>>1;
            if(s[n-mi]-s[mi]<=S){
                ri = mi-1;
            }
            else{
                le = mi;
            }
        }
        int L = le+1,R = n-le;
        //printf("mi=%lld,L=%lld,R=%lld\n",mi,L,R);
        int a1 = upper_bound(s+1,s+n+1,s[L-1]+S)-s;
        int a2 = lower_bound(s+1,s+n+1,s[R]-S)-s;
        a1--;
        a2++;
        //printf("a1=%lld,a2=%lld\n",a1,a2);
        a1 = R-a1;
        a2 = a2-L;
        bool f1 = (a1%2)!=0;
        bool f2 = (a2%2)!=0;
        bool ans = !(f1&f2);
        /*if(ans != bf(S)){
            printf("assert failed,ans=%d\n",ans);
            cout << n << endl;
            for(int i=1;i<=n;i++){
                printf("%lld ",a[i]);
            }
            cout << endl << S << endl;
            exit(-1);
        }*/
        if(!(f1&f2))printf("Alice\n");
        else printf("Bob\n");
    }
}
 
signed main(){
    //freopen("C.in","r",stdin);
    //int T;
    //scanf("%lld",&T);
    //while(T--){
        solve();
    //}
}
