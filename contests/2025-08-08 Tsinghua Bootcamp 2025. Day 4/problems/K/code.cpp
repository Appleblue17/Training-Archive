#include<bits/stdc++.h>
using namespace std;
const int N=1e6+56, inf=1e9;
int n;
int a[N],b[N],c[N];


void solve(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        c[i+n]=b[i];
    }
    sort(c+1,c+n*2+1);
    int m1=c[n],m2=c[n+1];
    int cnt=0;
    bool m1in=0,m2in=0;
    for(int i=1;i<=n;i++){
        if(a[i]==m1)m1in = 1;
        if(a[i]==m2)m2in = 1;//1:a 0:b
    }
    if(!(m1in ^ m2in)){
        for(int i=1;i<=n;i++){
            if(a[i]==m1 || b[i]==m1)swap(a[i],b[i]);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]>m2){
            cnt++;
        }
    }
    cnt = cnt - n/2;
    /*int ambsmall=0,bmasmall=0,f=0;
    for(int i=1;i<=n;i++){
        if((a[i] == m1 && b[i] == m2) || (a[i]==m2 && b[i]==m1)){
            f=1;
            break;
        }
        if(a[i]==m1 || a[i]==m2){
            if(b[i] < m1)ambsmall=1;
        }
        if(b[i]==m1 || b[i]==m2){
            if(a[i] < m1)bmasmall=1;
        }
    }
    if(ambsmall==1 && bmasmall==0){
        cnt=1;
    }
    if(f)cnt=0;*/
    //cntL: a larger
    for(int i=1;i<=n;i++){
        if(cnt > 0 && a[i] > m2 && b[i]<m1){
            swap(a[i],b[i]);
            cnt--;
        }
        if(cnt < 0 && a[i] < m1 && b[i]> m2){
            swap(a[i],b[i]);
            cnt++;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    putchar('\n');
    for(int i=1;i<=n;i++){
        printf("%d ",b[i]);
    }
    putchar('\n');
}

signed main(){
    int T;
    scanf("%d",&T);
    while(T--)solve();
}