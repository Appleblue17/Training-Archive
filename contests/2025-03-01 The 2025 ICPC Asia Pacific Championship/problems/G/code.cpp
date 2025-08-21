#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T, n, m;
char s[N], t[N];
int c[2][2];
#define fail {printf("no\n");return;}
#define yes {printf("yes\n");return;}
void solve(){
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    scanf("%s", t+1);
    memset(c, 0, sizeof c);
    for(int i=1; i<=n; ++i) c[0][s[i]-'0']++;
    for(int i=1; i<=m; ++i) c[1][t[i]-'0']++;
    if(c[0][0]<c[1][0]) fail
    if(c[0][1]<c[1][1]) fail
    int itt=1, its=1;
    while(itt<=m){
        if(t[itt]=='0'){
            while(its<=n&&s[its]=='1') ++its;
            if(its>n) fail
            ++its;
            ++itt;
        }
        else{
            int cnt=1, rp=itt;
            while(rp+1<=m&&t[rp+1]=='1') ++rp, ++cnt;
            if(itt==1&&rp==m){
                if(c[0][0]!=0) fail
                yes
            }
            bool occ0=0;
            bool flag=0;
            do{
                while(its<=n&&s[its]=='0') ++its, occ0=1;
                if(its>n) fail
                int rrp=its, ccnt=1;
                while(rrp+1<=n&&s[rrp+1]=='1') ++rrp, ++ccnt;
                its=rrp+1;
                if(itt==1&&occ0) fail
                if(rp==m&&rrp!=n) continue;
                if(ccnt>=cnt){
                    flag=1;
                    break;
                }
            }while(its<=n);
            if(flag==0) fail
            itt=rp+1;
        }
    }
    yes
}
int main(){
    scanf("%d", &T);
    while(T--) solve();
}