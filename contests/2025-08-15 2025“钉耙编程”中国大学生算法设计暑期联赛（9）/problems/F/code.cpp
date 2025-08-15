#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+4;
const int mod=1e9+7;
int T,n;
char s[N];
int pos[N];
signed main(){
    scanf("%s", s+1);
    n=strlen(s+1);
    pos[n+1]=n+1;
    for(int i=n; i>=1; --i){
        int sum=0;
        pos[i]=pos[i+1];
        for(int j=i; j<pos[i+1]; ++j){
            if(s[j]!='('&&s[j]!=')') break;
            if(s[j]=='(') ++sum;
            else --sum;
            if(sum<0) break;
            if(sum==0){
                pos[i]=j; break;
            }
        }
    }
    int ans=0;
    for(int i=2; i<n; ++i){
        for(int j=1; j<=n; ++j){
            if(i-j<=0||i+j>n||s[i-j]!=s[i+j]) break;
            if(pos[i-j]<=i+j) ++ans;
        }
    }
    for(int i=1; i<n; ++i){
        for(int j=0; j<=n; ++j){
            if(i-j<=0||i+j+1>n||s[i-j]!=s[i+j+1]) break;
            if(pos[i-j]<=i+j+1) ++ans;
        }
    }
    printf("%d\n", ans);
}