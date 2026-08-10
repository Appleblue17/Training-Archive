#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T, n, m, x, y;
int a[N];
int dep[N], dep2[N];
vector<int> e[N];
void dfs(int x, int fa){
    dep[x]=dep[fa]+1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y, x);
    }
}
void dfs2(int x, int fa){
    dep2[x]=dep2[fa]+1;
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs2(y, x);
    }
}
int rt, rt2;
int tag[N];
namespace Solver0{
    int mn[N];
    void dfsa(int x, int fa){
        for(auto y:e[x]) if(y!=fa){
            dfsa(y, x);
            mn[x]=min(mn[x], mn[y]+1);
        }
    }
    void dfsb(int x, int fa, int out){
        mn[x]=min(mn[x], out);
        if(a[x]>1) out=0;
        int mn1=1e9, mn2=1e9;
        for(auto y:e[x]) if(y!=fa){
            if(mn[y]<mn1){
                mn2=mn1; mn1=mn[y];
            }
            else {
                mn2=min(mn[y], mn2);
            }
        }
        for(auto y:e[x]) if(y!=fa){
            if(mn1==mn[y])
            dfsb(y, x, min(out+1, mn2+2));
            else
            dfsb(y, x, min(out+1, mn1+2));
        }
    }
    void solve0(){
        for(int i=1; i<=n; ++i){
            tag[i]=0;
            if(dep[i]+dep2[i]==dep[rt2]+1&&e[i].size()==1){
                tag[i]=1;
            }
            mn[i]=1e9;
            if(a[i]>1) mn[i]=0;
        }
        dfsa(1, 0);
        dfsb(1, 0, 1e9);
        int ans=1e9;
        for(int i=1; i<=n; ++i) if(tag[i]){
            ans=min(ans, mn[i]);
        }
        if(ans==1e9){
            printf("-1\n");
        }
        else{
            printf("%lld\n", 1ll*ans*y+x);
        }
    }
}
namespace Solver1{
    int cost2[N], cost3[N];
	int dep3[N];
    void dfsa(int x, int fa){
		dep3[x]=dep3[fa]+1;
        cost2[x]=cost3[x]=1e9;
        if(a[x]==2) cost2[x]=0;
        else if(a[x]>2) cost2[x]=cost3[x]=0;
        int mn1=1e9, mn2=1e9;
        for(auto y:e[x]) {
            if(y==fa) continue;
            dfsa(y, x);
            cost2[x]=min(cost2[x], cost2[y]+1);
            cost3[x]=min(cost3[x], cost3[y]+1);
            if(cost2[y]<mn1){
                mn2=mn1; mn1=cost2[y];
            }
            else {
                mn2=min(cost2[y], mn2);
            }
        }
        cost3[x]=min(cost3[x], mn1+mn2);
    }
    int costx[N], costy[N], costz[N];
    vector<int> vecx, vecy;
    int dfsb(int x, int fa, int rt, int d){
        costy[rt]=min(costy[rt], min(cost2[x], cost3[x])+d);
        int up=1e9;
        for(auto y:e[x]){
            if(y==fa) continue;
            up=min(dfsb(y, x, rt, d+1)+1, up);
        }
        if(tag[x]) up=0;
        costx[rt]=min(costx[rt], min(cost2[x], cost3[x])+up);
        costz[rt]=min(costz[rt], cost3[x]+d+up);
        vecy.push_back(min(cost2[x], cost3[x])+d);
        vecx.push_back(min((int)1e9, min(cost2[x], cost3[x])+up));
		return up;
    }
    void solve1(){
        int mid=0, len=dep[rt2];
        for(int i=1; i<=n; ++i) if(dep[i]+dep2[i]==len+1&&dep[i]==dep2[i]){
            mid=i;
        }
        dfsa(mid, 0);
		for(int i=1; i<=n; ++i){
			if(dep3[i]==(len+1)/2) tag[i]=1;
			else tag[i]=0;
		}
		int costxmn1=1e9, costxmn2=1e9, costymn1=1e9, costymn2=1e9, costzmn=1e9;
		int xfr1=-1, xfr2=-1, yfr1=-1, yfr2=-1;
        for(auto y:e[mid]){
            costx[y]=1e9; costy[y]=1e9; costz[y]=1e9;
            vecx.clear(); vecy.clear();
            dfsb(y, mid, y, 1);
            int mn=1e9;
            for(int i=0; i<(int)vecx.size(); ++i){
                costz[y]=min(costz[y], vecx[i]+mn);
                mn=min(mn, vecy[i]);
            }
			mn=1e9;
            for(int i=(int)vecx.size()-1; i>=0; --i){
                costz[y]=min(costz[y], vecx[i]+mn);
                mn=min(mn, vecy[i]);
            }
			if(costx[y]<costxmn1){
				costxmn2=costxmn1; xfr2=xfr1;
				costxmn1=costx[y]; xfr1=y;
			}
			else if(costx[y]<costxmn2){
				costxmn2=costx[y]; xfr2=y;
			}
			if(costy[y]<costymn1){
				costymn2=costymn1; yfr2=yfr1;
				costymn1=costy[y]; yfr1=y;
			}
			else if(costy[y]<costymn2){
				costymn2=costy[y]; yfr2=y;
			}
			costzmn=min(costzmn, costz[y]);
        }
        int ans=1e9;
		ans=min(ans, costxmn1+costxmn2);
		ans=min(ans, costzmn+dep[rt2]/2);
		if(xfr1!=yfr1){
			ans=min(ans, costxmn1+costymn1+dep[rt2]/2);
		}
		else{
			ans=min(ans, costxmn1+costymn2+dep[rt2]/2);
			ans=min(ans, costxmn2+costymn1+dep[rt2]/2);
		}
		ans=min(ans, costxmn1+cost2[mid]+dep[rt2]/2);
		ans=min(ans, cost3[mid]+dep[rt2]-1);
		if(ans>n*2){
			printf("-1\n");
		}
		else{
			printf("%lld\n", 1ll*ans*y+2ll*x);
		}
    }
}

namespace Solver2{
    int cost2[N], cost3[N];
	int dep3[N];
    void dfsa(int x, int fa){
        cost2[x]=cost3[x]=1e9;
        if(a[x]==2) cost2[x]=0;
        else if(a[x]>2) cost2[x]=cost3[x]=0;
        int mn1=1e9, mn2=1e9;
        for(auto y:e[x]) {
            if(y==fa) continue;
            dep3[y]=dep3[x]+1; dfsa(y, x);
            cost2[x]=min(cost2[x], cost2[y]+1);
            cost3[x]=min(cost3[x], cost3[y]+1);
            if(cost2[y]<mn1){
                mn2=mn1; mn1=cost2[y];
            }
            else {
                mn2=min(cost2[y], mn2);
            }
        }
        cost3[x]=min(cost3[x], mn1+mn2);
    }
    int costx[N], costy[N], costz[N];
    vector<int> vecx, vecy;
    int dfsb(int x, int fa, int rt, int d){
        costy[rt]=min(costy[rt], min(cost2[x], cost3[x])+d);
        int up=1e9;
        for(auto y:e[x]){
            if(y==fa) continue;
            up=min(dfsb(y, x, rt, d+1)+1, up);
        }
        if(tag[x]) up=0;
        costx[rt]=min(costx[rt], min(cost2[x], cost3[x])+up);
        costz[rt]=min(costz[rt], cost3[x]+d+up);
        vecy.push_back(min(cost2[x], cost3[x])+d);
        vecx.push_back(min((int)1e9, min(cost2[x], cost3[x])+up));
		return up;
    }
    void solve1(){
        int mid1=0, mid2=0, len=dep[rt2];
        for(int i=1; i<=n; ++i) if(dep[i]+dep2[i]==len+1&&abs(dep[i]-dep2[i])==1){
            if(mid1==0) mid1=i;
			else mid2=i;
        }
		for(int i=1; i<=n; ++i) dep3[i]=0;
        dfsa(mid1, mid2); dfsa(mid2, mid1);
		for(int i=1; i<=n; ++i){
			if(dep3[i]==len/2-1) tag[i]=1;
			else tag[i]=0;
		}
        {
			costx[mid1]=1e9; costy[mid1]=1e9; costz[mid1]=1e9;
            vecx.clear(); vecy.clear();
			dfsb(mid1, mid2, mid1, 0);
            int mn=1e9;
            for(int i=0; i<(int)vecx.size(); ++i){
                costz[mid1]=min(costz[mid1], vecx[i]+mn);
                mn=min(mn, vecy[i]);
            } 
			mn=1e9;
            for(int i=(int)vecx.size()-1; i>=0; --i){
                costz[mid1]=min(costz[mid1], vecx[i]+mn);
                mn=min(mn, vecy[i]);
            }
		}
		{
			costx[mid2]=1e9; costy[mid2]=1e9; costz[mid2]=1e9;
            vecx.clear(); vecy.clear();
			dfsb(mid2, mid1, mid2, 0);
            int mn=1e9;
            for(int i=0; i<(int)vecx.size(); ++i){
                costz[mid2]=min(costz[mid2], vecx[i]+mn);
                mn=min(mn, vecy[i]);
            } 
			mn=1e9;
            for(int i=(int)vecx.size()-1; i>=0; --i){
                costz[mid2]=min(costz[mid2], vecx[i]+mn);
                mn=min(mn, vecy[i]);
            }
		}
        int ans=1e9;
		ans=min(ans, costx[mid1]+costx[mid2]);
		ans=min(ans, min(costz[mid1], costz[mid2])+dep[rt2]/2);
		if(ans>n*2){
			printf("-1\n");
		}
		else{
			printf("%lld\n", 1ll*ans*y+2ll*x);
		}
    }
}
void solve(){
    scanf("%d%d%d%d", &n, &m, &x, &y); ++m;
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    if(n==1){
        if(m<=1){
            printf("0\n");
        }
        else if(m>3){
            printf("-1\n");
        }
        else if(a[1]<m){
            printf("-1\n");
        }
        else{
            printf("%d\n", x);
        }
        return ;
    }
    for(int i=1; i<=n; ++i) e[i].clear();
    for(int i=1, x, y; i<n; ++i){
        scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0);
    rt=0;
    for(int i=1; i<=n; ++i) if(dep[i]>dep[rt]) rt=i;
    dfs(rt, 0);
    rt2=0;
    for(int i=1; i<=n; ++i) if(dep[i]>dep[rt2]) rt2=i;
    dfs2(rt2, 0);
    if(dep[rt2]>=m){
        printf("0\n");
        return ;
    }
    if(dep[rt2]+2<m){
        printf("-1\n");
        return ;
    }
    if(dep[rt2]+1==m){
        Solver0::solve0();
        return ;
    }
    if(dep[rt2]&1){
        Solver1::solve1();
    }
    else{
        Solver2::solve1();
    }
}
int main(){
	// freopen("D:\\nya\\acm\\A\\test.in","r",stdin);
	// freopen("D:\\nya\\acm\\A\\test.out","w",stdout);
    scanf("%d", &T);
    while(T--){
        solve();
    }
}