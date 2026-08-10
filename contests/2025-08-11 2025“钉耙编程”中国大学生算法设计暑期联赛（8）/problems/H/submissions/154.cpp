#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T_,n,m;
char S[N],T[N];
int a[N];

int solve(){
    for(int i=1;i<=n;i++) a[i]=S[i]-'0';
    
    int st=1;
    while(st<=m && T[st]=='0') st++;
    
    int cnt=0;
    if(st<=m){
        for(int i=1;i+m-1<=n;i++){
            if(a[i+st-1]){
                cnt++;
                for(int j=1;j<=m;j++){
                    if(T[j]=='1') a[i+j-1]^=1;
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(a[i]) return -1;
    }
    return cnt;
}

int main(){
    scanf("%d",&T_);
    while(T_--){
        scanf("%d%d",&n,&m);
        scanf("\n%s",S+1);
        scanf("\n%s",T+1);
        
        printf("%d\n",solve());
        
    }
}