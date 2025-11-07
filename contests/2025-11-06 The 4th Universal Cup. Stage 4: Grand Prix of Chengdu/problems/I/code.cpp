#include<bits/stdc++.h>
using namespace std;
#define int long long
#define v2 p2
int n,L[1100000],R[1100000],m;
struct p2{
    int x,y;
    p2(int x=0,int y=0):x(x),y(y){}
    friend v2 operator + (const v2& A,const v2& B){return v2(A.x+B.x,A.y+B.y);}
    friend v2 operator - (const v2& A,const v2& B){return v2(A.x-B.x,A.y-B.y);}
    friend v2 operator * (const v2& A,const int p){return v2(A.x*p,A.y*p);}
};
vector<p2> P,p;
vector<p2> ret;
int dot(const v2& A,const v2& B){
    return A.x*B.x + A.y*B.y;
}
int cross(const v2& A,const v2& B){
    return A.x*B.y - A.y*B.x;
}
void findb(p2 A,p2 B){
    
    v2 v = B-A;
    int t = v.y;v.y = v.x;v.x = -t;
    int orig = 0;
    while(dot(v,p[orig+1]-p[orig])==0){
        orig++;
    }
    int c1 = orig;
    if(dot(p[c1+1]-p[c1],v) < 0)v = v*(-1);
    for(int i=19;i>=0;i--){
        if(orig+m-1>=c1+(1<<i)){
            int tw = c1+(1<<i);
            if(dot(v,p[tw+1]-p[tw])>0 && dot(v,p[tw]-p[c1])>=0)c1+=(1<<i);
        }
    }
    c1 = (c1+1)%m;
    int c2 = c1;
    v = v*(-1);
    for(int i=19;i>=0;i--){
        if(c2+(1<<i)<=c1+m-1){
            int tw = c2+(1<<i);
            if(dot(v,p[tw+1]-p[tw])>0 && dot(v,p[tw]-p[c2])>=0)c2 += (1<<i);
        }
    }
    //c2 = (c2+1)%n;
    c2++;c2%=m;
    //printf("c1=%lld,c2=%lld\n",c1,c2);
    ret.clear();ret.push_back(p[c1]);ret.push_back(p[c2]);
}
bool isOnorLeft(const p2 st,const p2 ed,const p2 P){
    return cross(ed-st,P-st)>=0;
}
void solve(){
    P.clear();p.clear();
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        P.push_back(p2(x,y));
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%lld%lld",&x,&y);
        p.push_back(p2(x,y));
    }
    for(int i=0;i<m;i++){
        p.push_back(p[i]);
    }
    for(int i=0;i<m;i++){
        p.push_back(p[i]);
    }
    for(int i=0;i<n;i++){
        P.push_back(P[i]);
    }
    for(int i=0;i<n;i++){
        P.push_back(P[i]);
    }
    //R
    int j=1;
    for(int i=0;i<n;i++){
        while(1){
            findb(P[i],P[j]);
            //printf("i=%lld,j=%lld,ret (%lld,%lld),(%lld,%lld)\n",i,j,ret[0].x,ret[0].y,ret[1].x,ret[1].y);
            if(!isOnorLeft(P[i],P[j],ret[0]) || !isOnorLeft(P[i],P[j],ret[1])){
                break;
            }
            j++;
        }
        R[i]=j-1;
    }
    //L
    j=1;
    for(int i=0;i<n;i++){
        while(1){
            findb(P[i],P[j]);
            if(isOnorLeft(P[j],P[i],ret[0]) && isOnorLeft(P[j],P[i],ret[1])){
                break;
            }
            j++;
        }
        L[i] = j;
    }
    for(int i=0;i<n;i++){
        //printf("L[%lld]=%lld,R[%lld]=%lld\n",i,L[i],i,R[i]);
        L[i+n]=L[i]+n;R[i+n]=R[i]+n;
    }
    j=1;
    __int128 ans=0,fans=0;
    queue<int> q;
    for(int i=0;i<n;i++){
        while(!q.empty() && q.front()<L[i]){
            //printf("remove %lld\n",q.front());
            ans -= q.front();
            q.pop();
        }
        while(j <= R[i]){
            if(R[j] >= L[i]){
                ans += R[j];
                q.push(R[j]);
                //printf("push %lld,j=%lld\n",R[j],j);
            }
            j++;
            
        }
        fans += ans - (__int128)q.size()*(L[i]-1);
        //printf("i=%lld,fans=%lld\n",i,fans);
    }
    printf("%lld\n",(long long)fans/3);
}
signed main(){
    int T;scanf("%lld",&T);
    while(T--){
        solve();
    }
    
}
