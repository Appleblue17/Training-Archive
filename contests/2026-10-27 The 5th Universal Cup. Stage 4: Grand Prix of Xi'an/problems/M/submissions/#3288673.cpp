#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
char s[4][N];
int n,g[4],c[4];
unordered_map<char,int> ma;

void solve(){
    scanf("%d",&n);
    for(int j=0;j<4;j++){
        scanf("%s",s[j]);
        g[j]=2000;c[j]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(s[j][i] == 'H'){
                c[j]++;
                if(c[j] == 100){
                    c[j] = 0;
                    g[0]+=30;g[1]+=30;g[2]+=30;g[3]+=30;g[j]-=30;
                }
            }
            else{
                c[j] = 0;
                g[j] -= ma[s[j][i]];
                //printf("i=%d,j=%d,s=%c,g=%d\n",i,j,s[j][i],g[j]);
            }
        }
        for(int j=0;j<4;j++){
            if(g[j] <= 0){
                g[j] = -1e9;
            }
            if(g[j] >= 2000){
                g[j] = 2000;
            }
        }
    }
    for(int j=0;j<4;j++){
            if(g[j] <= 0){
                g[j] = 0;
            }
    }
    printf("%d %d %d %d\n",g[0],g[1],g[2],g[3]);
}

int main(){
    ma['J'] = 50;ma['A'] = 100;ma['M'] = 200;
    int T;cin >> T;while(T--){
        solve();
    }
}