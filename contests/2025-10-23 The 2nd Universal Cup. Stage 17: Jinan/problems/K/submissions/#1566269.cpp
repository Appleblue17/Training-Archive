#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int T, n, k, a[N];
struct myheap{
    multiset<int> s1, s2;
    int sum1, sum2;
    void init(){
        s1.insert(-1e18); s2.insert(1e18);
        sum1=0; sum2=0;
    }
    int get(){
        return *s1.rbegin();
    }
    void adjust(){
        while(s1.size()>s2.size()){
            sum1-=*s1.rbegin(); sum2+=*s1.rbegin();
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
        while(s2.size()>s1.size()){
            sum2-=*s2.begin(); sum1+=*s2.begin();
            s1.insert(*s2.begin());
            s2.erase(s2.find(*s2.begin()));
        }
    }
    void ins(int x){
        // cout<<x<<' '<<get()<<endl;
        if(x<=get()) s1.insert(x), sum1+=x;
        else s2.insert(x), sum2+=x;
        // cout<<"ins finish"<<endl;
        adjust();
    }
    void del(int x){
        // cout<<x<<' '<<get()<<endl;
        if(x<=get()) s1.erase(s1.find(x)), sum1-=x;
        else s2.erase(s2.find(x)), sum2-=x;
        // cout<<"del finish"<<endl;
        adjust();
    }
    int calc(){
        return get()*s1.size()-sum1+sum2-get()*s2.size();
    }
};
void solve(){
    scanf("%lld%lld", &n, &k);
    for(int i=1; i<=n; ++i){
        scanf("%lld", &a[i]);
        a[i]-=i;
    }
    myheap H;
    H.init();
    int ans=1;
    for(int l=1, r=0; l<=n; ++l){
        while(r+1<=n){
            ++r;
            H.ins(a[r]);
            if(H.calc()>k){
                H.del(a[r]);
                --r;
                break;
            } 
        }
        ans=max(ans, r-l+1);
        H.del(a[l]);
    }
    printf("%lld\n", ans);
}
signed main(){
    scanf("%lld", &T);
    while(T--){
        solve();
    }
}
