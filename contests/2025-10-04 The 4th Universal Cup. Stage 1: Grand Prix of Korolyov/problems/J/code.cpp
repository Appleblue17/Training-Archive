
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int N=5500;
int n,m,k;
int a[N];

struct Young_Tableau{
    vector <int> V[N];
    
    struct rec{
        int x,y,z; // z in [x,y]
        bool typ; // 0: z,x,y; 1: x,y,z
    };
    vector <rec> REC;
    int len,siz;
    
    void pr(){
        cout<<"pr "<<len<<": "<<endl;
        for(int i=1;i<=len;i++){
            cout<<"  ";
            for(int x: V[i]) cout<<x<<" "; cout<<endl;
        }
    }
    void ins(int x){
        for(int i=1;i<=len+1;i++){
            int pos=V[i].size();
            while(pos>0 && V[i][pos-1]>x){
                if(pos<V[i].size()) REC.push_back({x,V[i][pos],V[i][pos-1],0});
                pos--;
            }
            if(pos==V[i].size()){
                V[i].push_back(x);
                len=max(len,i);
                break;
            }
            if(pos) REC.push_back({V[i][pos-1],V[i][pos],x,1});
            swap(x,V[i][pos]);
        }
        siz++;
    }
    
    vector <int> ANS[N];
    int p[N],L[N],R[N],mp[N];
    void link(int x,int y){
        if(x && y) R[x]=y,L[y]=x;
    }
    void cut(int x,int y){
        if(x && y) R[x]=0,L[y]=0;
    }
    
    void construct_k_lis(int k){
        k=min(k,len);
        for(int i=1;i<=siz;i++) mp[i]=0;
        
        int id=0;
        for(int t=1;t<=k;t++){
            int siz=V[t].size();
            for(int i=0;i<siz;i++){
                int x=V[t][i];
                p[++id]=x; mp[x]=id;
                L[id]=(i!=0)*(id-1);
                R[id]=(i!=siz-1)*(id+1);
            }
        }
                
        reverse(REC.begin(),REC.end());
        for(rec u: REC){
            int x=u.x,y=u.y,z=u.z,typ=u.typ;
            int posx=mp[x],posy=mp[y],posz=mp[z];
            if(!posx || !posy) continue; // not appear, skip
            if(x>y) continue; // type 3/4, skip
            if(R[posx]!=posy) continue; // x and y in different subsequence, skip
            
            if(!typ){ // type 2
                if(!posz){
                    p[posx]=z;
                    mp[z]=posx;
                    mp[x]=0;
                }
                else{
                    int posw=R[posz];
                    cut(posz,posw); cut(posx,posy);
                    link(posz,posy); link(posx,posw);
                }
            }
            else{ // type 1
                if(!posz){
                    p[posy]=z;
                    mp[z]=posy;
                    mp[y]=0;
                }
                else{
                    int posw=L[posz];
                    cut(posw,posz); cut(posx,posy);
                    link(posw,posy); link(posx,posz);
                }
            }
        }
        
        reverse(REC.begin(),REC.end());
        
        int aid=0;
        for(int i=1;i<=id;i++){
            if(L[i]) continue;
            aid++;
            int x=i;
            while(x) ANS[aid].push_back(p[x]),x=R[x];
        }
        
        // cout<<aid<<endl;
        // for(int i=1;i<=aid;i++){
        //     for(int x: ANS[i]) cout<<x<<" ";
        //     cout<<endl;
        // }
    }
};
Young_Tableau f,g;

bool vis[N];
int p[N],pid;
int q[N],qid;

namespace LIS{
    int c[N];
    int lowbit(int x){
        return x & (-x);
    }
    void modify(int x,int k,int n){
        while(x<=n) c[x]=max(c[x],k),x+=lowbit(x);
    }
    int query(int x){
        int tot=0;
        while(x) tot=max(tot,c[x]),x-=lowbit(x);
        return tot;
    }
    
    int dp[N];
    int solve(int *a,int n,int lim){
        for(int i=1;i<=lim;i++) c[i]=0;
        int tot=0;
        for(int i=1;i<=n;i++){
            dp[i]=query(a[i])+1;
            modify(a[i],dp[i],lim);
            tot=max(tot,dp[i]);
        }
        return tot;
    }
}

int buc1[N],buc2[N];
vector <int> A,B,C;
int tmp[N],tid;

int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=n;i++){
        f.ins(a[i]);
        g.ins(n+1-a[i]);
    }
    
    f.construct_k_lis(1);
    int mx=f.V[1].size(); mx=min(mx,m);
    
    int mn=0,tot=0;
    for(int i=1;i<=g.len && tot<m;i++){
        mn=i;
        tot+=g.V[i].size();
    }
    g.construct_k_lis(mn);
    
    if(k<mn || k>mx) return cout<<"No",0;
    
    memset(vis,0,sizeof(vis));
    tot=0;
    for(int x: f.ANS[1]){
        vis[x]=1;
        tot++;
        if(tot>=m) break;
    }
    for(int i=1;i<=n && tot<m;i++){
        if(!vis[i]) vis[i]=1,tot++;
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]]) p[++pid]=a[i];
    }
    
    memset(vis,0,sizeof(vis));
    tot=0;
    for(int t=1;t<=mn && tot<m;t++){
        for(int x: g.ANS[t]){
            vis[n+1-x]=1;
            tot++;
            if(tot>=m) break;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]]) q[++qid]=a[i];
    }
    
    assert(pid==m && qid==m);
    
    for(int i=1;i<=m;i++) buc1[p[i]]++,buc2[q[i]]++;
    for(int i=1;i<=n;i++){
        if(buc1[i] && buc2[i]) C.push_back(i);
        else if(buc1[i]) A.push_back(i);
        else if(buc2[i]) B.push_back(i);
    }
    
    assert(A.size()==B.size());
    int siz=A.size();
    
    int l=0,r=siz;
    while(l<=r){
        int mid=(l+r)>>1;
        memset(vis,0,sizeof(vis));
        for(int x: C) vis[x]=1;
        for(int i=0;i<mid;i++) vis[A[i]]=1;
        for(int i=mid;i<siz;i++) vis[B[i]]=1;
        tid=0;
        for(int i=1;i<=n;i++){
            if(vis[a[i]]) tmp[++tid]=a[i];
        }
        
        assert(tid==m);
        int ret=LIS::solve(tmp,m,n);
        if(ret==k){
            cout<<"Yes"<<endl;
            for(int i=1;i<=m;i++) printf("%d ",tmp[i]);
            return 0;
        }
        if(ret<k) l=mid+1;
        else r=mid-1;
    }
    
}

