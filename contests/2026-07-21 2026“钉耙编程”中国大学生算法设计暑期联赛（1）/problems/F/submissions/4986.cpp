#include<bits/stdc++.h>
using namespace std;
int n,Lmark,Rmark,dcnt;
const int N = 3100;
char s[N];

int fcnt=0;

bool cons(int x){
    Rmark = Lmark = -1;
    int ans = x*x*(x+1);
    int red = ans - n;
    if(red < 0)return 0;
    dcnt = x;
    int cnt = (red-1) / (x+1) + 1, rem = (red-1) % (x+1), nx = x - rem, nx1 = cnt - nx;
    
    //printf("cnt=%d,red=%d,rem=%d,nx=%d,nx1=%d,dcnt=%d\n",cnt,red,rem,nx,nx1,dcnt);
    assert(nx*x + nx1*(x+1) == red);
    
    
    
    int del = nx/(x+1), mov = nx%(x+1);
    dcnt -= del;
    if(mov){
        dcnt--;
        Rmark = mov;
    }
    
    del = nx1/(x), mov = nx1%(x); 
    dcnt -= del;
    if(mov){
        dcnt--;
        Lmark = x-mov;
    }
    
    if(dcnt<0)return 0;
    
    //printf("final dcnt=%d\n",dcnt);
    
    return 1;
}

void solve(){
    
    int x=0;
    for(int i=1000;i>=1;i--){
        
        if(cons(i)){
            x=i;
            break;
        }
    }
    
    if(x == 0){
        printf("construction failed on n=%d\n",n);
        fcnt++;
    }
    //return;
    int len=0;
    for(int i=1;i<=x;i++){
        putchar('h');
        len++;
        if(i==Lmark)putchar('d'),len++;
    }
    
    for(int i=1;i<=dcnt;i++){
        putchar('d');
        len++;
    }
    
    for(int i=1;i<=x+1;i++){
        putchar('u');
        len++;
        if(i==Rmark)putchar('d'),len++;
    }
    
    if(len > 3001){
        printf("construction failed on n=%d\n",n);
        fcnt++;
    }
    
    putchar('\n');
    
}
signed main(){
    int T;cin >> T;while(T--){
        scanf("%d",&n);
        //n = T+1;
        solve();
    }
    //cout << fcnt << endl;
}