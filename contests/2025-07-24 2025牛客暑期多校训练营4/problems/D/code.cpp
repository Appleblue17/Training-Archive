#include <bits/stdc++.h>
using namespace std;
const int N=220;
int k;
int A[3][3];
int B[3][3]; // 1
int C[3][3]; // 2
 
int n;
int a[N][N];
 
void cp(int x,int y,int f[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[x*3+i+1][y*3+j+1]=f[i][j];
        }
    }
}
 
int main() {
    // freopen("1.txt","w",stdout);
    cin>>k;
    n=30;
     
    A[1][1]=1;
    B[0][0]=B[1][1]=B[2][2]=1;
    C[0][0]=C[0][1]=C[1][1]=C[1][2]=C[2][2]=C[2][0]=1;
     
    a[2][0]=1;
    for(int i=0;i<n;i++){
        cp(i,i,C);
        if(i>0) cp(i,i-1,A);
    }
    for(int i=0;i<n;i++){
        if(k>>(n-1-i) & 1ll){
            if(i%2) a[0][i*3+2]=1;
            else a[0][i*3+1]=1;
        }
    }
    printf("%d\n",n*3+1);
    for(int i=0;i<=n*3;i++){
        for(int j=0;j<=n*3;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
     
}
