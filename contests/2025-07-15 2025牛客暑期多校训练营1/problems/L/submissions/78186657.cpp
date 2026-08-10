#pragma GCC Optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,b,n,q,a[210000],k;
 
multiset<int> hi;
multiset<int> lo;
multiset<int> pr;
unordered_map<int,int> ma;
int cnt=0,cntl=0,cnth=0;
 
void maintain(){
    while(-*lo.begin() > *hi.begin()){
        cnt++;
        int t = -*lo.begin();
        lo.erase(lo.find(-t));
        ma[t]--;
        hi.insert(t);
    }
    while(lo.size()>k){
        cntl++;
        int t = -*lo.begin();
        lo.erase(lo.find(-t));
        ma[t]--;
        hi.insert(t);
    }
    while(hi.size()>n-k){
        cnth++;
        int t = *hi.begin();
        ma[t]++;
        hi.erase(hi.find(t));
        lo.insert(-t);
    }
}
int query(){
    maintain();
    return -*lo.begin();
}
void prin(){
    printf("lo.begin=%lld,lo.size=%lld,hi.begin=%lld,hi.size=%lld\n",-*lo.begin(),lo.size(),*hi.begin(),hi.size());
    pr = hi;
    while(!pr.empty()){
        printf("hi contained %lld\n",*pr.begin());
        pr.erase(pr.find(*pr.begin()));
    }
    pr = lo;
    while(!pr.empty()){
        printf("lo contained %lld\n",-*pr.begin());
        pr.erase(pr.find(*pr.begin()));
    }
    for(pair<int,int> p:ma){
        printf("ma contained (%lld,%lld)\n",p.first,p.second);
    }
}
 
void solve(){
    hi.clear();lo.clear();ma.clear();
    scanf("%lld%lld",&n,&q);
    k = (n+1)/2;//lo gets the median
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        lo.insert(-a[i]);
        ma[a[i]]++;
    }
    while(lo.size()>k){
        int t = -*lo.begin();
        ma[t]--;
        lo.erase(lo.find(-t));
        hi.insert(t);
    }
    int p,v;
    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&p,&v);
        //prin();
        if(lo.find(-a[p])!=lo.end()){
            ma[a[p]]--;
            lo.erase(lo.find(-a[p]));
        }
        else{
            hi.erase(hi.find(a[p]));
        }
        a[p]+=v;
        lo.insert(-a[p]);
        ma[a[p]]++;
        //int me = query();
        //if(me >= a[p])lo.insert(a[p]);
        //else hi.insert(a[p]);
         
        int me = query();
        //printf("cnt=%lld,cntl=%lld,cnth=%lld\n",cnt,cntl,cnth);
        if(-*lo.begin()==*hi.begin()){
            //int t = lo.count(*lo.begin());
            int t = ma[-*lo.begin()];
            printf("%lld\n",k-t);
        }
        else printf("%lld\n",k);
    }
     
}
 
signed main() {
    //freopen("L.in","r",stdin);
    //freopen("L.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        solve();
    }
     
}
