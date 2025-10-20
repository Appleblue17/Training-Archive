//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int N=110,M=5100;
int n,m,a[M],vis[M];
bool f;int len;
void solve2(){
    printf("Bernardo\n");fflush(stdout);
    //printf("len=%d\n",len);
    for(int t=1;t<=n;t++){
        int y,a;
        bool f=0;
        scanf("%d%d",&y,&a);
        //printf("read y=%d,a=%d\n",y,a);
        for(int i=a;i<=a+y-1;i++){
            if(vis[i]){
                printf("%d\n",i);fflush(stdout);
                f=1;
                break;
            }
        }
        if(f)continue;
        for(int i=a;i<=a+y-1;i++){
            if(i%len==0){
                vis[i]=1;
                printf("%d\n",i);fflush(stdout);
                f=1;
                break;
            }
        }
        if(f)continue;
        printf("%d\n",a);fflush(stdout);
        vis[a]=1;
    }
    
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);f=0;
    for(int i=n;i>=1;i--){
        if(a[i]*(n-i+1) > m){
            f=1;
            len = a[i];
        }
    }
    if(f){
        solve2();
        return 0;
    }
    printf("Alessia\n");fflush(stdout);
    for(int i=n;i>=1;i--){
        int l=1,r=1,sm=0;
        for(r=1;r<=a[i];r++){
            sm+=vis[r];
        }
        r=a[i];
        while(r<=m){
            if(sm==0){
                printf("%d %d\n",a[i],l);fflush(stdout);
                int x=0;
                scanf("%d",&x);
                vis[x]=1;
                break;
            }
            sm+=vis[r+1];
            sm-=vis[l];
            l++;r++;
        }
    }
    
}
