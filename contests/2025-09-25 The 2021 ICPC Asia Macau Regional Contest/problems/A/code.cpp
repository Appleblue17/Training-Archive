#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=66;
int T,n;
int a[N][N];

int p[N*N],id;

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        id=0;
        for(int i=1;i<=n;i++){
            if(i%2) for(int j=1;j<=n;j++) p[++id]=a[i][j];
            else for(int j=n;j>=1;j--) p[++id]=a[i][j];
        }
        
        int tot1=0,tot2=0;
        for(int i=1;i<id;i++){
            if(p[i]<p[i+1]) tot1++;
            else tot2++;
        }
        if(tot1>tot2) reverse(p+1,p+id+1);
        for(int i=1;i<=id;i++){
            printf("%d ",p[i]);
        }
        printf("\n");
    }
}
