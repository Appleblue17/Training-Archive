#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
int n,a,b;
vector<int> f[N];
int solve(int a,int b,int A,int B){
    for(int i=0;i<=a-A;i++){
        f[i].clear();
        for(int j=0;j<=b-B;j++){
            f[i].push_back(1e18);
        }
    }
    f[0][0]=0;
    for(int i=0;i<=a-A;i++){
        for(int j=0;j<=b-B;j++){
            if(j<b-B)f[i][j+1] = min(f[i][j+1],f[i][j]+__gcd(i+A,j+B+1));
            if(i<a-A)f[i+1][j] = min(f[i+1][j],f[i][j]+__gcd(i+A+1,j+B));
        }
    }
    return f[a-A][b-B];
}
bool isP(int x){
    if(x==1)return 1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}
void sol(){
    scanf("%lld%lld",&a,&b);
    if(a<b)swap(a,b);
    int A=a,B=b-1;
    if(a==0 || b==0){
        int x = a+b;
        printf("%lld\n",x*(x+1)/2);
        return;
    }
    if(a<=3000 && b<=3000){
        printf("%lld\n",solve(a,b,0,0));
        return;
    }
    while(!isP(A))A--;
    while(!isP(B))B--;
    //cout << A << ' ' << B << endl;
    //cout << solve(10,10,5,7) << endl;
    //cout << solve(10,10,0,0) << endl;
    int ans = A+B;
    if(A==B){
        int x = A-1;
        while(!isP(x))x--;
        int tmp = A+x+min(solve(a,b,A,x),solve(a,b,x,B));
        tmp = min(tmp,A+A+solve(a,b,A,B)+A-1);
        ans = tmp;
    }
    else{
        int x = max(a-A,b-B);
        if(a==A){
            ans = A+B+solve(a,b,A,B);
        }
        else{
            int lim = 1000000/(a-A+1);
            int B2 = max(B-lim,1ll);
            ans = min(A+B+solve(a,b,A,B),A+B2+solve(a,b,A,B2));
        }
        
    }
    //if(ans != solve(a,b,0,0)){
    //    printf("%lld %lld,ans=%lld,solve=%lld\n",a,b,ans,solve(a,b,0,0));
    //}
    printf("%lld\n",ans);
}
signed main(){
    sol();
    //freopen("K.out","w",stdout);
    //for(int i=1;i<=1000;i++){
    //    for(int j=1;j<=i;j++){
    //        cout << i << ' ' << j << endl;
    //        a=i;b=j;sol();
    //    }
    //}
}