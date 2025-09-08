#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int n;
int fail[N], len[N], ch[N][26], diff[N], slink[N];
int lst=0, cnt=1;
void init(){
    fail[0]=1; fail[1]=0;
    len[0]=0; len[1]=-1;
}
int get_fail(int x, int lim){
    while(s[lim-len[x]-1]!=s[lim]) x=fail[x];
    return x;
}
void ins(int c, int lim){
    int p=get_fail(lst, lim);
    if(!ch[p][c]){
        len[++cnt]=len[p]+2;
        int q=get_fail(fail[p], lim);
        fail[cnt]=ch[q][c];
        ch[p][c]=cnt;
        diff[cnt]=len[cnt]-len[fail[cnt]];
        slink[cnt]=(diff[cnt]==diff[fail[cnt]])?slink[fail[cnt]]:fail[cnt];
    }
    lst=ch[p][c];
}
int f[N], g[N];
int main(){
    scanf("%d", &n);
    scanf("%s", s+1);
    init();
    g[0]=1e9;
    for(int i=1; i<=n; ++i){
        ins(s[i]-'a', i);
        f[i]=1e9;
        for(int p=lst; p; p=slink[p]){
            g[p]=f[i-len[slink[p]]-diff[p]];
            if(fail[p]^slink[p]) g[p]=min(g[p], g[fail[p]]);
            f[i]=min(f[i], g[p]+1);
        }
    }
    printf("%d\n", f[n]);
}
