#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5, B=700;
int T, n, m;
char s[N];
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef set<pii>::iterator sit;
set<pii> st;
int sum[B+5];
void add(int len){
    // cout<<"add: "<<len<<endl;
    for(int i=1; i<=B; ++i){
        sum[i]+=(len)/(i+1);
    }
}
void del(int len){
    // cout<<"del: "<<len<<endl;
    for(int i=1; i<=B; ++i){
        sum[i]-=(len)/(i+1);
    }
}
void calc(){
    if(st.size()==2){
        printf("0\n");
        return ;
    }
    sit p=st.begin(); ++p;
    int l1=0, l2=0;
    if((*p).fi==1){
        sit p2=st.end(); --p2; --p2;
        l1=(*p).se-(*p).fi+1;
        if(l1==n){
            int ans=n;
            for(int i=0; i<=B&&i<n; ++i){
                ans=min(ans, 1+i+(n-1-i+2*i+1)/(2*i+2));
            }
            printf("%d\n", ans);
            return ;
        }
        if((*p2).se==n){
            l2=(*p2).se-(*p2).fi+1;
            del(l1);
            del(l2);
            add(l1+l2);
        }
    }
    int ans=n;
    for(int i=1; i<=B&&i<=n; ++i){
        // cout<<"len: "<<i<<' '<<"cnt: "<<sum[i]<<' '<<"stp: "<<((i+1)/2)<<endl;
        ans=min(ans, sum[i]+((i+1)/2));
    }
    printf("%d\n", ans);
    if(l2!=0){
        del(l1+l2);
        add(l1); add(l2);
    }
}
void solve(){
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    st.clear();
    st.insert(mapa(-1, -1));
    st.insert(mapa(n+2, n+2));
    for(int i=1; i<=B; ++i) sum[i]=0;
    for(int l=1; l<=n; ++l){
        if(s[l]=='1') continue;
        int r=l;
        while(r+1<=n&&s[r+1]==s[l]) ++r;
        st.insert(mapa(l, r));
        add(r-l+1);
        l=r+1;
    }
    int tp, l, r;
    bool flag=0;
    while(m--){
        if(flag) calc();
        flag=1;
        scanf("%d%d%d", &tp, &l, &r);
        tp=3-tp;
        // cout<<tp<<' '<<l<<' '<<r<<endl;
        if(tp==1){
            sit p1=st.lower_bound(mapa(l, -1));
            sit p0=p1; p0--;
            int tl=l, tr=r;
            if((*p0).se>=l-1){
                int cl=(*p0).fi, cr=(*p0).se;
                if(cr>=r) {
                    continue;
                }
                del(cr-cl+1);
                st.erase(p0);
                tl=cl;
            }
            sit p2=p1;
            for(; ; ++p2){
                if((*p2).se>=r) break;
                del((*p2).se-(*p2).fi+1);
            }
            st.erase(p1, p2);
            if((*p2).fi<=r+1){
                int cl=(*p2).fi, cr=(*p2).se;
                del(cr-cl+1);
                st.erase(p2);
                tr=cr;
            }
            st.insert(mapa(tl, tr));
            add(tr-tl+1);
        }
        else{
            sit p1=st.lower_bound(mapa(l, -1));
            sit p0=p1; p0--;
            int tl=l, tr=r;
            if((*p0).se>=l){
                int cl=(*p0).fi, cr=(*p0).se;
                del(cr-cl+1);
                if(cr>=r) {
                    st.erase(p0);
                    if(cl<=l-1) add(l-1-cl+1), st.insert(mapa(cl, l-1));
                    if(cr>=r+1) add(cr-(r+1)+1), st.insert(mapa(r+1, cr));
                    continue;
                }
                st.erase(p0);
                if(cl<=l-1) tl=cl;
            }
            sit p2=p1;
            for(; ; ++p2){
                if((*p2).se>=r) break;
                del((*p2).se-(*p2).fi+1);
            }
            st.erase(p1, p2);
            if((*p2).fi<=r){
                int cl=(*p2).fi, cr=(*p2).se;
                del(cr-cl+1);
                st.erase(p2);
                if(cr>=r+1) tr=cr;
            }
            if(tl<=l-1) add(l-1-tl+1), st.insert(mapa(tl, l-1));
            if(tr>=r+1) add(tr-(r+1)+1), st.insert(mapa(r+1, tr));
        }
    }
    calc();
}
int main(){
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}