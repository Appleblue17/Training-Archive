#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
int n, m;
int a[N];
int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; ++i) scanf("%d", &a[i]);
    ll ans=0;
    ll sum=0;
    int cl=0, cr=0;
    multiset<int> st;
    for(int i=1, l, r, w; i<=n; ++i){
        scanf("%d%d%d", &l, &r, &w);
        if(cr<l){
            cl=l; cr=r;
            sum=0;
            for(int i=l; i<=r; ++i) sum+=a[i];
            st.clear();
        }
        else{
            while(cl<l){
                while(!st.empty()&&a[cl]>0){
                    --a[cl];
                    st.erase(st.find(*st.rbegin()));
                }
                int cur=min(sum, (ll)a[cl]);
                sum-=cur; a[cl]-=cur;
                ++cl;
            }
            while(cr<r){
                ++cr;
                sum+=a[cr];
            }
        }
        if(sum!=0){
            --sum;
            ans+=w;
            st.insert(w);
        }
        else if(!st.empty()&&*st.begin()<w){
            ans+=w-(*st.begin());
            st.erase(st.find(*st.begin()));
            st.insert(w);
        }
    }
    printf("%lld\n", ans);
}
