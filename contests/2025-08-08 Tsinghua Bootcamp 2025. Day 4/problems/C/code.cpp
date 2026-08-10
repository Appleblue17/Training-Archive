#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+56, inf=1e9;
string s[5];
char h[100][100];
void check(int x, int y, int z, int w){
    for(int i=0; i<s[x].size(); ++i){
        for(int j=0; j<s[y].size(); ++j){
            for(int ii=0; ii<s[z].size(); ++ii){
                if(s[x][i]==s[z][ii]){
                    for(int iii=ii+1; iii<s[z].size(); ++iii){
                        if(iii-ii+1>s[w].size()) break;
                        if(s[y][j]==s[z][iii]){
                            for(int k=i+1; k<s[x].size(); ++k) {
                                for(int jj=0; jj<s[w].size(); ++jj)if(s[x][k]==s[w][jj]){
                                    int p1=j+(k-i), p2=jj+(iii-ii);
                                    if(p1<(int)s[y].size()&&p2<(int)s[w].size()&&s[y][p1]==s[w][p2]){
                                        int mnx=100, mny=100;
                                        int sx=30, sy=30-ii;
                                        mnx=min(mnx, sx); mny=min(mny, sy);
                                        for(int o=0; o<s[z].size(); ++o) h[sx][sy+o]=s[z][o];
                                        sx=30-i; sy=30;
                                        mnx=min(mnx, sx); mny=min(mny, sy);
                                        for(int o=0; o<s[x].size(); ++o) h[sx+o][sy]=s[x][o];
                                        sx=30-j; sy=30+(iii-ii);
                                        mnx=min(mnx, sx); mny=min(mny, sy);
                                        for(int o=0; o<s[y].size(); ++o) h[sx+o][sy]=s[y][o];
                                        sx=30+(k-i), sy=30-jj;
                                        mnx=min(mnx, sx); mny=min(mny, sy);
                                        for(int o=0; o<s[w].size(); ++o) h[sx][sy+o]=s[w][o];
                                        printf("Yes\n");
                                        for(int o=mnx; o<mnx+18; ++o){
                                            for(int p=mny; p<mny+18; ++p){
                                                putchar(h[o][p]);
                                            }
                                            putchar('\n');
                                        }
                                        exit(0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
signed main(){
    for(int i=1; i<=4; ++i) cin>>s[i];
    for(int i=0; i<100; ++i) for(int j=0; j<100; ++j) h[i][j]='.';
    for(int i=1; i<=4; ++i){
        for(int j=1; j<=4; ++j)if(i!=j){
            for(int k=1; k<=4; ++k) if(i!=k&&j!=k){
                for(int l=1; l<=4; ++l) if(i!=l&&j!=l&&k!=l){
                    check(i, j, k, l);
                }
            }
        }
    }
    printf("No\n");
}