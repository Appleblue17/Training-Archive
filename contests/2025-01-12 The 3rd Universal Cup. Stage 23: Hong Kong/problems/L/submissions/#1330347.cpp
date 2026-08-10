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
const int N=205;
int T, n, m;
char s[N][N], t[N][N];
int w[N][N], w2[N][N];
vector<string> ans;
bool check(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i][j]=='B') return false;
        }
    }
    return true;
}
bool check2(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(s[i][j]=='W') return false;
        }
    }
    return true;
}
void solve(){
    read(n); read(m);
    for(int i=1; i<=n; ++i){
        scanf("%s", s[i]+1);
        for(int j=1; j<=m; ++j) t[i][j]=s[i][j];
    }
    ans.clear();
    bool flag=1;
    while(!check()){
        if(ans.size()==400) {
            flag=0; break;
        }
        int cur=1;
        string str=""; s[1][1]='B'+'W'-s[1][1];
        for(int i=1; i<n; ++i){
            int p=cur;
            for(int j=m; j>cur; --j){
                if(s[i][j]=='B') {
                    p=j; break;
                }
            }
            while(cur!=p){
                ++cur;
                s[i][cur]='B'+'W'-s[i][cur];
                str+="R";
            }
            str+="D";
            s[i+1][cur]='B'+'W'-s[i+1][cur];
        }
        while(cur!=m){
            ++cur; 
            s[n][cur]='B'+'W'-s[n][cur];
            str+="R";
        }
        ans.ep(str);
    }
    if(flag){
        printf("YES\n%d\n", (int)ans.size());
        for(auto t:ans){
            cout<<t<<endl;
        }
        return ;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j) s[i][j]=t[i][j];
    }
    ans.clear();
    while(!check2()){
        if(ans.size()==400) {
            printf("NO\n");
            return ;
        }
        int cur=1; s[1][1]='B'+'W'-s[1][1];
        string str="";
        for(int i=1; i<n; ++i){
            int p=cur;
            for(int j=m; j>cur; --j){
                if(s[i][j]=='W') {
                    p=j; break;
                }
            }
            while(cur!=p){
                ++cur;
                s[i][cur]='B'+'W'-s[i][cur];
                str+="R";
            }
            str+="D";
            s[i+1][cur]='B'+'W'-s[i+1][cur];
        }
        while(cur!=m){
            ++cur; 
            s[n][cur]='B'+'W'-s[n][cur];
            str+="R";
        }
        ans.ep(str);
    }
    printf("YES\n%d\n", (int)ans.size());
    for(auto t:ans){
        cout<<t<<endl;
    }
}
int main(){
	// freopen("D:\\nya\\acm\\B\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\B\\test.out","w",stdout);
	read(T);
	while(T--){
		solve();
	}
	return 0;
}

