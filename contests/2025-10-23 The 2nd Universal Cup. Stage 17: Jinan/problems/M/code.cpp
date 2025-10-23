#pragma GCC optimize(2)

#include <bits/stdc++.h>
using namespace std;

int T,n;
bool onc[2100];
int xx[2100];
vector<int> ans;
struct p2{
    int x,y;
    p2(int x=0,int y=0):x(x),y(y){}
    friend p2 operator - (const p2& a,const p2& b){return p2(a.x-b.x,a.y-b.y);}
    friend bool operator < (const p2& a,const p2& b){return a.x < b.x || (a.x == b.x && a.y < b.y);}
    friend bool operator == (const p2& a,const p2& b){return a.x == b.x && a.y == b.y;}
};
int X(p2 o,p2 a){
    if(a.x < o.x&& a.y < o.y)return 1;
    if(a.x >= o.x && a.y < o.y)return 2;
    if(a.x >= o.x && a.y >= o.y)return 3;
    else return 4;
    //if(a.x < o.x && a.y >= o.y)return 4;
}
vector<p2> p,c;

vector<int> id;

long long Cross(p2 a,p2 b){
    return (long long)a.x*b.y-(long long)a.y*b.x;
}
p2 o;
bool cmp(int i,int j){
    if(xx[i] != xx[j])return xx[i]<xx[j];
    return Cross(p[i]-o,p[j]-o)>0ll;
}

vector<p2> ConvexHull(vector<p2> p){
    sort(p.begin(),p.end());
    int n = p.size(),m=0;
    vector<p2> res(n+1);
    for(int i=0;i<n;i++){
        while(m>1 && Cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0ll)m--;
        res[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while(m>k && Cross(res[m-1]-res[m-2],p[i]-res[m-2])<=0ll)m--;
        res[m++]=p[i];
    }
    m -= n>1;
    res.resize(m);
    return res;
}

signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        p.push_back(p2(x,y));
    }
    c = ConvexHull(p);
    for(int i=0;i<n;i++){
        for(p2 v:c){
            if(v == p[i])onc[i]=1;
        }
    }
    //for(p2 v:c){
        //printf("c contains %d,%d\n",v.x,v.y);
    //}
    long long ans=1;
    for(int i=0;i<n;i++){
        
        if(onc[i])continue;
        //printf("i=%d start\n",i);
        o = p[i];
        id.clear();
        for(int j=0;j<n;j++){
            if(i==j)continue;
            id.push_back(j);
            xx[j] = X(o,p[j]);
        }
        sort(id.begin(),id.end(),cmp);
        //for(int i=0;i<id.size();i++){
            //printf("id[%d]=%d\n",i,id[i]);
        //}
        for(int i=0;i+1<id.size();i++){
            if(onc[id[i]] && onc[id[i+1]])ans++;
        }
        if(onc[id[id.size()-1]] && onc[id[0]])ans++;
    }
    printf("%lld\n",ans);
}











