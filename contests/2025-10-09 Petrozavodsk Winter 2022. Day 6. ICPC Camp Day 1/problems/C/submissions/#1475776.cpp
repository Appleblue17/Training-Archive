#include <bits/stdc++.h>
using namespace std;
const int N=5500;

int n,m;
int a[N];

struct mat{
    int f[N];
    mat(){
        memset(f,0,sizeof(f));
    }
};
mat operator *(mat X,mat Y){
    mat S;
    for(int i=0;i<=m;i++){
        for(int j=0;i+j<=m;j++){
            S.f[i+j]=max(S.f[i+j],X.f[i]+Y.f[j]);
        }
    }
    return S;
}

mat ksm(mat A,int x){
    mat T;
    while(x){
        if(x & 1) T=T*A;
        A=A*A;
        x>>=1;
    }
    return T;
}


int main(){
    // freopen("Cin.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    
    mat P;
    for(int i=1;i<=n;i++){
        int x=a[i];
        P.f[x]=max(P.f[x],i);
    }
    
    mat Q=ksm(P,n);
    int ans=0;
    for(int i=0;i<=m;i++) ans=max(ans,Q.f[i]);
    // cout<<ans<<endl;
    printf("%.10lf",1.0*ans/n);
;}
