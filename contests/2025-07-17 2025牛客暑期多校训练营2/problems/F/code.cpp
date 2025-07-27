#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N=5e5+5,mod=998244353;
int T,n,m;
char S[N];
 
int p[N],id;
int d[N];
signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        scanf("\n%s",S+1);
        for(int i=1;i<=n;i++) S[i+n]=S[i];
         
        int st=1;
        while(st<=n && S[st]!='1') st++;
        if(st>n){
            printf("%d\n",n);
            continue;
        }
         
        id=0;
        for(int i=st;i<=st+n;i++){
            if(S[i]=='1') p[++id]=i;
        }
        for(int i=2;i<=id;i++) d[i]=p[i]-p[i-1]-1;//cout<<d[i]<<" ";
        // cout<<endl;
         
        int alc=0,mx=0;
        for(int i=2;i<=id;i++){
            int x=max(0,d[i]-2*m);
            alc+=x;
            mx=max(mx,max(0,d[i]-m-1)-x);
        }
        printf("%d\n",alc+mx);
    }
}
