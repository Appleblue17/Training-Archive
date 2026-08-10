#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e4+5;

int n,K,M,f[N][6];
const int p=1e9+7;

char s[N];

void solve(){
    scanf("%s",s+1);
    cin >> K >> M;
    n = strlen(s+1);
    int mxn = n*9;
    int sm=0;
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        for(int j=mxn;j>=0;j--){
            for(int k=1;k<=min(9,j);k++){
                f[j][1]+=f[j-k][1];
                f[j][1]%=p;
            }
        }
        if(i == n)s[i]++;
        for(int j=0;j<s[i]-'0';j++){
            f[j+sm][1]++;
            f[j+sm][1]%=p;
        }
        if(i==n)s[i]--;
        sm += s[i]-'0';
    }
    //for(int i=0;i<=mxn;i++){
    //    printf("f[%d]=%d\n",i,f[i][1]);
    //}
    for(int k=1;k<=4;k++){
        for(int i=0;i<=mxn;i++){
            int x = i,nxt=0;
            while(x){
                nxt+=x%10;
                x/=10;
            }
            f[nxt][k+1]+=f[i][k];
            f[nxt][k+1]%=p;
        }
    }
    if(K > 4)K=4;
    if(M > mxn){
        printf("0\n");
        return;
    }
    //cout << f[5][1] << endl;
    //cout << K << ' ' << M << endl;
    printf("%d\n",f[M][K]);
    
}

int main(){
    int T;cin >> T;while(T--){
        solve();
    }
}
