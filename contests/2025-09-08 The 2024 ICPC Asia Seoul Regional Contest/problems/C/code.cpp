#include <bits/stdc++.h>
using namespace std;
const int N=2200;

int n,k,ans;
int val[N][N];

vector <int> A[N][N],B[N][N],C[N][N],D[N][N];

inline void ins(vector <int> &f,int x){
    if(!x) return ;
    if(f.size()>=4) return ;
    else{
        for(int t: f) if(t==x) return ;
        f.push_back(x);
    }
}

bool check(int x,int y){
    for(int a: A[x-1][y-1]){
        for(int b: B[x-1][y+1]){
            if(a==b) continue;
            for(int c: C[x+1][y-1]){
                if(a==c || b==c) continue;
                for(int d: D[x+1][y+1]){
                    if(a==d || b==d || c==d) continue;
                    return 1;
                }
            }
        }
    }
    return 0;
}

mt19937 rng(923499);

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&val[i][j]);
            // val[i][j]=rng()%(k+1);
            // if(rng()%10) val[i][j]=0;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            A[i][j]=A[i][j-1];
            for(int x: A[i-1][j]) ins(A[i][j],x);
            ins(A[i][j],val[i][j]);
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            B[i][j]=B[i][j+1];
            for(int x: B[i-1][j]) ins(B[i][j],x);
            ins(B[i][j],val[i][j]);
        }
    }
    
    
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            C[i][j]=C[i][j-1];
            for(int x: C[i+1][j]) ins(C[i][j],x);
            ins(C[i][j],val[i][j]);
        }
    }
    
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            D[i][j]=D[i][j+1];
            for(int x: D[i+1][j]) ins(D[i][j],x);
            ins(D[i][j],val[i][j]);
        }
    }
    
    for(int i=2;i<=n-1;i++){
        for(int j=2;j<=n-1;j++){
            if(!val[i][j] && check(i,j)){
                // cout<<"! "<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans;
}

