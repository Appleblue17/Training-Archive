#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
int T, n;
char s[N], t[N];
int dizhu;
void solve(){
    scanf("%d", &n);
    scanf("%s", s+1);
    scanf("%s", t+1);
    scanf("%d", &dizhu);
    set<int> xiaoa, xiaob, daa, dab, duia, duib;
    for(int i=1; i<=n; ++i){
        if(s[i]=='1'){
            if(i<dizhu){
                xiaoa.insert(i);
            }
            else{
                daa.insert(i);
            }
        }
        if(s[i]=='2'){
            duia.insert(i);
        }
    }
    for(int i=1; i<=n; ++i){
        if(t[i]=='1'){
            if(i<dizhu){
                xiaob.insert(i);
            }
            else{
                dab.insert(i);
            }
        }
        if(t[i]=='2'){
            duib.insert(i);
        }
    }
    if(xiaob.size()<=1){
        if(dab.empty()&&duib.empty()){
            for(int i=1; i<=n; ++i) {
                if(s[i]=='1'&&i<(*xiaob.begin())){
                    printf("Yes\n");
                    return ;
                }
            }
        }
        int x=0, y=0;
        for(int i=1; i<=n; ++i) {
            if(t[i]=='1'&&i>=dizhu) x=i;
            if(t[i]=='2') y=i;
        }
        for(int i=1; i<=n; ++i) {
            if(s[i]=='1'&&i<x){
                printf("Yes\n");
                return ;
            }
            if(s[i]=='2'&&i<y){
                printf("Yes\n");
                return ;
            }
        }
    }
    while(!xiaoa.empty()){
        if(xiaoa.size()==1) {
            xiaoa.clear(); break;
        }
        if(dab.empty()){
            break;
        }
        int x=*xiaoa.begin(); 
        xiaoa.erase(xiaoa.find(x));
        int y=*dab.begin(); 
        dab.erase(dab.find(y));
        if(daa.upper_bound(y)!=daa.end()){
            int z=*daa.upper_bound(y); daa.erase(daa.find(z));
            continue;
        }
        if(duib.empty()){
            break;
        }
        int u=*duib.begin(); duib.erase(duib.find(u));
        if(duia.upper_bound(u)!=duia.end()){
            int v=*duia.upper_bound(u); duia.erase(duia.find(v));
        }
        else{
            break;
        }
    }
    if(xiaoa.empty()){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        solve();
    }
}