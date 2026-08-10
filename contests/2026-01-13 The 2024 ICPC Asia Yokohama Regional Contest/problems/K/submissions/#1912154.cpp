#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1.1e6+5;

int n,m;
int a[N];
char S[N];

int f[M];


bool cmp1(int x,int y){
    int cx=__builtin_popcount(a[x]),cy=__builtin_popcount(a[y]);
    if(cx!=cy) return cx>cy;
    return x<y;
}

void FWT(int *f,int n){
    for(int k=1;k<n;k<<=1){
        for(int i=0;i<n;i+=k*2){
            for(int j=i;j<i+k;j++){
                int x=j,y=j+k;
                if(f[y]){
                    if(!f[x] || cmp1(f[y],f[x])) f[x]=f[y];
                }
            }
        }
    }
}

bool cmp2(int xx,int yy,int x,int y){
    int cx=__builtin_popcount(a[x]),cy=__builtin_popcount(a[y]);
    int cxx=__builtin_popcount(a[xx]),cyy=__builtin_popcount(a[yy]);
    if(cxx+cyy!=cx+cy) return cxx+cyy>cx+cy;
    if(xx!=x) return xx<x;
    return yy<y;
}

signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("\n%s",S);
        int mac=0;
        for(int j=0;j<m;j++){
            if(S[j]=='Y') mac |= 1<<j;
        }
        a[i]=mac;
        if(!f[mac]) f[mac]=i;
    }
    FWT(f,1<<m);
    
    // for(int i=0;i<(1<<m);i++) cout<<f[i]<<" "; cout<<endl;
    // return 0;
    
    int X=0,Y=0;
    for(int i=1;i<=n;i++){
        int imac=a[i] ^ ((1<<m)-1);
        int x=f[imac];
        if(f[imac]){
            int x=f[imac],y=i;
            if(x>y) swap(x,y);
            if(x==y) continue;
            
            if(!X || !Y) X=x,Y=y;
            else if(cmp2(x,y,X,Y)) X=x,Y=y;
        }
    }
    
    if(!X || !Y) cout<<"No";
    else cout<<X<<" "<<Y<<endl;
}
