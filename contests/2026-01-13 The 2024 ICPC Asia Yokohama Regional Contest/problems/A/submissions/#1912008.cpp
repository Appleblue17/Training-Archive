#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int n;
int a[N], b[N];
int tag[N];
signed main(){
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i], b[i]=a[i];
    sort(b+1, b+n+1);
    int ans=0;
    for(int r=n, l; r>=1; r=l-1){
        l=r;
        while(l-1>=1&&b[l-1]==b[l]) --l;
        for(int i=1; i<=n; ++i){
            if(a[i]==b[l]) tag[i]=1;
            else if(a[i]>b[l]) tag[i]=2;
            else tag[i]=0;
        }
        for(int i=1; i<=n; ++i){
            if(tag[i]==0) continue;
            int j=i;
            bool occ=0;
            while(tag[j]!=0){
                if(tag[j]==1) occ=1;
                ++j;
            }
            ans+=occ;
            i=j;
        }
    }
    cout<<ans<<endl;
}
