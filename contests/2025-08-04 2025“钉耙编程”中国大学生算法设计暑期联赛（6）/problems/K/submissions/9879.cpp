#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=1e6+5,INF=1e9;
int T,n,m,c;

int buc[N];
int p[N],id;

int bc[N];
bool check(int k){
    for(int i=1;i<=id;i++){
        int x=p[i],w=buc[x];
        bc[x%k]+=w;
    }
    bool fl=1;
    for(int i=1;i<=id && fl;i++){
        int x=p[i],w=buc[x];
        if(bc[x%k]!=n/c) fl=0;
    }
    
    for(int i=1;i<=id;i++){
        int x=p[i],w=buc[x];
        bc[x%k]=0;
    }
    return fl;
}

vector <int> ANS;

signed main(){
    cin>>T;
    while(T--){
        scanf("%d%d%d",&n,&m,&c);
        ANS.clear();
        for(int i=0;i<=m;i++) buc[i]=0;
        
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            buc[x]++;
        }
        
        bool fl=1;
        id=0;
        for(int i=0;i<=m;i++){
            if(buc[i]){
                p[++id]=i;
                if(buc[i]!=n/c) fl=0;
            }
        }
        
        if(fl){
            printf("-1\n");
            continue;
        }
        else if(id<=c){
            printf("0\n");
            continue;
        }
        
        int mn=INF,L,R;
        for(int l=1;l<=id-c;l++){
            int r=l+c;
            mn=min(mn,p[r]-p[l]);
        }
        
        for(int i=1;i<=mn+5;i++){
            if(check(i)) ANS.push_back(i);
        }
        printf("%d ",ANS.size());
        for(int x: ANS) printf("%d ",x);
        printf("\n");
    }
    
}