#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mapa make_pair
typedef long double ld;
typedef unsigned long long ull;
#define ep emplace_back
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return x*f;
}
const int N=2e6+5, B=20;
int T, n, m;
char s[N];
int a[N];
int pid[N], lp[N], rp[N];
bool op[N], op2[N]; bool full[21][N];
int st[21][N], ed[21][N], add[21][N];
void work(int t, int id){
    full[t][id]=1;
    for(int i=0; i<t; ++i) full[t][id]&=(a[i]==0);
    if(full[t][id]==0){
        int p1=0;
        while(p1<=t-1&&a[p1]==0) ++p1;
        st[t][id]=p1;
        int p2=0;
        while(t-1-p2>=0&&a[t-1-p2]==0) ++p2;
        ed[t][id]=p2;
        int lst=0;
        add[t][id]=0;
        for(int i=p1+1; i<t-1-p2; ++i){
            if(a[i]==0) ++lst;
            else{
                add[t][id]+=lst*(lst+1)/2;
                lst=0;
            }
        }
        add[t][id]+=lst*(lst+1)/2;
    }
}
int msk[N][2];
void rebuild(int id){
    if(op[id]) {
        for(int i=lp[id]; i<=rp[id]; ++i) a[i]^=1;
    }
    op[id]=0;
    msk[id][0]=msk[id][1]=0;
    for(int i=rp[id]; i>=lp[id]; --i){
        msk[id][0]<<=1; msk[id][1]<<=1;
        msk[id][0]+=a[i]; msk[id][1]+=a[i]^1;
    }
}
inline int get(int id, int l, int len){
    int ret=msk[id][op[id]]>>(l-lp[id]);
    if(l+len-1<=rp[id]) ret&=((1ll<<len)-1);
    else {
        ret+=(msk[id+1][op[id+1]]&((1<<(len-(rp[id]-l+1)))-1))<<(rp[id]-l+1);
    }
    return ret;
}
int main(){
    // freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
    // freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    for(int i=1; i<=20; ++i){
        for(int j=0; j<(1<<i); ++j){
            for(int k=0; k<i; ++k) a[k]=(j>>k)&1;
            work(i, j);
        }
    }
    n=read(); m=read();
    char tem=getchar();
    while(tem!='0'&&tem!='1') tem=getchar();
    for(int i=1; i<=n; ++i) s[i]=tem, tem=getchar(), a[i]=s[i]-'0';
    for(int i=1; i<=n; ++i) pid[i]=(i-1)/B+1;
    for(int i=1; i<=pid[n]; ++i) lp[i]=rp[i-1]+1, rp[i]=rp[i-1]+B;
    rp[pid[n]]=n;
    for(int i=1; i<=pid[n]; ++i) rebuild(i);
    while(m--){
        int tp;
        tp=read();
        if(tp==1){
            int l, r; l=read(); r=read();
            if(pid[l]==pid[r]){
                for(int i=l; i<=r; ++i) a[i]^=1;
                rebuild(pid[l]);
            }
            else{
                for(int i=l; i<=rp[pid[l]]; ++i) a[i]^=1;
                rebuild(pid[l]);
                for(int i=lp[pid[r]]; i<=r; ++i) a[i]^=1;
                rebuild(pid[r]);
                op2[pid[l]+1]^=1; op2[pid[r]]^=1;
            }
        }
        else{
            for(int i=1; i<=pid[n]; ++i) op2[i]^=op2[i-1], op[i]^=op2[i];
            for(int i=1; i<=pid[n]; ++i) op2[i]=0;
            int l, a, b; 
            l=read(); a=read(); b=read();
            int t=0;
            int lst=0;
            ll ans=0;
            while(t<l){
                int cur=min(l-t, 20);
                int cm=get(pid[a+t], a+t, cur)^get(pid[b+t], b+t, cur);
                if(full[cur][cm]){
                    lst+=cur;
                }
                else{
                    ans+=add[cur][cm];
                    lst+=st[cur][cm];
                    ans+=1ll*lst*(lst+1)/2ll;
                    lst=ed[cur][cm];
                }
                t+=cur;
            }
            ans+=1ll*lst*(lst+1)/2ll;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
