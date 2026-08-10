#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
const int N=510000;
char s[N];
inline int sm(int x){
    return x*(x+9)/2;
}
struct nd{
    int n,k,red;
    nd(int n=0,int k=0):n(n),k(k){
        int b1 = (n-k)/(k+1),b2 = b1+1;
        int c2 = (n-k)%(k+1),c1 = k+1-c2;
        int y = sm(b1)*c1+sm(b2)*c2;
        
        //if(k+1 == n){
        //    red = 5;
        //    return;
        //}
        k++;
        b1 = (n-k)/(k+1),b2 = b1+1;
        c2 = (n-k)%(k+1),c1 = k+1-c2;
        int ne = sm(b1)*c1+sm(b2)*c2;
        
        red = y-ne;
        
        //printf("called constructor %lld %lld,red=%lld\n",n,k,red);
    }
    friend bool operator<(const nd& A,const nd& B){return A.red < B.red;}
};
priority_queue<nd> q;
void solve(){
    while(!q.empty())q.pop();
    scanf("%lld%lld",&n,&k);
    scanf("%s",s+1);
    s[n+1]='1';
    n++;
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        if(s[i] == '1'){
            if(cnt != 0){
                q.push(nd(cnt,0));
                ans += sm(cnt);
            }
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    while(!q.empty() && k>0){
        nd t = q.top();
        q.pop();
        ans -= t.red;
        if(t.k+1 < t.n){
            q.push(nd(t.n,t.k+1));
        }
        k--;
    }
    printf("%lld\n",ans*5);
}
signed main(){
    int T;cin >> T;while(T--){
        solve();
    }
}