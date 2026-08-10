#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N=11000000;
int T,n,k,cnt[27];
char s[N],t[N];
char st[5],tmp[5],ed[5];

const int dir[8][4]={
    {1,2,3,4},
    {1,3,2,4},
    {4,2,3,1},
    {4,3,2,1},
    {2,1,4,3},
    {2,4,1,3},
    {3,1,4,2},
    {3,4,1,2}
};


void solve(){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    scanf("%s",t+1);
    memset(cnt,0,sizeof(cnt));
    
    for(int i=2;i<k;i++){
        if(s[i] != t[i]){
            printf("No\n");
            return;
        }
    }
    for(int i=n-k+2;i<n;i++){
        if(s[i] != t[i]){
            printf("No\n");
            return;
        }
    }
    
    for(int i=1;i<=n;i++){
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']--;
    }
    for(int i=0;i<=26;i++){
        if(cnt[i] != 0){
            printf("No\n");
            return;
        }
    }
    
    if(k*2==n){
        st[1] = s[1];st[2] = s[k];st[3] = s[k+1];st[4] = s[n];
        ed[1] = t[1];ed[2] = t[k];ed[3] = t[k+1];ed[4] = t[n];
        for(int o=0;o<=7;o++){
            for(int i=1;i<=4;i++){
                tmp[i] = st[dir[o][i-1]];
            }
            bool f=1;
            for(int i=1;i<=4;i++){
                if(tmp[i] != ed[i])f=0;
                //printf("%c %c\n",tmp[i],ed[i]);
            }
            if(f){
                printf("Yes\n");
                return;
            }
        }
        printf("No\n");
        return;
    }
    
    if(k*2-1 == n){
        if(s[k] != t[k]){
            printf("No\n");
            return;
        }
    }
    
    
    printf("Yes\n");
    return;
}

signed main(){
    cin>>T;
    while(T--){
        solve();
    }
}