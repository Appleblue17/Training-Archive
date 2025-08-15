#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int mod=1e9+7;
int n;
struct p2{
    int x,y;
    bool f=0;
    p2(int x=0,int y=0):x(x),y(y){f=0;}
    friend p2 operator -(const p2& A,const p2& B){return p2(A.x-B.x,A.y-B.y);}
    friend bool operator < (const p2& A,const p2& B){return A.x < B.x || (A.x == B.x && A.y < B.y);}
};
vector<p2> p,ans;
__int128 Cross(p2 a,p2 b){
    return a.x*b.y - a.y*b.x;
}

__int128 PolygonArea(vector<p2> po){
    int n = po.size();
    __int128 area=0;
    for(int i=1;i<n-1;i++){
        area += Cross(po[i]-po[0],po[i+1]-po[0]);
    }
    return area;
}

void solve(){
    p.clear();ans.clear();
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p.push_back(p2(x,y));
    }
    bool f = PolygonArea(p)<0;
    p.push_back(p[0]);
    p.push_back(p[1]);
    for(int i=1;i<=n;i++){
        __int128 tt = Cross(p[i]-p[i-1],p[i+1]-p[i]);
        if(tt==0)continue;
        p[i].f = (tt>0) ^ f;
        ans.push_back(p[i]);
    }
    //ans.empty() != 1
    sort(ans.begin(),ans.end());
    printf("%lld\n",(int)ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%lld %lld ",ans[i].x,ans[i].y);
        if(ans[i].f)printf("YES\n");
        else printf("NO\n");
    }
}
signed main(){
    int T;
    scanf("%lld",&T);
    while(T--){solve();}
}