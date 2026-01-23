#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N], t[N];
int T, n, m;
int tr(char c){
    if(c>='a'&&c<='z') return c-'a';
    return c-'0'+26;
}
int occ[36];
int nxt[N][36];
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%s", s+1);
        scanf("%s", t+1);
        n=strlen(s+1); m=strlen(t+1);
        for(int i=0; i<36; ++i) occ[i]=n+1;
        for(int i=n; i>=1; --i){
            for(int j=0; j<36; ++j) nxt[i][j]=occ[j];
            occ[tr(s[i])]=i;
        }
        int ansl=0, ansr=0, anslen=n+1;
        for(int i=1; i<=n-m+1; ++i) if(s[i]==t[1]){
            int ed=0;
            int cur=i;
            for(int j=2; j<=m; ++j){
                cur=nxt[cur][tr(t[j])];
                if(cur==n+1) break;
            }
            if(cur!=n+1){
                if(cur-i+1<anslen){
                    anslen=cur-i+1;
                    ansl=i; ansr=cur;
                }
            }
        }
        for(int i=ansl; i<=ansr; ++i) putchar(s[i]);
        putchar('\n');
    }
}
