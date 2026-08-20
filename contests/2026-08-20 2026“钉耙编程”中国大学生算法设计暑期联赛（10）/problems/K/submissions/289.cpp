#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T, n, m, ans[N], nxt[N];
int pop_count(int x){
    int cnt=0;
    while(x){
        if(x&1) cnt++;
        x>>=1;
    }
    return cnt;
}
void solve(){
    cin>>n;
    if(n >= N)printf("-1\n");
    else printf("%d\n", nxt[n]);
}
int main(){
    ios::sync_with_stdio(false);
    
    for(int i=1;i<N;i++){
        int x = pop_count(i);
        if(x*x*x == i>>1){
            ans[i] = 1;
            //cout << i << endl;
        }
    }
    //cout << '*' << endl;
    nxt[N-1] = -1;
    for(int i=N-2;i>=1;i--){
        nxt[i] = nxt[i+1];
        if(ans[i]) nxt[i] = i;
    }
    
    cin>>T;
    while(T--){
        solve();
    }
}