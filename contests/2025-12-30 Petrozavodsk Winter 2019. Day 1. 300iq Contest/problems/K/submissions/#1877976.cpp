#include <bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=13,mod=998244353;
int n,k;
char S[N];

int ch[13][2]={
    {},
    {2,7},
    {1,3},
    {4,10},
    {3,5},
    {6,11},
    {5,1},
    {8,6},
    {7,9},
    {10,12},
    {9,2},
    {12,4},
    {11,8}
};

void gmod(int &x){
    x%=mod;
}
struct mat{
    int P[M][M];
    mat(int x=0){
        memset(P,0,sizeof(P));
        for(int i=1;i<=12;i++) P[i][i]=x;
    }
};
mat operator +(mat X,mat Y){
    mat T;
    for(int i=1;i<=12;i++)
        for(int j=1;j<=12;j++)
            gmod(T.P[i][j]=X.P[i][j]+Y.P[i][j]);
    return T;
}
mat operator *(mat X,mat Y){
    mat T;
    for(int i=1;i<=12;i++)
        for(int k=1;k<=12;k++)
            for(int j=1;j<=12;j++)
                gmod(T.P[i][k]+=1ll*X.P[i][j]*Y.P[j][k]%mod);
    return T;
}

mat ksm(mat A,int x){
    mat T(1);
    while(x){
        if(x & 1) T=T*A;
        A=A*A;
        x>>=1;
    }
    return T;
}

int main() {
    scanf("%d",&n);
    scanf("\n%s",S+1);
    scanf("%d",&k);
    
    int u=1;
    for(int i=1;i<=n;i++) u=ch[u][S[i]-'a'];
    
    // cout<<u<<endl;
    
    mat F;
    for(int i=1;i<=12;i++){
        F.P[i][ch[i][0]]=1;
        F.P[i][ch[i][1]]=1;
    }
    
    mat G=ksm(F,k);
    
    // for(int i=1;i<=12;i++) cout<<G.P[1][i]<<" ";
    // cout<<endl;
    cout<<G.P[1][u];
}
