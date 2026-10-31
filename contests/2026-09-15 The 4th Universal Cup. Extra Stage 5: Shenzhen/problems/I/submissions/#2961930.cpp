#include <bits/stdc++.h>
using namespace std;
const int N=110;
int T,n;

int ans1[N],ans2[N];

bool vis[N];


void prt(int A){
    int tmp=-1,cnt=0;
    for(int i=0;i<9;i++){
        if(A>>i & 1){
            printf("%d ",i);
            cnt++;
            tmp=i;
        }
    }
    while(cnt<6) printf("%d ",tmp),cnt++;
}

signed main(){
    for(int A=1;A<(1<<9);A++){
        if(__builtin_popcount(A)>6) continue;
        for(int B=1;B<(1<<9);B++){
            if(__builtin_popcount(B)>6) continue;
            
            memset(vis,0,sizeof(vis));
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    bool Ai=(A>>i & 1) || (i==9 && (A>>6 & 1));
                    bool Bi=(B>>i & 1) || (i==9 && (B>>6 & 1));
                    bool Aj=(A>>j & 1) || (j==9 && (A>>6 & 1));
                    bool Bj=(B>>j & 1) || (j==9 && (B>>6 & 1));
                    
                    if((Ai && Bj) || (Bi && Aj)) vis[i*10+j]=vis[i+10*j]=1;
                }
            }
            
            int mex=1;
            while(vis[mex]) mex++;
            ans1[mex]=A;
            ans2[mex]=B;
        }
    }
    
    // for(int i=1;i<=99;i++){
    //     cout<<i<<": "<<ans1[i]<<" "<<ans2[i]<<endl;
    // }
    
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        
        int A=ans1[n],B=ans2[n];
        if(!A && !B) printf("No\n");
        else{
            printf("Yes\n");
            prt(A),prt(B);
            printf("\n");
        }
        
    }
    
}