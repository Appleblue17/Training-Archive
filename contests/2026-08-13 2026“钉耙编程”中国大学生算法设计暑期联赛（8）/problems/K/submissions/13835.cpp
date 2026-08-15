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
struct node{
	int ls, rs;
	ll siz, w; int pri;
	ll val;
    ll tagadd;
    bool tagrev;
}tr[N*10];
int rtl[N], rtr[N];
int idx;
void apply_rev(int x){
    tr[x].tagrev^=1;
    tr[x].tagadd*=-1; tr[x].val*=-1;
    swap(tr[x].ls, tr[x].rs);
}
void apply_add(int x, ll v){
    tr[x].val+=v;
    tr[x].tagadd+=v;
}
void down(int x){
    if(tr[x].ls){
        if(tr[x].tagrev||tr[x].tagadd){
            ++idx;
            tr[idx]=tr[tr[x].ls]; tr[idx].pri=rnd();
            tr[x].ls=idx;
        }
        if(tr[x].tagrev) apply_rev(tr[x].ls);
        if(tr[x].tagadd) apply_add(tr[x].ls, tr[x].tagadd);
    }
    if(tr[x].rs){
        if(tr[x].tagrev||tr[x].tagadd){
            ++idx;
            tr[idx]=tr[tr[x].rs]; tr[idx].pri=rnd();
            tr[x].rs=idx;
        }
        if(tr[x].tagrev) apply_rev(tr[x].rs);
        if(tr[x].tagadd) apply_add(tr[x].rs, tr[x].tagadd);
    }
    tr[x].tagadd=tr[x].tagrev=0;
}
void up(int x){
    tr[x].siz=tr[x].w+tr[tr[x].ls].siz+tr[tr[x].rs].siz;
}
void Split(int rt, ll v, int &x, int &y){
    if(rt==0){
        x=y=0;
        return ;
    }
    ++idx; tr[idx]=tr[rt]; rt=idx;
    down(rt);
    if(tr[rt].val<=v){
        x=rt; Split(tr[rt].rs, v, tr[x].rs, y);
        up(x);
    }
    else{
        y=rt;
        Split(tr[rt].ls, v, x, tr[y].ls);
        up(y);
    }
}
int Merge(int x, int y){
    if(x==0||y==0) return x+y;
    ++idx; tr[idx]=tr[x]; x=idx;
    ++idx; tr[idx]=tr[y]; y=idx;
    down(x); down(y);
    if(tr[x].pri<tr[y].pri){
        tr[x].rs=Merge(tr[x].rs, y);
        up(x);
        return x;
    }
    tr[y].ls=Merge(x, tr[y].ls);
    up(y);
    return y;
}
void add(int &rt, ll x, ll v){
    int xl, xm, xr;
    Split(rt, x-1, xl, xr);
    Split(xr, x, xm, xr);
    // cout<<tr[xl].siz<<' '<<tr[xm].siz<<' '<<tr[xr].siz<<endl;
    ++idx;
    tr[idx]=tr[xm]; tr[idx].pri=rnd(); tr[idx].val=x;
    tr[idx].w+=v; 
    tr[idx].siz+=v;
    xm=idx;
    rt=Merge(Merge(xl, xm), xr);
}
void solve(){
    fin>>n;
    idx=2;
    int lst=0;
    rtl[0]=1; rtr[0]=2; 
    tr[1].val=0; tr[1].tagadd=tr[1].tagrev=0; tr[1].ls=tr[1].rs=0; tr[1].w=tr[1].siz=1; 
    tr[2].val=0; tr[2].tagadd=tr[2].tagrev=0; tr[2].ls=tr[2].rs=0; tr[2].w=tr[2].siz=1; 
    for(int i=1, op; i<=n; ++i){
        ll x, y;
        rtl[i]=rtl[i-1]; rtr[i]=rtr[i-1];
        fin>>op>>x;
        x^=lst;
        if(op==1){
            add(rtl[i], x, 1);
            add(rtr[i], x, 1);
        }
        if(op==2){
            if(rtl[i]!=0){
                ++idx;
                tr[idx]=tr[rtl[i]];
                apply_add(idx, -x);
                rtl[i]=idx;
            }
            if(rtr[i]!=0){
                ++idx;
                tr[idx]=tr[rtr[i]];
                apply_add(idx, x);
                rtr[i]=idx;
            }
        }
        if(op==3){
            fin>>y;
            y^=lst;
            int xl, xm, xr, yl, ym, yr;
            Split(rtl[i], x-1, xl, xr);
            Split(xr, y, xm, xr);
            Split(rtr[i], x-1, yl, yr);
            Split(yr, y, ym, yr);
            {
                ++idx;
                tr[idx]=tr[xm]; tr[idx].pri=rnd();
                apply_rev(idx);
                apply_add(idx, x+y);
                xm=idx;
            }
            {
                ++idx;
                tr[idx]=tr[ym]; tr[idx].pri=rnd();
                apply_rev(idx);
                apply_add(idx, x+y);
                ym=idx;
            }
            ll add1=tr[xl].siz-tr[yl].siz;
            ll add2=tr[yr].siz-tr[xr].siz;
            rtl[i]=Merge(Merge(xl, ym), xr);
            rtr[i]=Merge(Merge(yl, xm), yr);
            add(rtl[i], x-1, add1);
            add(rtl[i], y, add1);
            add(rtr[i], x, add2);
            add(rtr[i], y+1, add2);
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
                fout.pc('N'); fout.pc('o'); fout.pc('\n');
            }
            else{
                fout.pc('Y'); fout.pc('e'); fout.pc('s'); fout.pc('\n');
                ++lst;
            }
        }
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	fin>>T;
	while(T--){
		solve();
	}
	return 0;
}