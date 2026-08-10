#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=4e7+5;
int T, n, m;
char s[N], t[N];
inline void read(int &x){
    x=0; char c=getchar();
    for(; c<'0'||c>'9'; c=getchar());
    for(; c>='0'&&c<='9'; c=getchar()) x=(x<<1)+(x<<3)+(c^48);
}
int val[N], w[N], sum[N];
char b[N]; int len;
int p[N];
int suf[N], pre[N];
void init(){
    for(int i=1; i<=len; ++i) w[i]=sum[i]=pre[i]=suf[i]=p[i]=0;
    len=0;
    b[++len]='$'; w[len]=0; b[++len]='#'; w[len]=0;
    for(int i=1; i<=m; ++i) b[++len]=t[i], w[len]=val[i], b[++len]='#', w[len]=0;
    b[++len]='^'; w[len]=0;
    for(int i=1; i<=len; ++i) sum[i]=sum[i-1]+w[i];
    for(int i=1; i<=len; ++i){
        if(b[i]=='v'&&w[i]==2){
            pre[i]=i;
        }
        else{
            pre[i]=pre[i-1];
        }
    }
    suf[len+1]=len+1;
    for(int i=len; i>=1; --i){
        if(b[i]=='v'&&w[i]==2){
            suf[i]=i;
        }
        else{
            suf[i]=suf[i+1];
        }
    }
}
void manacher(){
    int mr=0, mid;
    for(int i=2; i<=len; ++i){
        if(i<mr) p[i]=min(p[2*mid-i], mr-i);
        else p[i]=1;
        while(b[i-p[i]]==b[i+p[i]]) ++p[i];
        if(i+p[i]>mr){
            mr=i+p[i];
            mid=i;
        }
    }
}
void solve(){
    read(n);
    char c=getchar();
    while(c!='w'&&c!='v'&&c!='o') c=getchar();
    for(int i=1; i<=n; ++i){
        s[i]=c; c=getchar();
    }
    m=0;
    for(int i=1; i<=n; ++i){
        if(s[i]=='w'){
            val[++m]=1; t[m]='v';
            val[++m]=1; t[m]='v';
        }
        else{
            val[++m]=2; t[m]=s[i];
        }
    }
    init();
    manacher();
    int mx=0, al=-1, ar=-1;
    for(int i=2; i<=len; ++i){
        int cl=i-p[i]+1, cr=i+p[i]-1;
        while((sum[cr]-sum[cl-1])&1){
            int d1=suf[cl]-cl+1, d2=cr-pre[cr]+1;
            int d=min(d1, d2);
            cl+=d; cr-=d;
            if(cl>cr) break;
        }
        if(cl<=cr){
            if(sum[cr]-sum[cl-1]>mx){
                mx=sum[cr]-sum[cl-1];
                al=cl; ar=cr;
            }
        }
    }
    for(int i=al; i<=ar; ++i){
        if(b[i]!='o'&&b[i]!='v') continue;
        if(b[i]=='o') putchar('o');
        else if(w[i]==2) putchar('v');
        else {
            putchar('w');
            i+=3;
        }
    }
    putchar('\n');
}
signed main(){
    read(T);
    while(T--){
        solve();
    }
}


