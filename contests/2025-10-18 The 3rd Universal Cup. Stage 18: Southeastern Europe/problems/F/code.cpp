#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m; 
int lis[N], tot;
vector<int> a[N];
struct bit{
    int tr[N];
    void add(int x, int v){
        for(++x; x<N; x+=(x&-x)) tr[x]+=v;
    }
    int get(int x){
        int ret=0;
        for(++x; x>0; x-=(x&-x)) ret+=tr[x];
        return ret;
    }
}T1, T2;
signed main(){
    scanf("%d", &n);
    for(int i=1, x; i<=n; ++i){
        scanf("%d", &m);
        while(m--){
            scanf("%d", &x);
            a[i].push_back(x);
            lis[++tot]=x;
        }
    }
    sort(lis+1, lis+tot+1);
    tot=unique(lis+1, lis+tot+1)-lis-1;
    int ans=0;
    for(int i=1; i<=n; ++i){
        for(auto &t:a[i]){
            t=lower_bound(lis+1, lis+tot+1, t)-lis;
        }
        sort(a[i].begin(), a[i].end());
        T2.add(tot-a[i][0], 1);
        if(a[i].size()>1){
            T1.add(a[i].back(), 1);
        }
        else{
            T1.add(a[i][0], 1);
        }
        ans+=min(2, (int)a[i].size());
    }
    for(int i=1; i<=n; ++i){
        if(a[i].size()==1) continue;
        T1.add(a[i].back(), -1);
        T2.add(tot-a[i][0], -1);
        int num=T1.get(a[i][0])+T2.get(tot-a[i].back());
        int rep=0;
        for(auto t:a[i]){
            int tem=T1.get(t)+T2.get(tot-t);
            if(tem==num){
                rep=t; break;
            }
        }
        if(rep==0){
            T1.add(a[i].back(), 1);
            T2.add(tot-a[i][0], 1);   
        }
        else{
            --ans;
            T1.add(rep, 1);
            T2.add(tot-rep, 1);  
        }
    }
    printf("%d\n", ans);
}
