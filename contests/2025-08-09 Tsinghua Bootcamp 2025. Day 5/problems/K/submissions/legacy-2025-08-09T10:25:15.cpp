#include <bits/stdc++.h>
using namespace std;
const int N=11000;
char s[N],a[N],b[N],c[N]; int an,bn,cn,n;

void print(){
    bool fb=0;
    for(int i=1;i<=bn;i++){
        if(!(b[i]>='0' && b[i]<='9'))fb=1;
    }
    if(!fb){
        int cnt = bn%3;
        for(int i=1;i<bn;i++){
            putchar(b[i]);
            if(i%3==cnt){
                putchar('\'');
            }
        }
        putchar(b[bn]);
    }
    else{
        printf("%s",b+1);
    }
}

signed main(){
    scanf("%s",s+1);
    n = strlen(s+1);
    int u=1;
    while(s[u]!='='){
        a[++an]=s[u];
        u++;
    }
    u++;
    while(s[u]!='+'){
        b[++bn]=s[u];
        u++;
    }
    u++;
    while(u<=n){
        c[++cn]=s[u];
        u++;
    }
    

    printf("%s",a+1);
    putchar('=');
    print();
    putchar('+');
    memset(b,0,sizeof(b));
    for(int i=1;i<=cn;i++){
        b[i]=c[i];
    }
    bn=cn;
    print();
}