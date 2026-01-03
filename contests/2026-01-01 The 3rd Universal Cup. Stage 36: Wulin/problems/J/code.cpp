#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int T,n,m,q;
vector <int> A[N],S[N];

priority_queue < int,vector<int>,greater<int> > que;
bool check1(int k){
    while(que.size()) que.pop();
    int nw=m;
    for(int i=1;i<n;i++){
        // cout<<i<<": "<<endl;
        while(nw>=1 && S[i][nw]>k){
            que.push(nw);
            // cout<<"INS "<<nw<<endl;
            nw--;
        }
        if(que.size()){
            if(que.top()==m) return 0;
            que.pop();
        }
    }
    return 1;
}

bool check2(int k){
    while(que.size()) que.pop();
    int nw=m;
    for(int i=1;i<=n;i++){
        while(nw>=1 && S[i][nw]>k){
            que.push(nw);
            nw--;
        }
        if(que.size()){
            int x=que.top();
            que.pop();
        }
    }
    return que.empty();
}

int val[N];
int ansL[N],ansR[N];

bool solve(int x){
    int pos=upper_bound(val+1,val+n+1,x)-val-1;
    // cout<<x<<": "<<pos<<" "<<ansL[pos]<<" "<<ansR[pos]<<endl;
    if(x>=ansL[pos] && x<=ansR[pos]) return 1;
    return 0;
}

signed main(){
    // freopen("J.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&q);
        
        if(n<=m){
            for(int i=0;i<=n;i++){
                A[i].resize(m+1);
                S[i].resize(m+1);
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    scanf("%lld",&A[i][j]);
                }
            }
        }
        else{
            for(int i=0;i<=m;i++){
                A[i].resize(n+1);
                S[i].resize(n+1);
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    scanf("%lld",&A[j][i]);
                }
            }
            swap(n,m);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) S[i][j]=S[i][j-1]+S[i-1][j]-S[i-1][j-1]+A[i][j];
        }
        
        for(int t=1;t<=n;t++){
            int ll=S[t-1][m],rr=S[t][m]-1;
            val[t]=ll;
            // cout<<t<<": "<<ll<<" "<<rr<<endl;
            
            int l,r,L,R;
            l=ll,r=rr,R=l-1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(check1(mid)) R=mid,l=mid+1;
                else r=mid-1;
            }
            // cout<<"R = "<<R<<endl;
            
            l=ll,r=rr,L=r+1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(check2(mid)) L=mid,r=mid-1;
                else l=mid+1;
            }
            // cout<<"L = "<<L<<endl;
            ansL[t]=L,ansR[t]=R;
            
            // cout<<L<<" "<<R<<endl;
        }
        
        while(q--){
            int x; scanf("%lld",&x);
            if(solve(x)) printf("Putata\n");
            else printf("Budada\n");
        }
        
    }
    
    
}
