#include <bits/stdc++.h>
using namespace std;
const int N=110,INF=1e9;
int T,a,b;


int p[N],e[N],pid;
void decomp(int x){
    pid=0;
    for(int i=2;i*i<=x;i++){
        if(x%i) continue;
        p[++pid]=i; e[pid]=0;
        while(x%i==0) x/=i,e[pid]++;
    }
    if(x>1) p[++pid]=x,e[pid]=1;
}

map < pair<int,int>, int> mp;
int dfs(int a,int b){
    if(a==1) return 0;
    if(mp.count(make_pair(a,b))) return mp[make_pair(a,b)];
    
    int tot=a-1;
    for(int i=pid;i>=1;i--){
        if(!e[i]) continue;
        e[i]--;
        int k=p[i];
        
        int x=a%k,y=(k-x)%k;
        if(a<k) x=INF;
        if(k>2){
            if(x<=y) tot=min(tot,dfs((a-x)/k,(b-x)/k)+x+1);
            else tot=min(tot,dfs((a+y)/k,(b+y)/k)+y+1);
        }
        else{
            tot=min(tot,dfs((a-x)/k,(b-x)/k)+x+1);
            if(x) tot=min(tot,dfs((a+y)/k,(b+y)/k)+y+1);
        }
        e[i]++;
    }
    mp[make_pair(a,b)]=tot;
    return tot;
}


int main(){
    // freopen("Jin.txt","r",stdin);
    cin>>T;
    while(T--){
        cin>>a>>b;
        if(a>b) swap(a,b);
        decomp(b-a);
        cout<<dfs(a,b)<<endl;
    }
}
