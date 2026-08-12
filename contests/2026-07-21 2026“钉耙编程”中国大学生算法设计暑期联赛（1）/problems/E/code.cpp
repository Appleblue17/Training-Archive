#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, k, n;
char s[N];
int nxt[N];
long long check(){
    for(int i=2, j=0; i<=n; ++i){
        while(j&&s[i]!=s[j+1]) j=nxt[j];
        if(s[i]==s[j+1]) ++j;
        nxt[i]=j;
    }
    int sum=0;
    for(int i=1; i<n; ++i){
        for(char c='a'; c<='b'; ++c){
            int j=i;
            while(j&&s[j+1]!=c) j=nxt[j], sum++;
            
        }
    }
    return sum;
}
void solve(){
    scanf("%d", &k);
    int flag=-1;
    n=0;
    for(int i=100000; i>=1; --i){
        long long cur=1ll*i*(i+flag)/2ll;
        if(k>=cur){
            k-=cur;
            flag=1;
            for(int j=1; j<=i; ++j) s[++n]='a';
            if(k==0) break;
            --k; s[++n]='b';
        }
    }
    while(k>0){
        --k;
        s[++n]='b';
    }
    printf("%d 2\n", n);
    for(int i=1; i<=n; ++i) putchar(s[i]);
    putchar('\n');
    // scanf("%s", s+1);
    // n=strlen(s+1);
    // cout<<"sum:"<<check()<<endl;
    // assert(check()==T);
}
int main(){
    scanf("%d", &T);
    while(T--){
        // k=T;
        solve();
    }
    
}