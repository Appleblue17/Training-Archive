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
template <typename T>inline void read(T &x){
	x=0;char c=getchar();bool f=0;
	for(;c<'0'||c>'9';c=getchar()) f|=(c=='-');
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+(c^48);
	x=(f?-x:x);
}
const int N=1e6+5;
char ch[5]={'B', 'R', 'N', 'Q', 'K'};
vector<string> all;
inline bool check(string &cur){
    bool flag=0;
    for(int i=0; i<8; i+=2) if(cur[i]=='B') flag=1;
    if(!flag) return false;
    flag=0;
    for(int i=1; i<8; i+=2) if(cur[i]=='B') flag=1;
    if(!flag) return false;
    for(int i=0; i<8; ++i) if(cur[i]=='K'){
        flag=0;
        for(int j=i-1; j>=0; --j) {
            if(cur[j]=='R') flag=1;
        }
        if(!flag) return false;
        flag=0;
        for(int j=i+1; j<8; ++j) {
            if(cur[j]=='R') flag=1;
        }
        if(!flag) return false;
    }
    return true;
}
void dfs(string cur, vector<int> cnt){
    if(cur.size()==8){
        if(check(cur)) all.ep(cur);
        return ;
    }
    for(int i=0; i<5; ++i) if(cnt[i]){
        --cnt[i];
        dfs(cur+ch[i], cnt);
        ++cnt[i];
    }
}
int n;
bool used[1000];
bool vis[1000];
int ask[10], num[10];
int sim[1000][1000];
int occ[10];
// int goal;
mt19937 rnd(1234);
void solve(){
    // cout<<"goal: "<<all[goal]<<endl;
    for(int i=0; i<n; ++i) used[i]=0;
    for(int o=1; o<=6; ++o){
        ld mx=-1; int argmx=-1;
        int S=0;
        for(int i=0; i<n; ++i) if(!used[i]){
            bool flag=1;
            for(int p=1; p<o; ++p) if(sim[ask[p]][i]!=num[p]){
                flag=0; break;
            }
            S+=flag;
            vis[i]=flag;
        }
        for(int i=0; i<n; ++i) if(!used[i]){
            ld e=0;
            if(vis[i]) e=0.01;
            for(int w=0; w<=8; ++w) occ[w]=0;
            for(int j=0; j<n; ++j) if(!used[j]&&vis[j]){
                ++occ[sim[i][j]];
            }
            for(int w=0; w<=8; ++w) if(occ[w]) e+=1.0*occ[w]/S*log2l(1.0*S/occ[w]);
            if(e>mx){
                mx=e; argmx=i;
            }
        }
        assert(argmx!=-1);
        cout<<all[argmx]<<endl;
        used[argmx]=1;
        ask[o]=argmx;
        // num[o]=sim[goal][argmx];
        // cout<<num[o]<<endl;
        cin>>num[o];
        if(num[o]==8) return ;
    }
    // cout<<goal<<endl;
}
char tag[10];
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    vector<int> cnt;
    cnt.ep(2); cnt.ep(2); cnt.ep(2); cnt.ep(1); cnt.ep(1);
    dfs("", cnt);
    n=all.size();
    for(int i=0; i<n; ++i) for(int j=i; j<n; ++j){
        for(int k=0; k<8; ++k) sim[i][j]+=all[i][k]==all[j][k];
        sim[j][i]=sim[i][j];
    }
    // for(int i=0; i<n; ++i) goal=i, solve();
	while(~scanf("%s", tag)){
        if(tag[0]=='E') return 0;
        int gameid; cin>>gameid;
        solve();
    }
}

