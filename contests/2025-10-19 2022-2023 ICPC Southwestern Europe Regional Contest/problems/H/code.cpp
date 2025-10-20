#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
char S[N];

int A,B;

bool solve(){
    int x,y; scanf("%d%d",&x,&y);
    if(x==y){
        return 1ll*x*(A-B)==0;
    }
    
    if(x>y) swap(x,y);
    long long sum=1ll*x*A-1ll*y*B;
    
    sum=-sum;
    return (sum>=0 && sum%(y-x)==0 && sum/(y-x)<=n);
}

int main(){
    scanf("%d",&n);
    scanf("\n%s",S);
    
    for(int i=0;i<n;i++){
        if(S[i]=='+') A++;
        else B++;
    }
    
    scanf("%d",&q);
    while(q--){
        if(solve()) printf("YES\n");
        else printf("NO\n");
    }
    
    
}
