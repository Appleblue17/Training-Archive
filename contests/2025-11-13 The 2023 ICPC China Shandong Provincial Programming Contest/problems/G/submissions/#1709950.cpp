#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;

int T,n,k;
int a[N];
unordered_map<int, vector<int> > h;
signed main(){
    cin>>T;
    while(T--){
        h.clear();
        scanf("%lld", &n);
        for(int i=1; i<=n; ++i){
            scanf("%lld", &a[i]);
            h[a[i]-i].push_back(a[i]);
        }
        int ans=0;
        for(auto t:h){
            sort(t.second.begin(), t.second.end(), greater<int>());
            for(int i=0; i+1<(t.second.size()); i+=2){
                if(t.second[i]+t.second[i+1]>0){
                    ans+=t.second[i]+t.second[i+1];
                }
                else{
                    break;
                }
            }
        }
        printf("%lld\n", ans);
    }
}
