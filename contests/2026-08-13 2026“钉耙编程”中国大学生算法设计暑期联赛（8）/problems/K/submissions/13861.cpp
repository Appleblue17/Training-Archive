#pragma GCC optimize(2)
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
mt19937 rnd(1234);
struct IO{
    static const int S=1<<21;
    char buf[S],*p1,*p2;int st[105],Top;
    ~IO(){clear();}
    inline void clear(){fwrite(buf,1,Top,stdout);Top=0;}
    inline void pc(const char c){Top==S&&(clear(),0);buf[Top++]=c;}
    inline char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    inline IO&operator >> (char&x){while(x=gc(),x==' '||x=='\n'||x=='\r');return *this;}
    template<typename T>inline IO&operator >> (T&x){
        x=0;bool f=0;char ch=gc();
       while(!isdigit(ch)){if(ch=='-') f^=1;ch=gc();}
        while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=gc();
        f?x=-x:0;return *this;
    }
    inline IO&operator << (const char c){pc(c);return *this;}
    template<typename T>inline IO&operator << (T x){
        if(x<0) pc('-'),x=-x;
        do{st[++st[0]]=x%10,x/=10;}while(x);
        while(st[0]) pc('0'+st[st[0]--]);return *this;
    }
}fin,fout;
const int N=1e6+5;
int T, n;
int tim;
struct node{
	int ls, rs;
	int siz, w, pri, stp;
	ll val;
    ll tagadd;
    bool tagrev;
}tr[N*30];
int rtl[N], rtr[N];
int idx;
int gen(int x){
    if(tr[x].stp==tim) return x;
    ++idx;
    tr[idx]=tr[x];
    tr[idx].stp=tim; tr[idx].pri=rnd();
    return idx;
}
int apply_rev(int x){
    if(!x) return 0;
    x=gen(x);
    tr[x].tagrev^=1;
    tr[x].tagadd*=-1; tr[x].val*=-1;
    swap(tr[x].ls, tr[x].rs);
    return x;
}
int apply_add(int x, ll v){
    if(!x) return 0;
    x=gen(x);
    tr[x].val+=v;
    tr[x].tagadd+=v;
    return x;
}
int down(int x){
    if(!x) return 0;
    x=gen(x);
    if(tr[x].tagrev){
        tr[x].ls=apply_rev(tr[x].ls);
        tr[x].rs=apply_rev(tr[x].rs);
    }
    if(tr[x].tagadd){
        tr[x].ls=apply_add(tr[x].ls, tr[x].tagadd);
        tr[x].rs=apply_add(tr[x].rs, tr[x].tagadd);
    }
    tr[x].tagadd=tr[x].tagrev=0;
    return x;
}
int up(int x){
    if(!x) return 0;
    tr[x].siz=tr[x].w+tr[tr[x].ls].siz+tr[tr[x].rs].siz;
    return x;
}
void Split(int rt, ll v, int &x, int &y){
    if(rt==0){
        x=y=0;
        return ;
    }
    rt=down(rt);
    if(tr[rt].val<=v){
        Split(tr[rt].rs, v, x, y);
        tr[rt].rs=x; 
        x=up(rt);
    }
    else{
        Split(tr[rt].ls, v, x, y);
        tr[rt].ls=y;
        y=up(rt);
    }
}
int Merge(int x, int y){
    if(x==0||y==0) return x+y;
    if(tr[x].pri<tr[y].pri){
        x=down(x); 
        tr[x].rs=Merge(tr[x].rs, y);
        return up(x);
    }
    y=down(y);
    tr[y].ls=Merge(x, tr[y].ls);
    return up(y);
}
void add(int &rt, ll x, int v){
    if(!v) return ;
    int xl, xm, xr;
    Split(rt, x-1, xl, xr);
    Split(xr, x, xm, xr);
    // cout<<tr[xl].siz<<' '<<tr[xm].siz<<' '<<tr[xr].siz<<endl;
    ++idx;
    tr[idx]=tr[xm]; tr[idx].pri=rnd(); tr[idx].val=x;
    tr[idx].w+=v; 
    tr[idx].siz+=v; 
    tr[idx].stp=tim;
    xm=idx;
    rt=Merge(Merge(xl, xm), xr);
}
void solve(){
    fin>>n;
    idx=2;
    int lst=0;
    rtl[0]=1; rtr[0]=2; 
    tr[1].val=0; tr[1].tagadd=tr[1].tagrev=0; tr[1].ls=tr[1].rs=0; tr[1].w=tr[1].siz=1; tr[1].stp=0;
    tr[2].val=0; tr[2].tagadd=tr[2].tagrev=0; tr[2].ls=tr[2].rs=0; tr[2].w=tr[2].siz=1; tr[2].stp=0;
    for(int i=1, op; i<=n; ++i){
        tim=i;
        ll x, y;
        rtl[i]=rtl[i-1]; rtr[i]=rtr[i-1];
        fin>>op>>x;
        x^=lst;
        if(op==1){
            add(rtl[i], x, 1);
            add(rtr[i], x, 1);
        }
        if(op==2){
            rtl[i]=apply_add(rtl[i], -x);
            rtr[i]=apply_add(rtr[i], x);
        }
        if(op==3){
            fin>>y;
            y^=lst;
            int xl, xm, xr, yl, ym, yr;
            Split(rtl[i], x-1, xl, xr);
            Split(xr, y, xm, xr);
            Split(rtr[i], x-1, yl, yr);
            Split(yr, y, ym, yr);
            xm=apply_rev(xm);
            xm=apply_add(xm, x+y);
            ym=apply_rev(ym);
            ym=apply_add(ym, x+y);
            int add1=tr[xl].siz-tr[yl].siz;
            int add2=tr[yr].siz-tr[xr].siz;
            rtl[i]=Merge(Merge(xl, ym), xr);
            rtr[i]=Merge(Merge(yl, xm), yr);
            add(rtr[i], x-1, add1);
            add(rtr[i], y, add1);
            add(rtl[i], x, add2);
            add(rtl[i], y+1, add2);
        }
        if(op==4){
            rtl[i]=rtl[x]; rtr[i]=rtr[x];
        }
        if(op==5){
            int xl, xr, yl, yr;
            Split(rtl[i], x, xl, xr);
            Split(rtr[i], x-1, yl, yr);
            // cout<<tr[xl].siz<<' '<<tr[yl].siz<<endl;
            if(tr[xl].siz==tr[yl].siz){
                // cout<<"No"<<endl;
                fout.pc('N'); fout.pc('o'); fout.pc('\n');
            }
            else{
                // cout<<"Yes"<<endl;
                fout.pc('Y'); fout.pc('e'); fout.pc('s'); fout.pc('\n');
                ++lst;
            }
            rtl[i]=rtl[i-1]; rtr[i]=rtr[i-1];
        }
    }
}
void run(){
    fin>>T;
	for(int i=1; i<=T; ++i){
		solve();
        // cout<<"finish:"<<i<<endl;
    }
    exit(0);
}
char __stack_space[256 << 20];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    #if defined(__x86_64__) || defined(_M_X64)
        __asm__ __volatile__ (
            "movq %0, %%rsp\n\t"
            "call %P1\n\t"
            : 
            : "r" (__stack_space + sizeof(__stack_space)), "i" (run)
            : "memory"
        );
    #else
        __asm__ __volatile__ (
            "movl %0, %%esp\n\t"
            "call %P1\n\t"
            : 
            : "r" (__stack_space + sizeof(__stack_space)), "i" (run)
            : "memory"
        );
    #endif
	return 0;
}