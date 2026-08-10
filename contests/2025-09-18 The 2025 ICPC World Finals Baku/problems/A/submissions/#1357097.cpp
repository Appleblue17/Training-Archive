#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n;
int tr[N][2];
vector<int> vec[N];
int rt[N];
int sz(int x){
    return vec[rt[x]].size();
}
#define v(i) vec[rt[i]]
void dfs(int x){
    if(x==0) return ;
    if(tr[x][0]==0&&tr[x][1]==0){
        rt[x]=x;
        vec[x].push_back(x);
        return ;
    }
    dfs(tr[x][0]); dfs(tr[x][1]);
    if(sz(tr[x][0])==sz(tr[x][1])+1){
        vector<int> tem;
        for(auto t:v(tr[x][1])){
            tem.push_back(v(tr[x][0]).back());
            v(tr[x][0]).pop_back();
        }
        int lst=v(tr[x][0]).back(); v(tr[x][0]).pop_back();
        v(tr[x][0]).push_back(x);
        v(tr[x][0]).push_back(lst);
        reverse(tem.begin(), tem.end());
        for(int i=0; i<sz(tr[x][1]); ++i){
            v(tr[x][0]).push_back(v(tr[x][1])[i]);
            v(tr[x][0]).push_back(tem[i]);
        }
        rt[x]=rt[tr[x][0]];
    }
    else if(sz(tr[x][0])==sz(tr[x][1])){
        vector<int> tem;
        for(auto t:v(tr[x][0])){
            tem.push_back(v(tr[x][1]).back());
            v(tr[x][1]).pop_back();
        }
        v(tr[x][1]).push_back(x);
        reverse(tem.begin(), tem.end());
        for(int i=0; i<sz(tr[x][0]); ++i){
            v(tr[x][1]).push_back(tem[i]);
            v(tr[x][1]).push_back(v(tr[x][0])[i]);
        }
        rt[x]=rt[tr[x][1]];
    }
    else if(sz(tr[x][1])<sz(tr[x][0])){
        vector<int> tem;
        for(auto t:v(tr[x][1])){
            tem.push_back(v(tr[x][0]).back());
            v(tr[x][0]).pop_back();
        }
        v(tr[x][0]).push_back(x);
        reverse(tem.begin(), tem.end());
        for(int i=0; i<sz(tr[x][1]); ++i){
            v(tr[x][0]).push_back(v(tr[x][1])[i]);
            v(tr[x][0]).push_back(tem[i]);
        }
        rt[x]=rt[tr[x][0]];
    }
    else{
        vector<int> tem;
        for(int i=1; i<sz(tr[x][0]); ++i){
            tem.push_back(v(tr[x][1]).back());
            v(tr[x][1]).pop_back();
        }
        
        v(tr[x][1]).push_back(x);
        reverse(tem.begin(), tem.end());
        for(int i=0; i+1<sz(tr[x][0]); ++i){
            v(tr[x][1]).push_back(v(tr[x][0])[i]);
            v(tr[x][1]).push_back(tem[i]);
        }
        v(tr[x][1]).push_back(v(tr[x][0]).back());
        rt[x]=rt[tr[x][1]];
    }
    // cout<<"rt:"<<x<<endl;
    // for(auto t:v(x)) cout<<t<<' '; cout<<endl;
}
void dfs2(int x){
    if(x==0) return ;
    if(tr[x][0]==0&&tr[x][1]==0){
        rt[x]=x;
        vec[x].push_back(x);
        return ;
    }
    dfs2(tr[x][0]); dfs2(tr[x][1]);
    if(sz(tr[x][1])<sz(tr[x][0])){
        vector<int> tem;
        for(auto t:v(tr[x][1])){
            tem.push_back(v(tr[x][0]).back());
            v(tr[x][0]).pop_back();
        }
        v(tr[x][0]).push_back(x);
        reverse(tem.begin(), tem.end());
        for(int i=0; i<sz(tr[x][1]); ++i){
            v(tr[x][0]).push_back(v(tr[x][1])[i]);
            v(tr[x][0]).push_back(tem[i]);
        }
        rt[x]=rt[tr[x][0]];
    }
    else{
        vector<int> tem;
        for(int i=1; i<sz(tr[x][0]); ++i){
            tem.push_back(v(tr[x][1]).back());
            v(tr[x][1]).pop_back();
        }
        v(tr[x][1]).push_back(x);
        reverse(tem.begin(), tem.end());
        for(int i=0; i<sz(tr[x][0])-1; ++i){
            v(tr[x][1]).push_back(v(tr[x][0])[i]);
            v(tr[x][1]).push_back(tem[i]);
        }
        v(tr[x][1]).push_back(v(tr[x][0]).back());
        rt[x]=rt[tr[x][1]];
    }
}
void solve(){
    scanf("%d",&n);
    for(int i=1; i<=n; ++i){
        scanf("%d%d", &tr[i][0], &tr[i][1]);
        if(tr[i][0]==0&&tr[i][1]!=0){
            printf("impossible\n");
            return ;
        }
    }
    dfs(1);
    for(auto t:vec[rt[1]]) printf("%d ", t);
    putchar('\n');
    for(int i=1; i<=n; ++i) vec[i].clear();
    dfs2(1);
    for(auto t:vec[rt[1]]) printf("%d ", t);
    putchar('\n');
}
int main(){
    // freopen("Ain.txt", "r", stdin);
    // freopen("A2.txt", "w", stdout);
    T=1;
    while(T--){
        solve();
    }
    return 0;
}

