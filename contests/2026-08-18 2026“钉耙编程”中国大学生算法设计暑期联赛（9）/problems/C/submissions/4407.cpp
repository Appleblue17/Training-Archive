#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
// #define int long long
int Test, n, m, s, t;
int rd(){
    char c=getchar();
    int tot=0;
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
    return tot;
}
int e[N][N];
int dep[N];
vector<int> bin[N];
int cnt[N][N];
int dpmn[N][N], dpsz[N][N];
bitset<500> msk[N][N], slf[N];
void solve(){
    n=rd(); m=rd(); s=rd(); t=rd();
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            e[i][j]=0;
        }
    }
    for(int i=1, x, y; i<=m; ++i){
        x=rd(); y=rd();
        e[x][y]=e[y][x]=1;
    }
    for(int i=1; i<=n; ++i){
        dep[i]=1e9;
    }
    dep[s]=0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int x=que.front(); que.pop();
        for(int y=1; y<=n; ++y) if(e[x][y]){
            if(dep[y]>dep[x]+1){
                dep[y]=dep[x]+1;
                que.push(y);
            }
        }
    }
    // for(int i=1; i<=n; ++i) cout<<dep[i]<<endl;
    for(int i=0; i<n; ++i) bin[i].clear();
    for(int i=1; i<=n; ++i) if(dep[i]<n) bin[dep[i]].push_back(i);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j){
            dpmn[i][j]=1e9; dpsz[i][j]=0;
        }
    }
    for(int i=1; i<=n; ++i) if(e[s][i]){
        dpmn[s][i]=1; dpsz[s][i]=1;
    }
    for(int i=1; i<n; ++i){
        if(bin[i].empty()) break;
        for(auto x:bin[i-1]){
            for(auto z:bin[i+1]){
                msk[x][z].reset();
                for(auto y:bin[i]) if(e[x][y]||e[y][z]){
                    msk[x][z][y]=1;
                }
            }
        }
        for(auto x:bin[i]) {
            slf[x].reset();
            for(auto y:bin[i]) if(e[x][y]){
                slf[x][y]=1;
            }
        }
        for(auto y:bin[i]){
            for(auto x:bin[i-1]) if(e[x][y]){
                for(auto z:bin[i+1]) if(e[y][z]){
                    int nval=dpmn[x][y];
                    nval+=(slf[y]|msk[x][z]).count();
                    if(nval<dpmn[y][z]){
                        dpmn[y][z]=nval, dpsz[y][z]=dpsz[x][y];
                    }
                    else if(nval==dpmn[y][z]){
                        dpsz[y][z]=(dpsz[y][z]+dpsz[x][y])%mod;
                    }
                }
            }
        }
    }
    // for(int i=1; i<=n; ++i){
    //     for(int j=1; j<=n; ++j) if(dep[j]==dep[i]+1){
    //         cout<<i<<' '<<j<<' '<<dpmn[i][j]<<endl;
    //     }
    // }
    int ansmn=1e9, anssz=0;
    for(auto x:bin[dep[t]-1]) if(e[x][t]){
        int curv=dpmn[x][t];
        for(auto y:bin[dep[t]]) if(e[x][y]||e[t][y]) ++curv;
        for(auto y:bin[dep[t]+1]) if(e[t][y]) ++curv;
        if(curv<ansmn){
            ansmn=curv, anssz=dpsz[x][t];
        }
        else if(curv==ansmn){
            anssz=(anssz+dpsz[x][t])%mod;
        }
    }
    printf("%d %d\n", ansmn, anssz);
}
signed main(){
    Test=rd();
    while(Test--){
        solve();
    }
    
    
}