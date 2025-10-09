#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n, m, q;
int efr[N], eto[N];
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<pii> e[N], g[N], h[N];
// const int B=2;
const int B=500;
bool isb[N];
vector<int> big;
unordered_map<int, int> w[N][2];
inline ll hs(int x, int y){
    if(x>y) swap(x, y);
    return 1000000000ll*x+y;
}
unordered_map<ll, int> H;
int col[N];
char op[2];
bool ban[N];
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(mapa(y, i)); e[y].push_back(mapa(x, i));
        efr[i]=x; eto[i]=y;
    }
    for(int i=1; i<=n; ++i){
        if(e[i].size()>B){
            isb[i]=1;
            big.push_back(i);
        }
    }
    for(int i=1; i<=n; ++i){
        if(!isb[i]){
            for(auto [j, id]:e[i]){
                if(isb[j]){
                    w[j][0][i]=id;
                    h[i].push_back(mapa(j, id));
                }
                else{
                    g[i].push_back(mapa(j, id));
                }
            }
        }
        else{
            for(auto [j, id]:e[i]){
                if(isb[j]){
                    w[j][0][i]=id;
                    h[i].push_back(mapa(j, id));
                }
            }
        }
    }
    scanf("%d", &q);
    int x;
    while(q--){
        scanf("%s", op);
        if(op[0]=='?'){
            if(!H.empty()){
                ll cur;
                for(auto t:H){
                    cur=t.fi;
                    break;
                }
                printf("%d\n", H[cur]);
                ban[H[cur]]=1;
                H.erase(cur);
                // cout<<"type B"<<endl;
                // cout<<efr[H[cur]]<<' '<<col[efr[H[cur]]]<<' '<<eto[H[cur]]<<' '<<col[eto[H[cur]]]<<endl;
            }
            else{
                int id=0;
                for(auto t:big){
                    if(!w[t][col[t]^1].empty()){
                        int cur;
                        for(auto t:w[t][col[t]^1]){
                            cur=t.fi;
                            break;
                        }
                        id=w[t][col[t]^1][cur];
                        ban[id]=1;
                        w[t][col[t]^1].erase(cur);
                        w[cur][col[t]].erase(t);
                        break;
                    }
                }
                printf("%d\n", id);
                // cout<<"type A"<<endl;
                // cout<<efr[id]<<' '<<col[efr[id]]<<' '<<eto[id]<<' '<<col[eto[id]]<<endl;
            }
        }
        else{
            scanf("%d", &x);
            if(isb[x]){
                for(auto [y, id]:h[x]){
                    if(ban[id]) continue;
                    w[y][col[x]].erase(x);
                    w[y][col[x]^1][x]=id;
                }
            }
            else{
                for(auto [y, id]:g[x]){
                    if(ban[id]) continue;
                    if(col[y]==col[x]){
                        H[hs(x, y)]=id;
                    }
                    else{
                        H.erase(hs(x, y));
                    }
                }
                for(auto [y, id]:h[x]){
                    if(ban[id]) continue;
                    w[y][col[x]].erase(x);
                    w[y][col[x]^1][x]=id;
                }
            }
            col[x]^=1;
        }
    }
}
