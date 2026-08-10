#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=110000;
int T,n,m;
struct p2{
    p2(int x,int y):x(x),y(y){}
    int x,y;
};

int cross(p2 a,p2 b){
    return a.x*b.y - a.y*b.x;
}

int dot(p2 a,p2 b){
    return a.x*b.x + a.y*b.y;
}

bool operator ==(p2 a,p2 b){
    return cross(a,b)==0 && dot(a,b)>0;
}

bool operator <(p2 a,p2 b){
    p2 l = p2(-1,0);//min
    //printf("c = %d\n",cross(a,b));
    if(a == b)return 0;
    if(a==l)return 1;
    if(b==l)return 0;
    if(cross(a,b)==0)return atan2(a.y,a.x)<atan2(b.y,b.x);
    
    
    
    if(cross(a,b)<0){
        if(cross(a,l)<0 && cross(l,b)<0){
            return 1;
        }
        else return 0;//a > b
    }
    else{
        if(cross(b,l)<0 && cross(l,a)<0){
            return 0;
        }
        else return 1;
    }
}



vector<p2> p;

void solve(){
    scanf("%lld",&n);
    p.clear();
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p.push_back(p2(x,y));
    }
    sort(p.begin(),p.end());
    //for(int i=0;i<n;i++){
        //printf("p(%d,%d)\n",p[i].x,p[i].y);
    //}
    //cout << (int)(p[1]<p[2]) << endl;
    p2 r = p2(1,0);
    int ans=n;
    bool f=0;
    for(int i=0;i<n;i++){
        
        f=1;
        int rb = upper_bound(p.begin(),p.end(),p2(-p[i].x,-p[i].y))-p.begin();
        //printf("i=%d,rb=%d\n",i,rb);
        if(r<p[i] || r == p[i]){
            ans = min(i-rb+1,ans);
            ans = min(i-rb,ans);
            ans = min(n-i+rb,ans);
            ans = min(n-i+rb-1,ans);
        }
        else{
            ans = min(rb-i,ans);
            ans = min(rb-i-1,ans);
            ans = min(i+n-rb,ans);
            ans = min(i+n-rb+1,ans);
        }
        
        //cout << (int)(p[rb-1] == p2(-p[i].x,-p[i].y)) << endl;
        
        
    }
    if(!f)ans=0;
    printf("%lld\n",ans);
}

signed main(){
    scanf("%lld",&T);
    while(T--){
        solve();
    }
}
