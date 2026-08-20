#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int T, n;
int a[N];
int rd(){
	char c=getchar();
	int tot=0; bool f=0;
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) tot=(tot<<1)+(tot<<3)+(c^48),c=getchar();
	return f?-tot:tot;
}
int cnt[N];
int b[N], m;
int c[N], m2;
void solve(){
    bool flg=0;
    n=rd();
    for(int i=1; i<=n; ++i) a[i]=rd(), flg&=(a[i]>n);
    if(flg){
        printf("YES");
        return ;
    }
    for(int i=1; i<=n; ++i) cnt[i]=0;
    m=0;
    for(int i=1; i<=n; ++i) if(a[i]-i!=0) b[++m]=a[i]-i;
    sort(b+1, b+m+1);
    m2=0;
    for(int r=m, l; r>=1; r=l-1){
        l=r;
        while(b[l-1]==b[l]&&l-1>0) --l;
        int dt=b[l]-b[l-1];
        for(int i=1; i<=dt; ++i) c[++m2]=m-l+1;
    }
    sort(c+1, c+m2+1);
    if(m!=m2){
        printf("YES\n");
        return ;
    }
    for(int i=1; i<=m; ++i) if(b[i]!=c[i]){
        printf("YES\n");
        return ;
    }
    int mx=0;
    for(int i=1; i<=m; ++i) mx=max(mx, min(i, c[m-i+1]));
    // cout<<mx<<endl;
    if(mx&1){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
signed main(){
    T=rd();
    while(T--){
        solve();
    }
}