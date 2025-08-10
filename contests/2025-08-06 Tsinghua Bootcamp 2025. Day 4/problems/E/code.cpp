#include<bits/stdc++.h>
using namespace std;
const int N=1e6+56, inf=1e9;
int n;
pair<int, int> f[N];
bool check(int x){
    int id=0;
    for(int i=1; i<=n; ++i){
        if(f[i].second<=x){
            id=i;
        }
    }
    if(id==0) return false;
    int val=f[id].first;
    for(int i=1; i<=n; ++i){
        if(i==id) continue;
        if(f[i].first>=val) return false;
        ++val;
    }
    return true;
}
int main(){
    scanf("%d", &n);
    for(int i=1, x, y; i<=n; ++i){
        scanf("%d", &f[i].first);
    }
    for(int i=1, x, y; i<=n; ++i){
        scanf("%d", &f[i].second);
    }
    sort(f+1, f+n+1);
    int L=1, R=inf, mid, ret=inf+1;
    while(L<=R){
        mid=(L+R)/2;
        if(check(mid)){
            ret=mid; R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    if(ret==inf+1) ret=-1;
    printf("%d\n", ret);
}