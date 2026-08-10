#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
vector<int> e[N];
int v[N], deg[N];
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
vector<int> bin1, bin2; set<pair<int, pii> > bin3;
vector<int> vec[N];
bool ban[N];
int rnd;
void ins(int i){
    // cout<<"add: "<<i<<endl;
    if(v[i]) bin1.push_back(i);
    else {
        int x;
        for(int j:e[i]) if(!ban[j]) x=j;
        if(v[x]) {
            bin3.erase(bin3.find(mapa(vec[x].size(), mapa(deg[x], x))));
            vec[x].push_back(i);
            bin3.insert(mapa(vec[x].size(), mapa(deg[x], x)));
        }
        else bin2.push_back(i);
    }
}
bool check(int lim){
    for(int i=1; i<=n; ++i) v[i]=(i>=lim), deg[i]=0, ban[i]=0, vec[i].clear();
    for(int i=1; i<=n; ++i){
        for(auto j:e[i]){
            ++deg[j];
        }
    }
    bin1.clear(); bin2.clear(); bin3.clear();
    for(int i=1; i<=n; ++i) bin3.insert(mapa(0, mapa(deg[i], i)));
    for(int i=1; i<=n; ++i) if(deg[i]==1){
        ins(i);
    }
    for(rnd=1; rnd<=n; ++rnd){
        // cout<<"rnd: "<<rnd<<' '<<n<<endl;
        // for(int x=1; x<=n; ++x) if(!ban[x]){
        //     for(auto y:e[x]) if(!ban[y]&&x<y){
        //         cout<<x<<' '<<y<<endl;
        //     }
        // }
        if(rnd&1){
            if(n==rnd){
                for(int i=1; i<=n; ++i) if(!ban[i]) return v[i];
            }
            if(!bin1.empty()){
                return true;
            }
            if(!bin2.empty()){
                int x=bin2.back(); bin2.pop_back();
                // cout<<"del: "<<x<<endl;
                bin3.erase(mapa(vec[x].size(), mapa(deg[x], x)));
                ban[x]=1;
                for(auto y:e[x]) if(!ban[y]){
                    bin3.erase(mapa(vec[y].size(), mapa(deg[y], y)));
                    --deg[y];
                    bin3.insert(mapa(vec[y].size(), mapa(deg[y], y)));
                    if(deg[y]==1){
                        ins(y);
                    }
                }
            }
            else{
                int y=(*bin3.rbegin()).se.se;
                bin3.erase(mapa(vec[y].size(), mapa(deg[y], y)));
                int x=vec[y].back(); vec[y].pop_back();
                --deg[y];
                bin3.insert(mapa(vec[y].size(), mapa(deg[y], y)));
                // cout<<"del: "<<x<<endl;
                ban[x]=1;
                bin3.erase(mapa(vec[x].size(), mapa(deg[x], x)));
                if(deg[y]==1){
                    ins(y);
                }
            }
        }
        else{
            if(n==rnd) return false;
            if(!bin1.empty()){
                int x=bin1.back(); bin1.pop_back();
                // cout<<"del: "<<x<<endl;
                ban[x]=1;
                bin3.erase(mapa(vec[x].size(), mapa(deg[x], x)));
                for(auto y:e[x]) if(!ban[y]){
                    bin3.erase(mapa(vec[y].size(), mapa(deg[y], y)));
                    --deg[y];
                    bin3.insert(mapa(vec[y].size(), mapa(deg[y], y)));
                    if(deg[y]==1){
                        ins(y);
                    }
                }
                continue;
            }
            if(!bin2.empty()){
                int x=bin2.back(); bin2.pop_back();
                // cout<<"del: "<<x<<endl;
                bin3.erase(mapa(vec[x].size(), mapa(deg[x], x)));
                ban[x]=1;
                for(auto y:e[x]) if(!ban[y]){
                    bin3.erase(mapa(vec[y].size(), mapa(deg[y], y)));
                    --deg[y];
                    bin3.insert(mapa(vec[y].size(), mapa(deg[y], y)));
                    if(deg[y]==1){
                        ins(y);
                    }
                }
            }
            else{
                int y=(*bin3.rbegin()).se.se;
                bin3.erase(mapa(vec[y].size(), mapa(deg[y], y)));
                int x=vec[y].back(); vec[y].pop_back();
                --deg[y];
                bin3.insert(mapa(vec[y].size(), mapa(deg[y], y)));
                // cout<<"del: "<<x<<endl;
                ban[x]=1;
                bin3.erase(mapa(vec[x].size(), mapa(deg[x], x)));
                if(deg[y]==1){
                    ins(y);
                }
            }
            
        }
    }
    return false;
}
int main(){
    // freopen("G.in", "r", stdin);
    // freopen("G1.out", "w", stdout);
    scanf("%d", &n);
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    int L=2, R=n, mid, ret=1;
    while(L<=R){
        mid=(L+R)>>1;
        if(check(mid)){
            ret=mid; L=mid+1;
        }
        else{
            R=mid-1;
        }
    }
    printf("%d\n", ret);
}
