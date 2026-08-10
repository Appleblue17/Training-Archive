#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, m;
unordered_map<int, bool> h[N];
int deg[N];
int mx[N], fr[N];
void calc(){
    for(int i=1; i<=n; ++i){
        for(auto t:h[i]){
            ++deg[t.first];
        }
    }
    queue<int> que;
    for(int i=1; i<=n; ++i){
        mx[i]=0; fr[i]=0;
        if(!deg[i]) que.push(i);
    }
    while(!que.empty()){
        int x=que.front(); que.pop();
        for(auto t:h[x]){
            int y=t.first;
            if(mx[x]+1>mx[y]){
                mx[y]=mx[x]+1; fr[y]=x;
            }
            if(!(--deg[y])){
                que.push(y);
            }
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1, x, y; i<=m; ++i){
        scanf("%d%d", &x, &y);
        h[x][y]=1;
    }
    while(true){
        calc();
        int arg=1;
        for(int i=2; i<=n; ++i) if(mx[i]>=mx[arg]) arg=i;
        int tem=mx[arg];
        bool flag=0;
        while(fr[arg]){
            printf("? %d %d\n", fr[arg], arg);
            fflush(stdout);
            int tag;
            scanf("%d", &tag);
            if(tag==0){
                h[fr[arg]].erase(arg);
                flag=1;
                break;
            }
            arg=fr[arg];
        }
        if(!flag) {
            printf("! %d\n", tem);
            fflush(stdout);
            return 0;
        }
    }
}
