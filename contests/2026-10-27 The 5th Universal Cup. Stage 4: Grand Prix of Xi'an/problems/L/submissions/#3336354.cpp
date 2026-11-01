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
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=300;
int T, n, m;
// int adj[N][N];
// bool ban[N];
// bool vis[N];
// int asktimes;
bool ask(int x, int y, vector<int> s){
    // ++asktimes;
    if(x==y) while(1);
    for(auto t:s) if(t==x||t==y){
        while(1);
    }
    cout<<"? "<<x<<' '<<y<<' '<<s.size();
    for(auto t:s) cout<<' '<<t;
    cout<<endl;
    // for(auto t:s) ban[t]=1;
    // queue<int> que;
    // for(int i=1; i<=n; ++i) vis[i]=0;
    // que.push(x); vis[x]=1;
    bool ret=0;
    // while(!que.empty()){
    //     int u=que.front(); que.pop();
    //     if(u==y) {ret=1; break;}
    //     for(int v=1; v<=n; ++v) if(!ban[v]&&!vis[v]&&adj[u][v]){
    //         vis[v]=1;
    //         que.push(v);
    //     }
    // }
    // for(auto t:s) ban[t]=0;
    cin>>ret;
    return ret;
}
vector<vector<int> > cir;
vector<pii> ans;
bool notge[N];
int fa[N];
int getf(int x){
    if(x==fa[x]) return x;
    return fa[x]=getf(fa[x]);
}
void merge(int x, int y){
    x=getf(x); y=getf(y);
    if(x==y) return ;
    fa[x]=y;
}
void divide(vector<int> vec){
    if(vec.size()==2){
        ans.ep(vec[0], vec[1]);
        return ;
    }
    // cout<<"cur:";
    // for(auto t:vec) cout<<t<<' ';
    // cout<<endl;
    int ge=0;
    for(auto t:vec){
        if(notge[t]) continue;
        notge[t]=1;
        int piv=vec[0];
        if(piv==t) piv=vec[1];
        for(auto x:vec) if(x!=piv&&x!=t){
            vector<int> st; st.ep(t);
            if(!ask(piv, x, st)){
                ge=t;
                break;
            }
        }
        if(ge) break;
    }
    // cout<<ge<<endl;
    if(ge==0){
        cir.ep(vec);
        return ;
    }
    vector<int> gest; gest.ep(ge);
    vector<vector<int> > com;
    for(auto t:vec) if(t!=ge){
        int bel=-1;
        for(int i=0; i<(int)com.size(); ++i){
            if(ask(t, com[i][0], gest)){
                bel=i; break;
            }
        }
        // cout<<t<<' '<<bel<<endl;
        if(bel==-1) {
            vector<int> ncom;
            ncom.ep(t);
            com.ep(ncom);
        }
        else{
            com[bel].ep(t);
        }
    }
    for(auto &t:com) t.ep(ge);
    for(auto t:com){
        divide(t);
    }
}
void solve(){
    // asktimes=0;
    cin>>n;
    // cin>>m;
    // for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) adj[i][j]=0;
    // for(int i=1, x, y; i<=m; ++i){
    //     cin>>x>>y;
    //     adj[x][y]=1; adj[y][x]=1;
    // }
    vector<int> vec;
    for(int i=1; i<=n; ++i) vec.ep(i);
    cir.clear();
    ans.clear();
    for(int i=1; i<=n; ++i) notge[i]=0;
    divide(vec);
    for(auto v:cir){
        if(v.size()==3){
            ans.ep(v[0], v[1]);
            ans.ep(v[0], v[2]);
            ans.ep(v[1], v[2]);
            continue;
        }
        vector<int> seq;
        seq.ep(v[0]); seq.ep(v[1]); seq.ep(v[2]);
        int len=3;
        for(int i=3; i<(int)v.size(); ++i){
            vector<int> tmp;
            tmp.ep(seq[len-2]); tmp.ep(seq[len-1]);
            if(!ask(seq[0], v[i], tmp)){
                int w=seq.back(); seq.pop_back();
                seq.ep(v[i]); seq.ep(w);
                ++len;
                continue;
            }
            tmp.clear();
            tmp.ep(seq[0]); tmp.ep(seq[len-1]);
            if(!ask(seq[len-2], v[i], tmp)){
                seq.ep(v[i]); 
                ++len;
                continue;
            }
            int lv=0, rv=len-2, mid, ret=-1;
            while(lv<=rv){
                mid=(lv+rv)>>1;
                tmp.clear();
                tmp.ep(seq[len-1]); tmp.ep(seq[lv]);
                if(!ask(seq[mid+1], v[i], tmp)){
                    ret=mid; rv=mid-1;
                }
                else{
                    lv=mid+1;
                }
            }
            vector<int> nseq;
            for(int j=0; j<len; ++j){
                nseq.ep(seq[j]);
                if(j==ret) nseq.ep(v[i]);
            } 
            seq.swap(nseq);
            ++len;
        }
        for(int i=0; i+1<len; ++i) ans.ep(seq[i], seq[i+1]);
        ans.ep(seq[0], seq.back());
    }
    cout<<"! "<<ans.size()<<endl;
    for(auto [x, y]:ans) cout<<x<<' '<<y<<endl;
    // cout<<"ask:"<<asktimes<<endl;
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
