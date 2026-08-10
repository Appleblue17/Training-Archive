#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int ans=0,x=0;
    if(n%2==0){
        ans+=2;
        x=(n-2)/2;
    }
    else{
        ans+=1;
        x=(n-1)/2;
    }
    ans += (x/3)*2;
    printf("%d %d\n",ans,n);
}
