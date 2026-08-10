#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,INF=1e9;
int T,n,y,M;
vector <int> V[N];
int mx[N];
 
bool check1(int l,int r,int s,int y){
    for(int i=l;i<=r;i++){
        if(s<=mx[i]) return 0;
        int nw=0;
        for(int x: V[i]){
            nw=nw*s+x;
            if(nw>INF) return 1;
        }
        s=nw;
    }
    return (s>=y);
}
 
bool check2(int l,int r,int s,int y){
    for(int i=l;i<=r;i++){
        int nw=0;
        for(int x: V[i]){
            nw=nw*s+x;
            if(nw>y) return 0;
        }
        s=nw;
    }
    return (s<=y);
}
 
int p[N],id;
 
signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&y,&M);
         
        id=0;
        for(int i=1;i<=n;i++){
            V[i].clear();
            mx[i]=0;
            int len; scanf("%lld",&len);
            if(len==1) p[++id]=i;
            for(int t=1;t<=len;t++){
                int x; scanf("%lld",&x);
                V[i].push_back(x);
                mx[i]=max(mx[i],x);
            }
        }
        int L=1,R=0;
         
        if(!id){
            int l=2,r=M;
            L=r+1;
            while(l<=r){
                int mid=(l+r)>>1ll;
                if(check1(1,n,mid,y)) L=mid,r=mid-1;
                else l=mid+1;
            }
             
            l=L,r=M;
            R=l-1;
            while(l<=r){
                int mid=(l+r)>>1ll;
                if(check2(1,n,mid,y)) R=mid,l=mid+1;
                else r=mid-1;
            }
        }
        else{
            bool fl=1;
            for(int i=1;i<id && fl;i++){
                int a=p[i],b=p[i+1];
                int A=V[a][0],B=V[b][0];
                if(!check1(a+1,b-1,A,B+1)) fl=0;
            }
            if(fl){
                int a=p[id],A=V[a][0];
                if(!check1(a+1,n,A,y) || !check2(a+1,n,A,y)) fl=0;
            }
             
            if(fl){
                int a=p[1],A=V[a][0];
                 
                int l=2,r=M;
                L=r+1;
                while(l<=r){
                    int mid=(l+r)>>1ll;
                    if(check1(1,a-1,mid,A+1)) L=mid,r=mid-1;
                    else l=mid+1;
                }
                 
                R=M;
            }
        }
        if(L>R) printf("-1 -1\n");
        else printf("%lld %lld\n",L,R);
    }
}
