#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,INF=1e18;

int n,m,k;
struct abc{
    int val,num;
}a[N],b[N];
bool operator <(abc X,abc Y){
    return X.val<Y.val;
}

bool check(int x,int st){
    int nw=st,tme=x;
    int id1=n,id2=m;
    
    while(id1 || id2){
        if(!nw){
            if(id1){
                if(a[id1].val+k>tme) return 0;
                id1--;
            }
        }
        else{
            if(id2){
                if(b[id2].val+k>tme) return 0;
                id2--;
            }
        }
        tme-=k;
        nw^=1;
    }
    return 1;
}


vector <int> ANS[N];
int id;
void construct(int x,int st){
    int nw=st,tme=x;
    int id1=n,id2=m;
    
    while(id1 || id2){
        if(!nw){
            if(id1){
                ANS[++id]={tme-k,0,a[id1].num};
                id1--;
            }
        }
        else{
            if(id2){
                ANS[++id]={tme-k,1,b[id2].num};
                id2--;
            }
        }
        tme-=k;
        nw^=1;
    }
    for(int i=id;i>=1;i--){
        printf("%lld %lld %lld\n",ANS[i][0],ANS[i][1],ANS[i][2]);
    }
}

signed main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].val);
        a[i].num=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&b[i].val);
        b[i].num=i;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    
    int l=0,r=INF,ans=INF;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid,0) || check(mid,1)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<endl;
    if(check(ans,0)) construct(ans,0);
    else construct(ans,1);
}
