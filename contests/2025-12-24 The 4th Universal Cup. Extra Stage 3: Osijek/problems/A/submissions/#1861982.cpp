#include<bits/stdc++.h>
using namespace std;
const int N=30;
int a[N];
int n,k;
char s[N];
int bitc(int x){
    int ret=0;
    while(x){
        if(x%2)ret++;
        x/=2;
    }
    return ret;
}
int ans[N];
int main(){
    scanf("%d",&n);
    while(n--){
        int x=0;
        for(int i=0;i<=20;i++){
            scanf("%d",&a[i]);
            if(i == a[0])continue;
            if(i>=1)x = x^a[i];
        }
        if(a[0] == 20){
            int sm=0;
            for(int i=1;i<=19;i++){
                sm += bitc(a[i]);
            }
            printf("%d\n",sm%2);fflush(stdout);
            continue;
        }
        if(x & (1<<(a[0]-1))){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
        fflush(stdout);
        
    }
    scanf("%d",&k);
    while(k--){
        int x=0,sm=0;
        for(int i=0;i<=20;i++){
            scanf("%d",&a[i]);
            if(i == a[0])continue;
            if(i>=1)x = x^a[i];
            if(i>=1 && i<=19)sm += bitc(a[i]);
        }
        scanf("%s",s+1);
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=19;i++){
            //printf("s[%d]=%d\n",i,s[i]);
            if(a[0]==i)continue;
            //printf("i=%d,x^ai=%d\n",i,x^a[i]);
            if((s[i]-'0') ^ ((bool)((x^a[i])&(1<<(i-1))))){
                ans[i]=1;
                //printf("ans[%d]=1\n",i);
                sm++;
            }
        }
        if(a[0]<=19){
            ans[a[0]] = (s[20]-'0')^(sm&1);
        }
        
        int fans=0;
        for(int i=1;i<=19;i++){
            fans += (1<<(i-1))*ans[i];
        }
        
        printf("%d\n",fans);
        fflush(stdout);
        
    }
}
