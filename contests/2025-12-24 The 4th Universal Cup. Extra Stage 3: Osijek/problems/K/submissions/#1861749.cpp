#include<bits/stdc++.h>
using namespace std;
const int N=3;
int a[N];
int main(){
    int n;
    scanf("%d",&n);
    if(n <= 2){
        int sm=0;
        for(int i=1;i<=n;i++){
            
            printf("? %d\n",i);fflush(stdout);
            scanf("%d",&a[i]);
            sm+=a[i];
            if(a[i]%3==0){
                printf("! 1\n");
                return 0;
            }
        }
        if(sm%3==0){
            printf("! 1\n");
            return 0;
        }
        printf("! 0\n");
        return 0;
    }
    else{
        printf("! 1\n");
    }
}
