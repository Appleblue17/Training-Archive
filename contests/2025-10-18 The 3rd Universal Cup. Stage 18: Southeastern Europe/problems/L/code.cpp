#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5, eps=5e5;
int n;
int a[N], pos[N];
int tr[N];
void add(int x, int v){
    x+=eps;
    for(; x<N; x+=(x&-x)) tr[x]+=v;
}
int get(int x){
    x+=eps;
    int ret=0;
    for(; x>0; x-=(x&-x)) ret+=tr[x];
    return ret;
}
int main(){
    scanf("%d", &n);
    vector<int> ans;
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        pos[a[i]]=i;
        add(i, 1);
    }
    int lst=pos[n];
    int dlt=0;
    for(int i=n-1; i>=1; --i){
        int rk=get(pos[i]);
        if(rk<lst){
            lst=rk;
        }
        else{
            ans.push_back(rk);
            add(pos[i], -1);
            --dlt;
            add(dlt, 1);
            lst=1;
        }
    }
    printf("%d %d\n", (int)ans.size(), (int)ans.size());
    // reverse(ans.begin(), ans.end());
    for(auto t:ans){
        printf("%d %d\n", t, 1);
    }
}
