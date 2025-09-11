#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N], t[N];
int n, m;
int main() {
    scanf("%s", s+1);
    n=strlen(s+1);
    t[m=1]=s[1];
    for(int i=2; i<=n; ++i) if(s[i]!=s[i-1]) t[++m]=s[i];
    if(m==1){
        putchar(t[1]);
        return 0;
    }
    if(m&1){
        putchar(t[1]);
        putchar(t[2]);
        putchar(t[3]);
        return 0;
    }
    putchar(t[1]);
    putchar(t[2]);
    return 0;
}
