#include <bits/stdc++.h>
using namespace std;
const int N=330,M=330;

int n,m;
int a[N][M];
int v[N*M],id;

int c[M][N*M];

signed main(){
    cin>>n>>m;
    v[++id]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i][j-1];
            v[++id]=a[i][j];
        }
    }
    
    sort(v+1,v+id+1);
    id=unique(v+1,v+id+1)-v-1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int l=lower_bound(v+1,v+id+1,a[i][j-1])-v;
            int r=lower_bound(v+1,v+id+1,a[i][j])-v;
            c[j][l]++;
            c[j][r]--;
        }
    }
    
    for(int j=1;j<=m;j++){
        int mx=0;
        for(int i=1;i<=id;i++){
            c[j][i]+=c[j][i-1];
            mx=max(mx,c[j][i]);
        }
        printf("%d ",mx);
    }
    
}

