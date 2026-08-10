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
const int N=1e5+5;
int T, n, m;
int bid[8][N], lp[8][N], rp[8][N], idx[8];
inline ll hs(int x, int y){
    return 1000000000ll*x+y;
}
unordered_map<ll, bool> h;
vector<pair<int, pii> > edg;
void solve(int o, int l, int r){
    if(r-l+1<=2){
        return ;
    }
    if(r-l+1==3){
        if(h[hs(l, r)]==0){
            h[hs(l, r)]=1;
            edg.ep(mapa(l, mapa(l+1, r)));
        }
        return ;
    }
    int B=sqrt(r-l+1);
    int clp=idx[o]+1;
    for(int i=l; i<=r; i+=B){
        solve(o+1, i, min(r, i+B));
        ++idx[o];
        for(int j=i; j<=r&&j<=i+B; ++j) bid[o][j]=idx[o];
        lp[o][idx[o]]=i; rp[o][idx[o]]=min(i+B, r);
    }
    int crp=idx[o];
    for(int len=2; len<=crp-clp+1; ++len){
        for(int l=clp; l+len-1<=crp; ++l){
            int r=l+len-1;
            if(lp[o][r]==rp[o][r]) continue;
            edg.ep(mapa(lp[o][l], mapa(lp[o][r], rp[o][r])));
            h[hs(lp[o][l], rp[o][r])]=1;
        }
    }
    if(o!=0){
        for(int i=l+2; i<=r; ++i){
            if(h[hs(l, i)]==0){
                h[hs(l, i)]=1;
                edg.ep(mapa(l, mapa(i-1, i)));
            }
        }
        for(int i=r-2; i>=l; --i){
            if(h[hs(i, r)]==0){
                h[hs(i, r)]=1;
                edg.ep(mapa(i, mapa(i+1, r)));
            }
        }
    }
}
void qry(int l, int r){
    if(r-l+1<=3){
        for(int i=l; i<=r; ++i){
            cout<<i<<' ';
        }
        cout<<endl;
        return ;
    }
    for(int i=0; i<8; ++i){
        if(bid[i][l]!=bid[i][r]){
            vector<int> vec;
            vec.ep(l);
            vec.ep(rp[i][bid[i][l]]);
            vec.ep(lp[i][bid[i][r]]);
            vec.ep(r);
            vec.erase(unique(vec.begin(), vec.end()), vec.end());
            cout<<vec[0]<<' ';
            for(int i=1; i<(int)vec.size(); ++i){
                cout<<vec[i]<<" \n"[i==(int)vec.size()-1];
                if(h.find(hs(vec[i-1], vec[i]))==h.end()){
                    cout<<"failed on:";
                    cout<<l<<' '<<r<<endl;
                    exit(0);
                }
            }
            return ;
        }
    }
    cout<<"not found:";
    cout<<l<<' '<<r<<endl;
    exit(0);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
	cin>>n;
    for(int i=0; i<n; ++i) h[hs(i, i+1)]=1;
    solve(0, 0, n);
    cout<<edg.size()<<endl;
    for(auto t:edg){
        cout<<t.fi<<' '<<t.se.fi<<' '<<t.se.se<<endl;
    }
    // cout<<"------------------------"<<endl;
    int l, r;
    // for(int i=1; i<n; ++i){
    //     for(int j=i+1; j<=n; ++j){
    //         l=i; r=j;
    //         qry(l, r);
    //     }
    // }
    // cout<<"success"<<endl;
    cin>>m;
    while(m--){
        cin>>l>>r;
        qry(l, r);
    }
	return 0;
}

