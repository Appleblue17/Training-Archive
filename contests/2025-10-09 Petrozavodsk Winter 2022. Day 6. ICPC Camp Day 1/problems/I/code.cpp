#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int N=1.1e6+5;
const int eps=1e6;
int n, T, op, X;
int qtp[N], qx[N], qy[N];
int px[N], py[N], idx, ptim[N];
multiset<int> sb[N];
/*inline ll hs(int x, int y){
    return 1000000000ll*x+y;
}
unordered_map<ll, vector<int> > h;
vector<int> vec[N<<2];
void ins(int p, int l, int r, int L, int R, int v){
    if(L<=l&&r<=R){
        vec[p].emplace_back(v);
        return ;
    }
    int mid=(l+r)>>1;
    if(L<=mid) ins(p<<1, l, mid, L, R, v);
    if(R>mid) ins(p<<1|1, mid+1, r, L, R, v);
}
typedef pair<int, int> pii;
#define fi first
#define se second
#define mapa make_pair
struct ST1{
    int val[N];
    vector<pii> del[30], add[30];
    set<pii> st;
    void upd(int o, int id, int x, int y){
        val[id]=y;
        set<pii>::iterator it=st.lower_bound(mapa(x, -1));
        set<pii>::iterator it2=it;
        while(it2!=st.end()){
            if(val[(*it2).se]<=y){
                del[o].push_back(*it2);
                ++it2;
            }
            else{
                break;
            }
        }
        bool flag=1;
        if(it!=st.end()&&(*it).fi==x&&val[(*it).se]>=y){
            flag=0;
        }
        st.erase(it, it2);
        if(flag){
            st.insert(mapa(x, id));
            add[o].push_back(mapa(x, id));
        }
    }
    int get(int x){
        set<pii>::iterator it=st.upper_bound(mapa(x, n));
        if(it==st.begin()) return 0;
        --it;
        return val[(*it).se];
    }
    void back(int o){
        while(!add[o].empty()) {
            if(st.find(add[o].back())!=st.end()) st.erase(st.find(add[o].back()));
            add[o].pop_back();
        }
        while(!del[o].empty()) st.insert(del[o].back()), del[o].pop_back();
    }
}st1;

struct ST2{
    int val[N];
    vector<pii> del[30], add[30];
    set<pii> st;
    void upd(int o, int id, int x, int y){
        val[id]=y;
        set<pii>::iterator it=st.lower_bound(mapa(eps-x, -1));
        set<pii>::iterator it2=it;
        while(it2!=st.end()){
            if(val[(*it2).se]<=y){
                del[o].push_back(*it2);
                ++it2;
            }
            else{
                break;
            }
        }
        bool flag=1;
        if(it!=st.end()&&(*it).fi==eps-x&&val[(*it).se]>=y){
            flag=0;
        }
        st.erase(it, it2);
        if(flag){
            st.insert(mapa(eps-x, id));
            add[o].push_back(mapa(eps-x, id));
        }
    }
    int get(int x){
        set<pii>::iterator it=st.upper_bound(mapa(eps-x, n));
        if(it==st.begin()) return 0;
        --it;
        return val[(*it).se]+x;
    }
    void back(int o){
        while(!add[o].empty()) {
            if(st.find(add[o].back())!=st.end()) st.erase(st.find(add[o].back()));
            add[o].pop_back();
        }
        while(!del[o].empty()) st.insert(del[o].back()), del[o].pop_back();
    }
}st2;
void solve(int o, int p, int l, int r){
    for(auto t:vec[p]){
        st1.upd(o, t, max(0, py[t]-px[t]), py[t]);
        if(py[t]-px[t]>0) st2.upd(o, t, py[t]-px[t], px[t]);
    }
    if(l==r){
        if(qtp[l]!=3) {
            st1.back(o);
            st2.back(o);
            return ;
        }
        printf("%d\n", max(st1.get(qx[l]), st2.get(qx[l])));
        st1.back(o);
        st2.back(o);
        return ;
    }
    int mid=(l+r)>>1;
    solve(o+1, p<<1, l, mid); solve(o+1, p<<1|1, mid+1, r);
    st1.back(o);
    st2.back(o);
}*/
const int RB = 1e6+10;
inline int lowbit(int x){
    return x & (-x);
}
int seg[N*4][2];
void change(int rt,int le,int ri,int num,int pos,int x){
    //if(rt==1)printf("change %lld %lld %lld\n",num,pos,x);fflush(stdout);
    if(le == ri && le == pos){
        seg[rt][num] = x;
        return;
    }
    int mi = (le+ri)/2;
    if(pos <= mi){
        change(rt*2,le,mi,num,pos,x);
    }
    else{
        change(rt*2+1,mi+1,ri,num,pos,x);
    }
    seg[rt][num] = max(seg[rt*2][num],seg[rt*2+1][num]);
}

int query(int rt,int le,int ri,int num,int pos){
    if(pos >= ri){
        return seg[rt][num];
    }
    //printf("query %lld %lld %lld %lld %lld\n",rt,le,ri,num,pos);fflush(stdout);
    int ans=-1e9,mi = (le+ri)/2;
    if(pos <= mi){
        ans = max(ans,query(rt*2,le,mi,num,pos));
    }
    else{
        ans = max(ans,query(rt*2,le,mi,num,pos));
        ans = max(ans,query(rt*2+1,mi+1,ri,num,pos));
    }
    return ans;
    
}
multiset<int>::iterator it;
signed main(){
    for(int i=0;i<N*4;i++)seg[i][0]=seg[i][1]=-1e9;
    for(int i=0;i<N;i++)sb[i].insert(-1e9);
    scanf("%lld", &T);
    for(int i=1; i<=T; ++i){
        scanf("%d", &qtp[i]);
        if(qtp[i]==3){
            int pos=0;
            scanf("%lld", &pos);
            int ans[2]={0,0};
            ans[1] = query(1,1,RB,1,pos+1);
            ans[0] = query(1,1,RB,0,1e6+5-pos)+pos;
            //printf("ans = %lld,%lld\n",ans[0],ans[1]);fflush(stdout);
            printf("%lld\n",max(ans[1],ans[0]));
            //cout << '*' << i << ' ' << T << endl;
        }
        else{
            int a,b;
            scanf("%lld%lld", &a, &b);
            if(a < b)b = a;
            if(qtp[i]==1){
                int yb=-1e9;
                if(!sb[a-b].empty()){
                    //ya=*sa[a-b].begin();
                    it = sb[a-b].end();it--;
                    yb = *it;
                }
                sb[a-b].insert(b);
                //sa[a-b].insert(a);
                int nb=-1e9;
                if(!sb[a-b].empty()){
                    //na=*sa[a-b].begin();
                    it = sb[a-b].end();it--;
                    nb = *it;
                }
                if(yb != nb){
                    change(1,1,RB,1,a-b+1,nb+a-b);//pos+1
                    //cout << nb+a-b << endl;
                    change(1,1,RB,0,1e6+5-a+b,nb);//1e6+5-pos
                }
            }
            else{
                int yb=-1e9,nb=-1e9;
                if(!sb[a-b].empty()){
                    //ya=*sa[a-b].begin();
                    it = sb[a-b].end();it--;
                    yb = *it;
                }
                sb[a-b].erase(sb[a-b].find(b));
                //sb[a-b].erase(sb[a-b].find(a));
                if(!sb[a-b].empty()){
                    //na=*sa[a-b].begin();
                    it = sb[a-b].end();it--;
                    nb = *it;
                }
                if(yb != nb){
                    change(1,1,RB,1,a-b+1,nb+a-b);//pos+1
                    change(1,1,RB,0,1e6+5-a+b,nb);//1e6+5-pos
                }
            }
        }
    }
    return 0;
}
