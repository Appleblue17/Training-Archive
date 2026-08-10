#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,k,q;
int a[110],bs[110][110],pi[110];
void solve(){
    memset(bs,0,sizeof(bs));
    memset(pi,0,sizeof(pi));
    scanf("%d", &k);
    for(int i=1;i<=k;i++){
        memset(a,0,sizeof(a));
        int c,s;
        scanf("%d%d",&c,&s);
        for(int j=1;j<=c;j++){
            int l;
            scanf("%d",&l);
            a[l]^=1;
        }
        a[101] = s;
        //insert
        int val=0;
        for(int j=1;j<=100;j++){
            if(!a[j])continue;
            if(!pi[j]){
                pi[j] = 1;
                //printf("bs[%d]=",j);
                for(int o=1;o<=101;o++){
                    bs[j][o] = a[o];
                //    if(o<=5 || o==101)cout << bs[j][o] << ' ';
                }
                //putchar('\n');
                break;
            }
            else{
                for(int o=1;o<=101;o++){
                    a[o] ^= bs[j][o];
                }
            }
        }
        
        
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        memset(a,0,sizeof(a));
        int d;
        scanf("%d",&d);
        for(int j=1;j<=d;j++){
            int l;scanf("%d",&l);
            a[l]^=1;
        }
        int ans=0;
        for(int j=1;j<=100;j++){
            if(!a[j])continue;
            if(!pi[j]){
                ans=-1;
                break;
            }
            else{
                //printf("i=%d,j=%d,a=",i,j);
                for(int o=1;o<=101;o++){
                    a[o] ^= bs[j][o];
                //    if(o<=5 || o==101)cout << a[o] << ' ';
                }
                //putchar('\n');
            }
        }
        if(ans == 0){
            ans = a[101];
        }
        printf("%d\n",ans);
    }
    
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}