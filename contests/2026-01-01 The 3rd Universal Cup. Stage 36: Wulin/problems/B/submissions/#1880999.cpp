#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m;
bool f[N],vis[N];

int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) f[i]=vis[i]=0;
        
        while(m--){
            int x; scanf("%d",&x);
            int tot=0;
            if(!vis[x]){
                for(int i=x;i<=n;i+=x){
                    tot+=(!f[i]);
                    f[i]=1;
                }
                vis[x]=1;
            }
            if(!tot) printf("the lights are already on!\n");
            else printf("%d\n",tot);
            
        }
        
    }
    
    
}
