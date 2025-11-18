#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int ist=1,ied=n,jst=1,jed=n;
    printf("Yes\n%d\n",n-1);
    while(ist<ied){
        if(a != ied && b != jed){
            printf("%d %d %d %d\n",ied,jed,ist-ied,jst-jed);
            ied--;
            jed--;
        }
        else if(a != ied && b != jst){
            printf("%d %d %d %d\n",ied,jst,ist-ied,jed-jst);
            ied--;
            jst++;
        }
        else if(a != ist && b != jed){
            printf("%d %d %d %d\n",ist,jed,ied-ist,jst-jed);
            ist++;
            jed--;
        }
        else{
            printf("%d %d %d %d\n",ist,jst,ied-ist,jed-jst);
            ist++;
            jst++;
        }
    }
}
