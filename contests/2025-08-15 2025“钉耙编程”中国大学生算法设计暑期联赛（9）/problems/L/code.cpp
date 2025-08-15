#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int T,n,m,p[N];
int v[N];
struct Prob{
    int a,rka,b,rkb,id;
}a[N];
unordered_map<int,int> ma;
bool cmpa(Prob a,Prob b){
    if(a.a != b.a)return a.a < b.a;
    else return a.id < b.id;
}
bool cmpb(Prob a,Prob b){
    if(a.b != b.b)return a.b > b.b;
    else return a.id < b.id;
}

void solve(){
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=m;i++) scanf("%d",&p[i]),v[i]=p[i];
    sort(v+1,v+m+1);
    int vid=unique(v+1,v+m+1)-v-1;
    for(int i=1;i<=m;i++){
        p[i]=lower_bound(v+1,v+vid+1,p[i])-v;
    }
    for(int i=1;i<=vid;i++){
        a[i].a = a[i].b = a[i].rka = a[i].rkb = 0;
    }
    
    for(int i=1;i<=m;i++){
        if(!a[p[i]].a)a[p[i]].a=i;
        a[p[i]].b++;
        a[p[i]].id=p[i];
    }
    sort(a+1,a+vid+1,cmpa);
    for(int i=1;i<=vid;i++){
        a[i].rka=i;
        //printf("%d %d %d %d\n",a[i].a,a[i].b,a[i].rka,a[i].rkb);
    }
    sort(a+1,a+vid+1,cmpb);
    int ans=0;
    for(int i=1;i<=vid;i++){
        a[i].rkb=i;
        //printf("%d %d %d %d\n",a[i].a,a[i].b,a[i].rka,a[i].rkb);
        if(a[i].rka != a[i].rkb)ans++;
    }
    printf("%d\n",ans);
    
}
signed main(){
    scanf("%d",&T);
    while(T--){solve();}
}