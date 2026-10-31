#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;

int n,a[N];
char ans[N];

set <int> S;
vector <int> V[N];

int prev(int x){
    auto it=S.find(x);
    if(it==S.begin() || it==S.end()) return 0;
    return *(--it);
}
int suff(int x){
    auto it=S.find(x);
    if(it==S.end()) return 0;
    ++it;
    if(it==S.end()) return 0;
    return *it;
}

int x,y;
bool upd(int pos,int &u){
    if(!a[pos]) return 0;
    
    int lst=prev(pos);
    if(lst && a[lst] && a[lst]!=x && a[lst]!=y){
        // cout<<" ! find "<<lst<<" "<<pos<<" for "<<u<<endl;
        u=a[lst];
        
        ans[lst]='(',ans[pos]=')';
        a[lst]=a[pos]=0;
        S.erase(lst),S.erase(pos);
        return 1;
    }
    
    int nxt=suff(pos);
    if(nxt && a[nxt] && a[nxt]!=x && a[nxt]!=y){
        // cout<<" ! find "<<pos<<" "<<nxt<<" for "<<u<<endl;
        u=a[nxt];
        
        ans[pos]='(',ans[nxt]=')';
        a[nxt]=a[pos]=0;
        S.erase(nxt),S.erase(pos);
        return 1;
    }
    
    return 0;
}



void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) V[i].clear();
    for(int i=1;i<=n*2;i++) scanf("%d",&a[i]),V[a[i]].push_back(i);
    
    S.clear();
    for(int i=1;i<=n*2;i++) S.insert(i);
    
    x=y=-1;
    for(int i=1;i<n*2;i++){
        if(a[i]!=a[i+1]){
            x=a[i],y=a[i+1];
            
            ans[i]='(',ans[i+1]=')';
            a[i]=a[i+1]=0;
            S.erase(i),S.erase(i+1);
            break;
        }
    }
    
    // cout<<"start "<<x<<" "<<y<<endl;
    
    for(int t=1;t<n-1;t++){
        // cout<<"---> search for "<<x<<" "<<y<<endl;
        if(upd(V[x][0],x)) continue;
        if(upd(V[x][1],x)) continue;
        if(upd(V[y][1],y)) continue;
        if(upd(V[y][1],y)) continue;
        assert(0);
        // cout<<"WRONG!"<<endl;
        // exit(0);
    }
    
    int pos1=-1,pos2=-1;
    if(a[V[x][0]]) pos1=V[x][0];
    else pos1=V[x][1];
    if(a[V[y][0]]) pos2=V[y][0];
    else pos2=V[y][1];
    
    if(pos1>pos2) swap(pos1,pos2);
    ans[pos1]='(',ans[pos2]=')';
    for(int i=1;i<=n*2;i++) putchar(ans[i]);
    printf("\n");
}

int main(){
    int T; cin >> T;
    while(T--){
        solve();
    }
}