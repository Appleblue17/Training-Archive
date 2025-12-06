#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n, m, q;
vector<int> e[N];
int f[N];
int val[N];
int deg[N];
struct myheap{
    priority_queue<int> p, q;
    void push(int x){
        p.push(x);
    }
    void pop(int x){
        q.push(x);
    }
    int top(){
        while(!q.empty()&&q.top()==p.top()){
            p.pop(); q.pop();
        }
        return p.top();
    }
}hp;
void ins(int x, int l, int r){
    int cnt=0;
    for(auto y:e[x]){
        if(val[y]<=1) continue;
        hp.pop(deg[y]);
        ++deg[y];
        hp.push(deg[y]);
        ++cnt;
    }
    hp.pop(deg[x]);
    deg[x]+=cnt;
    hp.push(deg[x]);
}
void add(int x, int l, int r){
    if(val[x]==1){
        ins(x, l, r);
    }
    ++val[x];
}
void era(int x, int l, int r){
    int cnt=0;
    for(auto y:e[x]){
        if(val[y]<=1) continue;
        hp.pop(deg[y]);
        --deg[y];
        hp.push(deg[y]);
        ++cnt;
    }
    hp.pop(deg[x]);
    deg[x]-=cnt;
    hp.push(deg[x]);
}
void del(int x, int l, int r){
    if(val[x]==2){
        era(x, l, r);
    }
    --val[x];
}
int main(){
    scanf("%d%d%d", &n, &m, &q);
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for(int i=1; i<=n; ++i) hp.push(0);
    int l=1;
    for(int r=1; r<=n; ++r){
        int cnt=0;
        for(auto t:e[r]){
            if(t<l||t>r) continue;
            add(t, l, r);
            ++cnt;
        }
        val[r]=cnt;
        if(cnt>1){
            ins(r, l, r);
        }
        // for(int i=1; i<=n; ++i) cout<<val[i]<<' ';
        // cout<<endl;
        // for(int i=1; i<=n; ++i) cout<<deg[i]<<' ';
        // cout<<endl;
        // cout<<l<<' '<<r<<endl;
        while(hp.top()>2){
            cnt=0;
            for(auto t:e[l]){
                if(t<l||t>r) continue;
                ++cnt;
            }
            val[l]=0;
            if(cnt>1){
                era(l, l, r);
            }
            for(auto t:e[l]){
                if(t<l||t>r) continue;
                del(t, l, r);
            }
            ++l;
        }
        f[l]=r;
    }
    for(int i=1; i<=n; ++i) f[i]=max(f[i], f[i-1]);
    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        if(r<=f[l]){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
