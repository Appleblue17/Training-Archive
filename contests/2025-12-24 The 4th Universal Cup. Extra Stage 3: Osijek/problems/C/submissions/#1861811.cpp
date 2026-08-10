#include<bits/stdc++.h>
using namespace std;
const int N=4400;
int T,n;
int a[N];

int qry(int x,int y){
    printf("%d %d\n",x,y);
    fflush(stdout);
    
    int ret; scanf("%d",&ret);
    return ret;
}




int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        
        // for(int i=1; i<=n; ++i) cin>>a[i];
        
        int l=2,r=(n-1)/2,mx=1;
        while(l<=r){
            int mid=(l+r)>>1;
            
            int x=qry(1,mid*2),y=qry(2,mid*2-1);
            if(x==y) mx=mid,l=mid+1;
            else r=mid-1;
        }
        
        printf("3 %d %d\n",2*mx-1,2*mx+1);
        fflush(stdout);
    }
}
