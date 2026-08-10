#include <bits/stdc++.h>
using namespace std;
#define int long long
#define bint __int128
#define MP make_pair
const int N=1e6+5;

int n,m;
map <int,int> mp1,mp2;

int id1,id2;
pair<int,int> A[N],B[N];
int sa[N],sb[N];

int v[N],vid;
void add(int x){
    if(x<=0) return ;
    v[++vid]=x;
}

pair<int,int> pnt[N];
int pid;


int q[N],qid;


bool check(int x,int y,int z){
    bint X=pnt[y].first-pnt[x].first;
    bint Y=pnt[y].second-pnt[x].second;
    bint XX=pnt[z].first-pnt[y].first;
    bint YY=pnt[z].second-pnt[y].second;
    return Y*XX<YY*X;
}

double solve(){
    sort(pnt+1,pnt+pid+1);
    
    qid=0;
    for(int i=1;i<=pid;i++){
        while(qid>1 && !check(q[qid-1],q[qid],i)){
            qid--;
        }
        q[++qid]=i;
    }
    
    for(int i=1;i<=qid;i++){
        int x=q[i];
        // cout<<x<<": "<<pnt[x].first<<" / "<<n*2<<" "<<pnt[x].second<<" / "<<m*2<<endl;
    }
    
    for(int i=1;i<pid;i++){
        int x=q[i],y=q[i+1];
        if(pnt[x].first<=n && pnt[y].first>=n){
            double w=1.0*(n-pnt[x].first)/(pnt[y].first-pnt[x].first);
            double sum=pnt[x].second+w*(pnt[y].second-pnt[x].second);
            return sum/m/2;
        }
    }
    
}

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        int x; scanf("%lld",&x);
        mp1[x]++;
    }
    scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int x; scanf("%lld",&x);
        mp2[x]++;
    }
    
    for(pair<int,int> x: mp1) A[++id1]=x;
    for(pair<int,int> x: mp2) B[++id2]=x;
    
    for(int i=1;i<=id1;i++) sa[i]=sa[i-1]+A[i].second;
    for(int i=1;i<=id2;i++) sb[i]=sb[i-1]+B[i].second;
    
    // cout<<"A"<<endl;
    // for(int i=1;i<=id1;i++) cout<<A[i].first<<" "<<A[i].second<<endl;
    // cout<<"B"<<endl;
    // for(int i=1;i<=id2;i++) cout<<B[i].first<<" "<<B[i].second<<endl;
    
    int cur=0,sum=0;
    for(int i=1;i<=id2;i++){
        while(cur<=id1 && A[cur].first<B[i].first)cur++;
        
        int tot=sa[cur-1]*2+(A[cur].first==B[i].first)*A[cur].second;
        sum+=tot*B[i].second;
        // cout<<i<<": "<<B[i].second<<" "<<tmp<<endl;
    }
    // cout<<sum<<"/"<<2*n*m<<endl;
    if(sum>n*m){
        // cout<<"swap"<<endl;
        swap(n,m);
        swap(id1,id2);
        swap(A,B);
        swap(sa,sb);
    }
    
    vid=pid=0;
    
    for(int i=1;i<=id1;i++){
        int pos=A[i].first;
        add(pos-1); add(pos); add(pos+1);
    }
    for(int i=1;i<=id2;i++){
        int pos=B[i].first;
        add(pos-1); add(pos); add(pos+1);
    }
    sort(v+1,v+vid+1);
    vid=unique(v+1,v+vid+1)-v-1;
    
    int cur1=0,cur2=0;
    for(int t=1;t<=vid;t++){
        int pos=v[t];
        while(cur1<=id1 && A[cur1].first<pos) cur1++;
        while(cur2<=id2 && B[cur2].first<pos) cur2++;
        
        int tot1=sa[cur1-1]*2+(A[cur1].first==pos)*A[cur1].second;
        int tot2=sb[cur2-1]*2+(B[cur2].first==pos)*B[cur2].second;
        
        pnt[++pid]=MP(tot1,tot2);
        // cout<<pos<<": "<<tot1<<" / "<<n*2<<" "<<tot2<<" / "<<m*2<<endl;
    }
    
    cout<<setprecision(10)<<fixed<<solve()<<" ";
    
    for(int i=1;i<=pid;i++){
        int x=pnt[i].first,y=pnt[i].second;
        x=n*2-x;
        pnt[i]=MP(y,x);
    }
    swap(n,m);
    
    cout<<setprecision(10)<<fixed<<1-solve();
}
