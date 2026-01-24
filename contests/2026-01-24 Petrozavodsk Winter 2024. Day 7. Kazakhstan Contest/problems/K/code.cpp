#include<bits/stdc++.h>
using namespace std;
const int N=250;
int n,m,k,q;
int a[N][N],id[N*N];

bitset<N*N> b[N][N];
bitset<N*N> row[N],col[N];

bool cmp(int A,int B){
    int aj=A%m,bj = B%m;
    int ai=A/m,bi = B/m;
    return a[ai][aj] < a[bi][bj];
}

signed main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n*m;i++){
        id[i]=i;
    }
    sort(id,id+n*m,cmp);
    
    for(int t=0;t<n*m;t++){
        if(t >= k){
            int A = id[t-k];
            int r = A/m,c = A%m;
            //printf("id[t-k]=%d,r=%d,c=%d\n",A,r,c);
            row[r] |= b[r][c];
            col[c] |= b[r][c];
        }
        int A = id[t];
        int r = A/m,c = A%m;
        //printf("t=%d,r=%d,c=%d\n",t,r,c);
        //cout << row[r].test(2) << ' ' << row[c].test(2) << endl;
        b[r][c] = row[r] | col[c];
        b[r][c].set(t);
        //printf("b[%d][%d].test(2)=%d\n",r,c,b[r][c].test(2));
        
    }
    for(int t=0;t<n*m;t++){
        int tt=2;
        //printf("b[%d].test(%d) = %d\n",t,tt,b[t/n][t%m].test(tt));
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int ra,ca,rb,cb;
        scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
        ra--;ca--;rb--;cb--;
        if(b[ra][ca].test(a[rb][cb]-1)){
            printf("Ia\n");
        }
        else{
            printf("Joq\n");
        }
    }
    
    
    
}
