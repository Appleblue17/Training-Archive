#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m;
vector<int> fav[N], bin[N];
vector<int> del[N];
void solve(){
    scanf("%d%d",&n,&m);
    set<int> st;
    for(int i=1; i<=m; ++i) bin[i].clear(), del[i].clear(), st.insert(i);
    for(int i=1, p, c, x; i<=n; ++i){
        scanf("%d%d", &p, &c);
        bin[p].push_back(i);
        fav[i].clear();
        while(c--){
            scanf("%d", &x);
            fav[i].push_back(x);
        }
    }
    for(int i=m; i>=1; --i){
        if(st.size()<i){
            printf("no\n");
            return ;
        }
        for(auto t:bin[i]){
            for(auto w:fav[t]){
                if(st.find(w)!=st.end()){
                    del[i].push_back(w);
                    st.erase(w);
                }
            }
        }
    }
    for(int i=1; i<=m; ++i){
        for(auto t:del[i]) st.insert(t);
        if(st.empty()){
            printf("no\n");
            return ;
        }
        if(bin[i].empty()){
            st.erase(st.begin());
            continue;
        }
        unordered_map<int, int> h;
        for(auto t:bin[i]){
            for(auto w:fav[t]) ++h[w];
        }
        int w=-1;
        for(auto t:h){
            if(t.second==(int)bin[i].size()){
                if(st.find(t.first)!=st.end()){
                    w=t.first;
                    break;
                }
            }
        }
        if(w==-1){
            printf("no\n");
            return ;
        }
        st.erase(st.find(w));
    }
    printf("yes\n");
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}
