#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5;
typedef long long ll;
int n;
char s[N];
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
ll sum(ll l, ll r){
    return (r-l+1)*(l+r)/2ll;
}
int main(){
    scanf("%d", &n);
    scanf("%s", s+1);
    init();
    ll ans=0;
    init();
    for(int i=1; i<=n; ++i){
        ins(s[i]-'a', i);
        for(int p=lst; p; p=slink[p]){
            if(fail[p]!=slink[p]){
                int dt=len[p]-len[fail[p]];
                int st=len[p];
                if(len[p]%dt==0){
                    int ed=len[slink[p]]+dt;
                    // cout<<i<<' '<<ed<<' '<<st<<' '<<dt<<' '<<sum(ed/dt-1, st/dt-1)<<endl;
                    ans+=sum(ed/dt-1, st/dt-1);
                }
            }
            else{
                int dt=len[p]-len[fail[p]];
                if(len[p]%dt==0){
                    ans+=len[p]/dt-1;
                }
            }
        }
    }
    printf("%lld\n", ans);
}
