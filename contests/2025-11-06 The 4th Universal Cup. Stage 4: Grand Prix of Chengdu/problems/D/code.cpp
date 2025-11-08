#include<bits/stdc++.h>
using namespace std;
const int N=220;

int T,a,b,n,p;

bool dp[22][N];
int rec[22][N];

void prt(int t,int a){
    if(!t) return ;
    int x=rec[t][a];
    prt(t-1,a-x);
    if(x==1) printf("1//");
    else printf("1%d",x-1);
}

bool sol(int a,int b,int n,bool pr){
    if(a<0 || b<0) return 0;
    // n: round num
    for(int i=0;i<=n;i++){
        int j=n-i;
        if(dp[i][a] && dp[j][b]){
            if(pr){
                prt(i,a);
                printf("/");
                prt(j,b);
                printf("/");
            }
            return 1;
        }
    }
    return 0;
}


int col[6];

bool solve(){
    if(n>=6){
        bool ret=sol(a,b,21-n,1);
        if(p && ret) putchar('/');
        return ret;
    }
    else{
        int m=6-n;
        
        for(int mac=0;mac<(1<<m);mac++){
            if(!n && (mac>>5 & 1)!=p) continue;
            int sum1=0,sum2=0;
            for(int i=0;i<m;i++){
                if(mac>>i & 1) sum2+=i+2;
                else sum1+=i+2;
            }
            
            if(sol(a-sum1,b-sum2,15,0)){
                sol(a-sum1,b-sum2,15,1);
                
                int nw=0;
                for(int i=0;i<m;i++){
                    if(nw!=(mac>>i & 1)) putchar('/'),nw^=1;
                    printf("%d",i+2);
                }
                if(nw!=p) putchar('/');
                
                return 1;
            }
        }
        
        return 0;
    }
}

signed main(){
    int lim=200;
    dp[0][0]=1;
    for(int i=1;i<=15;i++){
        for(int j=0;j<=lim;j++){
            if(!dp[i-1][j]) continue;
            for(int t=1;t<=8;t++){
                if(t==2) continue;
                dp[i][j+t]=1;
                rec[i][j+t]=t;
            }
        }
    }
    
    
    cin>>T;
    while(T--){
        cin>>a>>b>>n>>p;
        if(!solve()){
            printf("NA");
            // printf("_%d_%d_%d_%d",a,b,n,p);
        }
        putchar('\n');
    }
    
}
