#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n;
int a[N][N], b[N][N], d[N][N];
struct node{
    int a, b, c, d, x;
};
vector<node> ans;
void perform(int x, int y, int z, int w, int v){
    ans.push_back((node){x, y, z, w, v});
    d[x][y]+=v;
    d[x][z]+=v;
    d[x][w]+=v;
    d[y][z]-=v;
    d[z][w]-=v;
    d[y][w]-=v;
    d[y][x]+=v;
    d[z][x]+=v;
    d[w][x]+=v;
    d[z][y]-=v;
    d[w][z]-=v;
    d[w][y]-=v;
}
int vis[N];
void perform2(int x, int y, int z, int w, int v){
    perform(x, y, z, w, v/2);
    perform(y, x, z, w, v/2);
}
int px[N*N], py[N*N], tot;
void prt(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cout<<d[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d", &n);
    for(int i=1; i<n; ++i){
        for(int j=i+1; j<=n; ++j){
            scanf("%d", &a[i][j]);
            a[j][i]=a[i][j];
        }
    }
    for(int i=1; i<n; ++i){
        for(int j=i+1; j<=n; ++j){
            scanf("%d", &b[i][j]);
            b[j][i]=b[i][j];
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            d[i][j]=a[i][j]-b[i][j];
        }
    }
    for(int i=2; i<=n-3; ++i){
        for(int j=1; j<i; ++j)if(d[i][j]&1){
            perform(j, i, i+1, i+2, 1);
        }
    }
    for(int i=1; i<n-3; ++i){
        int cnt=0;
        for(int j=n-2; j<=n; ++j) cnt+=(d[i][j]&1);
        if(cnt==0||cnt==3) continue;
        if(cnt==1){
            for(int j=n-2; j<=n; ++j) if(d[i][j]&1){
                int k=n-2; 
                if(k==j) ++k;
                perform(i, n-3, j, k, 1);
                perform(n-3, i, j, n+(n-1)+(n-2)-j-k, 1);
                break;
            }
        }
        else{
            for(int j=n-2; j<=n; ++j) if(!(d[i][j]&1)){
                int k=n-2; 
                if(k==j) ++k;
                perform(i, n-3, j, k, 1);
                perform(n-3, i, j, n+(n-1)+(n-2)-j-k, 1);
                break;
            }
        }
    }
    for(int i=1; i<n-3; ++i){
        int cnt=0;
        for(int j=n-2; j<=n; ++j) cnt+=(d[i][j]&1);
        assert(cnt==0||cnt==3);
        if(cnt==3){
            perform(i, n-2, n-1, n, 1);
        }
    }
    {
        int cnt=0;
        for(int j=n-2; j<=n; ++j) cnt+=(d[n-3][j]&1);
        for(int j=n-2; j<=n; ++j){
            for(int k=j+1; k<=n; ++k){
                cnt+=(d[j][k]&1);
            }
        }
        if(cnt!=0&&cnt!=2&&cnt!=4&&cnt!=6){
            printf("-1\n");
            return 0;
        }
        if(cnt==6){
            perform(n-3, n-2, n-1, n, 1);
        }
        if(cnt==4){
            perform(n-3, n-2, n-1, n, 1);
            cnt=2;
        }
        if(cnt==2){
            // prt();
            if(n<6){
                printf("-1\n");
                return 0;
            }
            vector<int> vec;
            for(int i=1; i<=n; ++i){
                for(int j=i+1; j<=n; ++j){
                    if(d[i][j]&1){
                        ++vis[i]; ++vis[j];
                    }
                }
            }
            int A=0;
            for(int i=1; i<=n; ++i) if(vis[i]==2) A=i;
            if(A==0){
                int p1=0, p2=0, p3=0, p4=0;
                for(int i=1; i<=n; ++i){
                    for(int j=i+1; j<=n; ++j){
                        if(d[i][j]&1){
                            if(p1==0) p1=i, p2=j;
                            else p3=i, p4=j;
                        }
                    }
                }
                int B=0, C=0, E=p3;
                for(int i=1; i<=n; ++i) if(vis[i]==0){
                    if(B==0) B=i;
                    else C=i;
                }
                A=p1;
                int D=p2, F=p4; 
                perform(D, A, B, E, -1);
                perform(D, A, B, C, 1);
                perform(E, A, C, D, 1);
                perform(E, A, B, C, -1);
                
                perform(E, A, C, F, -1);
                perform(E, A, C, B, 1);
                perform(F, A, B, E, 1);
                perform(F, A, C, B, -1);
                for(int i=1; i<=n; ++i) vis[i]=0;
                for(int i=1; i<=n; ++i){
                    for(int j=i+1; j<=n; ++j){
                        if(d[i][j]&1){
                            ++vis[i]; ++vis[j];
                        }
                    }
                }
                A=0;
                for(int i=1; i<=n; ++i) if(vis[i]==2) A=i;
            }
            int D=0, F=0;
            for(int i=1; i<=n; ++i) if(vis[i]==1){
                if(D==0) D=i;
                else F=i;
            }
            int B=0, C=0, E=0;
            for(int i=1; i<=n; ++i) if(vis[i]==0){
                if(B==0) B=i;
                else if(C==0) C=i;
                else E=i;
            }
            perform(D, A, B, E, -1);
            perform(D, A, B, C, 1);
            perform(E, A, C, D, 1);
            perform(E, A, B, C, -1);
            
            perform(E, A, C, F, -1);
            perform(E, A, C, B, 1);
            perform(F, A, B, E, 1);
            perform(F, A, C, B, -1);
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n; ++j){
            if(d[i][j]!=0) {
                for(int ii=1; ii<=n&&d[i][j]!=0; ++ii) if(ii!=i&&ii!=j){
                    for(int jj=ii+1; jj<=n&&d[i][j]!=0; ++jj) if(jj!=j&&jj!=i){
                        if(d[ii][jj]!=0){
                            perform2(i, j, ii, jj, -d[i][j]);
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; ++i){
        int cnt=0;
        for(int j=1; j<=n; ++j){
            cnt+=(d[i][j]!=0);
        }
        if(cnt>1){
            for(int j=1; j<n; ++j)if(d[i][j]!=0){
                int k=j+1;
                if(k==i) ++k;
                if(k>n) break;
                for(int o=1; o<=n; ++o) vis[o]=0;
                vis[i]=vis[j]=vis[k]=1;
                int A=i, D=j, B=k;
                int C=0, E=0;
                for(int o=1; o<=n; ++o) if(vis[o]==0){
                    if(C==0) C=o;
                    else E=o;
                }
                int v=d[i][j]/2;
                perform(D, A, B, E, -v);
                perform(D, A, B, C, v);
                perform(E, A, C, D, v);
                perform(E, A, B, C, -v);
                
                perform(E, A, B, C, -v);
                perform(E, A, B, D, v);
                perform(C, A, D, E, v);
                perform(C, A, B, D, -v);
            }
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            // cout<<d[i][j]<<' ';
            if(d[i][j]!=0){
                printf("-1\n");
                return 0;
            }
        }
        // cout<<endl;
    }
    printf("%d\n", (int)ans.size());
    for(auto t:ans){
        printf("%d %d %d %d %d\n", t.a, t.b, t.c, t.d, t.x);
    }
}
