#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,INF=1e18;
int T,n,m,k;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> vec[2][2];
int a[N]; char b[N];
int suma[N], sumb[N];
int bana[N][2], banb[N][3];
// & -> 0; | -> 1;  ^ -> 2
vector<pii> e[N];
void solve(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; ++i){
        bana[i][0]=bana[i][1]=0; e[i].clear();
        a[i]=-1; 
    }
    for(int i=1; i<=m; ++i){
        banb[i][0]=banb[i][1]=banb[i][2]=0; e[i+n].clear();
        b[i]=0; 
    }
    for(int i=1, x, op, y, z; i<=k; ++i){
        scanf("%d%d%d%d", &x, &op, &y, &z);
        vec[y][z].push_back(mapa(x, y));
        e[x].push_back(mapa(op+n, y+z*2));
        e[op+n].push_back(mapa(x, y+z*2));
    }
    for(auto [x, y]:vec[0][1]){
        a[x]=1; bana[x][0]=1; banb[y][0]=1;
    }
    for(auto [x, y]:vec[0][0]){
        if(a[x]==1){
            if(banb[y][0]){
                printf("No\n");
                return ;
            }
            b[y]='&';
            banb[y][1]=1; banb[y][2]=1;
        }
        else{
            a[x]=0;
            bana[x][1]=1;
        }
    }
    for(auto [x, y]:vec[1][1]){
        if(!banb[y][1]){
            banb[y][0]=banb[y][2]=1;
            b[y]='|';
        }
    }
    set<pii> st;
    for(int i=1; i<=n; ++i){
        if(a[i]!=-1) continue;
        st.insert(mapa(1-bana[i][0]+1-bana[i][1], i));
    }
    for(int i=1; i<=m; ++i){
        if(b[i]!=0) continue;
        st.insert(mapa(1-banb[i][0]+1-banb[i][1]+1-banb[i][2], i+n));
    }
    while(!st.empty()){
        pii bk=*st.rbegin(); st.erase(st.find(bk));
        int id=bk.se;
        if(id<=n){
            if(a[id]!=-1) continue;
            for(int i=0; i<2; ++i) if(!bana[id][i]){
                a[id]=i; break;
            }
            for(auto [y, z]:e[id]){
                int u=z&1, v=z/2;
                if(u==0&&v==0){
                    if(a[id]==1){
                        if(b[y-n]==0){
                            b[y-n]='&';
                            st.insert(mapa(0, y));
                        }
                        else if(b[y-n]!='&'){
                            printf("No\n");
                            return ;
                        }
                    }
                    else{
                        
                    }
                }
                if(u==1&&v==0){
                    if(a[id]==1){
                        if(b[y-n]==0){
                            if(banb[y-n][2]){
                                printf("No\n");
                                return ;
                            }
                            b[y-n]='^';
                            st.insert(mapa(0, y));
                        }
                        else if(b[y-n]!='^'){
                            printf("No\n");
                            return ;
                        }
                    }
                    else{
                        if(b[y-n]==0){
                            if(banb[y-n][0]){
                                printf("No\n");
                                return ;
                            }
                            b[y-n]='&';
                            st.insert(mapa(0, y));
                        }
                        else if(b[y-n]!='&'){
                            printf("No\n");
                            return ;
                        }
                    }
                }
                if(u==1&&v==1){
                    if(a[id]==1){
                        if(b[y-n]==0){
                            if(banb[y-n][0]){
                                printf("No\n");
                                return ;
                            }
                            b[y-n]='&';
                            st.insert(mapa(0, y));
                        }
                        else if(b[y-n]!='&'){
                            printf("No\n");
                            return ;
                        }
                    }
                    else{
                        if(b[y-n]==0){
                            if(banb[y-n][2]){
                                printf("No\n");
                                return ;
                            }
                            b[y-n]='^';
                            st.insert(mapa(0, y));
                        }
                        else if(b[y-n]!='^'){
                            printf("No\n");
                            return ;
                        }
                    }
                }
            }
        }
        else{
            if(b[id-n]!=0) continue;
            if(!banb[id-n][0]) b[id-n]='&';
            if(!banb[id-n][1]) b[id-n]='|';
            if(!banb[id-n][2]) b[id-n]='^';
            for(auto [y, z]:e[id]){
                int u=z&1, v=z/2;
                if(u==0&&v==0){
                    if(b[id-n]=='&'){
                        if(a[y]==-1){
                            if(!bana[y][0]){
                            	a[y]=0;
                            }
							else if(!bana[y][1]){
                            	a[y]=1;
							}
							else{
								printf("No\n");
								return ;
							}
                            st.insert(mapa(0, y));
                        }
						else{
							
						}
                    }
                    else{
                    }
                }
                if(u==1&&v==0){
                    if(b[id-n]=='&'){
                        if(a[y]==-1){
                            if(!bana[y][0]){
                            	a[y]=0;
                            	st.insert(mapa(0, y));
                            }
							else{
								printf("No\n");
								return ;
							}
                        }
						else if(a[y]!=0){
							printf("No\n");
							return ;
						}
                    }
                    else if(b[id-n]=='^'){
                        if(a[y]==-1){
                            if(!bana[y][1]){
                            	a[y]=1;
                            	st.insert(mapa(0, y));
                            }
							else{
								printf("No\n");
								return ;
							}
                        }
						else if(a[y]!=1){
							printf("No\n");
							return ;
						}
                    }
					else{
						printf("No\n");
						return ;
					}
                }
                if(u==1&&v==1){
                    if(b[id-n]=='&'){
                        if(a[y]==-1){
                            if(!bana[y][1]){
                            	a[y]=1;
                            	st.insert(mapa(0, y));
                            }
							else{
								printf("No\n");
								return ;
							}
                        }
						else if(a[y]!=1){
							printf("No\n");
							return ;
						}
                    }
                    else if(b[id-n]=='^'){
                        if(a[y]==-1){
                            if(!bana[y][0]){
                            	a[y]=0;
                            	st.insert(mapa(0, y));
                            }
							else{
								printf("No\n");
								return ;
							}
                        }
						else if(a[y]!=0){
							printf("No\n");
							return ;
						}
                    }
					else{
                        if(a[y]==-1){
                            if(!bana[y][0]){
                            	a[y]=0;
                            }
							else if(!bana[y][1]){
                            	a[y]=1;
							}
							else{
								printf("No\n");
								return ;
							}
                            st.insert(mapa(0, y));
                        }
						else{
							
						}
					}
                }
            }
        }
    }
	printf("Yes\n");
	for(int i=1; i<=n; ++i) printf("%d", a[i]); putchar('\n');
	for(int i=1; i<=m; ++i) putchar(b[i]); putchar('\n');
}
signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}