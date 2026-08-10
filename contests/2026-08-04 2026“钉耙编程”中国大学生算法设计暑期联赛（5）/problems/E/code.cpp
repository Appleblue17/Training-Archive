#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5,INF=1e9;
int T,n,k,m,q;

map <string,int> mp;
int id;

char S[N];

vector <int> V[N];
vector <int> ANS;

signed main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&k,&m,&q);
        mp.clear(); id=0;
        ANS.clear();
        
        for(int i=1;i<=n;i++){
            scanf("\n%s",S);
            string str=S;
            if(!mp[str]) mp[str]=++id;
            V[mp[str]].push_back(i);
            // cout<<mp[str]<<endl;
        }
        
        for(int t=1;t<=id;t++){
            bool fl=0;
            int lst=-INF,tot=0;
            for(int i=0;i<V[t].size();i++){
                if(i>=q) break;
                int x=V[t][i];
                if(!fl){
                    if(x==lst+1) tot++;
                    else tot=1;
                    if(tot>=k) fl=1;
                    lst=x;
                }
                else if(x>V[t][0]+m) ANS.push_back(x);
            }
        }
        if(ANS.size()){
            sort(ANS.begin(),ANS.end());
            for(int x: ANS) printf("%d ",x);
            printf("\n");
        }
        else printf("empty\n");
        
        for(int i=1;i<=id;i++) V[i].clear();
    }
}