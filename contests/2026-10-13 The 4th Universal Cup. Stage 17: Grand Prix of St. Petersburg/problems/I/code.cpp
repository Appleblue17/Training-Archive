#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int st;
int n;
int ind[N];
struct DSU{
    int fa[N];
    int getf(int x){
        if(x==fa[x]) return x;
        return fa[x]=getf(fa[x]);
    }
    bool merge(int x, int y){
        x=getf(x); y=getf(y);
        if(x==y) return true;
        fa[y]=x; return false;
    }
}D;
deque<int> lc[N], rc[N];
int lv[N], rv[N];
int idl[N], idr[N];
void rcmerge(int rt, int x){
    if(rc[idr[rt]].size()>rc[idr[x]].size()){
        while(!rc[idr[x]].empty()) rc[idr[rt]].push_back(rc[idr[x]].front()), rc[idr[x]].pop_front();
    }
    else{
        while(!rc[idr[rt]].empty()) rc[idr[x]].push_front(rc[idr[rt]].back()), rc[idr[rt]].pop_back();
        idr[rt]=idr[x];
    }
}
void lcmerge(int rt, int x){
    if(lc[idl[rt]].size()>lc[idl[x]].size()){
        while(!lc[idl[x]].empty()) lc[idl[rt]].push_back(lc[idl[x]].front()), lc[idl[x]].pop_front();
    }
    else{
        while(!lc[idl[rt]].empty()) lc[idl[x]].push_front(lc[idl[rt]].back()), lc[idl[rt]].pop_back();
        idl[rt]=idl[x];
    }
}
int ed;
int main(){
    // cout<<(&ed-&st)/1024/1024<<endl;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        D.fa[i]=i;
        lv[i]=rv[i]=i;
        lc[i].push_back(i); rc[i].push_back(i);
        idl[i]=idr[i]=i;
    }
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        if(D.merge(x, y)){
            printf("Bad oriented forest\n");
            fflush(stdout);
            return 0;
        }
        ++ind[y];
        if(ind[y]>=2){
            printf("Bad oriented forest\n");
            fflush(stdout);
            return 0;
        }
        int rt=D.getf(x);
        if(rv[rt]+1==lv[y]){
            while(!rc[idr[rt]].empty()){
                if(rc[idr[rt]].back()==x) break;
                rc[idr[rt]].pop_back();
            }
            if(rc[idr[rt]].empty()){
                printf("Bad segment at %d\n", x);
                fflush(stdout);
                return 0;
            }
            rcmerge(rt, y);
            rv[rt]=rv[y];
            printf("Good\n");
            fflush(stdout);
        }
        else if(rv[y]==lv[rt]-1){
            while(!lc[idl[rt]].empty()){
                if(lc[idl[rt]].back()==x) break;
                lc[idl[rt]].pop_back();
            }
            if(lc[idl[rt]].empty()){
                printf("Bad segment at %d\n", x);
                fflush(stdout);
                return 0;
            }
            lcmerge(rt, y);
            lv[rt]=lv[y];
            printf("Good\n");
            fflush(stdout);
        }
        else{
            printf("Bad segment at %d\n", x);
            fflush(stdout);
            return 0;
        }
    }
}