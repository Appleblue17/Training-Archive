#include <bits/stdc++.h>
using namespace std;
#define int long long
const int lim=1e9;

int A,B,C,D;
int cnt;

// int qry(int l,int r,int L,int R){
//     if(l>r || L>R) return 0;
//     cout<<"? "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
//     int x=(l<=A && A<=r && L<=B && B<=R)+(l<=C && C<=r && L<=D && D<=R);
//     x+=(r-l+1)*(R-L+1);
//     cout<<x<<endl;
    
//     x-=(r-l+1)*(R-L+1);
//     cnt++;
//     return x;
// }

int qry(int l,int r,int L,int R){
    if(l>r || L>R) return 0;
    cout<<"? "<<l<<" "<<L<<" "<<r<<" "<<R<<endl;
    int x; cin>>x;
    x-=(r-l+1)*(R-L+1);
    return x;
}

vector < pair<int,int> > ANS;

void solve(int l,int r,int L,int R,int x){
    if(!x || l>r || L>R) return ;
    if(l==r && L==R){
        for(int i=1;i<=x;i++) ANS.push_back(make_pair(l,L));
        return ;
    }
    int mid=(l+r)>>1,MID=(L+R)>>1;
    
    if(x==2){
        int ret;
        ret=qry(l,mid,L,MID);
        solve(l,mid,L,MID,ret);
        
        ret=qry(l,mid,MID+1,R);
        solve(l,mid,MID+1,R,ret);
        
        ret=qry(mid+1,r,L,MID);
        solve(mid+1,r,L,MID,ret);
        
        ret=qry(mid+1,r,MID+1,R);
        solve(mid+1,r,MID+1,R,ret);
    }
    else{
        int ret1=qry(l,mid,L,R);
        int ret2=qry(l,r,L,MID);
        
        int ll,rr,LL,RR;
        if(ret1) ll=l,rr=mid;
        else ll=mid+1,rr=r;
        
        if(ret2) LL=L,RR=MID;
        else LL=MID+1,RR=R;
        
        solve(ll,rr,LL,RR,1);
    }
}


signed main(){
    // cin>>A>>B>>C>>D;
    solve(1,lim,1,lim,2);
    
    cout<<"! "<<ANS[0].first<<" "<<ANS[0].second<<" "<<ANS[1].first<<" "<<ANS[1].second<<endl;
    // cout<<cnt;
}