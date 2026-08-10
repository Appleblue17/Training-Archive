#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
#define int long long
int n, m;
int lp[N], rp[N];
int presum[N];
int res=1e18;
vector<pair<int, int> > vec;
int mnpos=n, mxpos2, mnpos2, mxpos=1;
void solve(){
    if(vec.empty()||(int)vec.size()==m){
        printf("%lld\n", mxpos-mnpos);
        exit(0);
    }
    sort(vec.begin(), vec.end());
    int ans=mxpos-vec[0].first;
    int mmxxrr=0;
    for(auto t:vec) mmxxrr=max(mmxxrr, t.second);
    ans=min(ans, mmxxrr-mnpos);
    res=min(res, mxpos-mnpos2+mxpos-mnpos);
    int pre=0;
    vector<pair<pair<int, int>, int> > bin;
    multiset<int> st;
    for(int l=0; l<(int)vec.size(); ){
        int r=l, mxr=vec[l].second;
        while(r+1<(int)vec.size()&&vec[r+1].first<=mxr){
            ++r; mxr=max(mxr, vec[r].second);
        }
        presum[l]=pre;
        pre+=mxr-vec[l].first;
        presum[r]=pre;
        int cur=pre*2;
        if(r+1<(int)vec.size()) cur+=mxpos-vec[r+1].first;
        ans=min(ans, cur);
        bin.push_back(make_pair(make_pair(mxr, r), cur));
        l=r+1;
        st.insert(cur);
    }
    for(auto t:bin){
        ans=min(ans, (*st.begin())-2ll*presum[t.first.second]+t.first.first-mnpos);
        st.erase(st.find(t.second));
    }
    res=min(res, ans+mxpos-mnpos);
}
signed main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
    scanf("%lld%lld", &n, &m);
    mnpos=1e18; mxpos=-1e18; mnpos2=1e18;
    for(int i=1; i<=m; ++i){
        scanf("%lld%lld", &lp[i], &rp[i]);
        mnpos=min(mnpos, min(lp[i], rp[i]));
        mxpos=max(mxpos, max(lp[i], rp[i]));
        if(lp[i]>rp[i]){
            vec.push_back(make_pair(rp[i], lp[i]));
        }
        else{
            mnpos2=min(mnpos2, lp[i]);
        }
    }
    solve();
    vec.clear();
    mnpos=1e18; mxpos=-1e18; mnpos2=1e18;
    for(int i=1; i<=m; ++i){
        lp[i]=n-lp[i]+1; rp[i]=n-rp[i]+1;
        mnpos=min(mnpos, min(lp[i], rp[i]));
        mxpos=max(mxpos, max(lp[i], rp[i]));
        if(lp[i]>rp[i]){
            vec.push_back(make_pair(rp[i], lp[i]));
        }
        else{
            mnpos2=min(mnpos2, lp[i]);
        }
    }
    solve();
    printf("%lld\n", res);
}