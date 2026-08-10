#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,INF=1e9;
int T,n;
char S[N];

signed main(){
    scanf("%s",S);
    n=strlen(S);
    
    for(int i=0;i+1<n;i++){
        if(S[i]==S[i+1]) putchar(S[i]);
        else putchar(S[i+1]),putchar(S[i]);
    }
    
}
