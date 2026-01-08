#include <bits/stdc++.h>
using namespace std;
int T, n, m;
void solve(){
    scanf("%d%d", &n, &m);
    unordered_map<int, int> h;
    
    if(m==2){
        for(int i=1, x; i<=n; ++i) scanf("%d", &x), h[x%3]++;
        if(h[1]==0&&h[2]==1){
            printf("Ana\n");
        }
        else{
            printf("Bob\n");
        }
        return ;
    }
    for(int i=1, x; i<=n; ++i) scanf("%d", &x), h[x]++;
    if(m>3){
        if(h[1]==n){
            printf("Bob\n");
            return ;
        }
        if(h[1]+h[2]==n){
            if(h[1]==0&&h[2]==1){
                printf("Ana\n");
            }
            else{
                printf("Bob\n");
            }
            return ;
        }
        if(h[1]==0&&h[2]<=1) printf("Ana\n");
        else printf("Bob\n");
        return ;
    }
    if(h[1]!=0){
        printf("Bob\n");
        return ;
    }
    if(h[1]+h[2]==n){
        if(h[1]==0&&h[2]==1){
            printf("Ana\n");
        }
        else{
            printf("Bob\n");
        }
        return ;
    }
    if(h[2]>=2) {
        printf("Bob\n");
        return ;
    }
    int x=0;
    if(h[2]==1){
        n-=h[3];
        h[3]=0;
        x++;
    }
    //printf("%d %d %d\n",h[2],h[5],h[6]);
    if(h[2]==1 && h[5]%2==1 && h[6]==1 && (n-h[2]-h[3]-h[4]-h[5]-h[6] == 0)){
        printf("Bob\n");
        return;
    }
    if(h[3]>0||n-h[2]-h[3]-h[4]-h[5]>0){
        printf("Ana\n");
        return ;
    }
    if((h[5]+x)&1){
        printf("Ana\n");
    }
    else{
        printf("Bob\n");
    }
}
signed main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}
