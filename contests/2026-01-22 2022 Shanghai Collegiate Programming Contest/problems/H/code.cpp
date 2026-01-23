#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int T, n, m, k;
int a[N];
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &k);
        for(int i=1; i<=n; ++i){
            scanf("%d", &a[i]); a[i+n]=a[i];
        }
        bool flag=1;
        for(int i=1; i<=n; ++i){
            if(a[i]!=a[1]) flag=0;
        }
        if(flag){
            printf("%d\n", (n+k-1)/k);
            continue;
        }
        int st=-1;
        for(int i=1; i<=n; ++i) if(a[i]!=a[i+1]){
            st=i+1; break;
        }
        
        int ans=0, mx=0; 
        for(int l=st, r; l<=st+n-1; ++l){
            r=l;
            while(r+1<=st+n-1&&a[r+1]==a[l]) ++r;
            ans+=(r-l+1+k-1)/k;
            mx=max(mx, r-l+1);
            // cout<<l<<' '<<r<<endl;
            l=r;
        }
        if(mx<k) ans=-1;
        printf("%d\n", ans);
    }
}
