#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int T, n;
int s[N];
struct SA{
    int x[N], y[N], c[N], sa[N], ht[N], rk[N];
    void get_sa(){
        for(int i=1; i<=n*2; ++i) c[i]=x[i]=y[i]=sa[i]=ht[i]=rk[i]=0;
        for(int i=1; i<=n; ++i) c[x[i]=s[i]]++;
        int m=n;
        for(int i=2; i<=m; ++i) c[i]+=c[i-1];
        for(int i=n; i; --i) sa[c[x[i]]--]=i;
        for(int k=1; k<=n; k<<=1){
            int num=0;
            for(int i=n-k+1; i<=n; ++i) y[++num]=i;
            for(int i=1; i<=n; ++i){
                if(sa[i]>k) y[++num]=sa[i]-k;
            }
            for(int i=1; i<=m; ++i) c[i]=0;
            for(int i=1; i<=n; ++i) c[x[i]]++;
            for(int i=2; i<=m; ++i) c[i]+=c[i-1];
            for(int i=n; i; --i) sa[c[x[y[i]]]--]=y[i], y[i]=0;
			for(int i=1; i<=n; ++i){
				swap(x[i], y[i]);
			}
            x[sa[1]]=1; num=1;
            for(int i=2; i<=n; ++i){
                x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
            }
            if(num==n) break;
            m=num;
        }
    }
    void get_ht(){
        for(int i=1; i<=n; ++i) rk[sa[i]]=i;
        for(int i=1, k=0; i<=n; ++i){
            if(rk[i]==1) continue;
            if(k) --k;
            int j=sa[rk[i]-1];
            while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
            ht[rk[i]]=k;
        }
    }
    int st[N][20], lg[N];
    void build(){
        for(int i=2; i<=n; ++i) lg[i]=lg[i>>1]+1;
        for(int i=1; i<=n; ++i) st[i][0]=ht[i];
        for(int t=1; t<=lg[n]; ++t){
            for(int i=1; i+(1<<t)-1<=n; ++i){
                st[i][t]=min(st[i][t-1], st[i+(1<<(t-1))][t-1]);
            }
        }
    }
    inline int lcp(int x, int y){
        if(x>n||y>n) return 0;
        if(x==y) return n-x+1;
        x=rk[x]; y=rk[y];
        if(x>y) swap(x, y);
        ++x;
        int t=lg[y-x+1];
        return min(st[x][t], st[y-(1<<t)+1][t]);
    }
}S;
int len[N];
vector<int> vec[N], item[N], bin[N];
ll ans[N];
struct Fenwick{
    ll tr[N];
    void clr(){
        for(int i=0; i<=n; ++i) tr[i]=0;
    }
    void add(int x, ll v){
        for(; x<=n; x+=(x&-x)) tr[x]+=v;
    }
    ll get(int l, int r){
        ll ret=0;
        for(; r>0; r-=(r&-r)) ret+=tr[r];
        for(--l; l>0; l-=(l&-l)) ret-=tr[l];
        return ret;
    }
}T1, T2, T3, T4, T5;
ll mp[N];
void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &s[i]);
    }
    for(int i=0; i<=n+1; ++i) vec[i].clear(), item[i].clear(), bin[i].clear();
    S.get_sa();
    S.get_ht();
    S.build();
    for(int i=1; i<=n; ++i){
        len[i]=S.lcp(1, i);
        if(i!=1) {
            vec[len[i]].push_back(i);
            bin[i+len[i]-1].push_back(i);
            bin[len[i]].push_back(i);
        }
    }
    ll pre=0, sum=0; int cnt=n-1;
    T1.clr(); T2.clr(); T3.clr(); T4.clr(); T5.clr();
    for(int i=2; i<=n; ++i) sum+=i, T4.add(i, 1), T5.add(i, i);
    for(auto j:vec[0]){
        T4.add(j, -1); T5.add(j, -j);
    }
    for(auto j:vec[0]){
        sum-=j; --cnt;
    }
    for(int i=1; i<=n; ++i){
        for(auto t:item[i]){
            T1.add(t+len[t]-1, 1);
            T2.add(t+len[t]-1, t);
            T3.add(t+len[t]-1, len[t]);
        }
		vector<int> tmp;
        ll ddd=0;
        for(auto t:bin[i-1]){
            if(t+len[t]-1==i-1){
                int w=S.lcp(len[t]+2, i+1);
                if(w<i-len[t]-2){
                    mp[s[len[t]+1]]+=w+1;
					tmp.push_back(s[len[t]+1]);
                }
                else {
                    w=i-len[t]-2;
                    if(i+w+1>n||s[len[t]+1]!=s[i+w+1]){
                        mp[s[len[t]+1]]+=w+1;
						tmp.push_back(s[len[t]+1]);
                    }
                    else{
                        mp[s[len[t]+1]]+=w+2+S.lcp(i+1, i+2+w);
						tmp.push_back(s[len[t]+1]);
                    }
                }
            }
            else if(t>i){
                if(t+len[t]-1==n) {
                    ddd+=len[t];
                }
                else{
                    mp[s[t+len[t]]]+=S.lcp(t+len[t]+1, i+1)+1;
					tmp.push_back(s[len[t]+t]);
                    ddd+=len[t];
                }
            }
            else{
                ddd+=i-t;
            }
        }
        ans[i]=0;
        for(auto t:tmp) ans[i]=max(ans[i], mp[t]), mp[t]=0;
        // cout<<ans[i]<<endl;
        ans[i]+=ddd;
        // cout<<ddd<<endl;
        ans[i]+=pre;
        // cout<<pre<<endl;
        ans[i]+=n;
        ll c1=T1.get(i, n), c2=T2.get(i, n), c3=T3.get(i, n);
        ans[i]-=c3;
        ll c4=T4.get(i+1, n), c5=T5.get(i+1, n);
        // cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<' '<<c5<<endl;
        ans[i]+=1ll*(cnt-c4+c1)*i-(c2+sum-c5);
        ans[i]+=1ll*c4*(i-1);
        for(auto j:vec[i]){
            sum-=j; --cnt;
        }
        for(auto j:vec[i-1]){
            item[max(i+1, j)].push_back(j);
            pre+=len[j];
        }
        for(auto j:vec[i]){
            T4.add(j, -1); T5.add(j, -j);
        }
		// cout<<"ans: "<<i<<' '<<ans[i]<<endl;
    }
    ll opt=0;
    for(int i=1; i<=n; ++i) opt+=ans[i]^i;
    printf("%lld\n", opt);
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
